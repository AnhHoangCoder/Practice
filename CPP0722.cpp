#include <iostream>
#include <fstream>
#include <numeric>
#include <vector>

using namespace std;
using bint = string;

ifstream in("input.txt");
ofstream out("output.txt");

bint operator*(bint a , int b){
    if(a == "0" || b == 0) return "0";
    int n = a.size();
    int nho = 0;
    bint s(n , '0');
    for(int i = n-1 ; i >= 0 ; i--){
        nho += ((a[i] - '0') * b);
        s[i] = (nho % 10) + '0';
        nho /= 10;
    }
    if(nho > 0){
        s = to_string(nho) + s;
    }
    return s;
}

bint catalan(int n){
    vector<int> tu;
    for(int i = n+2 ; i <= 2*n ; i++){
        tu.push_back(i);
    }
    for(int i = 2 ; i <= n ; i++){
        int x = i;
        for(int j = 0 ; j < tu.size() && x > 1 ; j++){
            int d = std::gcd(x,tu[j]);
            x /= d;
            tu[j] /= d;
        }
    }
    bint res = "1";
    for(int x : tu){
        res = res * x;
    }
    return res;
}

void test_case(){
    short n;
    in >> n;
    out << catalan(n+1) << "\n";
}

int main(){
    test_case();
    return 0;
}