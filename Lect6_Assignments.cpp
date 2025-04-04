1. Given a list of integer numbers: 2, 1, 10, 6, 3, 8, 7, 13, 20.  - 
-Draw the binary search tree 
        2
       / \
      1   10
         /   \
        6     13
       / \      \
      3   8      20
         /
        7
#include <iostream>
using namespace std;

// Định nghĩa cấu trúc một Node trong cây BST
struct Node {
    int data;      // Giá trị của Node
    Node* left;    // Con trỏ đến Node con bên trái
    Node* right;   // Con trỏ đến Node con bên phải

    // Hàm khởi tạo Node mới
    Node(int value) {
        data = value;
        left = right = nullptr;  // Ban đầu chưa có con nào
    }
};

// Hàm chèn một giá trị vào cây BST
Node* insert(Node* root, int value) {
    if (root == nullptr) // Nếu cây rỗng, tạo node mới
        return new Node(value);
    
    if (value < root->data) // Nếu giá trị nhỏ hơn Node gốc, chèn vào bên trái
        root->left = insert(root->left, value);
    else // Nếu giá trị lớn hơn hoặc bằng Node gốc, chèn vào bên phải
        root->right = insert(root->right, value);
    
    return root; // Trả về Node gốc sau khi chèn
}

// Duyệt cây theo thứ tự trung tố (Inorder: Left - Root - Right)
void inorder(Node* root) {
    if (root == nullptr) return; // Nếu cây rỗng thì thoát
    inorder(root->left);  // Duyệt bên trái
    cout << root->data << " "; // In giá trị của Node hiện tại
    inorder(root->right); // Duyệt bên phải
}

// Duyệt cây theo thứ tự tiền tố (Preorder: Root - Left - Right)
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " "; // In giá trị của Node hiện tại trước
    preorder(root->left);  // Duyệt bên trái
    preorder(root->right); // Duyệt bên phải
}

// Duyệt cây theo thứ tự hậu tố (Postorder: Left - Right - Root)
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);  // Duyệt bên trái
    postorder(root->right); // Duyệt bên phải
    cout << root->data << " "; // In giá trị của Node hiện tại sau cùng
}

