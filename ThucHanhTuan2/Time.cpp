#include "Time.h"
void Time::Nhap()//hàm nhập vào thời gian và kiểm tra tính hợp lệ. Giờ(0-23), Phút,Giây(0-59)
{
    cout<<"Xin nhap vao thoi gian hien tai(Gio/Phut/Giay): ";
    cin>>Gio;
    while(Gio<0||Gio>23)
    {
        cout<<"Gio khong hop le vui long nhap lai.\n";
        cin>>Gio;
    }
cin>>Phut;
    while(Phut<0||Phut>59)
    {
        cout<<"Phut khong hop le vui long nhap lai.\n";
        cin>>Phut;
    }
cin>>Giay;
    while(Giay<0||Giay>59)
    {
        cout<<"Giay khong hop le vui long nhap lai.\n";
        cin>>Giay;
    }

}
istream& operator>>(istream&is,Time&a)//nạp chồng toán tử của hàm nhập.
{
    cout<<"Xin nhap vao thoi gian hien tai(Gio/Phut/Giay): ";
is>>a.Gio;
    while(a.Gio<0||a.Gio>23)
    {
        cout<<"Gio khong hop le vui long nhap lai.\n";
        is>>a.Gio;
    }
is>>a.Phut;
    while(a.Phut<0||a.Phut>59)
    {
        cout<<"Phut khong hop le vui long nhap lai.\n";
        is>>a.Phut;
    }
is>>a.Giay;
    while(a.Giay<0||a.Giay>59)
    {
        cout<<"Giay khong hop le vui long nhap lai.\n";
        is>>a.Giay;
    }
    return is;
}
void Time::TinhCongThemMotGiay()
{
    if(Giay==59)
    {
        Giay=0;
        if(Phut==59)
            {
                Phut=0;
                    if(Gio==23) Gio=0;
                    else Gio++;
            }
        else Phut++;

    }
    else Giay++;
}
void Time::Xuat()
{
    cout<<"Thoi gian hien tai la "<<((Gio<10)?"0":"")<<Gio<<":"<<((Phut<10)?"0":"")<<Phut<<":"<<((Giay<10)?"0":"")<<Giay<<"\n";
}
ostream& operator<<(ostream&os, Time&a)
{
    os<<"Thoi gian hien tai la "<<((a.Gio<10)?"0":"")<<a.Gio<<":"<<((a.Phut<10)?"0":"")<<a.Phut<<":"<<((a.Giay<10)?"0":"")<<a.Giay<<"\n";
    return os;
}