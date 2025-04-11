#include <iostream>
#include <vector>
using namespace std;

// Hàm để in một hoán vị
void printPermutation(const vector<int>& arr) {
    for (int num : arr) {
        cout << num;
    }
    cout << endl;
}

// Hàm đệ quy sinh tất cả hoán vị
void generatePermutations(vector<int>& arr, int l, int r) {
    if (l == r) {
        printPermutation(arr); // In ra hoán vị nếu đã cố định hết
    } else {
        for (int i = l; i <= r; ++i) {
            swap(arr[l], arr[i]); // Hoán đổi để cố định vị trí l
            generatePermutations(arr, l + 1, r); // Đệ quy phần còn lại
            swap(arr[l], arr[i]); // Hoàn tác hoán đổi để backtrack
        }
    }
}

int main() {
    int n;
    cin >> n; // Nhập từ bàn phím

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        arr[i] = i + 1; // Tạo mảng từ 1 đến n

    generatePermutations(arr, 0, n - 1); // Gọi hàm sinh hoán vị

    return 0;
}