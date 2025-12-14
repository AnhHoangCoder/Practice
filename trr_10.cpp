//Bài toán cái túi

#include <iostream>
#include <fstream>

using namespace std;

#define Max 100

int A[Max] , C[Max];
int XOPT[Max] , X[Max];
int n , b;
float W , FOPT = -32000 , g , weight = 0;

ifstream fin("input.txt");
ofstream fout("output.txt");

inline void nhap(int A[]){
    for(int i = 1 ; i <= n ; i++){
        fin >> A[i];
    }
}

inline void xuat(int A[]){
    for(int i = 1 ; i <= n ; i++){
        fout << A[i] << " ";
    }
    fout << "\n";
}

void Init(){
    fin >> n >> b;
    fout << "So luong do vat: " << n << "\n";
    fout << "Trong luong tui: " << b << "\n";

    fout << "Vector khoi luong cua moi do vat: ";
    nhap(A);
    xuat(A);

    fout << "Vector gia tri su dung cua moi do vat: ";
    nhap(C);
    xuat(C);
}

void result(){
    fout << "Ket qua toi uu: " << FOPT << "\n";
    fout << "Phuong an toi uu: ";
    for(int i = 1 ; i <= n ; i++){
        fout << XOPT[i] << " ";
    }
    fout << "\n";
}

void Update_kyluc(){
    if(g > FOPT){
        FOPT = g;
        for(int i = 1 ; i <= n ; i++){
            XOPT[i] = X[i];
        }
    }
}

void Branch_and_bound(int i){
    int t = (b-weight) / A[i];//Số lượng đồ vật thứ i
    for(int j = t ; j >= 0 ; j--){
        //với mỗi số lượng đồ vật khác nhau thì ta có các kết quả khác nhau
        X[i] = j;
        weight = weight + A[i] * X[i];
        g = g + C[i] * X[i];
        if(i == n){
            Update_kyluc();
        }
        else if(g + C[i+1] * (b - weight) / A[i+1] > FOPT){
            Branch_and_bound(i+1);
        }
        weight = weight - A[i] * X[i];
        g = g - C[i] * X[i];
    }
}

int main(){
    Init();
    Branch_and_bound(1);
    result();
    fin.close();
    fout.close();
    return 0;
}