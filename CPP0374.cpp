#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

void test_case(){
    string s;
    in >> s;
    int n = s.size();

    vector<int> dp_a(n) , dp_b(n);
    dp_a[0] = (s[0] == 'A') ? 0 : 1;
    dp_b[0] = (s[0] == 'B') ? 0 : 1;

    for(int i = 1 ; i < n ; i++){
        if(s[i] == 'A'){
            dp_a[i] = dp_a[i-1];
            dp_b[i] = min(dp_b[i-1] + 1 , dp_a[i-1] + 1);
        }
        else{
            dp_a[i] = min(dp_b[i-1] + 1 , dp_a[i-1] + 1);
            dp_b[i] = dp_b[i-1];
        }
    }
    out << dp_a[n-1] << "\n";
}

int main(){
    test_case();
    return 0;
}