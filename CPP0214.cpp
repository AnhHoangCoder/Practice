#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

void test_case(){
    int n , k;
    in >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        in >> a[i];
    }
    
    deque<int> dq;
    for(int i=0;i<k;i++){
        while(!dq.empty() && a[i] >= a[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    out << a[dq.front()] << " ";
    for(int i=k;i<n;i++){
        while(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }

        while(!dq.empty() && a[i] >= a[dq.front()]){
            dq.pop_front();
        }
        dq.push_back(i);
        out << a[dq.front()] << " ";
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