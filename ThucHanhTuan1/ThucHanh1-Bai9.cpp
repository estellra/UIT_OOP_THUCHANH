#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cctype>  
using namespace std;
class SoTietKiem //class sổ tiết kiệm chứa các thông tin của sổ tiết kiệm và các getter để các hàm ngoài class có thể tiếp cận
{
private:
    string maso;
    string loaitietkiem;
    string hoten;
    string cmnd;
    int ngay, thang, nam;
    double sotiengui;
    double laisuat;
public:
    SoTietKiem() {};
    bool kiemtrangay(int ng, int t, int n) //kiểm tra ngày có hợp lệ không
    {
        if (n<0||n>2025) return 0;
        int Thang[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if ((n%4==0&&n%100!=0)||n%400== 0) Thang[1] = 29; 
        return (t>=1&&t<=12&&ng>=1&&ng<=Thang[t-1]);
    }

    bool kiemtracmnd(const string &cmnd) //kiểm tra xem cmnd có phải toàn là số không
    {
        if(cmnd.length()==9||cmnd.length()==12)
            {
               for(char b:cmnd)
               {
                    if(!(isdigit(b)||b==' ')) return 0;
               }
            }
        else return 0;
        return 1;
    }
    bool kthoten(const string&a) //kiểm tra họ tên có phải toàn là chữ không
    {
        if (a.length()>30) return 0;
        for (char b:a) {
            if (!(isalpha(b))) return 0;  
        }
        return 1;
    }

    void input() //nhập vào các thông tin của sổ tiết kiệm
    {
        do 
        {
            cout << "Nhap ma so: ";
            cin >> maso;
            if(maso.length()>5||maso.find(' ') != string::npos) cout<<"Ma so khong hop le, vui long nhap lai.\n";
        } while (maso.length()>5||maso.find(' ') != string::npos);
        cin.ignore();
        string loai[]={"nganhan","daihan","khongkyhan"};
        do 
        {
            cout << "Nhap loai tiet kiem(nganhan,daihan,khongkyhan): ";
            getline(cin,loaitietkiem);
            if(loaitietkiem.length()>10||(loaitietkiem!=loai[1]&&loaitietkiem!=loai[0]&&loaitietkiem!=loai[2])) cout<<"Loai tiet kiem khong hop le, vui long nhap lai.\n";
        } while(loaitietkiem.length()>10||(loaitietkiem!=loai[1]&&loaitietkiem!=loai[0]&&loaitietkiem!=loai[2]));
        do 
        {
            cout << "Nhap ho ten khach hang: ";
            getline(cin,hoten);
            if(!kthoten(hoten)) cout<<"Ho ten khong hop le vui long nhap lai.\n";
        }while(!kthoten(hoten));

        do 
        {
            cout<<"Nhap CMND (9 hoac 12 so): ";
            cin>>cmnd;
            if(!kiemtracmnd(cmnd)) cout<<"CMND khong hop le vui long nhap lai.\n";
        } while (!kiemtracmnd(cmnd));

        do 
        {
            cout<<"Nhap ngay mo so(ngay/thang/nam): ";
            cin>>ngay>>thang>>nam;
            if(!kiemtrangay(ngay,thang,nam)) cout<<"Ngay khong hop le vui long nhap lai.\n";
        }while(!kiemtrangay(ngay,thang,nam));

        do 
        {
            cout<<"Nhap so tien gui (so duong): ";
            cin>>sotiengui;
            if(sotiengui<=0) cout<<"So tien gui khong hop le, vui long nhap lai.\n";
        }while(sotiengui<=0);
        do
        {
            cout << "Nhap lai suat (%/nam): ";
            cin >> laisuat;
            if(laisuat<=0) cout<<"Lai suat khong hop le, vui long nhap lai(>0%):\n";
        }while(laisuat<=0);
    }

    void hienThiThongTin() const // làm đẹp output hiển thị các đề mục
    {
        cout<<left<<setw(8)<<maso
             << setw(12) << loaitietkiem
             << setw(15) << hoten
             << setw(12) << cmnd
             << setw(10) << (to_string(ngay) + "/" + to_string(thang) + "/" + to_string(nam))
             << setw(12) << sotiengui
            << laisuat << "%\n";
    }

    string getCMND() const { return cmnd; }// các gettter
    string getMaSo() const { return maso; }
    string getHoTen() const {return hoten;}
    int getNgay() const { return ngay; }
    int getThang() const { return thang; }
    int getNam() const { return nam; }
    double getSoTienGui() const { return sotiengui; }
    string getLoaiTietKiem() const { return loaitietkiem; }
    double getLaiSuat() const {return laisuat;}
    double tinhlai() const 
    {
        time_t t = time(0);
        tm *now = localtime(&t);
        int namHienTai = now->tm_year + 1900;
        int thangHienTai = now->tm_mon + 1;
        int ngayHienTai = now->tm_mday;
        int sothanggui = (namHienTai - nam) * 12 + (thangHienTai - thang);
        if(loaitietkiem=="nganhan")
            {
                if(sothanggui>6) sothanggui=6;
            }
        else if(loaitietkiem=="daihan")
            {
                if(sothanggui<6) sothanggui=0;
            }
        return sotiengui * (laisuat / 100.0) * (sothanggui / 12.0);
    }
    
    void ruttien(double sotien) //hàm rút tiền nhờ vào việc kiểm tra số dư tài khoản với số tiền định rút
    {
        time_t t = time(0);
        tm *now = localtime(&t);
        int namHienTai = now->tm_year + 1900;
        int thangHienTai = now->tm_mon + 1;
        int ngayHienTai = now->tm_mday;
        int sothanggui = (namHienTai - nam) * 12 + (thangHienTai - thang);
        if (sotien > sotiengui) 
        {
            cout << "Khong the rut qua so du hien co!\n";
        } 
        else 
        {
            sotiengui -= sotien;
                if(loaitietkiem=="nganhan")
                {
                    if(sothanggui!=6) 
                    {
                        cout<<"Do ban da rut tien truoc ky han nen lai suat se bi giam di mot phan tu.\n";
                        laisuat/=4;
                        cout<<"Lai suat bay gio: "<<laisuat<<"\n";
                    }
                }
                else if(loaitietkiem=="daihan")
                {
                    if(sothanggui<6)
                    {
                        cout<<"Do ban da rut tien truoc ky han nen lai suat se bi giam di mot phan tu.\n";
                        laisuat/=4;
                        cout<<"Lai suat bay gio: "<<laisuat<<"\n";
                    }
                    }
                }
            cout << "Ban da rut " << sotien <<".\n"<<"So du con lai: " << sotiengui <<"\n";
    }
    
};

class DanhSachSoTietKiem //class danh sách sổ tiết kiệm và các hàm tính
{
private:
    vector<SoTietKiem> DanhSach;
public:
    void input()//hàm để nhập vào các sổ tiết kiệm
     {
        int n;
        cout << "Nhap so luong so tiet kiem: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            SoTietKiem stk;
            cout << "Nhap thong tin so tiet kiem thu " << i + 1 << ":\n";
            stk.input();
            DanhSach.push_back(stk);
        }
    }

