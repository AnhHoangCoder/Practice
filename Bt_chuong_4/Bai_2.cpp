//Bài toán người du lịch

#include <iostream>

using namespace std;

#define Max 20

int n;
int B[Max] , C[Max][Max];
int A[Max] , XOPT[Max];
int can , c_min , fopt;

void Read_data(){
    cout << "So thanh pho: "; cin >> n;
    cout << "Ma tran chi phi: " << endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> C[i][j];
        }
    }
}

int Min_matrix(){
    int Min = 1000;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i != j && Min > C[i][j]){
                Min = C[i][j];
            }
        }
    }
    return Min;
}

void Init(){
    c_min = Min_matrix();
    fopt = 3000 ; can = 0 ; A[1] = 1;
    for(int i=1;i<=n;i++){
        B[i] = 1;
    }
}

void Result(){
    cout << "Hanh trinh toi uu: " << fopt << endl;
    cout << "Hanh trinh: ";
    for(int i=1;i<=n;i++){
        cout << XOPT[i] << " ";
    }
    cout << "1" << endl;
}

void swap(){
    for(int i=1;i<=n;i++){
        XOPT[i] = A[i];
    }
}

void Update_kyluc(){
    int sum = can + C[A[n]][A[1]];
    if(sum > fopt){
        swap();
        fopt = sum;
    }
}

void Try(int i){
    for(int j=2;j<=n;j++){
        if(B[j]){//Tránh trùng lặp
            A[i] = j;
            B[j] = 0;
            can += C[A[i-1]][A[i]];
            if(i == n){
                Update_kyluc();
            }
            else if(can + (n-i+1) * c_min < fopt){
                Try(i+1);
            }
            B[j] = 1; can -= C[A[i-1]][A[i]];
        }
    }
}

int main(){
    Read_data();
    Init();
    Try(2);
    Result();
    return 0;
}