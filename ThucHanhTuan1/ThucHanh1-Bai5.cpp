#include <iostream>

using namespace std;

class date
{
    private:
    int Ngay,Thang,Nam;
    public:
    date& NgayTruoc();
    date& NgaySau();
    int TinhThu();
    friend istream& operator>>(istream&, date&);
    friend ostream& operator<<(ostream&, const date&);
};
istream& operator>>(istream &is, date &a)
{
    cout<<"Nhap vao Ngay/Thang/Nam: ";
    is>>a.Ngay>>a.Thang>>a.Nam;
        if(a.Nam<1)
        {
            cout<<"Nam khong hop le! Vui long nhap lai"<<"\n";
            is>>a.Nam;
        }
        if(a.Thang <1 || a.Thang >12)
        {
            cout<<"Thang khong hop le! Vui long nhap lai"<<"\n";
            is>>a.Thang;
        }
        if(a.Thang ==1|| a.Thang==3||a.Thang==5||a.Thang==7||a.Thang==8||a.Thang==10||a.Thang==12)
        {
        while(a.Ngay<1 ||a.Ngay>31)
            {
            cout<<"Ngay khong hop le! Vui long nhap lai"<<"\n";
            is>>a.Ngay;
            }
        }
    bool check=0;
    if(a.Nam%4==0&&a.Nam%100!=0) check=1;
    if(check)
    {
        if(a.Thang ==4|| a.Thang==6||a.Thang==9||a.Thang==11)
        {
        while(a.Ngay<1 ||a.Ngay>30)
            {
            cout<<"Ngay khong hop le! Vui long nhap lai"<<"\n";
            is>>a.Ngay;
            }
        }
        if(a.Thang ==2)
    {
        while(a.Ngay<1 ||a.Ngay>29)
        {
            cout<<"Ngay khong hop le! Vui long nhap lai"<<"\n";
            is>>a.Ngay;
        }
    }
}
    else
    {
        if(a.Nam<0)
        {
            cout<<"Nam khong hop le! Vui long nhap lai"<<"\n";
            is>>a.Nam;
        }
        if(a.Thang <1 || a.Thang >12)
        {
            cout<<"Thang khong hop le! Vui long nhap lai"<<"\n";
            is>>a.Thang;
        }
        if(a.Thang ==1|| a.Thang==3||a.Thang==5||a.Thang==7||a.Thang==8||a.Thang==10||a.Thang==12)
        {
        while(a.Ngay<1 ||a.Ngay>31)
            {
            cout<<"Ngay khong hop le! Vui long nhap lai"<<"\n";
            is>>a.Ngay;
            }
        }
        if(a.Thang ==4|| a.Thang==6||a.Thang==9||a.Thang==11)
        {
        while(a.Ngay<1 ||a.Ngay>30)
            {
            cout<<"Ngay khong hop le! Vui long nhap lai"<<"\n";
            is>>a.Ngay;
            }
        }
        if(a.Thang ==2)
    {
        while(a.Ngay<1 ||a.Ngay>29)
        {
            cout<<"Ngay khong hop le! Vui long nhap lai"<<"\n";
            is>>a.Ngay;
        }
    }
    }
    return is;
}

