#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

//chuyển về vector tính toán cho dễ 
vector<int> to_vector(string &s){
    vector<int> res;
    for(char c : s){
        res.push_back(c - '0');
    }
    return res;
}

bool cmp(vector<int> &a, vector<int> &b){
    if(a.size() != b.size()) return a.size() > b.size();
    for(int i = 0 ; i < a.size() ; i++){
        if(a[i] != b[i]){
            return a[i] > b[i];
        }
    }
    return true;
}

vector<int> subtract(vector<int> a , vector<int> &b){
    int carry = 0;
    int n = a.size() , m = b.size();

    for(int i=0;i<n;i++){
        int idxA = n-1-i;
        int idxB = m-1-i;
        
        int digitB = (idxB >= 0) ? b[idxB] : 0;
        a[idxA] -= b[idxB] + carry;
        
        if(a[idxA] < 0){
            a[idxA] += 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
    }
    //còn dư 0 ở đầu thì xóa bớt đi
    while(a.size() > 1 && a[0] == 0) a.erase(a.begin());
    return a;
}

string operator / (string a , string b){
    vector<int> num = to_vector(a);
    vector<int> demon = to_vector(b);

    string result;
    vector<int> cur;

    for(int digit : num){
        //lấy số từ trái qua phải
        cur.push_back(digit);
        while(cur.size() > 1 && cur[0] == 0) cur.erase(cur.begin());

        int cnt = 0;
        while(cmp(cur , demon)){
            cur = subtract(cur , demon);
            cnt++;
        }
        result += to_string(cnt);
    }
    size_t pos = result.find_first_not_of('0');
    return (pos != string::npos) ?  result.substr(pos) : "0";
}

void test_case(){
    string a , b;
    in >> a >> b;
    out << a / b << "\n";    
}

int main(){
    int t;
    in >> t;
    while(t--){
        test_case();
    }
    return 0;
}