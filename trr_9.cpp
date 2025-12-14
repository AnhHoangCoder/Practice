#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
    vector<int> value  = {4, 6, 3, 5, 2};
    vector<int> weight = {9, 8, 5, 3, 2};

    int W = 21;
    int best_value = 0;
    int best_mask = 0;

    for(int mask = 0; mask < (1 << 5); mask++){
        int sum_W = 0, sum_V = 0;

        for(int i = 0; i < 5; i++){
            if(mask & (1 << i)){
                sum_W += weight[i];
                sum_V += value[i];
            }
        }

        if(sum_W <= W && sum_V > best_value){
            best_value = sum_V;
            best_mask = mask;
        }
    }

    fout << "Gia tri lon nhat: " << best_value << "\n";
    fout << "Phuong an toi uu:\n";

    for(int i = 0; i < 5; i++){
        fout << "x" << i + 1 << " = " << ((best_mask >> i) & 1) << "\n";
    }

    return 0;
}
