#include <iostream>
#include <iomanip>

using namespace std;

float diem_ut(string s){
	if(s == "KV1") return 0.5;
	else if(s == "KV2") return 1.0;
	else if(s == "KV3") return 2.5;
	else return 0;
}

class SinhVien{
private:
	string id , name;
	float toan , ly , hoa;
public:
	friend istream& operator >> (istream &in , SinhVien &a){
		in >> a.id;
		in.ignore();
		getline(in , a.name);
		in >> a.toan >> a.ly >> a.hoa;
		return in;
	}
	friend ostream& operator << (ostream &out ,const SinhVien &a){
		string tmp = a.id.substr(0,3);
		float diemUT = diem_ut(tmp);
		float sum = a.toan*2 + a.ly + a.hoa;
		bool dk = false;
		if(sum + diemUT >= 24){
			dk = true;
		}
		out << a.id << " " << a.name << " " << diemUT << " " << fixed << setprecision((int)sum == sum ? 0 : 1)<< sum << " ";
		if(dk){
			out << "TRUNG TUYEN";
		}
		else{
			out << "TRUOT";
		}
		out << endl;
		return out;
	}
};

int main(){
	SinhVien a;
	cin >> a;
	cout << a;
	return 0;
}