#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X; // Đọc số phần tử và tổng cần tìm

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i]; // Đọc danh sách tuổi
    }

    vector<bool> dp(X + 1, false); // dp[s] = true nếu có tổng s
    dp[0] = true; // Tổng 0 luôn tạo được (tập rỗng)

    // Duyệt từng phần tử trong danh sách
    for (int i = 0; i < n; i++) {
        // Duyệt ngược để không dùng một phần tử nhiều lần
        for (int j = X; j >= A[i]; j--) {
            if (dp[j - A[i]]) {
                dp[j] = true;
            }
        }
    }

    // Kiểm tra xem có tạo được tổng X không
    if (dp[X]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
