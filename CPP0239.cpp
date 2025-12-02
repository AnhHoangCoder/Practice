#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;
using db = double;

const db EPS = 1e-9;

ifstream in("input.txt");
ofstream out("output.txt");

int matrix_rank(vector<vector<db>> &a , int n , int m){
    int rank = 0;
    for(int col = 0 ; col < m ; col++){
        int tmp = rank;
        for(int i = rank ; i < n ; i++){
            if(fabs(a[i][col]) > fabs(a[tmp][col])){
                tmp = i;
            }
        }
        if(fabs(a[tmp][col]) < EPS) continue;
        swap(a[tmp] , a[rank]);

        db div = a[rank][col];
        for(int j = col ; j < m ; j++){
            a[rank][j] /= div;
        }

        for(int i = 0 ; i < n ; i++){
            if(i != rank && fabs(a[i][col]) > EPS){
                db fac = a[i][col];
                for(int j = col ; j < m ; j++){
                    a[i][j] -= fac * a[rank][j];
                }
            }
        }
        rank++;
    }
    return rank;
}

void test_case(){
    int n , m;
    in >> n >> m;
    vector<vector<db>> a(n , vector<db> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            in >> a[i][j];
        }
    }
    out << matrix_rank(a , n , m) << "\n";
}

int main(){
    int t;
    in >> t;
    while(t--){
        test_case();
    }
    return 0;
}