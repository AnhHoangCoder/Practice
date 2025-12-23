#include <iostream>
#include <cmath>

using namespace std;

class SoPhuc{
    int thuc , ao;
public:
    SoPhuc (int t=0 ,int a=0){
        thuc = t;
        ao = a;
    }
    friend istream& operator >> (istream &in , SoPhuc &a){
        in >> a.thuc >> a.ao;
        return in;
    }
    friend ostream& operator << (ostream &out ,const SoPhuc &a){
        out << a.thuc << " ";
        char tmp = '+';
        if(a.ao < 0){
            tmp = '-';
        }
        out << tmp << " " << fabs(a.ao) << "i" << endl;
        return out;
    }
    friend SoPhuc operator + (const SoPhuc &a ,const SoPhuc &b){
        return SoPhuc(a.thuc + b.thuc , a.ao + b.ao);
    }
};

int main(){
    SoPhuc p(2,2) , q(3,4);
    cin >> p >> q;
    cout << p + q;
    return 0;
}