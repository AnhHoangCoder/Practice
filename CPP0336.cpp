#include <iostream>
#include <vector>

using namespace std;


void test_case(){
    string s1 , s2;
    cin >> s1 >> s2;
    vector<int> have(256) , need(256);
    
    for(char c : s2){
        need[c]++;
    }

    int s = 0;//có bao nhiêu kí tự trong s2
    for(auto x : need){
        if(x > 0){
            s++;
        }
    }

    int n = s1.size();

    int formed = 0;
    int left = 0 , right = 0;
    int best_len = 1e9 , best_l = 0;
    while(right < n){
        have[s1[right]]++;

        if(need[s1[right]] > 0 && have[s1[right]] == need[s1[right]]){
            formed++;
        }

        while(left <= right && formed == s){
            //cập nhật kết quả mới
            if(right - left + 1 < best_len){
                best_len = right - left + 1;
                best_l = left;
            }
            //thu nhỏ cửa sổ lại
            have[s1[left]]--;
            if(need[s1[left]] > 0 && have[s1[left]] < need[s1[left]]){
                formed--;
            }
            left++;
        }
        right++;
    }
    if(best_len == 1e9){
        cout << "-1" << endl;
    }
    else{
        cout << s1.substr(best_l , best_len) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}