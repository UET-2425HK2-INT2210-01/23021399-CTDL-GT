Bài tập 1: Danh sách liên kết
Viết chương trình cài đặt một danh sách liên kết đơn với các hàm sau:
a. append x: Chèn một phần tử x vào cuối danh sách.
b. search x: Tìm vị trí đầu tiên của phần tử x trong danh sách, in ra vị trí đó, nếu không tìm thấy in "NO".
c. reverse: Đảo ngược danh sách liên kết.
Chương trình nhận đầu vào gồm số nguyên n là số lần thao tác ở dòng thứ nhất, các dòng sau nhập thao tác theo định dạng bên dưới. Đầu ra in kết quả, các phần tử cách nhau một khoảng trắng. 


#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

void append(int x) {
        Node* newNode = new Node(x); //Tạo một nút mới (newNode)
        if (!head) { //Kiểm tra danh sách có rỗng không (head == nullptr)
            head = newNode; //Nếu danh sách liên kết chưa có phần tử nào (head == nullptr), thì gán head = newNode (nút mới trở thành đầu danh sách).
            return;
        }
        Node* temp = head; //Tạo con trỏ temp để duyệt danh sách từ đầu (head)
        while (temp->next) { //Duyệt đến nút cuối cùng của danh sách 
        }
        temp->next = newNode; //Gán newNode vào cuối danh sách
    }

    void search(int x) { //Khởi tạo con trỏ và biến vị trí
        Node* temp = head; //temp: Con trỏ để duyệt danh sách, bắt đầu từ head.
        int position = 0; //position: Biến đếm vị trí của mỗi phần tử trong danh sách (bắt đầu từ 0).
        while (temp) { // Duyệt danh sách liên kết
            if (temp->data == x) { //Kiểm tra nếu tìm thấy giá trị cần tìm
                cout << position << endl;
                return;
            }
            temp = temp->next; //Di chuyển con trỏ và tăng vị trí
            position++;
        }
        cout << "NO" << endl; // Nếu không tìm thấy phần tử
    }

    void reverse() { //Khởi tạo các con trỏ
        Node* prev = nullptr; //prev: Giữ con trỏ đến nút trước của current, ban đầu là nullptr (vì nút đầu danh sách sau khi đảo sẽ trở thành nút cuối).
        Node* current = head; //current: Trỏ đến nút hiện tại, bắt đầu từ head
        Node* next = nullptr; //next: Dùng để lưu trữ nút tiếp theo của current trước khi thay đổi liên kết.
        while (current) { // Duyệt và đảo liên kết từng nút
            next = current->next; //Lưu next để không mất dấu phần còn lại của danh sách
            current->next = prev; //Đảo liên kết: current->next trỏ về prev (thay vì trỏ đến next như trước).
            prev = current; //Di chuyển prev lên current.
            current = next; //Di chuyển current lên next.
        }
        head = prev; //cập nhật head 
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList linkedList;
    
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "append") {
            int x;
            cin >> x;
            linkedList.append(x);
        } else if (command == "search") {
            int x;
            cin >> x;
            linkedList.search(x);
        } else if (command == "reverse") {
            linkedList.reverse();
        }
    }
    
    linkedList.display();
    return 0;
}

Bài tập 2: Hàng đợi ưu tiên với Doubly Linked List
Viết chương trình cài đặt cấu trúc hàng đợi ưu tiên hỗ trợ hai thao tác:
a. enqueue x p: Thêm phần tử x vào hàng đợi với độ ưu tiên p. Phần tử có độ ưu tiên cao hơn được đặt trước.
b. dequeue: Loại bỏ phần tử có độ ưu tiên cao nhất khỏi hàng đợi.
Chương trình nhận đầu vào gồm số nguyên n là số lần thao tác ở dòng thứ nhất, các dòng sau nhập thao tác theo định dạng bên dưới. Dữ liệu ra in hàng đợi sau khi thao tác, các phần tử in dưới dạng (giá trị, độ ưu tiên).

#include <iostream>

using namespace std;

struct Node {
    int value, priority;
    Node* next;
    Node* prev;
    Node(int v, int p) : value(v), priority(p), next(nullptr), prev(nullptr) {}
};

class PriorityQueue {
private:
    Node* head;
public:
    PriorityQueue() : head(nullptr) {}
    
    void enqueue(int value, int priority) {
        Node* newNode = new Node(value, priority);
        if (!head || head->priority < priority) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->priority >= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            if (temp->next) temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void dequeue() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }

    void printQueue() {
        Node* temp = head;
        while (temp) {
            cout << "(" << temp->value << ", " << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    PriorityQueue pq;
    
    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;
        if (command == "enqueue") {
            int x, p;
            cin >> x >> p;
            pq.enqueue(x, p);
        } else if (command == "dequeue") {
            pq.dequeue();
        }
        pq.printQueue();
    }
    return 0;
}


Bài tập 3: Kiểm tra dãy ngoặc hợp lệ với Stack
Cho một xâu ký tự chỉ gồm các dấu ngoặc: (), [], {}. Hãy kiểm tra xem xâu đó có đặt tính hợp lệ hay không, tức là các dấu ngoặc phải đóng đúng thứ tự. Chươngtrình nhận dữ liệu đầu vào là xâu ký tự chỉ gồm các dấu ngoặc ở dòng 1. Đầu ra, in Valid nếu xâu hợp lệ, ngược lại in Invalid.

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s;
    cin >> s;
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;
    return 0;
}
