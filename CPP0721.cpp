#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

inline void nhap(vector<int> &a , int n){
    for(int i=0;i<n;i++){
        in >> a[i];
    }
}

void test_case(){
    int n;
    in >> n;
    vector<int> a(n);
    nhap(a,n);
    vector<int> dp;
    
    for(int x : a){
        auto it = lower_bound(dp.begin() , dp.end() , x);
        if(it == dp.end()){
            dp.push_back(x);
        }
        else{
            *it = x;
        }
    }
    out << dp.size() << endl;
}

int main(){
    int t;
    in >> t;
    while(t--){
        test_case();
    }
    return 0;
}