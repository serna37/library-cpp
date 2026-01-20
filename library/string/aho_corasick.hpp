#pragma once
#include "library/string/trie.hpp"
template <int char_size, int margin>
struct AhoCorasick : Trie<char_size, margin> {
    using Trie<char_size, margin>::nodes;
    vector<int> failure; // 失敗リンク
    vector<int> count;   // そのノードでマッチするパターンの総数
    AhoCorasick() : Trie<char_size, margin>() {}
    // 失敗リンクの構築と遷移関数の最適化
    void build() {
        int n = (int)nodes.size();
        failure.assign(n, 0);
        count.assign(n, 0);
        for (int i = 0; i < n; i++) {
            count[i] = (int)nodes[i].accept.size();
        }
        queue<int> que;
        for (int i = 0; i < char_size; i++) {
            if (nodes[0].nxt[i] != -1) {
                que.push(nodes[0].nxt[i]);
            } else {
                nodes[0].nxt[i] = 0;
            }
        }
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            for (int i = 0; i < char_size; i++) {
                int &next_node = nodes[now].nxt[i];
                int fail_link = nodes[failure[now]].nxt[i];
                if (next_node != -1) {
                    failure[next_node] = fail_link;
                    count[next_node] += count[fail_link];
                    que.push(next_node);
                } else {
                    next_node = fail_link;
                }
            }
        }
    }
    // 次の状態へ遷移
    int next(int now, char c) const { return nodes[now].nxt[c - margin]; }
    // 文字列全体を走査して総ヒット数を返す
    long long count_all(const string &s) const {
        long long res = 0;
        int now = 0;
        for (char c : s) {
            now = next(now, c);
            res += count[now];
        }
        return res;
    }
};
