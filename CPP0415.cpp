#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

inline void nhap(vector<int> &a , int n){
    for(int i=0;i<n;i++){
        in >> a[i];
    }
}

int max_num(vector<int> &a , int n){
    int Max = a[0];
    for(int i=1;i<n;i++){
        if(a[i] > Max) Max = a[i];
    }
    return Max;
}

int min_num(vector<int> &a , int n){
    int Min = a[0];
    for(int i=1;i<n;i++){
        if(a[i] < Min) Min = a[i];
    }
    return Min;
}

void test_case(){
    int n , m;
    in >> n >> m;

    vector<int> a(n) , b(m);
    nhap(a,n);
    nhap(b,m);

    int Min = min_num(b,m);
    int Max = max_num(a,n);

    out << 1LL * Max * Min << "\n";
}

int main(){
    int t;
    in >> t;
    while(t--){
        test_case();        
    }
    return 0;
}