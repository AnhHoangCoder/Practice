#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int max_square(vector<vector<char>> &a , int n){
    int res = 0;
    for(int len = n ; len >= 1 ; len--){
        bool check = false;
        for(int i = 0; i < n+1-len && !check ; i++){
            for(int j = 0 ; j < n+1-len && !check ; j++){
                bool ok = true;
                for(int u = j ; u < j+len ; u++){
                    if(a[i][u] != 'X' || a[i+len-1][u] != 'X') ok = false;
                }
                for(int v = i ; v < i+len ; v++){
                    if(a[v][j] != 'X' || a[v][j+len-1] != 'X') ok = false;
                }
                if(ok){
                    res = len;
                    check = true;
                }
            }
        }
        if(check){
            break;
        }
    }
    return res;
}

void test_case(){
    int n;
    in >> n;
    vector<vector<char>> a(n , vector<char> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            in >> a[i][j];
        }
    }

    if(max_square(a,n) != 0){
        out << max_square(a,n) << "\n";
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