// Hàm chính
int main() {
    // Mảng các giá trị cần chèn vào BST
    int values[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    int n = sizeof(values) / sizeof(values[0]); // Tính số phần tử trong mảng

    Node* root = nullptr; // Khởi tạo cây rỗng

    // Chèn từng giá trị vào cây BST
    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    // Hiển thị cây theo các kiểu duyệt khác nhau
    cout << "Duyệt trung tố (Inorder): ";
    inorder(root);
    cout << endl;

    cout << "Duyệt tiền tố (Preorder): ";
    preorder(root);
    cout << endl;

    cout << "Duyệt hậu tố (Postorder): ";
    postorder(root);
    cout << endl;

    return 0;
}

-Draw the binary search tree after inserting values:  14, 0, 35 
        2
       / \
      1   10
     /   /   \
    0   6     13
       / \      \
      3   8      14
         /         \
        7           20
                      \
                      35
#include <iostream>  
using namespace std;

// Cấu trúc một Node trong BST
struct Node {
    int data;      // Giá trị của node
    Node* left;    // Con trỏ đến node con trái
    Node* right;   // Con trỏ đến node con phải

    // Hàm khởi tạo một node mới
    Node(int value) {
        data = value;
        left = right = nullptr;  // Ban đầu chưa có con nào
    }
};

// Hàm chèn một giá trị vào BST
Node* insert(Node* root, int value) {
    if (root == nullptr)  // Nếu cây rỗng, tạo node mới
        return new Node(value);
    
    if (value < root->data)  // Nếu giá trị nhỏ hơn node gốc, chèn vào bên trái
        root->left = insert(root->left, value);
    else  // Nếu giá trị lớn hơn hoặc bằng node gốc, chèn vào bên phải
        root->right = insert(root->right, value);
    
    return root;  // Trả về node gốc sau khi chèn
}

// Hàm duyệt cây theo thứ tự trung tố (Inorder: Left - Root - Right)
void inorder(Node* root) {
    if (root == nullptr) return;  // Nếu cây rỗng thì thoát
    inorder(root->left);  // Duyệt cây con bên trái
    cout << root->data << " ";  // In giá trị của node hiện tại
    inorder(root->right);  // Duyệt cây con bên phải
}

// Hàm chính
int main() {
    // Danh sách số cần chèn vào cây BST
    int values[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    int n = sizeof(values) / sizeof(values[0]);  // Số phần tử trong mảng

    Node* root = nullptr;  // Khởi tạo cây rỗng

    // Chèn các phần tử ban đầu vào BST
    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    // Chèn thêm các số mới vào BST
    root = insert(root, 14);
    root = insert(root, 0);
    root = insert(root, 35);

    // Hiển thị cây theo thứ tự Inorder (sẽ in dãy số theo thứ tự tăng dần)
    cout << "Duyệt trung tố (Inorder): ";
    inorder(root);
    cout << endl;

    return 0; 
}

- Draw the binary search tree after deleting: 6, 13, 35 
        2
       / \
      1   10
     /   /   \
    0   7     13
       / \      \
      3   8      14
                 \
                 20
                   \
                   35
#include <iostream>  
using namespace std;

// Cấu trúc một Node trong BST
struct Node {
    int data;      // Giá trị của node
    Node* left;    // Con trỏ đến node con trái
    Node* right;   // Con trỏ đến node con phải

    // Hàm khởi tạo một node mới
    Node(int value) {
        data = value;
        left = right = nullptr;  // Ban đầu chưa có con nào
    }
};

// Hàm chèn một giá trị vào BST
Node* insert(Node* root, int value) {
    if (root == nullptr)  // Nếu cây rỗng, tạo node mới
        return new Node(value);
    
    if (value < root->data)  // Nếu giá trị nhỏ hơn node gốc, chèn vào bên trái
        root->left = insert(root->left, value);
    else  // Nếu giá trị lớn hơn node gốc, chèn vào bên phải
        root->right = insert(root->right, value);
    
    return root;  // Trả về node gốc sau khi chèn
}

// Hàm tìm node có giá trị nhỏ nhất trong cây con bên phải
Node* findMin(Node* root) {
    while (root->left != nullptr)  // Tìm node nhỏ nhất
        root = root->left;
    return root;
}

// Hàm xóa một node khỏi BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;  // Nếu cây rỗng, thoát

    if (key < root->data)  // Nếu giá trị cần xóa nhỏ hơn node hiện tại, tìm bên trái
        root->left = deleteNode(root->left, key);
    else if (key > root->data)  // Nếu lớn hơn, tìm bên phải
        root->right = deleteNode(root->right, key);
    else {
        // Trường hợp 1: Node không có con hoặc chỉ có 1 con
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;  // Giải phóng bộ nhớ
            return temp;  // Trả về cây mới sau khi xóa
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Trường hợp 2: Node có hai con
        Node* temp = findMin(root->right);  // Tìm node nhỏ nhất bên phải
        root->data = temp->data;  // Thay thế giá trị của root bằng node nhỏ nhất
        root->right = deleteNode(root->right, temp->data);  // Xóa node nhỏ nhất
    }
    return root;  // Trả về cây BST sau khi xóa
}

// Hàm duyệt cây theo thứ tự trung tố (Inorder: Left - Root - Right)
void inorder(Node* root) {
    if (root == nullptr) return;  // Nếu cây rỗng thì thoát
    inorder(root->left);  // Duyệt cây con bên trái
    cout << root->data << " ";  // In giá trị của node hiện tại
    inorder(root->right);  // Duyệt cây con bên phải
}

// Hàm chính
int main() {
    // Danh sách số cần chèn vào cây BST
    int values[] = {2, 1, 10, 6, 3, 8, 7, 13, 20, 14, 0, 35};
    int n = sizeof(values) / sizeof(values[0]);  // Số phần tử trong mảng

    Node* root = nullptr;  // Khởi tạo cây rỗng

    // Chèn các phần tử vào BST
    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    // In cây BST trước khi xóa
    cout << "Cây BST trước khi xóa: ";
    inorder(root);
    cout << endl;

    // Xóa các node 6, 13, 35
    root = deleteNode(root, 6);
    root = deleteNode(root, 13);
    root = deleteNode(root, 35);

    // In cây BST sau khi xóa
    cout << "Cây BST sau khi xóa 6, 13, 35: ";
    inorder(root);
    cout << endl;

    return 0; 
}


2. Given a list of integer numbers: 2, 1, 10, 6, 3, 8, 7, 13, 20.  
- Draw the heap tree
          2
        /   \
       1     10
      / \    / \
     6   3  8   7
    / \
   13 20
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// Cấu trúc TreeNode để biểu diễn mỗi nút trong cây heap
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Hàm xây dựng cây nhị phân hoàn chỉnh (cây heap) từ danh sách đã cho
TreeNode* buildHeapTree(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    
    // Tạo nút gốc
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (i < nums.size() && !q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        
        // Gán con trái nếu có
        if (i < nums.size()) {
            current->left = new TreeNode(nums[i++]);
            q.push(current->left);
        }
        
        // Gán con phải nếu có
        if (i < nums.size()) {
            current->right = new TreeNode(nums[i++]);
            q.push(current->right);
        }
    }
    
    return root;
}

// Hàm hỗ trợ tính chiều cao của cây
int getHeight(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

// Hàm in cây ra màn hình theo cấu trúc trực quan
void printTree(TreeNode* root) {
    if (!root) return;
    
    int height = getHeight(root);
    int spaces = pow(2, height) * 2;
    
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    
    while (!q.empty()) {
        int levelSize = q.size();
        int currentSpaces = spaces / (pow(2, level + 1));
        
        // In khoảng trắng đầu dòng
        for (int i = 0; i < currentSpaces; i++) {
            cout << " ";
        }
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node) {
                cout << node->val;
                
                // Tính toán khoảng cách giữa các nút
                int betweenSpaces = spaces / (pow(2, level));
                for (int j = 0; j < betweenSpaces - to_string(node->val).length(); j++) {
                    cout << " ";
                }
                
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << " ";
                q.push(nullptr);
                q.push(nullptr);
            }
        }
        
        cout << endl;
        level++;
        if (level == height) break;
    }
}

