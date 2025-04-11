#include <iostream>
using namespace std;

// Hàm đệ quy để sinh tất cả các xâu nhị phân độ dài n
void generateBinary(int n, string prefix) {
    if (n == 0) {
        cout << prefix << endl;  // Nếu đã đủ độ dài thì in ra
    } else {
        generateBinary(n - 1, prefix + "0"); // Thêm '0' vào chuỗi
        generateBinary(n - 1, prefix + "1"); // Thêm '1' vào chuỗi
    }
}

int main() {
    int n;
    cin >> n; // Nhập độ dài từ bàn phím

    generateBinary(n, ""); // Bắt đầu với chuỗi rỗng

    return 0;
}
