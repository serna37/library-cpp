#pragma once
template <int char_size, int margin> struct Trie {
    struct Node {
        vector<int> nxt;
        vector<int> accept; // その地点で終わる単語のIDリスト
        int exist;          // その地点を接頭辞として持つ単語の数
        Node() : nxt(char_size, -1), exist(0) {}
    };
    vector<Node> nodes;
    Trie() { nodes.emplace_back(); }
    int size() const { return (int)nodes.size(); }
    // 単語の追加
    virtual void add(const string &s, int id = -1) {
        int now = 0;
        for (char c : s) {
            int x = c - margin;
            if (nodes[now].nxt[x] == -1) {
                nodes[now].nxt[x] = (int)nodes.size();
                nodes.emplace_back();
            }
            now = nodes[now].nxt[x];
            nodes[now].exist++;
        }
        if (id != -1) nodes[now].accept.push_back(id);
    }
    // 単一の単語の検索 (完全一致)
    bool search(const string &s) const {
        int now = 0;
        for (char c : s) {
            int x = c - margin;
            if (nodes[now].nxt[x] == -1) return false;
            now = nodes[now].nxt[x];
        }
        return !nodes[now].accept.empty();
    }
    // 接頭辞検索：s を接頭辞として持つ単語の数を返す
    int count_prefix(const string &s) const {
        int now = 0;
        for (char c : s) {
            int x = c - margin;
            if (nodes[now].nxt[x] == -1) return 0;
            now = nodes[now].nxt[x];
        }
        return nodes[now].exist;
    }
};
