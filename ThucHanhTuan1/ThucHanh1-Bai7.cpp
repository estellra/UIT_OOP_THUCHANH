#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class HocSinh//khai bao class hoc sinh voi cac getter de cac ham ngoai co the tuong tac duoc
{
    private:
    string Ten;
    double Toan,Van,NgoaiNgu,DTB;
    public:
    friend istream& operator>>(istream&,HocSinh&);
    double getToan() const {return Toan;}
    double getVan() const {return Van;}
    double getNgoaiNgu() const {return NgoaiNgu;}
    double getDTB() const {return DTB;}
    void setDTB(double dtb) {DTB = dtb;} 
    string getTen() const {return Ten;}
    
};
class DanhSachHocSinh//class danh sach hoc sinh và các hàm tính toán
{
    private:
    vector<HocSinh> DanhSach;
    int n;
    public:
    friend istream& operator>>(istream&,DanhSachHocSinh&);
    void TinhDTB( DanhSachHocSinh&);
    void SapXepDTB(DanhSachHocSinh&);
    string chuyendoi(const string&);
    int TimKiemHocSinh(const string&);
    void PhanLoaiHocSinh(const DanhSachHocSinh&);
    void TimDiemToanThapNhat(const DanhSachHocSinh&);
    void TimDTBCaoNhat(const DanhSachHocSinh&);
    vector<HocSinh> getDanhSach() const {return DanhSach;}

};
istream& operator>>(istream&is,HocSinh&a)//nạp chồng toán tử để nhập vào thông tin học sinh
{
    cout<<"Nhap vao ten cua hoc sinh: ";
    nhaplai:
    is.ignore();
    getline(is,a.Ten);
    int i=0;
    while(a.Ten[i]!='\0')
        {
            if(a.Ten[i]>='0'&&a.Ten[i]<='9')
                {
                    cout<<"Ten chua ky tu khong hop le, vui long nhap lai.\n";
                    goto nhaplai;
                }
            if(i>40) 
                {
                    cout<<"Ten chua qua nhieu ky tu, vui long nhap lai.\n";
                    goto nhaplai;
                }
            i++;
        }
    do
    {
        cout<<"Nhap vao diem mon Toan: ";
        is>>a.Toan;
        if(a.Toan<0||a.Toan>10)
        cout<<"Diem Toan khong hop le, vui long nhap lai.\n";
    }while(a.Toan<0||a.Toan>10);
    do
    {
        cout<<"Nhap vao diem mon Van: ";
        is>>a.Van;
        if(a.Van<0||a.Van>10)
        cout<<"Diem Van khong hop le, vui long nhap lai.\n";
    }while(a.Van<0||a.Van>10);
    do
    { 
        cout<<"Nhap vao diem Ngoai Ngu: ";
        is>>a.NgoaiNgu;
        if(a.NgoaiNgu<0||a.NgoaiNgu>10)
        cout<<"Diem Ngoai Ngu khong hop le, vui long nhap lai.\n";
    }while(a.NgoaiNgu<0||a.NgoaiNgu>10);   
    return is;
}
istream& operator>>(istream&is,DanhSachHocSinh&a)
{
    cout<<"Nhap vao so hoc sinh.\n";
    is>>a.n;
    a.DanhSach.resize(a.n);
    for(int i=0; i<a.n;i++)
        {
            cout<<"Xin nhap vao thong tin cua hoc sinh thu "<<i+1<<"\n";
            is>>a.DanhSach[i];
        }
        return is;
}
void DanhSachHocSinh::TinhDTB(DanhSachHocSinh&a)//tính đtb của học sinh
{
    for(int i=0;i<a.n;i++)
        {
            double dtb=((2*a.DanhSach[i].getToan())+a.DanhSach[i].getVan()+a.DanhSach[i].getNgoaiNgu())/4;
            a.DanhSach[i].setDTB(dtb);
        }
}
void DanhSachHocSinh::SapXepDTB(DanhSachHocSinh&a)//sắp xếp danh sách học sinh dựa vào đtb
{
    sort(a.DanhSach.begin(), a.DanhSach.end(), [](const HocSinh &hs1, const HocSinh &hs2)
     {
        return hs1.getDTB() < hs2.getDTB();
     }
);

}

