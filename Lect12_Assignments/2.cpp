#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Cấu trúc để lưu cạnh
struct Edge {
    int u, v, cost;
};

// So sánh để sắp xếp cạnh theo chi phí tăng dần
bool cmp(const Edge &a, const Edge &b) {
    return a.cost < b.cost;
}

// Cấu trúc Union-Find (DSU) để quản lý tập hợp liên thông
struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return false; // Cùng tập hợp rồi, không nối
        // Union by rank
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

int main() {
    ifstream fin("connection.txt");
    ofstream fout("connection.out");

    int n, m;
    fin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        fin >> edges[i].u >> edges[i].v >> edges[i].cost;
    }

    // Sắp xếp cạnh theo chi phí tăng dần
    sort(edges.begin(), edges.end(), cmp);

    UnionFind uf(n);
    int total_cost = 0;
    vector<Edge> result; // lưu các cạnh được chọn

    for (const auto& e : edges) {
        if (uf.unite(e.u, e.v)) {
            total_cost += e.cost;
            result.push_back(e);
        }
    }

    // In ra tổng chi phí
    fout << total_cost << "\n";
    // In ra các cạnh trong MST
    for (const auto& e : result) {
        fout << e.u << " " << e.v << " " << e.cost << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}
