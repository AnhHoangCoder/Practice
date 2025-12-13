//Liệt kê tất cả các xâu nhị phân có độ dài bằng n ko chứa 2 số 0 liên tiếp

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
vector<int> a;

// // dùng kỹ thuật sinh kế tiếp
// void print(){
//     for(int i=1;i<=n;i++){
//         fout << a[i];
//     }
//     fout << " ";
// }

// bool sinh(){
//     int i = n;
//     while(i > 0 && a[i] == 1){
//         a[i] = 0;
//         i--;
//     }
//     if(i == 0) return false;
//     a[i]++;
//     return true;
// }

// void test_case(){
//     fin >> n;
//     a.assign(n+1 , 0);
//     do{
//         bool check = true;
//         for(int i=1;i<n;i++){
//             if(a[i] == 0 && a[i+1] == 0){
//                 check = false;
//                 break;
//             }
//         }
//         if(check){
//             print();
//         }
//     }while(sinh());
//     fout << "\n";
// }

//dùng kỹ thuật quay lui
void back_track(int i){
    for(int j=0;j<=1;j++){
        if(i > 1 && a[i-1] == 0 && j == 0) continue;

        a[i] = j;
        if(i == n){
            for(int u = 1 ; u <= n ; u++){
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
    fin >> n;
    a.assign(n+1 , 0);
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