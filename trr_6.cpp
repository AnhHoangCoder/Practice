// Liệt kê tất cả các cách chọn trên mỗi hàng , mỗi cột khác nhau các phần tử
// của ma trận vuông A cấp n sao cho tổng các phần tử đó đúng = k
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n, k;
vector<vector<int>> a;
vector<int> col_indices; // col_indices[i] = j (chọn cột j), = -1 (không chọn)
vector<bool> used_col;

void print_solution() {
    fout << "[ ";
    bool has_element = false;
    for (int i = 0; i < n; i++) {
        if (col_indices[i] != -1) {
            fout << a[i][col_indices[i]] << " ";
            has_element = true;
        }
    }
    if (!has_element && k == 0) fout << "Empty Set "; // Trường hợp k=0 và không chọn gì
    fout << "]" << endl;
}

void back_track(int row, int sum) {
    // Điều kiện dừng: Khi đã xem xét hết tất cả các hàng
    if (row == n) {
        if (sum == k) {
            print_solution();
        }
        return;
    }

    // Lựa chọn 1: Thử chọn một cột j chưa dùng ở hàng hiện tại
    for (int j = 0; j < n; j++) {
        if (!used_col[j]) {
            used_col[j] = true;
            col_indices[row] = j; // Đánh dấu hàng row chọn cột j
            
            back_track(row + 1, sum + a[row][j]);
            
            // Quay lui
            used_col[j] = false;
            col_indices[row] = -1; 
        }
    }

    col_indices[row] = -1;
    back_track(row + 1, sum);
}

void test_case() {
    if (!(fin >> n >> k)) return;
    a.assign(n, vector<int>(n, 0));
    used_col.assign(n, false);
    col_indices.assign(n, -1); // Mặc định ban đầu là không chọn hàng nào

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> a[i][j];
        }
    }

    back_track(0, 0);
    fout << "---------End case----------" << endl;
}

int main() {
    int t;
    if (!(fin >> t)) return 0;
    while (t--) {
        test_case();
    }
    fin.close();
    fout.close();
    return 0;
}