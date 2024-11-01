//Nguyễn Tùng Dương 20210266

#include <bits/stdc++.h>
using namespace std;

typedef struct{
    string tenMH;
    string donVi;
    int donGia;
    int soLuong;
} MatHang;

typedef struct {
    string TenKho;
    string MaPhieu;
    string Ngay, Thang, Nam;
    int soMatHang;
    int STDTT; //số tiền đã thanh toán
    //int STTT; //số tiền thanh toán
    int STVC; //số tiền vận chuyển
    int ThanhTien;
    int TongThanhToan;
    MatHang MH[100];
} XuatKho;

XuatKho XK[100];
int n;
int TONG_THANH_TIEN = 0;
int TONG_DA_THANH_TOAN = 0;
int TONG_VAN_CHUYEN = 0;
int TONG_THANH_TOAN = 0;

int VanChuyen(int soluong, string donvi){
    if (donvi == "Thung"){
        if (soluong < 20) return 70;
        if (soluong < 35) return 105;
        if (soluong < 50) return 125;
        return 170;
    }
    else {
        if (soluong <= 50) return 50;
        return 125;
    }
}

int TinhTrangThanhToan(int TongTien, int daThanhToan ){
    return TongTien - daThanhToan;
}

void insert_list(){
    cout<<" Le Thi Hoa - 9959 - 727741 - IT3040 - 2022.2"<<endl;
    cout<<"Ban da chon nhap PHIEU XUAT VA MAT HANG!"<<endl;

    for (int i = 1; i<=n; i++) {
        cout<<"Nhap thong tin Phieu Xuat " <<i<<" :"<<endl;
        fflush(stdin);
        cout<<"\tTen Kho Hang: "; getline(cin, XK[i].TenKho);
        cout<<endl;
        fflush(stdin);
        cout<<"\tMa phieu xuat: "; cin>>XK[i].MaPhieu;
        cout<<endl;

        cout<<"Ngay Lap Phieu Xuat\n";
        cout<<endl;
        cout<<"\tNgay: "; cin>>XK[i].Ngay;
        cout<<endl;
        cout<<"\tThang: "; cin>>XK[i].Thang;
        cout<<endl;
        cout<<"\tNam: "; cin>>XK[i].Nam;
        cout<<endl;
        cout<<"\tSo mat hang: "; cin>>XK[i].soMatHang;
        cout<<endl;
        cout<<"\tNhap danh sach mat hang: "<<endl;
        int VC = 0, TT = 0;
        for (int j = 1; j <= XK[i].soMatHang; j++){
            cout<<"\tMat hang thu "<<j<<endl;
            fflush(stdin);
            cout<<"\t\tTen mat hang: "; getline(cin, XK[i].MH[j].tenMH);
            fflush(stdin);
            cout<<"\t\tDon vi tinh: "; getline(cin, XK[i].MH[j].donVi);

            cout<<"\t\tSo luong: "; cin>>XK[i].MH[j].soLuong;
            cout<<"\t\tDon gia: "; cin>>XK[i].MH[j].donGia;

            VC += VanChuyen(XK[i].MH[j].soLuong, XK[i].MH[j].donVi);
            TT += XK[i].MH[j].soLuong * XK[i].MH[j].donGia;
        }

        cout<<"So tien da thanh toan: "; cin>>XK[i].STDTT;
        XK[i].STVC = VC;
        XK[i].ThanhTien = TT;
        XK[i].TongThanhToan = XK[i].ThanhTien + XK[i].STVC;

        TONG_THANH_TIEN += XK[i].ThanhTien;
        TONG_VAN_CHUYEN += XK[i].STVC;
        TONG_THANH_TOAN += XK[i].TongThanhToan;
        TONG_DA_THANH_TOAN += XK[i].STDTT;

    }

}

