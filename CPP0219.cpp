#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void test_case(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int> (m));
    
    queue<pair<int , int>> qe;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            if(a[i][j] == 1){
                qe.push({i,j});
            }
        }
    }
    while(!qe.empty()){
        auto [x,y] = qe.front();
        qe.pop();
        for(int i=0;i<n;i++){
            a[i][y] = 1;
            for(int j=0;j<m;j++){
                a[x][j] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}