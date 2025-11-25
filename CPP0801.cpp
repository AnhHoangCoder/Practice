#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream in("PTIT.in");
    ofstream out("PTIT.out");
    
    if(!in.is_open()){
        cerr << "Ko the mo file PTIT.in" << endl;
    }

    if(!out.is_open()){
        cerr << "Ko the mo file PTIT.out" << endl;
    }

    string s;
    while(getline(in , s)){
        out << s << endl;
    }

    out << s << endl;
    in.close();
    out.close();
    return 0;
}