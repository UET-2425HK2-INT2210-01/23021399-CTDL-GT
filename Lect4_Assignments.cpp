1. What are two desirable properties of a hash function? (Hai tính chất mong muốn của hàm băm là gì?)

1,Tính chất phân tán tốt (Uniformity - Phân bố đều)
-Hàm băm cần phân tán đầu vào một cách đều đặn trên không gian giá trị đầu ra để tránh va chạm (collision) nhiều nhất có thể.
-Nếu nhiều đầu vào khác nhau có cùng giá trị băm, hệ thống sẽ dễ gặp xung đột, giảm hiệu suất.

2.Tính chất chống va chạm (Collision Resistance - Chống đụng độ)
-Khó tìm thấy hai giá trị đầu vào khác nhau nhưng có cùng giá trị băm.
-Đặc biệt quan trọng trong các ứng dụng bảo mật, như chữ ký số và mã hóa mật khẩu.
*Ngoài ra, trong lĩnh vực bảo mật, một số hàm băm còn cần các tính chất khác như:
-Tính chất một chiều (Preimage Resistance): Không thể dễ dàng tìm được đầu vào từ giá trị băm.
-Tính chất chống tiền ảnh thứ hai (Second Preimage Resistance): Khó tìm được giá trị đầu vào khác có cùng giá trị băm với một đầu vào cụ thể.

2. Draw the 11-entry hash that results from using the hash function h(i) = (2i+5) mod 
11 to hash keys 12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5.  
a) Assume collisions are handled by chaining.  
#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int TABLE_SIZE = 11;

// Hàm băm
int hashFunction(int key) {
    return (2 * key + 5) % TABLE_SIZE;
}

// Lớp HashTable sử dụng phương pháp nối chuỗi (Chaining)
class HashTableChaining {
private:
    vector<list<int>> table;

public:
    HashTableChaining() : table(TABLE_SIZE) {}

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void display() {
        cout << "Bảng băm sử dụng Nối Chuỗi:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (int val : table[i])
                cout << val << " -> ";
            cout << "NULL\n";
        }
    }
};

int main() {
    vector<int> keys = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};

    HashTableChaining chainingTable;
    for (int key : keys) {
        chainingTable.insert(key);
    }
    chainingTable.display();

    return 0;
}

b) Assume collisions are handled by linear probing. 
#include <iostream>
#include <vector>

using namespace std;

const int TABLE_SIZE = 11;

// Hàm băm
int hashFunction(int key) {
    return (2 * key + 5) % TABLE_SIZE;
}

// Lớp HashTable sử dụng phương pháp Thăm Dò Tuyến Tính (Linear Probing)
class HashTableLinearProbing {
private:
    vector<int> table;
    vector<bool> occupied; // Đánh dấu vị trí đã bị chiếm dụng

public:
    HashTableLinearProbing() : table(TABLE_SIZE, -1), occupied(TABLE_SIZE, false) {}

    void insert(int key) {
        int index = hashFunction(key);
        while (occupied[index]) { // Nếu vị trí đã bị chiếm, tìm vị trí tiếp theo
            index = (index + 1) % TABLE_SIZE;
        }
        table[index] = key;
        occupied[index] = true;
    }

    void display() {
        cout << "Bảng băm sử dụng Thăm Dò Tuyến Tính:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            if (occupied[i])
                cout << table[i] << "\n";
            else
                cout << "NULL\n";
        }
    }
};

int main() {
    vector<int> keys = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};

    HashTableLinearProbing linearTable;
    for (int key : keys) {
        linearTable.insert(key);
    }
    linearTable.display();

    return 0;
}

3. Draw the 17-entry hash that results from using the hash function h(i) = (i+3) mod 
17 to hash keys 1, 3, 18, 8, 23, 35, 11, 36, 20, 16.  
c) Assume collisions are handled by chaining.  
#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int TABLE_SIZE = 17;

// Hàm băm
int hashFunction(int key) {
    return (key + 3) % TABLE_SIZE;
}

