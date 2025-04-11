#include <iostream>
using namespace std;

// Hàm đệ quy để tìm GCD theo thuật toán Euclid
int gcd(int x, int y) {
    if (y == 0)
        return x;               // Nếu y = 0 thì GCD là x
    else
        return gcd(y, x % y);   // Đệ quy: GCD(x, y) = GCD(y, x % y)
}

int main() {
    int X, Y;
    cin >> X >> Y; // Nhập 2 số nguyên từ bàn phím

    // Đảm bảo GCD luôn là số dương
    int result = gcd(abs(X), abs(Y));

    cout  << result << endl;

    return 0;
}
