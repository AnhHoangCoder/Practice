//Liệt kê các cách chia số tự nhiên n thành các số nhỏ hơn n
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n,k;
vector<int> a;

//dùng sinh 
bool sinh(){
    int i = k;
    while(i > 0 && a[i] == 1) i--;
    if(i == 0) return false;
    a[i]--;
    int sum = 0;
    for(int j = 1 ; j <= i ; j++){
        sum += a[j];
    }
    
    int res = n - sum;
    k = i;
    while(res > a[i]){
        a[++k] = a[i];
        res -= a[i];
    }
    if(res > 0) a[++k] = res;
    return true;
}

void test_case(){
    fin >> n;
    a.assign(n+1 , 0);
    k = 1;
    a[k] = n;
    do{
        if(a[1] != n){
            for(int u = 1 ; u <= k ; u++){
                if(u > 1) fout << " + ";
                fout << a[u];
            }
            fout << "\n";
        }
    } while(sinh());
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