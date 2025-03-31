#include "SoPhuc.h"
void SoPhuc::Nhap()//hàm để nhập vào số phức dạng a+bi
{
    cout<<"Nhap vao phan thuc(a) va phan ao(b) cua so phuc a+bi.\n";
    cin>>Thuc>>Ao;
}
void SoPhuc::Xuat()//hàm để xuất số phức
{
    cout<<Thuc<<((Ao>0)?"+":"")<<Ao<<"i";
}
istream& operator>>(istream&is,SoPhuc&a)//nạp chồng toán tử để nhập số phức thay vì gọi hàm nhập
{
    cout<<"Nhap vao phan thuc(a) va phan ao(b) cua so phuc a+bi.\n";
    is>>a.Thuc>>a.Ao;
    return is;
}
ostream& operator<<(ostream&os, SoPhuc&a)//nạp chồng toán tử để xuất số phức
{
    os<<a.Thuc;
    if(a.Ao>0) cout<<"+";
    else if(a.Ao==0) return os;
    os<<a.Ao<<"i";
    return os;
}
SoPhuc SoPhuc::Tong(const SoPhuc&a)//tính tổng 2 số phức
{
    SoPhuc b;
    b.Thuc=this->Thuc+a.Thuc;
    b.Ao=this->Ao+a.Ao;
    return b;
}
SoPhuc SoPhuc::Hieu(const SoPhuc&a)//tính hiệu 2 số phức
{
    SoPhuc b;
    b.Thuc=this->Thuc-a.Thuc;
    b.Ao=this->Ao-a.Ao;
    return b;
}
SoPhuc SoPhuc::Tich(const SoPhuc&a)//tính tích 2 số phức
{
    SoPhuc b;
    b.Thuc=this->Thuc*a.Thuc-this->Ao*a.Ao;
    b.Ao=this->Thuc*a.Ao+this->Ao*a.Thuc;
    return b;
}
SoPhuc SoPhuc::Thuong(const SoPhuc&a)//tính thương 2 số phức
{
    SoPhuc b;
    b.Thuc=(this->Thuc*a.Thuc+this->Ao*a.Ao)/(a.Thuc*a.Thuc+a.Ao*a.Ao);
    b.Ao=(a.Thuc*this->Ao-this->Thuc*a.Ao)/(a.Thuc*a.Thuc+a.Ao*a.Ao);
    return b;
}