#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

void nhap(ifstream &in,set<string> &v , vector<string> &a){
    string s;
    while(in >> s){
        for(char &c : s){
            c = tolower(c);
        }
        a.push_back(s);
        v.insert(s);
    }
}

int main(){
    ifstream in1("DATA1.in");
    ifstream in2("DATA2.in");

    set<string> hop,giao;
    vector<string> a,b;
    nhap(in1 , hop , a);
    nhap(in2 , hop , b);

    for(auto x : a){
        for(auto y : b){
            if(x == y){
                giao.insert(x);
            }
        }
    }
    for(auto x : hop){
        cout << x << " ";
    }
    cout << endl;
    for(auto x : giao){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}