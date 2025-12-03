#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

ifstream in("input.txt");
ofstream out("ouput.txt");

void test_case(){
    string s;
    in >> s;
    int n = s.size();
    unordered_set<char> unique_chars(s.begin() , s.end());
    int total = unique_chars.size();

    unordered_map<char , int> cnt;
    int left = 0 , right = 0 , res = n , have = 0;
    while(right < n){
        cnt[s[right]]++;
        if(cnt[s[right]] == 1) have++;
        
        while(have == total){
            res = min(res , right - left + 1);
            cnt[s[left]]--;
            if(cnt[s[left]] == 0) have--;
            left++;
        }
        right++;
    }
    out << res << "\n";
}

int main(){
    int t;
    in >> t;
    while(t--){
        test_case();
    }
    return 0;
}