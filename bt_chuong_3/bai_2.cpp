#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n , b , cnt;
vector<int> a;
vector<int> x;

//dùng kỹ thuật quay lui
void back_track(int i , int sum){
    int max_xi = (b-sum) / a[i];

    for(int xi = 0 ; xi <= max_xi ; xi++){
        x[i] = xi;
        int new_sum = sum + a[i] * xi;

        if(i == n){
            if(new_sum == b){
                cnt++;
                for(int j = 1 ; j <= n ; j++){
                    fout << x[j] << " , ";
                }
                fout << "\n";
            }
        }
        else{
            back_track(i+1 , new_sum);
        }
    }
}

int main(){
    cnt = 0;
    fin >> n;
    a.resize(n+1);
    x.resize(n+1);

    for(int i=1;i<=n;i++){
        fin >> a[i];
    }
    fin >> b;
    back_track(1 , 0);
    if(cnt == 0){
        fout << "No value" << "\n";
    }
    return 0;
}
