#include <iostream>
#include <deque>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream in("input.txt");
    ofstream out("output.txt");
    int t;
    in >> t;
    in.ignore();
    while(t--){
        string s;
        getline(in , s);

        deque<string> dq;
        stringstream ss(s);
        string tmp;
        
        while(ss >> tmp){
            dq.push_front(tmp);
        }
        for(auto x : dq){
            out << x << " ";
        }
        out << endl;
    }
    in.close();
    out.close();
    return 0;
}