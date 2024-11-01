#include <bits/stdc++.h>
using namespace std;
void nhap(int &n, double toan[], double van[], double anh[], double tb[])
{
    cout<<"Nhap so luong hoc sinh: ";
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cout<<"Nhap diem toan, van, ngoai ngu cua hoc sinh "<<i<<" : ";
        cin>>toan[i]>>van[i]>>anh[i];
    }
}
void tinh_diem_tb(int &n, double toan[], double van[], double anh[], double tb[])
{
    for (int i=1; i<=n; i++)
    {
        tb[i]=(toan[i]+van[i]+anh[i])/3;
    }
}
void hien_thi_diem(int &n, double toan[], double van[], double anh[], double tb[])
{
    for (int i=1; i<=n; i++)
    {
        cout<<"Hoc sinh "<<i<<" co diem toan van anh va tb la: "<<toan[i]<<" "<<van[i]<<" "<<anh[i]<<" "<<tb[i];
        cout<<endl;
    }
}
void hien_thi_maxx(int &n, double toan[], double van[], double anh[], double tb[])
{
    double maxx=0;
    for (int i=1; i<=n; i++)
    {
        if ( tb[i] > maxx ) maxx= tb[i];
    }
    cout<<"Nhung hoc sinh co diem tb cao nhat la: "<<endl;
    for (int i=1; i<=n; i++)
        if ( tb[i]== maxx ) cout<<"Hoc sinh "<<i<<endl;
}
void hien_thi_tb(int &n, double toan[], double van[], double anh[], double tb[])
{
    int sum_toan=0, sum_van=0, sum_anh=0, sum_tb=0;
    for (int i=1; i<=n; i++)
    {
        sum_toan+=toan[i];
        sum_van+=van[i];
        sum_anh+=anh[i];
        sum_tb+= tb[i] ;
    }
    cout<<"Diem trung binh toan: "<<sum_toan/n<<endl;
    cout<<"Diem trung binh van : "<<sum_van/n<<endl;
    cout<<"Diem trung binh anh : "<<sum_anh/n<<endl;
    cout<<"Diem trung binh tat ca: "<<sum_tb/n<<endl;
}
void hien_thi_thutu(int &n, double toan[], double van[], double anh[], double tb[])
{
    int nho[1000];
    double tb1[1000];
    for (int i=1; i<=n; i++) tb1[i]=tb[i],nho[i]=i;
    for (int i=1; i<n; i++)
        for (int j=i; j<=n; j++)
    {
        if (tb1[i] < tb1[j])
        {
            swap(tb1[i],tb1[j]);
            swap(nho[i],nho[j]);
        }
    }
    for (int i=1; i<=n; i++)
        cout<<"Hoc sinh "<<nho[i]<<" co diem tb "<<tb1[i]<<endl;
}
int main()
{
    int n;
    double toan[1000], van[1000], anh[1000], tb[1000];
    nhap(n, toan, van, anh, tb);
    tinh_diem_tb(n, toan, van, anh, tb);
    int lua_chon;
    cout<<"Nhan 1 de hien thi diem trung binh."<<endl;
    cout<<"Nhan 2 de hien thi hoc sinh co diem trung binh cao nhat."<<endl;
    cout<<"Nhan 3 de hien thi trung binh tat ca cac mon."<<endl;
    cout<<"Nhan 4 de hien thi bang diem trung binh giam dan."<<endl;
    cout<<"Nhan 0 de dong ung dung."<<endl;
    cout<<"Nhap lua chon: ";
    cin>>lua_chon;
    while (lua_chon != 0)
    {
        if (lua_chon==1) hien_thi_diem(n, toan, van, anh, tb);
        if (lua_chon==2) hien_thi_maxx(n, toan, van, anh, tb);
        if (lua_chon==3) hien_thi_tb(n, toan, van, anh, tb);
        if (lua_chon==4) hien_thi_thutu(n, toan, van, anh, tb);
        cout<<"Nhap lua chon: ";
        cin>>lua_chon;
    }
}
