#include <iostream>
using namespace std;

class PhanSo//class phân số
{
    private:
    int Tu,Mau;
    public:
    int ucln(int ,int );
    PhanSo& rutgon();
    friend istream& operator>>(istream&, PhanSo&);
    friend ostream& operator<<(ostream&,  PhanSo& );
};


istream& operator>>(istream &is, PhanSo &ps)//nạp chồng toán tử để input ngày phân số
    {
        cout<<"Nhap vao tu so: ";
        is>>ps.Tu;
        cout<<"Nhap vao mau so(khac 0): ";
        do
        {
        is>>ps.Mau;
        if(ps.Mau==0) cout<<"Mau so khong hop le vui long nhap lai: ";
        }while(ps.Mau==0);
        return is;
    }


ostream& operator<<(ostream &os,  PhanSo &ps)//nạp chồng toán tử để xuất thẳng kết quả
    {
        ps.rutgon();//rút gọn trước khi output
        if(ps.Mau<-1)
        {
            os<<ps.Tu*-1<<"/"<<ps.Mau*-1;
        }
        else if(ps.Mau==-1)
        {
            os<<ps.Tu*-1;
        }
        else if(ps.Mau==0)
        {
            os<<"Phan so khong xac dinh(mau so =0)!";
        }
        else if(ps.Mau!=0&&ps.Tu==0)
        {
            os<<0;
        }
        else if(ps.Mau==1)
        {
            os<<ps.Tu;
        }
        else if(ps.Mau>1)
        {
            os<<ps.Tu<<"/"<<ps.Mau;
        }
    return os;
    }


int PhanSo::ucln(int a, int b)//tìm ước chung lớn nhất để rút gọn
{
    if(a==0||b==0) return 0;
    if(a>b) 
    {
        if(a%b==0) return b;
        return ucln(a%b,b);
    }
    else if(a<=b) 
    {
        if(b%a==0) return a;
        return ucln(a,b%a);
    }
    return 0;
}


PhanSo& PhanSo::rutgon()//rút gọn ps
{
    int t=ucln(abs(this->Tu),abs(this->Mau));
    if(t!=0)
        {
            this->Tu/=t;
            this->Mau/=t;
        }
    return *this;
}


int main()
{
    PhanSo a;
    cin>>a;
    cout<<a;
}
