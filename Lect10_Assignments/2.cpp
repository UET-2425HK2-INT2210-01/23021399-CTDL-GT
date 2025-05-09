#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y; // Nhập số đỉnh, số cạnh, đỉnh bắt đầu và đỉnh đích

    vector<vector<int>> adj(n + 1); // Danh sách kề cho đồ thị có hướng

    // Nhập các cạnh
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Đồ thị có hướng: chỉ thêm 1 chiều
    }

    vector<int> dist(n + 1, -1); // Mảng lưu khoảng cách (số cạnh), -1 là chưa thăm

    queue<int> q;
    q.push(X);       // Bắt đầu từ đỉnh X
    dist[X] = 0;      // Khoảng cách từ X đến X là 0

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adj[current]) {
            if (dist[neighbor] == -1) { // Nếu chưa thăm
                dist[neighbor] = dist[current] + 1; // Cập nhật khoảng cách
                q.push(neighbor);
            }
        }
    }

    cout << dist[Y] << endl; // In ra số cạnh từ X đến Y (nếu không đến được thì là -1)

    return 0;
}
