#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

ifstream in("input.txt");
ofstream out("output.txt");

ll powmod(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void test_case(){
    int n , r;
    in >> n >> r;
    vector<ll> gt(n+1);
    gt[0] = 1;
    for(int i=1;i<=n;i++){
        gt[i] = gt[i-1] * (ll)i % MOD;
    }
    ll tu = gt[n];
    ll mau = gt[r] * gt[n-r] % MOD;
    ll ans = tu * powmod(mau , MOD-2) % MOD;
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