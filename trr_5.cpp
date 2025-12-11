//Liệt kê các dãy con của An sao cho tổng các phần tử của dãy con đó = k
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n, k;
vector<int> a;
vector<int> res;

ifstream fin("input.txt");
ofstream fout("output.txt");

void back_track(int idx, int sum) {
    // Nếu tổng bằng k, in ra kết quả
    if (sum == k) {
        for (int i = 0; i < res.size(); i++) {
            fout << res[i] << " ";
        }
        fout << "\n";
        return;
    }

    // Nhánh cận: Chỉ áp dụng đúng nếu dãy số toàn số dương
    if (sum > k) {
        return;
    }

    // Duyệt từ idx đến hết
    for (int i = idx; i < n; i++) {
        res.push_back(a[i]);
        // Để đảm bảo phần tử tiếp theo phải nằm sau phần tử a[i]
        back_track(i + 1, sum + a[i]); 
        
        res.pop_back();
    }
}

void test_case() {
    fin >> n >> k;
    a.assign(n, 0);
    res.clear();
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    
    // Mẹo: Nên sort mảng a trước nếu đề bài yêu cầu in theo thứ tự từ điển
    // sort(a.begin(), a.end()); 

    back_track(0, 0);
    fout << "\n";
}

int main() {
    int t;
    if (fin >> t) {
        while(t--){
            test_case();
        }
    }
    fin.close();
    fout.close();
    return 0;
}