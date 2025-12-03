#include <iostream>
#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

bool check(string s){
    int sum_chan = 0 , sum_le = 0;
    for(char x : s){
        int num = x - '0';
        if(num % 2 == 0){
            sum_chan += num;
        }
        else{
            sum_le += num;
        }
    }
    if((sum_le - sum_chan) % 11 != 0) return false;
    return true;
}

void test_case(){
    string s;
    in >> s;
    if(check(s)){
        out << "1";
    }
    else{
        out << "0";
    }
    out << "\n";
}

int main(){
    int t;
    in >> t;
    while(t--){
        test_case();
    }
    return 0;
}