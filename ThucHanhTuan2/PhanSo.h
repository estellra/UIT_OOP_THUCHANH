#pragma once
#include <iostream>
using namespace std;
#ifndef PHANSO_H
#define PHANSO_H
class PhanSo
{
    private:
    int Tu,Mau;
    public:
    void Nhap();
    void Xuat(const PhanSo&);
    PhanSo& RutGon();
    PhanSo Tong(const PhanSo&);
    PhanSo Hieu(const PhanSo&);
    PhanSo Tich(const PhanSo&);
    PhanSo Thuong(const PhanSo&);
    double SoSanh(const PhanSo&);
    friend istream& operator>>(istream&,PhanSo&);//nạp chồng toán tử nhập
    friend ostream& operator<<(ostream&,PhanSo&);//nạp chồng toán tử xuất
    int getTu() const {return Tu;}// getter để lấy được giá trị của tử lúc xuất
};
#endif          