#include "PhanSo.cpp"
int main()
{
    PhanSo a,b;
    cin>>a>>b;
    PhanSo x,y,z,q;
    x=a.Tong(b);
    y=a.Hieu(b);
    z=a.Tich(b);
    q=a.Thuong(b);
    cout<<a<<((b.getTu()>=0)?"+":"")<<b<<"="<<x<<"\n";
    cout<<a<<((b.getTu()<0)?"":"-")<<b<<"="<<y<<"\n";
    cout<<a<<"*"<<b<<"="<<z<<"\n";
    cout<<a<<"/"<<b<<"="<<q<<"\n";
    if(a.SoSanh(b)>0) cout<<"Phan so "<<a<<" lon hon phan so "<<b<<"\n";
    else if(a.SoSanh(b)==0) cout<<"Hai phan so bang nhau va bang "<<b<<"\n";
    else cout<<"Phan so "<<a<<" nho hon phan so "<<b<<"\n";
}