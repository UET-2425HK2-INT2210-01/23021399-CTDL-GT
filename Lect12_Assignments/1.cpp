#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ifstream fin("jobs.txt");  // Mở file input
    ofstream fout("jobs.out"); // Mở file output

    int n, m;
    fin >> n >> m;  // Đọc số lượng công việc và số ràng buộc

    vector<vector<int>> graph(n + 1); // Danh sách kề của đồ thị
    vector<int> indegree(n + 1, 0);  // Mảng đếm bậc vào của mỗi đỉnh

    // Đọc các ràng buộc u phải làm trước v
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        graph[u].push_back(v); // Tạo cạnh từ u đến v
        indegree[v]++;         // Tăng bậc vào của v
    }

    queue<int> q;
    // Thêm các công việc không có ràng buộc (bậc vào = 0) vào hàng đợi
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order; // Mảng lưu thứ tự sắp xếp công việc

    // Thuật toán topological sort (Kahn's algorithm)
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);  // Thêm công việc u vào thứ tự

        // Duyệt các công việc phụ thuộc vào u
        for (int v : graph[u]) {
            indegree[v]--;   // Giảm bậc vào của v
            if (indegree[v] == 0) {
                q.push(v);    // Nếu v không còn phụ thuộc nào thì thêm vào hàng đợi
            }
        }
    }

    // Kiểm tra xem có đủ n công việc được sắp xếp không (không có chu trình)
    if ((int)order.size() == n) {
        for (int job : order) {
            fout << job << " ";
        }
        fout << "\n";
    } else {
        // Nếu không đủ, nghĩa là tồn tại chu trình, không thể sắp xếp hợp lệ
        fout << "No valid job ordering exists.\n";
    }

    fin.close();
    fout.close();

    return 0;
}