int main() {
    vector<int> nums = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    
    // Xây dựng cây heap
    TreeNode* root = buildHeapTree(nums);
    
    // In cấu trúc cây ra màn hình
    cout << "Cấu trúc cây heap:" << endl;
    printTree(root);
    
    return 0;
}

-Draw the heap tree after inserting values:  14, 0, 35
            0
          /   \
         2     10
        / \    / \
       6   1  8   7
      / \  / \  /
     13 20 14 3 35
#include <iostream>
#include <vector>
using namespace std;

void heapifyUp(vector<int>& heap, int index) {
    int parent = (index - 1) / 2;  // Tính chỉ số của phần tử cha
    if (parent >= 0 && heap[index] < heap[parent]) {  // Kiểm tra nếu phần tử con nhỏ hơn phần tử cha
        swap(heap[index], heap[parent]);  // Hoán đổi phần tử con và phần tử cha
        heapifyUp(heap, parent);  // Gọi đệ quy để tiếp tục so sánh với phần tử cha mới
    }
}

void insertIntoMinHeap(vector<int>& heap, int val) {
    heap.push_back(val);  // Bước 1: Thêm phần tử vào cuối heap
    heapifyUp(heap, heap.size() - 1);  // Bước 2: Đảm bảo tính chất của heap bằng cách gọi heapify-up
}

int main() {
    vector<int> heap = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    
    // Chèn các giá trị 14, 0, 35 vào heap
    insertIntoMinHeap(heap, 14);
    insertIntoMinHeap(heap, 0);
    insertIntoMinHeap(heap, 35);
    
    // In ra các giá trị trong heap
    for (int num : heap) cout << num << " ";
    return 0;
}

- Draw the heap tree after deleting: 6, 13, 35 
            0
          /   \
         2     7
        / \    / \
       3   1  10  8
      / \  
     14 20 

#include <iostream>
#include <vector>
using namespace std;

void heapifyDown(vector<int>& heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;  // Chỉ số của con trái
    int right = 2 * index + 2; // Chỉ số của con phải

    if (left < heap.size() && heap[left] < heap[smallest])  // Kiểm tra nếu con trái nhỏ hơn
        smallest = left;
    if (right < heap.size() && heap[right] < heap[smallest])  // Kiểm tra nếu con phải nhỏ hơn
        smallest = right;

    if (smallest != index) {  // Nếu phần tử nhỏ nhất không phải là phần tử gốc
        swap(heap[index], heap[smallest]);  // Hoán đổi với phần tử nhỏ nhất
        heapifyDown(heap, smallest);  // Gọi đệ quy để tiếp tục kiểm tra với phần tử đã hoán đổi
    }
}


void deleteFromMinHeap(vector<int>& heap, int val) {
    auto it = find(heap.begin(), heap.end(), val);  // Tìm phần tử cần xóa
    if (it == heap.end()) return;  // Nếu không tìm thấy phần tử cần xóa, trả về

    int index = it - heap.begin();  // Tính chỉ số của phần tử cần xóa
    heap[index] = heap.back();  // Thay thế phần tử cần xóa bằng phần tử cuối cùng
    heap.pop_back();            // Loại bỏ phần tử cuối cùng
    heapifyDown(heap, index);   // Gọi heapifyDown để duy trì tính chất của min-heap
}

int main() {
    vector<int> heap = {0, 2, 7, 6, 1, 10, 8, 13, 20, 14, 3, 35};

    // Xóa các giá trị 6, 13, 35 khỏi heap
    deleteFromMinHeap(heap, 6);
    deleteFromMinHeap(heap, 13);
    deleteFromMinHeap(heap, 35);

    // In ra các giá trị trong heap
    for (int num : heap) cout << num << " ";
    return 0;
}
