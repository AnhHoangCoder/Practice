//Hoán vị liền kề phía trước
//kỹ thuật sinh kế tiếp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

void hoan_vi(vector<int> &a){
    int n = a.size();
    int i = n-2;
    while(i >= 0 && a[i] < a[i+1]) i--;
    if(i < 0){
        reverse(a.begin() , a.end());
    }
    else{
        int j = n-1;
        while(a[j] > a[i]) j--;
        swap(a[j] , a[i]);
        reverse(a.begin() + i + 1 , a.end());
    }
}

void test_case(){
    int n;
    fin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        fin >> a[i];
    }
    hoan_vi(a);
    for(int x : a){
        fout << x << " ";
    }
    fout << "\n";
}

int main(){
    int t;
    fin >> t;
    while(t--){
        test_case();
    }
    return 0;
}