#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int cmp(string a , string b){
    if(a.size() != b.size()) return a.size() < b.size() ? -1 : 1;
    if(a == b) return 0;
    return a < b ? -1 : 1;
}

string subtract(string a , string b){
    string res = "";
    int carry = 0;
    while(a.size() > b.size()) b = "0" + b;
    for(int i = a.size() - 1 ; i >= 0 ; i--){
        int x = (a[i] - '0') - (b[i] - '0') - carry;
        if(x < 0){
            x += 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        res = char(x + '0') + res;
    }
    while(res.size() > 1 && res[0] == '0') res.erase(0,1);
    return res;
}

string mod_big(string a , string b){
    string cur = "";
    for(char c : a){
        cur += c;
        while(cur.size() > 1 && cur[0] == '0') cur.erase(0,1);
        while(cmp(cur , b) >= 0){
            cur = subtract(cur , b);
        }        
    }
    if(cur == "") cur = "0";
    return cur;
}

string big_Gcd(string a , string b){
    if(b == "0") return a;
    return big_Gcd(b , mod_big(a,b));    
}

void test_case(){
    string a , b;
    fin >> a >> b;
    fout << big_Gcd(a,b) << "\n";
}

int main(){
    int t;
    fin >> t;
    while(t--){
        test_case();
    }
    return 0;
}