#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main(){
    ifstream in("DATA.in");

    map<string , int> mp;
    string s;
    while(in >> s){
        mp[s]++;
    }
    for(auto x : mp){
        cout << x.first << " " << x.second << endl;
    }
    in.close();
    return 0;
}