#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
#define Max 101

ifstream in("input.txt");
ofstream out("output.txt");

//chéo dưới trái -> trái -> chéo trên trái -> trên
//-> chéo trên phải -> phải -> chéo dưới phải -> dưới
vector<int> dx = {1 , 0 , -1 , -1 , -1 , 0 , 1 , 1};
vector<int> dy = {-1 , -1 , -1 , 0 , 1 , 1 , 1 , 0};

int n,m;
vector<vector<int>> a(Max , vector<int> (Max));
bool check[Max][Max];

void dem(int x , int y){
    check[x][y] = true;
    for(int i=0;i<8;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !check[nx][ny] && a[nx][ny] == 1){
            dem(nx,ny);
        }
    }
}

void test_case(){
    in >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            in >> a[i][j];
        }
    }

    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == 1 && !check[i][j]){
                dem(i,j);
                count++;
            }
        }
    }
    out << count << "\n";
}

int main(){
    int t;
    in >> t;
    while(t--){
        test_case();
    }
    return 0;
}