    void OutputDanhSach() //output ra danh sách các sổ
    const {
        cout << left << setw(8) << "Ma So"
             << setw(12) << "Loai TK"
             << setw(15) << "Ho Ten"
             << setw(12) << "CMND"
             << setw(10) << "Ngay Mo"
             << setw(12) << "So Tien"
             << setw(12) << "Lai Suat" << "\n";
        for (const auto &stk : DanhSach) {
            stk.hienThiThongTin();
        }
    }
    void OutputDanhSachLaiSuat() //làm đẹp output
    const {
        cout << left << setw(8) << "Ma So"
             << setw(12) << "Loai TK"
             << setw(15) << "Ho Ten"
             << setw(12) << "CMND"
             << setw(10) << "Ngay Mo"
             << setw(12) << "So Tien"
             << setw(12) << "Lai Suat"
             << setw(12) << "Tien Lai" << "\n";
        for (const auto &stk : DanhSach) {
            cout << left << setw(8) << stk.getMaSo()
                 << setw(12) << stk.getLoaiTietKiem()
                 << setw(15) << stk.getHoTen()
                 << setw(12) << stk.getCMND()
                 << setw(10) << (to_string(stk.getNgay()) + "/" + to_string(stk.getThang()) + "/" + to_string(stk.getNam()))
                 << setw(12) << stk.getSoTienGui()
                 << stk.getLaiSuat()<<setw(12) << "%"
                 << setw(12) << fixed << setprecision(2) << stk.tinhlai() << "\n";
        }
    }
    
//tìm kiếm sổ tiết kiệm theo cmnd thông qua việc so sánh 2 chuỗi ký tự
    void TimKiemTheoCMND(const string &cmnd) const {
        bool found = false;
        for (const auto &stk : DanhSach) {
            if (stk.getCMND() == cmnd) {
                stk.hienThiThongTin();
                found = true;
            }
        }
        if (!found) cout << "Khong tim thay so tiet kiem voi CMND: " << cmnd <<"\n";
    }
//tìm kiếm sổ tiết kiệm ttheo mã sỗ thông qua so sánh 2 chuỗi ký tự
    void TimKiemTheoMaSo(const string &maso) const {
        bool found = false;
        for (const auto &stk : DanhSach) {
            if (stk.getMaSo() == maso) {
                stk.hienThiThongTin();
                found = true;
            }
        }
        if (!found) cout << "Khong tim thay so tiet kiem voi ma so: " << maso << "\n";
    }
//rút tiền từ sổ tiết kiệm ứng với mã số tài khoản
    void RutTienTheoMaSo() {
        string ms;
        double sotien;
        cout << "Nhap ma so tiet kiem can rut tien: ";
        cin >> ms;
            for (auto &stk:DanhSach) 
            {
                if (stk.getMaSo() == ms) 
                {
                    cout << "Nhap so tien muon rut: ";
                    cin >> sotien;
                    stk.ruttien(sotien);
                    return;
                }
        }
        cout << "Khong tim thay so tiet kiem voi ma so: " <<ms<<"\n";
    }
    
//sắp xếp các sổ theo số dư
    void SapXepTheoSoTien() {
        sort(DanhSach.begin(), DanhSach.end(), [](const SoTietKiem &a, const SoTietKiem &b) {
            return a.getSoTienGui() > b.getSoTienGui();
        });
    }
//sắp xếp các sổ theo ngày mở sổ
    void SapXepTheoNgayMo() {
        sort(DanhSach.begin(), DanhSach.end(), [](const SoTietKiem &a, const SoTietKiem &b) {
            if (a.getNam() != b.getNam()) return a.getNam() < b.getNam();
            if (a.getThang() != b.getThang()) return a.getThang() < b.getThang();
            return a.getNgay() < b.getNgay();
        });
    }
    //tìm kiếm các sổ mở sau một ngày nào đó thông qua so sánh ngày
    void CacSoMoSauNgay() {
        int ng,t,n;
        cout << "Nhap ngay(ngay/thang/nam): \n";
        cin>>ng>>t>>n;
        cout << "Danh sach so tiet kiem mo tu sau ngay " << ng<< "/" << t << "/" << n << ":\n";
        bool b = 0;
        for (const auto &stk : DanhSach) {
            if (stk.getNam() > n ||
                (stk.getNam() == n && stk.getThang() > t) ||
                (stk.getNam() == n && stk.getThang() == t && stk.getNgay() > ng)) {
                stk.hienThiThongTin();
                b = 1;
            }
        }
        
        if (!b) {
            cout << "Khong co so tiet kiem nao duoc mo sau ngay " << ng << "/" << t << "/" << n << ".\n";
        }
    }
    
};

