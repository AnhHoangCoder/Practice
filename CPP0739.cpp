#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

void test_case(ifstream &in , ofstream &out){
    string s;
    in >> s;
    int n = s.size();
    stack<int> st;
    for(int i=0;i<=n;i++){
        st.push(i+1);
        if(s[i] == 'I' || i == n){
            while(!st.empty()){
                out << st.top();
                st.pop();
            }
        }
    }
    out << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream in("input.txt");
    ofstream out("output.txt");

    int t;
    in >> t;
    while(t--){
        test_case(in , out);
    }
    in.close();
    out.close();
    return 0;
}