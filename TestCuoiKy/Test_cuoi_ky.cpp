#include <bits/stdc++.h>
using namespace std;


typedef struct {
    string MaNV;
    string HoTenNV;
    int NamSinh;
    int hsLuong;
    string ChucDanh;
} NhanVien;

typedef struct {
    string ten;
    string DiaChi;
    int SoLuongNV;
    int LuongToiThieu;
    NhanVien NV[100];
} PhongBan;

PhongBan PB[100];
int n;

void insert_info(){
    cout<<"Ban da chon nhap danh sach!"<<endl;
    for (int i = 1; i<=n; i++) {
        cout<<"Nhap thong tin phong ban thu: " <<i<<endl;
        cout<<"\tTen phong ban: "; cin>>PB[i].ten;
        cout<<"\tDia chi: "; cin>>PB[i].DiaChi;
        cout<<"\tLuong toi thieu: "; cin>>PB[i].LuongToiThieu;
        cout<<"\tSo luong NV: "; cin>>PB[i].SoLuongNV;
        cout<<"\tNhap danh sach nhan vien: "<<endl;
        string str;
        for (int j = 1; j <= PB[i].SoLuongNV; j++){
            cout<<"\tNhan vien thu "<<j<<endl;

            cout<<"\t\tMa nhan vien: "; cin>>str;
            PB[i].NV[j].MaNV = str;
            str = "";
            fflush(stdin);
            cout<<"\t\tHo ten nhan vien: "; getline(cin, str);
            PB[i].NV[j].HoTenNV = str;
            cout<<"\t\tNam sinh: "; cin>>PB[i].NV[j].NamSinh;
            cout<<"\t\tNhap He so luong: "; cin>>PB[i].NV[j].hsLuong;
            cout<<"\t\tNhap chuc danh: "; cin>>PB[i].NV[j].ChucDanh;
        }
    }

}
int PCCV(string CD){
    if (CD == "GVCC") return 2000;
    if (CD == "GVC") return 1500;
    if (CD == "GV") return 1000;
    if (CD == "CBKT") return 750;
    if (CD == "CBHC") return 500;
}

void printList(){
    cout<<"Ban da chon xuat danh sach: "<<endl;

    for (int i = 1; i<=n; i++) {
        cout<<"\tTen phong ban: "<<PB[i].ten<<endl;
        cout<<"\tDia chi: "<<PB[i].DiaChi<<endl;
        cout<<"\tLuong toi thieu: "<<PB[i].LuongToiThieu<<endl;
        cout<<"\tTong Luong: "<<           endl;
        cout<<"\tTong Cong Doan Phi: "<<   endl;
        cout<<"\tBang luong nhan vien: "<<endl;

        cout<<setiosflags(ios::left)<<setw(10)<<"MaNV";
        cout<<setiosflags(ios::left)<<setw(25)<<"Ho va Ten";
        cout<<setiosflags(ios::left)<<setw(10)<<"Chuc Danh";
        cout<<setiosflags(ios::left)<<setw(10)<<"PCCV";
        cout<<setiosflags(ios::left)<<setw(10)<<"HesoL";
        cout<<setiosflags(ios::left)<<setw(15)<<"Luong";
        cout<<setiosflags(ios::left)<<setw(15)<<"CDP";
        cout<<setiosflags(ios::left)<<setw(15)<<"Con Nhan";
        cout<<endl;
        for (int j = 1; j <= PB[i].SoLuongNV; j++){

            cout<<setiosflags(ios::left)<<setw(10)<<PB[i].NV[j].MaNV;
            cout<<setiosflags(ios::left)<<setw(25)<<PB[i].NV[j].HoTenNV;
            cout<<setiosflags(ios::left)<<setw(10)<<PB[i].NV[j].ChucDanh;
            cout<<setiosflags(ios::left)<<setw(10)<<PCCV(PB[i].NV[j].ChucDanh);
            cout<<setiosflags(ios::left)<<setw(10)<<PB[i].NV[j].hsLuong;
            cout<<setiosflags(ios::left)<<setw(15)<<PB[i].NV[j].hsLuong * PB[i].LuongToiThieu;
            cout<<setiosflags(ios::left)<<setw(15)<<(PB[i].NV[j].hsLuong * PB[i].LuongToiThieu + PCCV(PB[i].NV[j].ChucDanh))/100;
            cout<<setiosflags(ios::left)<<setw(15)<<(PB[i].NV[j].hsLuong * PB[i].LuongToiThieu + PCCV(PB[i].NV[j].ChucDanh))/100*99;
            cout<<endl;

        }
    }

}

void init(){

    printf("**   CHUONG TRINH QUAN LY Chi bo - Dang vien **\n");
    printf("**1. Nhap cac Chi bo                         **\n");
    printf("**2. In ket qua ds Chi bo Dang vien          **\n");
    printf("**3. Thoat                                   **\n");
    printf("***********************************************\n");
    printf("**       Nhap lua chon cua ban               **\n");
}


int main(){
    init();
    int type;
    cin>>type;
    while (type != 3){
        if (type == 1){
            cout<<"Nhap so phong ban: ";
            cin>>n;
            insert_info();
        }
        if (type == 2){
            printList();
        }
        init();
    }
}
