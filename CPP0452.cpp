#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using ll = long long;

ifstream in("input.txt");
ofstream out("output.txt");

inline void nhap(vector<ll> &a , int n){
    for(int i=0;i<n;i++){
        in >> a[i];
    }
}

void test_case(){
    int n_1 , n_2 , n_3;
    in >> n_1 >> n_2 >> n_3;
    vector<ll> a(n_1) , b(n_2) , c(n_3);
    nhap(a,n_1);
    nhap(b,n_2);
    nhap(c,n_3);

    int i = 0 , j = 0 , k = 0;
    bool check = false;
    while(i < n_1 && j < n_2 && k < n_3){
        if(a[i] == b[j] && b[j] == c[k]){
            out << a[i] << " ";
            check = true;

            ll val = a[i];
            while(i < n_1 && a[i] == val) i++;
            while(j < n_2 && b[j] == val) j++;
            while(k < n_3 && c[k] == val) k++;
        }
        else{
            ll Min = min(a[i],min(b[j] , c[k]));
            if(a[i] == Min) i++;
            else if(b[j] == Min) j++;
            else k++;
        }
    }
    if(!check){
        out << "-1" << "\n";
    }
    else{
        out << "\n";
    }
}

int main(){
    int t;
    in >> t;
    while(t--){
        test_case();
    }
    return 0;
}