using namespace std;
#include "Date.h"
#include <iostream>
void Date::nhap(Date&a)//hàm nhập cho phép user nhập vào ngày tháng năm và kiểm tra tính hợp lệ
{
    cout<<"Vui long nhap vao ngay thang nam(ngay/thang/nam): \n";
    cin>>a.ngay>>a.thang>>a.nam;
    while(a.nam<1)// nếu tháng <0 thì không hợp lệ và nhập lại
        {
            cout<<"Nam khong hop le vui long nhap lai.\n";
            cin>>a.nam;
        }
    while(a.thang<1||a.thang>12)//tháng nằm ngoài khoảng 1-12 thì không hợp lệ và nhập lại
        {
            cout<<"Thang khong hop le vui long nhap lai.\n";
            cin>>a.thang;
        }
    bool namnhuan=a.nam%4==0&&a.nam%100!=0;//kiểm tra xem có phải năm nhuận không
    if(a.thang==1||a.thang==3||a.thang==5||a.thang==7||a.thang==8||a.thang==10||a.thang==12)//nếu là các tháng 1/3/5/7/8/10/12 thì kiểm tra xem ngày có nằm trong khoảng 1-31 không
    {
        if(a.ngay<1||a.ngay>31)
        {
            cout<<"Ngay khong hop le vui long nhap lai.\n";
            cin>>a.ngay;
        }
    }
    else if(a.thang==4||a.thang==6||a.thang==9||a.thang==11)//nếu là các tháng 4/6/9/11 thì kiểm tra ngày có nằm trong khoảng 1-30 không
    {
        if(a.ngay<1||a.ngay>30)
        {
            cout<<"Ngay khong hop le vui long nhap lai.\n";
            cin>>a.ngay;
        }
    }
    else if(a.thang==2)//nếu là tháng 2 thì nếu là năm nhuận thì kiểm tra ngày có nằm trong khoảng 1-29 không, ngược lại thì nằm trong khoảng 1-28
    {
        if(namnhuan)
        {
            if(a.ngay<1||a.ngay>29)
            {
                cout<<"Ngay khong hop le vui long nhap lai.\n";
                cin>>a.ngay;
            }
        }
        else
        {
            if(a.ngay<1||a.ngay>28)
            {
                cout<<"Ngay khong hop le vui long nhap lai.\n";
                cin>>a.ngay;
            }
        }
    }
}
void Date::NgayThangNamTiepTheo(Date&a)//hàm tính ngày tháng năm tiếp theo
{
    bool namnhuan=a.nam%4==0&&a.nam%100!=0;//kiểm tra năm nhuận
    if(a.thang==1||a.thang==3||a.thang==5||a.thang==7||a.thang==8||a.thang==10||a.thang==12)
    {
        if(a.ngay<31)//nếu là các tháng kể trên và ngày <31 thì đơn giản tăng ngày lên 1 đơn vị
        {
            a.ngay++;
        }
        else if(a.ngay==31)//nếu ngày ==31 thì cho ngày  =1 và tăng tháng lên 1 đơn vị
        {
            if(a.thang==12)//nếu là tháng 12 thì năm tăng lên 1 đơn vị, tháng và ngày quay về 1
                {
                    a.nam++;
                    a.ngay=1;
                    a.thang=1;
                }
            else
             {
                a.ngay=1;
                a.thang++;
            }
           
        }
    }
    else if(a.thang==4||a.thang==6||a.thang==9||a.thang==11)//tương tự nhưng với các tháng 4,6,9,11 và ngày tối đa là 30
        {
            if(a.ngay<30) a.ngay++;
            else if(a.ngay==30)
            {
                a.ngay=1;
                a.thang++;
            }
        }
    else if(a.thang==2)//tương tự nhưng với tháng 2 và kiểm tra trước tiên xem năm có nhuận không để xác dịnh ngày tối đa của tháng
        {
            if(namnhuan)
            {
                if(a.ngay<29) a.ngay++;
                else if(a.ngay==29)
                    {
                        a.ngay=1;
                        a.thang++;
                    }
            }
            else
            {
                if(a.ngay<28) a.ngay++;
                else if(a.ngay==28)
                    {
                        a.ngay=1;
                        a.thang++;
                    }
            }
        }

}
void Date::xuat(Date&a)
{
    cout<<"Ngay tiep theo cua ngay "<<a.ngay<<"/"<<a.thang<<"/"<<a.nam;
    a.NgayThangNamTiepTheo(a);
    cout<<" la ngay "<<a.ngay<<"/"<<a.thang<<"/"<<a.nam<<"\n";
}
