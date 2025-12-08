//Liệt kê tổ hợp chập k của n
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n , k;
vector<int> a;
// //dùng phương pháp sinh tổ hợp

// bool sinh(){
//     int i = k;
//     while(i > 0 && a[i] == n-k+i) i--;
//     if(i == 0) return false;
//     a[i]++;
//     for(int j=i+1;j<=k;j++){
//         a[j] = a[j-1]+1;
//     }
//     return true;
// }

// void test_case(){
//     fin >> n >> k;
//     a.assign(k+1 , 0);
    
//     for(int i=1;i<=k;i++){
//         a[i] = i;
//     }

//     do{
//         for(int i=1;i<=k;i++){
//             fout << a[i];
//         }
//         fout << " ";
//     } while(sinh());
//     fout << "\n";
// }


//Dùng phương pháp quay lui
void back_track(int i){
    for(int j = a[i-1]+1 ; j <= n-k+i ; j++){
        a[i] = j;
        
        if(i == k){
            for(int u=1;u<=k;u++){
                fout << a[u];
            }
            fout << " ";
        }
        else{
            back_track(i+1);
        }
    }
}

void test_case(){
    fin >> n >> k;
    a.assign(k+1 , 0);
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