#include "SoPhuc.cpp"
int main()
{
    SoPhuc a,b,x,y,z,q;
    cin>>a>>b;
    x=a.Tong(b);
    y=a.Hieu(b);
    z=a.Tich(b);
    q=a.Thuong(b);
    cout<<"Tong cua 2 so phuc "<<a<<" va "<<b<<" la: "<<x<<"\n";
    cout<<"Hieu cua 2 so phuc "<<a<<" va "<<b<<" la: "<<y<<"\n";
    cout<<"Tich cua 2 so phuc "<<a<<" va "<<b<<" la: "<<z<<"\n";
    cout<<"Thuong cua 2 so phuc "<<a<<" va "<<b<<" la: "<<q<<"\n";

}