#pragma once
/**
 * @brief UnionFind 素集合データ構造
 */
struct UnionFind {
  private:
    vector<int> parent, size;

  public:
    UnionFind(int N) {
        parent.assign(N, -1);
        size.assign(N, 1);
    }
    int operator[](int p) {
        return size[find(p)];
    }
    int find(int p) {
        return !~parent[p] ? p : (parent[p] = find(parent[p]));
    }
    bool unite(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (size[x] > size[y]) swap(x, y);
        parent[x] = y, size[y] += size[x];
        return true;
    }
};
