#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class SoTay{
    string name , date , sdt;
public:
    friend istream& operator >> (istream &in , SoTay &a){
        getline(in , a.date);
        getline(in , a.name);
        getline(in , a.sdt);
        return in;
    }
    friend ostream& operator << (ostream &out , const SoTay &a){
        string date = a.date.substr(5);
        out << a.name << ": " << a.sdt << " " << date << endl;
        return out;
    }
};

int main(){
    ifstream fin("SOTAY.txt");
    ofstream fout("DIENTHOAI.txt");
    
    vector<SoTay> a;
    for(int i=0;i<3;i++){
        SoTay x;
        fin >> x;
        a.push_back(x);
    }
    for(const auto &x : a){
        fout << x;
    }
    return 0;
}