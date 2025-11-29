#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int Max_S(vector<int> &h){
    int n = h.size();
    int max_area = 0;
    stack<int> st;
    for(int i = 0; i <= n ; i++){
        int height = (i == n) ? 0 : h[i];
        while(!st.empty() && height < h[st.top()]){
            int top = st.top();
            st.pop();

            int width = st.empty() ? i : i - st.top() - 1;
            max_area = max(max_area , h[top] * width);
        }
        st.push(i);
    }
    return max_area;
}

void test_case(){
    int n,m;
    in >> n >> m;
    vector<vector<int>> a(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            in >> a[i][j];
        }
    }

    vector<int> height(m);
    int Max_vl = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == 1){
                height[j]++;
            }
            else{
                height[j] = 0;
            }
        }
        Max_vl = max(Max_vl , Max_S(height));
    }
    out << Max_vl << "\n";
}

int main(){
    int t;
    in >> t;
    while(t--){
        test_case();
    }
    return 0;
}