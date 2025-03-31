#pragma once
#include <iostream>
using namespace std;
#ifndef SOPHUC_H
#define SOPHUC_H
class SoPhuc
{
    private:
    double Thuc,Ao;
    public:
    void Nhap();
    void Xuat();
    SoPhuc Tong(const SoPhuc&);
    SoPhuc Hieu(const SoPhuc&);
    SoPhuc Tich(const SoPhuc&);
    SoPhuc Thuong(const SoPhuc&);
    friend istream& operator>>(istream&,SoPhuc&);
    friend ostream& operator<<(ostream&,SoPhuc&);
};
#endif          