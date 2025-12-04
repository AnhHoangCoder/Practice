#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct Time{
    int gio , phut , giay;
};

bool cmp(Time a , Time b){
    if(a.gio != b.gio) return a.gio < b.gio;
    if(a.phut != b.phut) return a.phut < b.phut;
    return a.giay < b.giay;
}

int main(){
    int n;
    in >> n;
    vector<Time> t(n);
    for(int i=0;i<n;i++){
        in >> t[i].gio >> t[i].phut >> t[i].giay;
    }
    sort(t.begin() , t.end() , cmp);
    for(auto &x : t){
        out << x.gio << " " << x.phut << " " << x.giay << "\n"; 
    }
    return 0;
}