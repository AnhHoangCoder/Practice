#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

string operator * (string a , string b){
    if(a == "0" || b == "0") return "0";
    int n = a.size() , m = b.size();
    vector<int> res(n+m);

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int num = (a[i] - '0') * (b[j] -'0');
            int sum = res[i+j+1] + num;
            res[i+j+1] = sum%10;
            res[i+j] += sum/10;
        }
    }
    int i = 0;
    while(i < res.size() && res[i] == 0) i++;
    string ans = "";
    for(;i < res.size() ; i++){
        ans += (res[i] + '0');
    }
    return ans;
}

void test_case(){
    string a , b;
    in >> a >> b;
    out << a*b << "\n";
}

int main(){
    int t;
    in >> t;
    while(t--){
        test_case();
    }
    return 0;
}