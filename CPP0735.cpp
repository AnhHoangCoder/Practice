#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

inline void nhap(vector<vector<int>> &a , int n , int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            in >> a[i][j];
        }
    }
}

int matrix_lv(vector<int> &h){
    int n = h.size();
    int max_size = 0;
    stack<int> st;
    
    for(int i=0;i<=n;i++){
        int height = (i == n) ? 0 : h[i];
        while(!st.empty() && height < h[st.top()]){
            int top = st.top();
            st.pop();

            int width = st.empty() ? i : i - st.top() - 1;
            int size = min(h[top] , width);
            max_size = max(max_size , size);
        }
        st.push(i);
    }
    return max_size;
}

void test_case(){
    int n,m;
    in >> n >> m;
    vector<vector<int>> a(n , vector<int> (m));
    nhap(a,n,m);

    vector<int> height(m);
    int Max_lv = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == 1) height[j]++;
            else height[j] = 0;
        }
        Max_lv = max(Max_lv , matrix_lv(height));
    }
    out << Max_lv << "\n";
}

int main(){
    int t;
    in >> t;
    while(t--){
        test_case();
    }
    return 0;
}