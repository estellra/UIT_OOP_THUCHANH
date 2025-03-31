#pragma once
#include <iostream>
using namespace std;
#ifndef TIME_H
#define TIME_H
class Time
{
    private:
    int Giay,Phut,Gio;
    public:
    void Nhap();
    void Xuat();
    friend istream& operator>>(istream&,Time&);
    friend ostream& operator<<(ostream&,Time&);
    void TinhCongThemMotGiay();
};
#endif          