int main() {
    DanhSachSoTietKiem ds;
    ds.input();
    int choice;
    cout<<"Chon 1 tinh toan so tien lai tinh den thoi diem hien tai.\n";
    cout<<"Chon 2 de rut tien.\n";
    cout<<"Chon 3 de tim kiem so tiet kiem bang cmnd hoac ma so.\n";
    cout<<"Chon 4 de tim kiem tat ca cac so tiet kiem duoc duoc mo ke tu mot thoi gian nhat dinh.\n";
    cout<<"Chon 5 de sap xep danh sach so tiet kiem theo thu tu tien gui giam dan.\n";
    cout<<"Chon 6 de sap xep danh sach so tiet kiem theo thu tu ngay mo so tang dan.\n";
    cin>>choice;
    switch(choice)//lựa chọn chức năng
    {
        case 1:
        {
            ds.OutputDanhSachLaiSuat();//xuất ra danh sách các sổ tiết kiệm cùng với số tiền lãi
            break;
        }
        case 2:
        {
            ds.RutTienTheoMaSo();//rút tiền theo mã sổ nhập vào
            break;
        }
        case 3:
        {
            int timkiem;
            cout<<"Nhan 1 de tim kiem theo ma so, 2 de tim kiem theo cmnd.\n";
            cin>>timkiem;
            switch(timkiem)
                {
                    case 1:
                    {
                        cout<<"Nhap vao ma so ma ban muon tim.\n";
                        string ms;
                        cin.ignore();
                        getline(cin,ms);
                        ds.TimKiemTheoMaSo(ms); //tìm kiếm sổ tiết kiệm theo mã sổ
                        break;
                    }
                    case 2:
                    {
                        cout<<"Nhap vao cmnd ma ban muon tim.\n";
                        string cmnd;
                        cin.ignore();
                        getline(cin,cmnd);
                        ds.TimKiemTheoCMND(cmnd);//tìm kiếm sổ tiết kiệm theo cmnd
                    }
                }
                break;
        }
        case 4:
        {
            ds.CacSoMoSauNgay();//tìm kiếm danh sách các sổ mở sau một ngày nào đó
            break;
        }
        case 5:
        {
            ds.SapXepTheoSoTien();//sắp xếp các sổ theo số dư tài khoản
            ds.OutputDanhSach();
            break;
        }
        case 6:
        {
            ds.SapXepTheoNgayMo();//sắp xếp các sổ theo ngày mở sổ
            ds.OutputDanhSach();
        }
    }
    return 0;
}
