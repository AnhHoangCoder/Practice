#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

void test_case(){
    int n;
    fin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        fin >> a[i];
    }
    int Min = INT_MAX;
    for(int i=0;i<n-1;i++){
        Min = min(Min , a[i+1] - a[i]);
    }
    fout << Min << endl;
}

int main(){
    int t;
    fin >> t;
    while(t--){
        test_case();
    }
    return 0;
}