void print_list(){
    cout<<" Le Thi Hoa - 9959 - 727741 - IT3040 - 2022.2"<<endl;
    cout<<"Ban da chon IN RA PHIEU XUAT!"<<endl;

    for (int i = 1; i<=n; i++) {
        cout<<"\tTen Kho Hang: "<<XK[i].TenKho<<endl;
        cout<<"\tNgay "<<XK[i].Ngay<<" thang "<<XK[i].Thang<<" nam "<<XK[i].Nam<<endl;
        cout<<"\tSo mat hang: "<<XK[i].soMatHang<<endl;
        cout<<"\tSo tien da thanh toan: "<<XK[i].STDTT<<endl;
        cout<<"\tTong Thanh Tien: "<<XK[i].ThanhTien<<endl;
        cout<<"\tTong Van Chuyen: "<<XK[i].STVC<<endl;
        cout<<"\tTong Phai Thanh Toan: "<<XK[i].TongThanhToan<<endl;
        if (TinhTrangThanhToan(TONG_THANH_TOAN, TONG_DA_THANH_TOAN) > 0)
            cout<<"\tTinh trang Thanh toan: \tChuyen phieu xuat sau so tien: "<<TinhTrangThanhToan(TONG_THANH_TOAN, TONG_DA_THANH_TOAN)<<endl;
        else
            cout<<"\tTinh trang Thanh toan: \tThanh toan thieu so tien: "<<-TinhTrangThanhToan(TONG_THANH_TOAN, TONG_DA_THANH_TOAN)<<endl;

        cout<<"\t\tChi tiet cac Mat Hang: "<<endl;

        cout<<setiosflags(ios::left)<<setw(25)<<"TenMH";
        cout<<setiosflags(ios::left)<<setw(10)<<"DoMHT";
        cout<<setiosflags(ios::left)<<setw(10)<<"soL";
        cout<<setiosflags(ios::left)<<setw(15)<<"dongia";
        cout<<setiosflags(ios::left)<<setw(15)<<"ThanhTien";
        cout<<setiosflags(ios::left)<<setw(15)<<"VanChuyen";
        cout<<setiosflags(ios::left)<<setw(15)<<"Cong";

        cout<<endl;
        for (int j = 1; j <= XK[i].soMatHang; j++){

            cout<<setiosflags(ios::left)<<setw(25)<<XK[i].MH[j].tenMH;
            cout<<setiosflags(ios::left)<<setw(10)<<XK[i].MH[j].donVi;
            cout<<setiosflags(ios::left)<<setw(10)<<XK[i].MH[j].soLuong;
            cout<<setiosflags(ios::left)<<setw(15)<<XK[i].MH[j].donGia;
            cout<<setiosflags(ios::left)<<setw(15)<<XK[i].MH[j].soLuong * XK[i].MH[j].donGia;
            cout<<setiosflags(ios::left)<<setw(15)<<VanChuyen(XK[i].MH[j].soLuong, XK[i].MH[j].donVi);
            cout<<setiosflags(ios::left)<<setw(15)<<XK[i].MH[j].soLuong * XK[i].MH[j].donGia + VanChuyen(XK[i].MH[j].soLuong, XK[i].MH[j].donVi);

            cout<<endl;

        }
        cout<<"--------------------------------------------------------------------------------------------"<<endl;
        cout<<endl;
    }
    cout<<"Tong thanh tien cac Phieu Xuat: "<<TONG_THANH_TIEN<<endl;
    cout<<"Tong van chuyen cac Phieu Xuat: "<<TONG_VAN_CHUYEN<<endl;
    cout<<"Tong phai thanh toan cac Phieu Xuat: "<<TONG_THANH_TOAN<<endl;
    cout<<"Tong da thanh toan cac phieu xuat: "<<TONG_DA_THANH_TOAN<<endl;

    if (TinhTrangThanhToan(TONG_THANH_TOAN, TONG_DA_THANH_TOAN) > 0)
        cout<<"\tTinh trang Thanh toan: \tChuyen phieu xuat sau so tien: "<<TinhTrangThanhToan(TONG_THANH_TOAN, TONG_DA_THANH_TOAN)<<endl;
    else
        cout<<"\tTinh trang Thanh toan: \tThanh toan thieu so tien: "<<-TinhTrangThanhToan(TONG_THANH_TOAN, TONG_DA_THANH_TOAN)<<endl;

    cout<<"Bam phim bat ky de tiep tuc!"<<endl;
    char c;
    cin>>c;

}

void init(){
    cout<<" Le Thi Hoa - 9959 - 727741 - IT3040 - 2022.2"<<endl;
    cout<<"**   CHUONG TRINH QUAN LY PHIEU XUAT **"<<endl;
    cout<<"**1. Nhap CAC PHIEU XUAT, MAT HANG   **"<<endl;
    cout<<"**2. IN KET QUA PHIEU XUAT VA MAT HANG**"<<endl;
    cout<<"**0. Thoat                            **"<<endl;
    cout<<"****************************************"<<endl;
    cout<<"**   Nhap lua chon cua ban            **"<<endl;
    int type;
    cin>>type;
    if (type == 0) {
            cout<<" Le Thi Hoa - 9959 - 727741 - IT3040 - 2022.2"<<endl;
            cout<<"Ban da chon thoat chuong trinh!";
            return;
    }
    if (type == 1) insert_list();
    if (type == 2) print_list();

    init();
}

int main(){
    cout<<" Le Thi Hoa - 9959 - 727741 - IT3040 - 2022.2:"<<endl;
    cout<<"Nhap so Phieu Xuat: "; cin>>n;
    init();
}
