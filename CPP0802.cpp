#include <iostream>
#include <fstream>

using namespace std;
using ll = long long;

bool is_num(string s){
    for(char c : s){
        if(!isdigit(c)){
            return false;
        }
    }
    return true;
}

int main(){
    ifstream in("DATA.in");

    string s;
    ll sum = 0;    
    while(in >> s){
        if(s.size() > 9){
            continue;
        }
        if(is_num(s)){
            sum += stoll(s);
        }
    }
    cout << sum << endl;
    return 0;
}