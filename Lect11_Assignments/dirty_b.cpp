#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    ifstream fin("dirty.txt");
    ofstream fout("dirty.out", ios::app); // Ghi tiếp vào cuối file

    int n, m, s, e;
    fin >> n >> m >> s >> e;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    // Nhập dữ liệu và khởi tạo ma trận khoảng cách
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        fin >> u >> v >> d;
        dist[u][v] = d;
    }

    for (int i = 1; i <= n; ++i)
        dist[i][i] = 0;

    // Floyd-Warshall
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    // Ghi kết quả ra file
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] == INF)
                fout << "INF";
            else
                fout << dist[i][j];
            if (j < n) fout << " ";
        }
        fout << "\n";
    }

    return 0;
}
