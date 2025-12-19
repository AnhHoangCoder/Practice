#include <iostream>

using namespace std;

using ll = long long;

ll p;

ll luy_thua(int a , int b){
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void test_case(){
    int x , y;
    cin >> x >> y >> p;
    cout << luy_thua(x,y) << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}