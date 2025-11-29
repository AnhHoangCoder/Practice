#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

void test_case(ifstream &in , ofstream &out){
    int n , m , x , y , z , t;
    in >> n >> m >> x >> y >> z >> t;
    //các hướng di chuyển là up -> right -> bot -> left
    vector<int> dx = {-1 , 0 , 1 , 0};
    vector<int> dy = {0 , 1 , 0 , -1};

    queue<pair<int,int>> q;    
    vector<vector<int>> a(n,vector<int> (m));
    vector<vector<int>> dist(n,vector<int> (m,-1));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            in >> a[i][j];
        }
    }
    
    if(a[x][y] == 0 || a[z][t] == 0){
        out << "-1" << "\n";
    }

    q.push({x , y});
    //0 là đánh dấu đi qua rồi , -1 là chưa đi qua
    dist[x][y] = 0;
    while(!q.empty()){
        auto [u , v] = q.front();
        q.pop();

        if(u == z && v == t){
            break;
        }
        for(int i=0;i<4;i++){
            int nx = dx[i] + u;
            int ny = dy[i] + v;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(a[nx][ny] == 1 && dist[nx][ny] == -1){
                    dist[nx][ny] = dist[u][v] + 1;
                    q.push({nx , ny});
                }
            }
        }
    }
    out << dist[z][t] << "\n";
}
int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int t;
    in >> t;
    while(t--){
        test_case(in , out);
    }
    return 0;
}