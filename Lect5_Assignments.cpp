#include <iostream
#include <vector>
#include <algorithm>
#include <unordered_map> // Thư viện ánh xạ không theo thứ tự
using namespace std;

class TreeNode { // Định nghĩa lớp TreeNode đại diện cho mỗi nút trong cây
public:
    int value; // Giá trị của nút
    vector<TreeNode*> children; // Danh sách con của nút hiện tại
    TreeNode(int val) : value(val) {} // Hàm khởi tạo với giá trị đầu vào
};

class Tree { // Định nghĩa lớp Tree quản lý toàn bộ cây
private:
    unordered_map<int, TreeNode*> nodes; // Ánh xạ giá trị nút với con trỏ đến đối tượng TreeNode

public:
    void addEdge(int parent, int child) { // Thêm cạnh vào cây
        if (nodes.find(parent) == nodes.end()) // Nếu nút cha chưa tồn tại thì tạo mới
            nodes[parent] = new TreeNode(parent);
        if (nodes.find(child) == nodes.end()) // Nếu nút con chưa tồn tại thì tạo mới
            nodes[child] = new TreeNode(child);
        nodes[parent]->children.push_back(nodes[child]); // Thêm con vào danh sách con của nút cha
    }

    int calculateHeight(TreeNode* node) { // Tính chiều cao của cây
        if (node->children.empty()) // Nếu không có con trả về 0
            return 0;
        int height = 0;
        for (auto child : node->children) // Duyệt qua các con và tính chiều cao đệ quy
            height = max(height, calculateHeight(child));
        return height + 1; // Trả về chiều cao lớn nhất cộng thêm 1
    }

    void preorder(TreeNode* node) { // Duyệt theo thứ tự trước
        cout << node->value << " "; // In giá trị hiện tại
        for (auto child : node->children) // Duyệt các con
            preorder(child);
    }

    void postorder(TreeNode* node) { // Duyệt theo thứ tự sau
        for (auto child : node->children) // Duyệt các con trước
            postorder(child);
        cout << node->value << " "; // In giá trị hiện tại
    }

    bool isBinaryTree() { // Kiểm tra cây nhị phân
        for (auto& pair : nodes) { // Duyệt qua tất cả các nút
            if (pair.second->children.size() > 2) // Nếu có nhiều hơn 2 con thì không phải cây nhị phân
                return false;
        }
        return true;
    }

    void inorder(TreeNode* node) { // Duyệt theo thứ tự giữa (chỉ với cây nhị phân)
        if (node->children.size() == 1) { // Nếu có một con, duyệt con trước rồi đến nút hiện tại
            inorder(node->children[0]);
            cout << node->value << " ";
        } else if (node->children.size() == 2) { // Nếu có hai con, duyệt con trái, nút hiện tại, con phải
            inorder(node->children[0]);
            cout << node->value << " ";
            inorder(node->children[1]);
        } else { // Nếu không có con nào, in giá trị hiện tại
            cout << node->value << " ";
        }
    }

    TreeNode* getRoot() { return nodes[1]; } // Lấy gốc cây (giả sử nút 1 là gốc)
};

int main() {
    int n, m; // Số lượng nút và cạnh
    cin >> n >> m;
    Tree tree;
    for (int i = 0; i < m; ++i) { // Nhập dữ liệu từ bàn phím
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v); // Thêm cạnh vào cây
    }

    TreeNode* root = tree.getRoot(); // Lấy gốc cây

    cout << tree.calculateHeight(root) << endl; // In chiều cao của cây

    tree.preorder(root); // In thứ tự trước
    cout << endl;

    tree.postorder(root); // In thứ tự sau
    cout << endl;

    if (tree.isBinaryTree()) { // Kiểm tra cây nhị phân
        tree.inorder(root); // In thứ tự giữa nếu là cây nhị phân
        cout << endl;
    } else {
        cout << "NOT BINARY TREE" << endl; // In nếu không phải cây nhị phân
    }

    return 0;
}
