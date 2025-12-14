//Bài toán người du lịch

#include <iostream>
#include <fstream>

using namespace std;

#define Max 20

int n , B[Max] , C[Max][Max] , count = 0;
int A[Max] , XOPT[Max];
int g , c_min , fopt;

void Read_data(){
    cin >> n;
    cout << "So thanh pho: " << n << endl;
    cout << "Ma tran chi phi: \n";
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> C[i][j];
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j<= n ; j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

int Min_matrix(){
    int Min = 1000;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(i != j && Min > C[i][j]){
                Min = C[i][j];
            }
        }
    }
    return Min;
}

void Init(){
    c_min = Min_matrix();
    fopt = 32000;
    g = 0; A[1] = 1;
    for(int i = 1 ; i <= n ; i++){
        B[i] = 1;
    }
}

void swap(){
    for(int i = 1 ; i <= n ; i++){
        XOPT[i] = A[i];
    }
}

void Update_kyluc(){
    int sum = g + C[A[n]][A[1]];
    if(sum < fopt){
        swap();
        fopt = sum;
    }
}

void Try(int i){
    for(int j = 2 ; j <= n ; j++){
        if(B[j]){ //tránh chọn trùng thành phố 
            A[i] = j;
            B[j] = 0;
            g = g + C[A[i-1]][A[i]];
            if(i == n) Update_kyluc();
            else if(g + (n-i+1) * c_min < fopt){
                count++;
                Try(i+1);
            }
            B[j] = 1;
            g = g - C[A[i-1]][A[i]];
        }
    }
}

void Result(){
    cout << "Chi phi hanh trinh toi uu: " << fopt << endl;
    cout << "Hanh trinh : " << "\n";
    for(int i = 1 ; i <= n ; i++){
        cout << XOPT[i] << " ";
    }
    cout << "1";
    cout << endl;
}

int main(){
    Read_data();
    Init();
    Try(2);
    Result();
    return 0;
}