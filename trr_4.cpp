//Liệt kê các xâu nhị phân có độ dài n và có đúng k số 0 liên tiếp
//và m số 1 liên tiếp

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n,k,m;
vector<string> res;

//dùng quay lui

bool check(string &s){
    int cnt_0 = 0 , cnt_1 = 0;
    for(int i = 0 ; i+k <= s.size() ; i++){
        if(s.substr(i,k) == string(k,'0')){
            if((i > 0 && s[i-1] == '0') || (i+k < s.size() && s[i+k] == '0')){
                continue;
            }
            cnt_0++;
        }
    }
    for(int i = 0; i+m <= s.size() ; i++){
        if(s.substr(i,m) == string(m , '1')){
            if((i > 0 && s[i-1] == '1') || (i+m < s.size() && s[i+m] == '1')) continue;
            cnt_1++;
        }
    }
    return cnt_0 == 1 && cnt_1 == 1;
}

void back_track(string s){
    if(s.size() == n){
        if(check(s)){
            res.push_back(s);
        }
        return;
    }
    back_track(s + "0");
    back_track(s + "1");
}

void test_case(){
    res.clear();
    fin >> n >> k >> m;
    back_track("");
    for(auto  &x : res){
        fout << x << "\n";
    }
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