ostream& operator<<(ostream&os,const date&a)
{
    os<<a.Ngay<<"/"<<a.Thang<<"/"<<a.Nam<<".\n";
    return os;
}
date& date::NgayTruoc()
{
    bool check=0;
    if(this->Nam%4==0&&this->Nam%100!=0) check=1;
    if(this->Thang==5||this->Thang==7||this->Thang==10||this->Thang==12)
    {
        if(this->Ngay>1) this->Ngay--;
        else
        {
            this->Ngay=30;
            this->Thang--;
        }
    }
    else if(this->Thang ==4|| this->Thang==6||this->Thang==9||this->Thang==11||this->Thang==8||this->Thang==2||this->Thang==1)
    {
        if(this->Ngay>1) this->Ngay--;
        else
        {
            if(this->Thang==1) 
            {
                this->Ngay=31;
                this->Thang=12;
                this->Nam--;
            }
            else
            {
            this->Ngay=31;
            this->Thang--;
            }
        }
    }
    else if(this->Thang ==3)
    {
            if(check)
                {
                    if(this->Ngay>1) this->Ngay--;
                    else
                    {
                        this->Ngay=29;
                        this->Thang--;
                    }
                }
            else
                {
                    if(this->Ngay>1) this->Ngay--;
                    else
                    {
                        this->Ngay=28;
                        this->Thang--;
                    }
                }
        }
        return *this;
}
date& date::NgaySau()
{
    bool check=0;
    if(this->Nam%4==0&&this->Nam%100!=0) check=1;
    if(this->Thang ==1|| this->Thang==3||this->Thang==5||this->Thang==7||this->Thang==8||this->Thang==10||this->Thang==12)
    {
        if(this->Ngay<31) this->Ngay++;
        else
        {
            this->Ngay=1;
            if(this->Thang!=12) this->Thang++;
            else 
            {
                this->Thang=1;
                this->Nam++;
            }
        }
    }
        if(this->Thang ==4|| this->Thang==6||this->Thang==9||this->Thang==11)
    {
        if(this->Ngay<30) this->Ngay++;
        else
        {
            this->Ngay=1;
            this->Thang++;
        }
    }
        if(this->Thang ==2)
    {
            if(check)
                {
                    if(this->Ngay<29) this->Ngay++;
                    else
                    {
                        this->Ngay=1;
                        this->Thang++;
                    }
                }
            else
                {
                    if(this->Ngay<28) this->Ngay++;
                    else
                    {
                        this->Ngay=1;
                        this->Thang++;
                    }
                }
        }
    return *this;
}
int date::TinhThu()
{
    if(this->Thang ==2) 
    {
        this->Thang=14;
        this->Nam--;
    }
    else if(this->Thang==1)
    {
            this->Thang=13;
            this->Nam--;
    }
    int q=this->Ngay, m=this->Thang, k=this->Nam%100, j=this->Nam/100,h;
    h=q+13*(m+1)/5 + k + k/4+j/4+5*j;
    h%=7;
    return h;
}

int main()
{
    date a;
    cin>>a;
    cout<<"Chao mung ban den voi chuong trinh tinh toan ngay thang!\n";
    cout<<"Chon 1 de tim ngay ke tiep cua ngay ma ban da nhap.\n";
    cout<<"Chon 2 de tim nay truoc ngay ma ban da nhap.\n";
    cout<<"Chon 3 de tinh xem do la ngay thu may trong nam.\n";
    int n;
    cin>>n;
    switch(n)
    {
        case 1:
        cout<<"Ban da lua chon chuc nang tim ngay ke tiep.\n";
        cout<<"Ngay ke tiep cua ngay "<<a<<" la ngay "<<a.NgaySau();
        break;
        break;
        case 2:
        cout<<"Ban da lua chon chuc nang tim ngay truoc do.\n";
        cout<<"Ngay truoc do cua ngay "<<a<<" la ngay "<<a.NgayTruoc();
        break;
        case 3:
        cout<<"Ban da lua chon chuc nang tim xem ngay thu may trong nam.\n";
        cout<<"Ngay "<<a;
        int t=a.TinhThu();
        switch(t)
            {
                case 0:
                cout<<" la thu bay";
                break;
                case 1:
                cout<<" la chu nhat";
                break;
                case 2:
                cout<<" la thu hai";
                break;
                case 3:
                cout<<" la thu ba";
                break;
                case 4:
                cout<<" la thu bon";
                break;
                case 5:
                cout<<" la thu nam";
                break;
                case 6:
                cout<<" la thu sau";
                break;
            }
    }

}