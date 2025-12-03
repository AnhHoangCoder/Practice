#include <iostream>
#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

string add(string a , string b){
    if(a.size() < b.size()){
        swap(a,b);
    }
    while(a.size() != b.size()) b = "0" + b;
    int n = a.size();
    string c(n , '0');
    int nho = 0;
    for(int i=n-1;i>=0;i--){
        nho += (a[i] -  '0') + (b[i] - '0');
        c[i] = nho%10 + '0';
        nho /= 10;
    }
    if(nho > 0){
        c = to_string(nho%10) + c;
    }
    return c;
}

bool TF(string a , string b , string s){
    int x = a.size() + b.size();
    while(x < s.size()){
        string c = add(a,b);
        string d = s.substr(x,c.size());
        if(c == d){
            a = b;
            b = c;
            x += c.size();
        }
        else{
            return false;
        }
    }
    return true;
}

void test_case(){
    string s;
    in >> s;
    int n = s.size();
    string a;
    for(int i=0;i<=n/2;i++){
        a.push_back(s[i]);
        string b;
        for(int j=i+1;j<=n*2/3;j++){
            b.push_back(s[j]);
            if(TF(a,b,s)){
                out << "Yes" << "\n";
                return;
            }
        }
    }
    out << "No" << "\n";
}

int main(){
    int t;
    in >> t;
    while(t--){
        test_case();
    }
    return 0;
}