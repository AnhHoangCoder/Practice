// #include <iostream>

// using namespace std;

// using ll = long long;

// bool so_nt(ll n){
//     if(n < 2) return false;
//     if(n == 2 || n == 3) return true;
//     if(n % 2 == 0 || n % 3 == 0) return false;
//     for(int i = 5 ; (ll)i*i <= n ; i+=6){
//         if(n % i == 0 || n % (i+2) == 0) return false;
//     }
//     return true;
// }

// void test_case(){
//     ll n;
//     cin >> n;
//     for(int i = 2 ; (ll)i*i <= n ; i++){
//         if(so_nt(i)){
//             while(n % i == 0){
//                 cout << i << " ";
//                 n/=i;
//             }
//         }
//     }
//     if(n > 1){
//         if(so_nt(n)){
//             cout << n;
//         }
//     }
//     cout << endl;
// }

// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         test_case();
//     }
//     return 0;
// }

#include <iostream>
#include <cmath>
#include <cstring>

#define Max 1000000

using namespace std;
using ll = long long;

char prime[Max+1];

void sang(){
    memset(prime,1,sizeof(prime));
    prime[0] = 0,prime[1] = 0;
    for(int i=2;i<=sqrt(Max);i++){
        if(prime[i]){
            for(int j=i*i;j<=Max;j+=i){
                prime[j] = 0;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sang();
    int t;
    ll n;
    cin >> t;
    while(t--){
        cin >> n;
        if(n<2) continue;
        for(int i=2;i<=sqrt(n);i++){
            if(!prime[i]) continue;
            while(n%i==0){
                cout << i << " ";
                n/=i;
            }
        }
        if(n>1){
            cout << n << endl;
        }
        else{
            cout << endl;
        }
    }
    return 0;
}