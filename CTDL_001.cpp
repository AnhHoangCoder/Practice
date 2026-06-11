// Một xâu nhị phân độ dài n (n < 10) được gọi là thuận nghịch hay đối xứng nếu đảo ngược xâu nhị phân đó ta vẫn nhận được chính nó. Cho số tự nhiên n (n nhập từ bàn phím). Hãy viết chương trình liệt kê tất cả các xâu nhị phân thuận nghịch có độ dài n.  Hai phần tử khác nhau của xâu thuận nghịch được ghi cách nhau một khoảng trống.

// Ví dụ với n = 4 ta tìm được 4 xâu nhị phân thuận nghịch như dưới đây.

// 0                      0                      0                      0         

// 0                      1                      1                      0         

// 1                      0                      0                      1         

// 1                      1                      1                      1

// Ví dụ

// Input	Output
// 4	
// 0 0 0 0

// 0 1 1 0

// 1 0 0 1

// 1 1 1 1

#include <iostream>

using namespace std;

int n;
int a[10];

bool check(){
    for(int i = 0; i < n/2; i++){
        if(a[i] != a[n-i-1]){
            return false;
        }
    }
    return true;
}

bool sinh(){
    int i = n - 1;
    while(i >= 0 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i < 0) return false;
    a[i]++;
    return true;
}

void testCase(){
    cin >> n;
    for(int i = 0; i < n; i++){
        a[i] = 0;
    }
    do{
        if(check()){
            for(int i = 0; i < n; i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }while(sinh());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--){
        testCase();
    }
    return 0;
}