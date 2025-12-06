#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> a;
int n;

//kỹ thuật sinh xâu nhị phân
// bool sinh(){
//     int i = n-1;
//     while(i>=0 && a[i] == 1){
//         a[i] = 0;
//         i--;
//     }
//     if(i < 0) return false;
//     a[i] = 1;
//     return true;
// }

// void test_case(){
//     fin >> n;
//     a.assign(n , 0);
//     for(int i=0;i<n;i++){
//         a[i] = 0;
//     }
//     do{
//         for(int x : a){
//             fout << x;
//         }
//         fout << " ";
//     }while(sinh());
//     fout << "\n";
// }

void back_track(int i){
    for(int j=0;j<=1;j++){
        a[i] = j;
        if(i == n-1){
            for(int x : a){
                fout << x;
            }
            fout << " ";
        }
        else{
            back_track(i+1);
        }
    }
}

//kỹ thuật quay lui nhị phân
void test_case(){
    fin >> n;
    a.assign(n,0);
    back_track(0);
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