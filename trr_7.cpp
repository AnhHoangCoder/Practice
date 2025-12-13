//Giải bài toán n quân hậu sao cho chúng ko ăn đc nhau

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n  , cnt;

vector<bool> used_col;
vector<bool> used_main;
vector<bool> used_sub;

vector<int> pos;

void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            fout << (pos[i] == j ? "Q " : ". ");
        }
        fout << "\n";
    }
    fout << "\n";
}

void back_track(int row){
    if(row > n){
        //đặt đủ n quân hậu
        cnt++;
        print();
        return;
    }

    for(int col = 1 ; col <= n ; col++){
        if(!used_col[col] && !used_main[row+col] && !used_sub[row-col+n]){
            pos[row] = col;
            used_col[col] = true;
            used_main[row+col] = true;
            used_sub[row-col+n] = true;

            back_track(row+1);

            used_col[col] = false;
            used_main[row+col] = false;
            used_sub[row-col+n] = false;
        }
    }
}

void test_case(){
    fin >> n;
    cnt = 0;
    used_col.assign(n+1 , false);
    used_main.assign(2*n+1 , false);
    used_sub.assign(2*n+1 , false);
    pos.assign(n+1 , 0);

    back_track(1);
    if(cnt == 0){
        fout << "No Solution\n";
    }
    fout << "\n";
}

int main(){
    int t;
    fin >> t;
    while(t--){
        test_case();
    }
    return 0;
}