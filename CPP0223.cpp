#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

void test_case(){
    int n,m;
    fin >> n >> m;
    vector<vector<int>> a(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            fin >> a[i][j];
        }
    }

    int c1 = 0 , c2 = m-1;
    int h1 = 0 , h2 = n-1;
    while(h1 <= h2 && c1 <= c2){
        for(int i=c1;i<=c2;i++){
            fout << a[h1][i] << " ";
        }
        h1++;
        for(int i=h1;i<=h2;i++){
            fout << a[i][c2] << " ";
        }
        c2--;
        if(h1 <= h2){
            for(int i=c2;i>=c1;i--){
                fout << a[h2][i] << " ";
            }
            h2--;
        }
        if(c1 <= c2){
            for(int i=h2;i>=h1;i--){
                fout << a[i][c1] << " ";
            }
            c1++;
        }
    }
    fout << endl;
}

int main(){
    int t;
    fin >> t;
    while(t--){
        test_case();
    }
    return 0;
}