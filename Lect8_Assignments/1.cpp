#include <iostream>
#include <vector>
using namespace std;

// Hàm Quick Sort đơn giản
void quickSort(vector<double> &a, int left, int right) {
    int i = left, j = right;
    double pivot = a[(left + right) / 2]; // chọn phần tử giữa làm pivot

    // Phân chia mảng
    while (i <= j) {
        while (a[i] < pivot) i++;      // tìm phần tử lớn hơn hoặc bằng pivot
        while (a[j] > pivot) j--;      // tìm phần tử nhỏ hơn hoặc bằng pivot
        if (i <= j) {
            swap(a[i], a[j]);          // hoán đổi nếu cần
            i++;
            j--;
        }
    }

    // Gọi đệ quy cho hai phần
    if (left < j) quickSort(a, left, j);
    if (i < right) quickSort(a, i, right);
}

int main() {
    int n;
    cin >> n; // Đọc số lượng phần tử

    vector<double> a(n); // Mảng chứa các số thực

    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Nhập từng số thực
    }

    quickSort(a, 0, n - 1); // Gọi hàm quick sort

    // In kết quả ra, cách nhau bởi dấu cách
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1) cout << " "; // tránh dấu cách cuối dòng
    }

    cout << endl;
    return 0;
}
