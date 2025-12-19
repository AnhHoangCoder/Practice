#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> a;

void quay_lui(int i){
    for(int j=0;j<=1;j++){
        a[i] = j;
        if(i == n){
            int cnt_k = 0;
            bool sai = false;

            int len = 0;
            for(int u=1;u<=n;u++){
                if(a[u] == 1){
                    len++;
                }
                else{
                    if(len == k) cnt_k++;
                    if(len > k) sai = true;
                    len = 0;
                }
            }
            if(len == k){
                cnt_k++;
            }
            if(len > k) sai = true;

            if(!sai && cnt_k == 1){
                for(int u=1;u<=n;u++){
                    cout << (a[u] == 0 ? 'A' : 'B');
                }
                cout << " ";
            }
        }
        else{
            quay_lui(i+1);
        }
    }
}

int main(){
    cin >> n >> k;
    a.resize(n+1);
    quay_lui(1);
    return 0;
}