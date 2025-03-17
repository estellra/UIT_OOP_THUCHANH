#include <iostream>
using namespace std;
class tinhtoan
{
    private:
    double x;
    int n;
    public:
    friend double GiaiThua(const int&);
    friend double SoMu(const double&, const int& );
    double TinhSin();
    friend istream& operator>>(istream&, tinhtoan&);
    friend ostream& operator<<(ostream&, tinhtoan&);

};
istream& operator>>(istream &is, tinhtoan &a)
{
    cout<<"Nhap vao gia tri X can tinh cua sin(X): \n";
    is>>a.x;
    cout<<"Nhap vao muc do chinh xac n cua gia tri sin(X): (n>=0)\n";
    is>>a.n;
    return is;
}
ostream& operator<<(ostream&os,  tinhtoan&a)
{
   os<<a.x;
    return os;
}

double GiaiThua(const int&n)
{
    double t=1;
    for(int i=1;i<=n; i++)
        {
            t*=i;
        }
    return t;
}
double SoMu(const double& x, const int& n) {
    double t = 1;
    for (int i = 0  ; i < n; i++) {
        t *= x;
    }
    return t;
}
double tinhtoan::TinhSin()
{
    double sin=0; 
    for(int i=0;i<=(this->n);i++)
    {
        if(i%2==0)
            {
                sin+=SoMu(this->x,2*i+1)/GiaiThua(2*i+1);
            }
        else
            {
                sin-=SoMu(this->x,2*i+1)/GiaiThua(2*i+1);
            }
    }
return sin;
}
int main()
{
    tinhtoan a;
    cin>>a;
    double sin=a.TinhSin();
    cout<<"gia tri cua sin("<<a<<") la "<<sin;    
}