string DanhSachHocSinh::chuyendoi(const string&str)//chuyển đổi chuỗi chữ  về chữ thường hết
{
    string t = str;
    transform(t.begin(), t.end(), t.begin(), ::tolower);
    return t;
}
int DanhSachHocSinh::TimKiemHocSinh(const string &cantim)//tìm kiếm học sinh dựa vào tên có trước đã được chueyẻn về dạng ký tự thường hết
{
    bool ktra = 0;
    string tucantim = chuyendoi(cantim); 

    cout << "Ket qua tim kiem:\n";
    for (int i=0;i<this->n;i++)
    {
        string ten = chuyendoi(this->DanhSach[i].getTen()); 
        if (ten.find(tucantim) != string::npos) 
        {
            return i;
        }
    }

    return -1;
}
void DanhSachHocSinh::TimDiemToanThapNhat(const DanhSachHocSinh&a)//tìm học sinh có điểm toán thấp nhất
{
    int min=a.DanhSach[0].getToan();
    int t;
    for(int i=0; i<a.n;i++)
        {
            if(min>a.DanhSach[i].getToan()) 
            {
                min=a.DanhSach[i].getToan();
                t=i;
            }
        }
    cout<<"Hoc sinh voi so diem mon toan thap nhat la:  "<<a.DanhSach[t].getTen()<<". Diem toan: "<<a.DanhSach[t].getToan()<<"\n";
}
void DanhSachHocSinh::TimDTBCaoNhat(const DanhSachHocSinh&a)//tìm học sinh có đtb cao nhất
{
    int max=a.DanhSach[0].getDTB();
    int t;
    for(int i=0; i<a.n;i++)
        {
            if(max<a.DanhSach[i].getDTB()) 
            {
                max=a.DanhSach[i].getDTB();
                t=i;
            }
        }
    cout<<"Hoc sinh voi so diem trung binh cao nhat la:  "<<a.DanhSach[t].getTen()<<". Diem trung binh: "<<a.DanhSach[t].getDTB()<<"\n";
}
void DanhSachHocSinh::PhanLoaiHocSinh(const DanhSachHocSinh &a)// phân loại học sinh dựa vào đtb
{
    for(int i=0; i<a.n;i++)
        {
            if(a.DanhSach[i].getDTB()<5)
            {
                cout<<"Ho Ten: "<<a.DanhSach[i].getTen()<<". DTB: "<<a.DanhSach[i].getDTB()<<". Xep loai: Yeu.\n";
            }
            else if(a.DanhSach[i].getDTB()>=5&&a.DanhSach[i].getDTB()<6.5)
            {
                cout<<"Ho Ten: "<<a.DanhSach[i].getTen()<<". DTB: "<<a.DanhSach[i].getDTB()<<". Xep loai: Trung Binh.\n";
            }
            else if(a.DanhSach[i].getDTB()>=6.5&&a.DanhSach[i].getDTB()<8)
            {
                cout<<"Ho Ten: "<<a.DanhSach[i].getTen()<<". DTB: "<<a.DanhSach[i].getDTB()<<". Xep loai: Kha.\n";
            }
            else if(a.DanhSach[i].getDTB()>=8&&a.DanhSach[i].getDTB()<9)
            {
                cout<<"Ho Ten: "<<a.DanhSach[i].getTen()<<". DTB: "<<a.DanhSach[i].getDTB()<<". Xep loai: Gioi.\n";
            }
            else if(a.DanhSach[i].getDTB()>9)
            {
                cout<<"Ho Ten: "<<a.DanhSach[i].getTen()<<". DTB: "<<a.DanhSach[i].getDTB()<<". Xep loai: Xuat Sac.\n";
            }
        }
}
int main()
{
    cout<<"Chao mung den voi chuong trinh quan ly hoc sinh!^^\n";
    DanhSachHocSinh a;
    cin>>a;
    int chucnang;
    cout<<"Nhan 1 de tim kiem hoc sinh theo ten.\n";
    cout<<"Nhan 2 de tim hoc sinh voi so diem trung binh cao nhat.\n";
    cout<<"Nhan 3 de tim hoc sinh co diem Toan thap nhat.\n";
    cout<<"Nhan 4 de tinh diem trung binh va phan loai tat ca hoc sinh.\n";
    a.TinhDTB(a);
    cin>>chucnang;
    switch(chucnang)//chức năng tương ứng với từng số nguyên
    {
        case 1:
        {
            cout<<"Xin moi nhap vao ten hoc sinh muon tim kiem. \n";
            string t;
            cin.ignore();
            getline(cin,t);
            int i=a.TimKiemHocSinh(t);
            vector<HocSinh> b=a.getDanhSach();
            if(i!=-1){
                if(b[i].getDTB()<5)
            {
                cout<<"Ho Ten: "<<b[i].getTen()<<". DTB: "<<b[i].getDTB()<<". Xep loai: Yeu.\n";
            }
            else if(b[i].getDTB()>=5&&b[i].getDTB()<6.5)
            {
                cout<<"Ho Ten: "<<b[i].getTen()<<". DTB: "<<b[i].getDTB()<<". Xep loai: Trung Binh.\n";
            }
            else if(b[i].getDTB()>=6.5&&b[i].getDTB()<8)
            {
                cout<<"Ho Ten: "<<b[i].getTen()<<". DTB: "<<b[i].getDTB()<<". Xep loai: Kha.\n";
            }
            else if(b[i].getDTB()>=8&&b[i].getDTB()<9)
            {
                cout<<"Ho Ten: "<<b[i].getTen()<<". DTB: "<<b[i].getDTB()<<". Xep loai: Gioi.\n";
            }
            else if(b[i].getDTB()>9)
            {
                cout<<"Ho Ten: "<<b[i].getTen()<<". DTB: "<<b[i].getDTB()<<". Xep loai: Xuat Sac.\n";
            }
            }
            else cout<<"khong co hoc sinh nao voi ten ma ban da nhap.\n";
            break;
        }
        
        case 2:
        {
            a.TimDTBCaoNhat(a);
            break;
        }
        case 3:
        {
            a.TimDiemToanThapNhat(a);
            break;
        }
        case 4:
        {
            a.PhanLoaiHocSinh(a);
            break;
        }
    }




}
