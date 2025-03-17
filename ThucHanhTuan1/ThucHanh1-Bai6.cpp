#include <iostream>
#include <vector>
using namespace std;
class mang
{
    private:
    vector<int> a;
    int n;
    public:
    friend istream& operator>>(istream&, mang&);
    void tim(const mang&);

};
istream& operator>>(istream&is,mang&a)
{
    cout<<"vui long nhap vao so phan tu cua mang!\n";
    is>>a.n;
    for(int i=0;i<a.n;i++)
    {
        int t;
        is>>t;
        a.a.push_back(t);
    }
    return is;
}
void mang::tim(const mang&b)
{
    int counter=0;
    vector<int> c;
    for(int i=0;i<=b.n-this->n;i++)
        {
               bool t=1;
                for(int j=0 ;j<this->n; j++)
                    {
                        if(b.a[i+j]!=this->a[j])
                            {
                                t=0;
                                break;
                            }
                    }
                if(t)
                {
                    counter++;
                    c.push_back(i);
                }
        }
    if(counter==0) cout<<"Mang A khong xuat hien trong mang B\n";
    else
    {
        cout<<"Mang A da xuat hien trong mang B "<<counter<<" lan.\n";
        cout<<"Cac vi tri bat dau cua cac lan xuat hien cua mang A trong mang B la ";
        for(int i=0; i<counter; i++)
            cout<<c[i]<<" ";
    }

}

int main()
{
    mang a,b;
    cin>>a>>b;
    a.tim(b);
}