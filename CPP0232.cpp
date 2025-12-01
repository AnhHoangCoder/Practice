#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int ans;

void max_s(vector<vector<int>> &a , int n , int m , int idx){
    if(idx == n) return;
    vector<int> h(m);
    int Max = 0;
    for(int i=0;i<m;i++){
        int dem = 0;
        for(int j=idx;j<n;j++){
            if(a[j][i] == 1) dem++;
            else break;
        }
        h[i] = dem;
        Max = max(Max , h[i]);
    }
    vector<int> count(Max+1);
    for(int x : h){
        count[x]++;
    }
    int cnt = 0;
    for(int i=Max;i>=1;i--){
        cnt += count[i];
        ans = max(ans , cnt * i);
    }
    max_s(a,n,m,idx+1);
}

void test_case(){
    ans = 0;
    int n , m;
    in >> n >> m;
    vector<vector<int>> a(n , vector<int> (m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            in >> a[i][j];
        }
    }

    max_s(a,n,m,0);
    out << ans << "\n";
}

int main(){
    int t;
    in >> t;
    while(t--){
        test_case();
    }
    return 0;
}