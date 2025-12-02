#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

//ta có 8 hướng di chuyển
vector<pair<int , int>> d = { {0 , -1} , {-1 , -1} , {-1 , 0} ,
{-1 , 1} , {0 , 1} , {1 , 1} , {1 , 0} , {1 , -1} };

void test_case(){
    int n,m;
    in >> n >> m;
    vector<vector<char>> a(n , vector<char> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            in >> a[i][j];
        }
    }

    vector<vector<bool>> used(n , vector<bool> (m , false));
    queue<pair<int , int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i == 0 || i == n-1 || j == 0 || j == m-1){
                if(a[i][j] == 'O'){
                    q.push({i , j});
                    used[i][j] = true;
                }
            }
        }
    }

    while(!q.empty()){
        auto [x , y] = q.front();
        q.pop();
        for(auto [i ,j] : d){
            int nx = x + i;
            int ny = y + j;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(!used[nx][ny] && a[nx][ny] == 'O'){
                    q.push({nx , ny});
                    used[nx][ny] = true;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!used[i][j] && a[i][j] == 'O'){
                a[i][j] = 'X';
            }
            out << a[i][j] << " ";
        }
        out << "\n";
    }
}

int main(){
    int t;
    in >> t;
    while(t--){
        test_case();        
    }
    return 0;
}