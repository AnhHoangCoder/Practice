#include <iostream>
#include <cstring>

using namespace std;

#define Max 100000

char prime[Max+1];

void so_nt(){
    memset(prime , 1 , sizeof(prime));
    prime[0] = 0 , prime[1] = 0;
    for(int i = 2 ; i*i <= Max ; i++){
        if(prime[i]){
            for(int j = i*i ; j <= Max ; j+=i){
                prime[j] = 0;
            }
        }
    }        
}

void test_case(){
    int n,m;
    cin >> m >> n;
    while(m <= n){
        if(prime[m]){
            cout << m << " ";
        }
        m++;
    }
    cout << endl;
}

int main(){
    so_nt();
    int t;
    cin >> t;
    while(t--){
        test_case();
    }    
    return 0;
}