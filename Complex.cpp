#include <iostream>
#include <cmath>

using namespace std;

class Complex{
	int thuc,ao;
public:
	friend istream& operator >> (istream &in , Complex &a){
		in >> a.thuc >> a.ao;
		return in;
	}
	friend ostream& operator << (ostream &out ,const Complex &a){
        if(a.ao == 0){
            out << a.thuc;
            return out;
        }
		char c = (a.ao < 0) ? '-' : '+';
		out << a.thuc << " " << c;
        if(abs(a.ao) == 1){
            out << " ";
        }
        else{
            out << " " << abs(a.ao);
        }
        out << "i";
		return out;
	}
	friend Complex operator+(Complex a , Complex b){
		Complex sum;
		sum.thuc = a.thuc + b.thuc;
		sum.ao = a.ao + b.ao;
		return sum;
	}
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        Complex A, B;
        cin >> A >> B;
        cout << A + B << endl;
    }
    return 0;
}