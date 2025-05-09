#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    ifstream fin("dirty.txt");
    ofstream fout("dirty.out");

    int n, m, s, e;
    fin >> n >> m >> s >> e;

    vector<tuple<int, int, int>> edges;
    vector<int> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);

    // Đọc dữ liệu từ file
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        fin >> u >> v >> d;
        edges.emplace_back(u, v, d);
    }

    dist[s] = 0;

    // Bellman-Ford
    for (int i = 1; i <= n - 1; ++i) {
        for (auto [u, v, d] : edges) {
            if (dist[u] < INF && dist[u] + d < dist[v]) {
                dist[v] = dist[u] + d;
                parent[v] = u;
            }
        }
    }

    // Kiểm tra chu trình âm
    for (auto [u, v, d] : edges) {
        if (dist[u] < INF && dist[u] + d < dist[v]) {
            fout << "Negative cycle detected\n";
            return 0;
        }
    }

    // Ghi kết quả ra file
    if (dist[e] == INF) {
        fout << "INF\n";
        fout << "No path\n";
    } else {
        fout << dist[e] << "\n";

        vector<int> path;
        for (int cur = e; cur != -1; cur = parent[cur])
            path.push_back(cur);
        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); ++i) {
            fout << path[i];
            if (i + 1 < path.size()) fout << " ";
        }
        fout << "\n";
    }

    return 0;
}
