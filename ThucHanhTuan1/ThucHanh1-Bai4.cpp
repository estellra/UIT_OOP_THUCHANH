#include <iostream>
#include <cmath>

using namespace std;

class TinhToan {
private:
    double x; // Giá trị x (độ)
public:
    void Nhap();   // Hàm nhập dữ liệu
    double GiaiThua(int n);  // Tính giai thừa
    double SinX();  // Hàm tính sin(x)
    double getX() const {return x;}
};

void TinhToan::Nhap() {
    cout << "Nhap x (do): ";
    cin >> x;
}

double TinhToan::GiaiThua(int n) {
    double t = 1;
    for (int i = 1; i <= n; i++) {
        t *= i;
    }
    return t;
}

double TinhToan::SinX() {
    double radian = x * M_PI / 180.0; // Chuyển độ sang radian
    double sinX = 0.0;
    double term;
    int n = 0;

    do {
        term = pow(-1, n) * pow(radian, 2 * n + 1) / GiaiThua(2 * n + 1);
        sinX += term;
        n++;
    } while (fabs(term) >= 0.00001); // Dừng khi phần tử nhỏ hơn 0.00001

    return sinX;
}

int main() {
    TinhToan tt;
    tt.Nhap();
    cout << "Sin(" << tt.getX() << ") = " << tt.SinX() << endl;
    return 0;
}
