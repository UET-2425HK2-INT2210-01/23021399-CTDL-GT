#include <iostream>
#include <vector>

using namespace std;

// Hàm duyệt DFS từ một đỉnh
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true; // Đánh dấu đã thăm đỉnh này
    for (int neighbor : adj[node]) { // Duyệt tất cả các đỉnh kề
        if (!visited[neighbor]) { // Nếu đỉnh kề chưa được thăm
            dfs(neighbor, adj, visited); // Gọi đệ quy DFS
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; // Nhập số đỉnh và số cạnh

    // Tạo danh sách kề (adjacency list)
    vector<vector<int>> adj(n + 1); // Mảng từ 1 đến n
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y; // Nhập cạnh nối giữa x và y
        adj[x].push_back(y); // Thêm y vào danh sách kề của x
        adj[y].push_back(x); // Thêm x vào danh sách kề của y (vì đồ thị vô hướng)
    }

    vector<bool> visited(n + 1, false); // Mảng đánh dấu các đỉnh đã thăm
    int components = 0; // Biến đếm số thành phần liên thông

    // Duyệt qua tất cả các đỉnh
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) { // Nếu đỉnh chưa được thăm
            dfs(i, adj, visited); // Bắt đầu DFS từ đỉnh đó
            components++; // Mỗi lần DFS là tìm thấy một thành phần liên thông
        }
    }

    cout << components << endl; // In ra số thành phần liên thông
    return 0;
}
