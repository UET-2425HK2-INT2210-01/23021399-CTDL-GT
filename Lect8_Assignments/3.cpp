#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X; // Số vật và trọng lượng tối đa

    vector<int> weight(n), value(n);

    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i]; // Nhập trọng lượng và giá trị từng vật
    }

    vector<int> dp(X + 1, 0); // dp[j] = giá trị lớn nhất với trọng lượng tối đa j

    for (int i = 0; i < n; i++) {
        for (int j = X; j >= weight[i]; j--) {
            // Cập nhật dp[j]: hoặc không lấy vật i, hoặc lấy vật i
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    // Giá trị lớn nhất có thể mang theo
    cout << dp[X] << endl;

    return 0;
}
