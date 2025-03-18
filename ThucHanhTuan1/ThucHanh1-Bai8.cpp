#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>  
#include <cctype>  

using namespace std;

bool ktmachuyenbay(const string& a) {//kiem tra xem ma chuyen bay co chua ky tuc dac biet khong
    if (a.length()>5) return 0;
    for (char b:a) 
    {
        if (!isalnum(b)) return 0;  
    }
    return 1;
}

bool ktngay(int ng, int t, int n) {//kiem tra xem ngay co hop le khong
    if (n<0||n>2025) return 0;
    int Thang[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if ((n%4==0&&n%100!=0)||n%400== 0) Thang[1] = 29; 
    return (t>=1&&t<=12&&ng>=1&&ng<=Thang[t-1]);
}

bool ktthoigian(int h,int m) {//kiem tra thoi gian co hop le khong
    return (h>=0&&h<24&&m>= 0&&m<60);
}

bool ktdiadiem(const string&a) {//kiem tra xem dia diem co chua ky tu dac biet khong
    if (a.length() > 20) return 0;
    for (char b:a) {
        if (!(isalpha(b)||b==' ')) return 0;  
    }
    return 1;
}

class ChuyenBay {//tao class chuyen bay chua cac thong tin cua chuyen bay cung voi cac getter va setter
private:
    string maChuyenBay;
    int ngay, thang, nam;
    int gio, phut;
    string noidi, noiden;

    public:
        string getMaChuyenBay() const { return maChuyenBay; }
        int getNgay() const { return ngay; }
        int getThang() const { return thang; }
        int getNam() const { return nam; }
        int getGio() const { return gio; }
        int getPhut() const { return phut; }
        string getNoiDi() const { return noidi; }
        string getNoiDen() const { return noiden; }
        void setMaChuyenBay(const string &ma) { maChuyenBay = ma; }
        void setNgay(int d) { ngay = d; }
        void setThang(int m) { thang = m; }
        void setNam(int y) { nam = y; }
        void setGio(int h) { gio = h; }
        void setPhut(int p) { phut = p; }
        void setNoiDi(const string &di) { noidi = di; }
        void setNoiDen(const string &den) { noiden = den; }
        void output() const {// định dạng để lúc xuất nhìn đẹp hơn
            cout << left << setw(8) << maChuyenBay
                << setw(12) << (to_string(ngay) + "/" + to_string(thang) + "/" + to_string(nam))
                << setw(8) << (to_string(gio) + ":" + (phut < 10 ? "0" : "") + to_string(phut))
                << setw(10) << noidi
                << setw(10) << noiden << endl;
        }

        bool operator<(const ChuyenBay& cb) const {//nạp chồng toán tử để so sánh thời gian
            if (nam != cb.nam) return nam < cb.nam;
            if (thang != cb.thang) return thang < cb.thang;
            if (ngay != cb.ngay) return ngay < cb.ngay;
            if (gio != cb.gio) return gio < cb.gio;
            return phut < cb.phut;
        }
    };

    class DanhSachChuyenBay {//class danh sách chuyến bay và các hàm tính toán
    private:
        vector<ChuyenBay> DanhSach;
        int n;

    public:
    void input(DanhSachChuyenBay&);//hàm input
    void hienThiDanhSach() const {//hàm output
        cout<<left<<setw(8)<<"Ma chuyen bay"<<setw(8)<<"  Ngay"<<setw(8)<<"Gio"; 
        cout<<setw(8)<<"Noi di"<<setw(8)<<"Noi den"<<"\n";
        for (const auto& cb:DanhSach) {
            cb.output();
        }
    }
    void timkiemtheongaydivanoidi(string,int,int,int);//tìm kiếm theo nơi đi và ngày đi
    void timkiemtheonoidivanoiden(string,string);//tìm kiếm theo nơi đi và nơi đên
    void sapXepChuyenBay() {
        sort(DanhSach.begin(), DanhSach.end());
    }
};
void DanhSachChuyenBay::input(DanhSachChuyenBay &a)//ham nhap vao cac chuyen bay
 {
    cout << "Nhap vao so luong chuyen bay: ";
    cin >> a.n;
    a.DanhSach.resize(a.n); 
    for (int i = 0; i < a.n; i++) {
        cout << "\nNhap vao thong tin chuyen bay thu " << i + 1 << ":\n";
        string ma, di, den;
        int d, m, y, h, p;
        cout << "Ma chuyen bay: ";
        do {
            cin >> ma;
            if (!ktmachuyenbay(ma)) 
                cout << "Ma chuyen bay khong hop le. Vui long nhap lai!\n";
        } while (!ktmachuyenbay(ma));
        a.DanhSach[i].setMaChuyenBay(ma);
        cout << "Ngay khoi hanh (Nhap theo thu tu ngay/thang/nam): ";
        do {
            cin >> d >> m >> y;
            if (!ktngay(d, m, y)) 
                cout << "Ngay khong hop le. Vui long nhap lai!\n";
        } while (!ktngay(d, m, y));
        a.DanhSach[i].setNgay(d);
        a.DanhSach[i].setThang(m);
        a.DanhSach[i].setNam(y);
        cout << "Gio khoi hanh (Nhap theo thu tu gio/phut): ";
        do {
            cin >> h >> p;
            if (!ktthoigian(h, p)) 
                cout << "Thoi gian khong hop le. Vui long nhap lai!\n";
        } while (!ktthoigian(h, p));
        a.DanhSach[i].setGio(h);
        a.DanhSach[i].setPhut(p);
        cin.ignore(); 
        cout << "Noi di: ";
        do {
            getline(cin, di);
            if (!ktdiadiem(di)) 
                cout << "Noi di khong hop le. Vui long nhap lai!\n";
        } while (!ktdiadiem(di));
        a.DanhSach[i].setNoiDi(di);
        cout << "Noi den: ";
        do {
            getline(cin, den);
            if (!ktdiadiem(den)) 
                cout << "Noi den khong hop le. Vui long nhap lai!\n";
        } while (!ktdiadiem(den));
        a.DanhSach[i].setNoiDen(den);
    }
}
void DanhSachChuyenBay::timkiemtheongaydivanoidi(string khoihanh,int ng,int t,int n) //tim kiem chuyen bay theo ngay di va noi di theo nơi đi và ngày đi cho trước
{
   
    cout<<"Danh sach cac chuyen bay khoi hanh tu "<<khoihanh<<" vao ngay "<<ng<<"/"<<t<<"/"<<n<<":\n";

    bool c=0;
    for (const auto &i : this->DanhSach)
     { 
        if (i.getNgay() == ng && i.getThang() == t && i.getNam() == n && i.getNoiDi() == khoihanh) {
            i.output(); 
            c = 1;
    }
    }
    if (!c) {
        cout<<"Khong co chuyen bay nao khoi hanh tu "<<khoihanh<<" vao ngay "<<ng<<"/"<<t<<"/"<<n<<".\n";
    }
}
void DanhSachChuyenBay::timkiemtheonoidivanoiden(string khoihanh,string dichden)//tìm kiếm chuyến bay theo nơi đi và nơi đến đã cho trước
{
    cout<<"Danh sach cac chuyen bay khoi hanh tu "<<khoihanh<<" va den "<<dichden<<":\n";
    bool c=0;
    for (const auto &i : this->DanhSach)
     { 
        if (i.getNoiDen()==dichden&&i.getNoiDi()==khoihanh) {
            i.output(); 
            c = 1;
    }
    }
    if (!c) {
        cout<<"Khong co chuyen bay nao khoi hanh tu "<<khoihanh<<" va den "<<dichden<<":\n";
    }
}

int main() {
    DanhSachChuyenBay ds;
    ds.input(ds);//nhập vào các chuyếnn bay
    ds.sapXepChuyenBay();//sắp xếp
    int choice;//lựa chọn chức năng
    cout<<"Nhan 1 de hien thi danh sach toan bo chuyen bay.\n";
    cout<<"Nhan 2 de tim kiem cac chuyen bay co cung noi khoi hanh trong cung mot ngay.\n";
    cout<<"Nhan 3 de tim kiem cac chuyen bay co cung noi di va noi den\n";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            ds.hienThiDanhSach();//hiển thị toàn bộ chuyến bay
            break;
        }
        case 2:
        {
            cout<<"Xin moi nhap vao noi khoi hanh ban muon tim kiem.\n";
            string khoihanh;
            cin.ignore();
            getline(cin,khoihanh);
            cout<<"Xin nhap vao ngay khoi hanh.\n";
            int ng,t,n;
            cin>>ng>>t>>n;
            ds.timkiemtheongaydivanoidi(khoihanh,ng,t,n);//tìm kiếm theo ngày đi và nơi đi
            break;
        }
        case 3:
        {
            string khoihanh,diemden;
            cout<<"Xin moi nhap vao noi khoi hanh ban muon tim kiem.\n";
            cin.ignore();
            getline(cin,khoihanh);
            cout<<"Xin moi nhap vao diem den ma ban mong muon.\n";
            getline(cin,diemden);
            ds.timkiemtheonoidivanoiden(khoihanh,diemden);//tìm kiếm theo nơi đi và nơi đến
            break;
        }
    }
    
    return 0;
}
