#include "PhanSo.h"
using namespace std;


void PhanSo::Nhap()//hàm để user nhập vào phân số 
{
    cout<<"Nhap vao tu so va mau so phan so(mau so khac 0): \n";
    cin>>Tu>>Mau;
    while(Mau==0)
        {
            cout<<"Mau so khong hop le vui long nhap lai: \n";
            cin>>Mau;
        }
}

int ucln(int a, int b)//tìm ước chung lớn nhất để có thể rút gọn phân số
{
    if(a>=b&&a%b==0) return b;
    else if(a<b&&b%a==0) return a;
    if(a>b) return ucln(a%b,b);
    else return ucln(a,b%a);
     
}
PhanSo& PhanSo::RutGon()
{
    if(Tu!=0&&Mau!=0)
    {
    int t=ucln(abs(this->Tu),abs(this->Mau));
    Tu/=t;
    Mau/=t;
    }
    return *this;
    
}
PhanSo PhanSo::Tong(const PhanSo&a)//tính tổng 2 phân số bằng cách quy đồng
{
    PhanSo t;
    
    t.Tu=this->Tu*a.Mau+this->Mau*a.Tu;
    t.Mau=this->Mau*a.Mau;
    return t;
}
PhanSo PhanSo::Hieu(const PhanSo&a)//tính hiệu 2 phân số bằng cách quy đồng
{
    PhanSo t;
    t.Tu=this->Tu*a.Mau-this->Mau*a.Tu;
    t.Mau=this->Mau*a.Mau;
    return t;
}
PhanSo PhanSo::Tich(const PhanSo&a)//tính tích 2 phân số
{
    PhanSo t;
    t.Tu=this->Tu*a.Tu;
    t.Mau=this->Mau*a.Mau;
    return t;
}
PhanSo PhanSo::Thuong(const PhanSo&a)//tính thương 2 phân số
{
    PhanSo t;
    t.Tu=this->Tu*a.Mau;
    t.Mau=this->Mau*a.Tu;
    return t;
}
double PhanSo::SoSanh(const PhanSo&a)//so sánh 2 phân số thông qua quy đồng và tìm tử số lớn hơn
{
    double t=((double)this->Tu/this->Mau)-((double)a.Tu/a.Mau);
    if(t>0) return 1;
    else if(t==0) return 0;
    return -1;
}
void PhanSo::Xuat(const PhanSo&a)//xuất phân số
{
    cout<<a.Tu<<"/"<<a.Mau<<"\n";
}
istream& operator>>(istream& is, PhanSo& a) //nạp chồng toán tử để nhập phân số thay vì gọi hàm mỗi lần
{
    cout << "Nhap vao tu so va mau so phan so (mau so khac 0): \n";
    is >> a.Tu >> a.Mau;
    while (a.Mau == 0) {
        cout << "Mau so khong hop le, vui long nhap lai: \n";
        is >> a.Mau;
    }
    return is;
}
ostream& operator<<(ostream& os,PhanSo&a)//nhập chồng toán tử để xuất phân số
{
    a.RutGon();
    if(a.Mau<-1)
        {
            os<<a.Tu*-1<<"/"<<a.Mau*-1;
        }
    else if(a.Mau==-1)
        {
            os<<a.Tu*-1;
        }
    else if(a.Mau==0)
        {
            os<<"Phan so khong xac dinh(mau so =0)!";
        }
    else if(a.Mau!=0&&a.Tu==0)
        {
            os<<0;
        }
    else if(a.Mau==1)
        {
            os<<a.Tu;
        }
     else if(a.Mau>1)
        {
            os<<a.Tu<<"/"<<a.Mau;
        }
    return os;
}