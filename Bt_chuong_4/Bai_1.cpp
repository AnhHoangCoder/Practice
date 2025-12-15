//Bài toán cái túi

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// //Kỹ thuật duyệt toàn bộ
// int main(){
//     int n,b;
//     cout << "So luong do vat: ";
//     cin >> n;
//     cout << "Trong luong tui: ";
//     cin >> b;

//     vector<int> value(n);
//     vector<int> weight(n);
    
//     cout << "Nhap khoi luong va gia tri (W V): " << "\n";
//     for(int i=0;i<n;i++){
//         cout << "Do vat " << i+1 << ": ";
//         cin >> weight[i] >> value[i];
//     }

//     int fopt = 0 , best_mask = 0;
    
//     for(int mask=0 ; mask < (1 << n) ; mask++){
//         int sum_v = 0 , sum_w = 0;
//         for(int i=0 ; i < n ; i++){
//             if(mask & (1 << i)){
//                 sum_w += weight[i];
//                 sum_v += value[i];
//             }
//         }
//         if(sum_w <= b && sum_v > fopt){
//             fopt = sum_v;
//             best_mask = mask;       
//         }
//     }

//     cout << "Ket qua toi uu: " << fopt << "\n";
//     cout << "Phuong an toi uu: ";
//     for(int i=0;i<n;i++){
//         cout << "x" << i+1 << " = " << ((best_mask >> i) & 1) << "; ";  
//     }
//     cout << "\n";
//     return 0;
// }


//Kỹ thuật nhánh cận

int n , b;
struct Item{
    int A , C;
    int id;       // <--- SỬA: Thêm biến lưu vị trí ban đầu
    double ratio;
};

vector<Item> item;

float fopt = 0;
int g = 0 , weight = 0;
vector<int> X;
vector<int> XOPT;

// Hàm tính cận (Upper Bound)
float calc_bound(int i){
    int w = weight;
    float val = g;

    for(int j = i; j <= n; j++){
        if(w + item[j].A <= b){
            w += item[j].A;
            val += item[j].C;
        }
        else{
            val += 1.0 * item[j].C * (b - w) / item[j].A;
            break;
        }
    }
    return val;
}

void branch_and_bound(int i){
    for(int j = 1 ; j >= 0 ; j--){   // Thử chọn (1) trước, không chọn (0) sau
        X[i] = j;
        weight += item[i].A * j;
        g += item[i].C * j;

        if(weight <= b){
            if(i == n){
                if(g > fopt){
                    fopt = g;
                    XOPT = X; // XOPT này đang lưu theo thứ tự ĐÃ SORT
                }
            }
            else{
                float bound = calc_bound(i+1);
                if(bound > fopt) // Cắt tỉa nhánh cận
                    branch_and_bound(i+1);
            }
        }

        // Backtrack
        weight -= item[i].A * j;
        g -= item[i].C * j;
    }
}

int main(){
    cout << "So luong do vat: "; cin >> n;
    cout << "Trong luong tui: "; cin >> b;

    item.resize(n+1);

    cout << "Nhap khoi luong va gia tri (W V):\n";
    for(int i=1;i<=n;i++){
        cout << "Do vat " << i << ": ";
        cin >> item[i].A >> item[i].C;
        item[i].id = i;
    }

    X.resize(n+1);
    XOPT.resize(n+1);

    for(int i=1;i<=n;i++){
        item[i].ratio = 1.0 * item[i].C / item[i].A;
    }

    // Sắp xếp theo đơn giá giảm dần
    sort(item.begin()+1 , item.end() , [](Item a , Item b){
        return a.ratio > b.ratio;
    });

    branch_and_bound(1);

    cout << "Ket qua toi uu: " << fopt << "\n";
    
    vector<int> final_res(n+1);
    for(int i=1; i<=n; i++){
        // item[i].id là vị trí gốc
        // XOPT[i] là quyết định cho đồ vật đang đứng ở vị trí i (đã sort)
        final_res[item[i].id] = XOPT[i];
    }

    cout << "Phuong an toi uu (theo thu tu nhap vao): ";
    for(int i=1;i<=n;i++){
        cout << final_res[i] << " ";
    }
    cout << "\n";
    return 0;
}