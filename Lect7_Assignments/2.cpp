#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

int main() {
    std::ifstream input("matrix.txt");     // Mở file đầu vào
    std::ofstream output("matrix.out");    // Mở file đầu ra

    int m, n;
    input >> m >> n;                       // Đọc số hàng và số cột

    std::vector<std::vector<int>> matrix(m, std::vector<int>(n));

    // Đọc ma trận từ file
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            input >> matrix[i][j];

    int maxSum = INT_MIN;                  // Lưu tổng lớn nhất
    int finalLeft = 0, finalRight = 0, finalTop = 0, finalBottom = 0;

    // Duyệt qua tất cả các cặp hàng làm top và bottom
    for (int top = 0; top < m; ++top) {
        std::vector<int> temp(n, 0);       // Khởi tạo mảng tạm

        for (int bottom = top; bottom < m; ++bottom) {
            // Cộng dồn các hàng vào mảng temp
            for (int i = 0; i < n; ++i)
                temp[i] += matrix[bottom][i];

            // Áp dụng thuật toán Kadane trên mảng 1D temp https://spacedev.vn/resources/docs/general/algorithm/kadanes-algorithm
            int sum = 0, startCol = 0;
            int localLeft = 0, localRight = 0;
            int localMax = INT_MIN;

            for (int col = 0; col < n; ++col) {
                if (sum <= 0) {
                    sum = temp[col];
                    startCol = col;
                } else {
                    sum += temp[col];
                }

                if (sum > localMax) {
                    localMax = sum;
                    localLeft = startCol;
                    localRight = col;
                }
            }

            // Cập nhật nếu tìm được tổng lớn hơn
            if (localMax > maxSum) {
                maxSum = localMax;
                finalLeft = localLeft;
                finalRight = localRight;
                finalTop = top;
                finalBottom = bottom;
            }
        }
    }

    // Ghi kết quả ra file (chỉ số hàng, cột bắt đầu và kết thúc, tổng)
    // Lưu ý: cộng 1 vì chỉ số trong đề bài bắt đầu từ 1
    output << finalTop + 1 << " "
           << finalLeft + 1 << " "
           << finalBottom + 1 << " "
           << finalRight + 1 << " "
           << maxSum << std::endl;

    input.close();
    output.close();
    return 0;
}
