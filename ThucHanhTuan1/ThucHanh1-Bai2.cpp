#include <iostream>
using namespace std;

class PhanSo//khai bao class phan so va cac ham ben trong
{
    private:
    int Tu,Mau;
    public:
    int ucln(int ,int );
    PhanSo& rutgon();
    friend istream& operator>>(istream&, PhanSo&);
    friend ostream& operator<<(ostream&,  PhanSo& );
    double SoSanh(const PhanSo&);
};


istream& operator>>(istream &is, PhanSo &ps)//nap chong toan tu de nhap vao phan so
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


ostream& operator<<(ostream &os,  PhanSo &ps)//nap chong toan tu de xuat phan so
    {
        ps.rutgon();
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


int PhanSo::ucln(int a, int b)//tim uoc chung lon nhat de rut gon phan so
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


PhanSo& PhanSo::rutgon()//rut gon phan so nho vao ucln
{
    int t=ucln(abs(this->Tu),abs(this->Mau));
    if(t!=0)
        {
            this->Tu/=t;
            this->Mau/=t;
        }
    return *this;
}
double PhanSo::SoSanh(const PhanSo&a)//so sanh 2 phan so qua viec quy dong mau
{
    return this->Tu*a.Mau-this->Mau*a.Tu;
}

int main()
{
    PhanSo a,b;
   cout<<"Nhap vao phan so thu nhat: \n";
   cin>>a;
   cout<<"Nhap vao phan so thu hai: \n";
   cin>>b;
   if(a.SoSanh(b)>0)
   {
        cout<<"Phan so thu nhat lon hon phan so so thu hai => Phan so lon hon = "<<a;
   }
   else if(a.SoSanh(b)==0)
   {
        cout<<"Hai phan so bang nhau va = "<<a;
   }
   else
   {
        cout<<"Phan so thu hai lon hon phan so thu nhat => Phan so lon hon = "<<b;
   }
}