// Lớp HashTable sử dụng phương pháp nối chuỗi (Chaining)
class HashTableChaining {
private:
    vector<list<int>> table;

public:
    HashTableChaining() : table(TABLE_SIZE) {}

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void display() {
        cout << "Bảng băm sử dụng Nối Chuỗi:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (int val : table[i])
                cout << val << " -> ";
            cout << "NULL\n";
        }
    }
};

int main() {
    vector<int> keys = {1, 3, 18, 8, 23, 35, 11, 36, 20, 16};

    HashTableChaining chainingTable;
    for (int key : keys) {
        chainingTable.insert(key);
    }
    chainingTable.display();

    return 0;
}
d) Assume collisions are handled by linear probing.  
#include <iostream>
#include <vector>

using namespace std;

const int TABLE_SIZE = 17;

// Hàm băm
int hashFunction(int key) {
    return (key + 3) % TABLE_SIZE;
}

// Lớp HashTable sử dụng phương pháp Thăm Dò Tuyến Tính (Linear Probing)
class HashTableLinearProbing {
private:
    vector<int> table;
    vector<bool> occupied; // Đánh dấu vị trí đã bị chiếm dụng

public:
    HashTableLinearProbing() : table(TABLE_SIZE, -1), occupied(TABLE_SIZE, false) {}

    void insert(int key) {
        int index = hashFunction(key);
        while (occupied[index]) { // Nếu vị trí đã bị chiếm, tìm vị trí tiếp theo
            index = (index + 1) % TABLE_SIZE;
        }
        table[index] = key;
        occupied[index] = true;
    }

    void display() {
        cout << "Bảng băm sử dụng Thăm Dò Tuyến Tính:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            if (occupied[i])
                cout << table[i] << "\n";
            else
                cout << "NULL\n";
        }
    }
};

int main() {
    vector<int> keys = {1, 3, 18, 8, 23, 35, 11, 36, 20, 16};

    HashTableLinearProbing linearTable;
    for (int key : keys) {
        linearTable.insert(key);
    }
    linearTable.display();

    return 0;
}

4. A student has following information: 
● ID: An unique integer number  
● Name:  a string of at most 100 characters 
● Class: a string of at most 30 characters 
Your task is to write a program to manage students for your university with follow 
operations: 
● Insert (ID, Name, Class): Insert a student into the list 
● Delete (ID): Delete student ID from the list 
● Infor (ID):  Return the Name and Class of student ID separated by a 
comma. If the student is not exist, return string ‘NA,NA’ 
Input: Operations come from keyboard. Each operation is in one line. 
Output: Write to the screen the results from calling infor(ID) operations. 

#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

// Cấu trúc lưu thông tin sinh viên
struct Student {
    string name;
    string className;
};

// Lớp quản lý danh sách sinh viên
class StudentManager {
private:
    unordered_map<int, Student> students;

public:
    // Thêm sinh viên
    void insert(int id, const string &name, const string &className) {
        students[id] = {name, className};
    }

    // Xóa sinh viên theo ID
    void remove(int id) {
        students.erase(id);
    }

    // Lấy thông tin sinh viên theo ID
    string infor(int id) {
        if (students.find(id) != students.end()) {
            return students[id].name + "," + students[id].className;
        }
        return "NA,NA";
    }
};

int main() {
    StudentManager manager;
    string command;

    while (getline(cin, command)) {
        if (command.empty()) continue; // Bỏ qua dòng trống

        // Xử lý đầu vào
        size_t openParen = command.find('(');
        size_t closeParen = command.find(')');

        if (openParen == string::npos || closeParen == string::npos) continue;

        string operation = command.substr(0, openParen);
        string params = command.substr(openParen + 1, closeParen - openParen - 1);

        stringstream ss(params);
        if (operation == "Insert") {
            int id;
            string name, className;
            getline(ss, name, ','); // Đọc ID đầu tiên dưới dạng chuỗi
            id = stoi(name);
            getline(ss, name, ','); // Đọc tên sinh viên
            getline(ss, className); // Đọc lớp

            manager.insert(id, name, className);
        } 
        else if (operation == "Delete") {
            int id;
            ss >> id;
            manager.remove(id);
        } 
        else if (operation == "Infor") {
            int id;
            ss >> id;
            cout << manager.infor(id) << endl;
        }
    }

    return 0;
}
