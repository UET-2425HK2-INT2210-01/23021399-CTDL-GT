#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream input("numbers.txt");     // Mở tệp đầu vào để đọc
    std::ofstream output("numbers.sorted"); // Mở tệp đầu ra để ghi

    std::vector<double> numbers; // Khai báo vector để lưu các số thực

    double num;
    while (input >> num) {
        numbers.push_back(num); // Đọc từng số thực và thêm vào vector
    }

    std::sort(numbers.begin(), numbers.end()); // Sắp xếp vector theo thứ tự tăng dần

    // Ghi các số đã sắp xếp ra file, mỗi dòng chứa 2 số cách nhau bởi dấu cách
    for (size_t i = 0; i < numbers.size(); i += 2) {
        output << numbers[i];
        if (i + 1 < numbers.size()) {
            output << " " << numbers[i + 1];
        }
        output << std::endl;
    }

    input.close();  // Đóng tệp đầu vào
    output.close(); // Đóng tệp đầu ra

    return 0;
}
