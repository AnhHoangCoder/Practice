#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class MonHoc{
    string name , id;
    int stc;
public:
    friend istream& operator >> (istream &in , MonHoc &a){
        in >> a.id;
        in.ignore();
        getline(in , a.name);
        in >> a.stc;
        return in;
    }
    friend ostream& operator << (ostream &out , const MonHoc &a){
        out << a.id << " " << a.name << " " << a.stc << endl;
        return out;
    }
    string get_name(){
        return name;
    }
};

int main(){
    ifstream fin("MONHOC.in");
    int n;
    fin >> n;
    fin.ignore();
    vector<MonHoc> a;
    for(int i=0;i<n;i++){
        MonHoc x;
        fin >> x;
        a.push_back(x);
    }
    sort(a.begin() , a.end() , [](MonHoc a , MonHoc b){
        return a.get_name() < b.get_name();
    });
    for(auto x : a){
        cout << x;
    }
    return 0;
}