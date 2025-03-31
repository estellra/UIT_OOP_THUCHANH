#pragma once
#ifndef DATE_H
class Date //khai báo lớp Date
{
    private://khai báo các thuộc tính là ngày tháng và năm
    int ngay,thang,nam;
    public://khai báo các thuộc tính(function) của lớp là nhập xuất và tìm ngày tháng năm tiếp theo.
    void nhap(Date&);
    void xuat(Date&);
    void NgayThangNamTiepTheo(Date&);
};
#endif          