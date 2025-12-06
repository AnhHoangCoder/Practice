#include <iostream>
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
    int max_num = a[0];
    int max_ans = max_num;
    for(int i=1;i<n;i++){
        max_num = max(a[i] , max_num + a[i]);
        max_ans = max(max_ans , max_num);
    }
    fout << max_ans << "\n";
}

int main(){
    int t;
    fin >> t;
    while(t--){
        test_case();
    }
    return 0;
}