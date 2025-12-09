//Liệt kê các hoán vị của 1,2,...n
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
vector<int> a;

// //dùng phương pháp sinh kế tiếp
// bool sinh(){
//     int i = n-1;
//     while(i > 0 && a[i] > a[i+1]) i--;
//     if(i == 0) return false;
//     int j = n;
//     while(a[j] < a[i]) j--;
//     swap(a[i],a[j]);
//     reverse(a.begin() + i + 1 , a.end());
//     return true;
// }

// void test_case(){
//     fin >> n;
//     a.assign(n+1,0);
//     for(int i=1;i<=n;i++){
//         a[i] = i;
//     }
//     do{
//         for(int i=1;i<=n;i++){
//             fout << a[i];
//         }
//         fout << " ";
//     } while(sinh());
//     fout << "\n";
// }


//Dùng phương pháp quay lui
vector<bool> used;

void back_track(int i){
    for(int j = 1 ; j <= n ; j++){
        if(!used[j]){
            a[i] = j;
            used[j] = true;
            if(i == n){
                for(int u = 1 ; u <= n ; u++){
                    fout << a[u];
                }
                fout << " ";
            }
            else{
                back_track(i+1);
            }
            used[j] = false;
        }
    }
}

void test_case(){
    fin >> n;
    a.assign(n+1 , 0);
    used.assign(n+1 , false);
    back_track(1);
    fout << "\n";
}

int main(){
    int t;
    fin >> t;
    while(t--){
        test_case();
    }
    return 0;
}