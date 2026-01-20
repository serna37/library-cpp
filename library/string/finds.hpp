#pragma once
#include "library/string/rolling_hash.hpp"
#include "library/string/aho_corasick.hpp"
// 統合検索エンジン：戻り値を map<検索単語, 出現インデックスのリスト> で返却
map<string, vector<int>> finds(const string &T,
                               const vector<string> &patterns) {
    map<string, vector<int>> res_map;
    if (patterns.empty() || T.empty()) return res_map;
    // 1. パターンが1つだけで、かつ短い場合（ナイーブ）
    if (patterns.size() == 1 && patterns[0].size() < 10) {
        const string &S = patterns[0];
        size_t p = T.find(S);
        while (p != string::npos) {
            res_map[S].push_back((int)p);
            p = T.find(S, p + 1);
        }
        return res_map;
    }
    // 2. パターンが1つだけだが、長い場合（Rolling Hash）
    if (patterns.size() == 1) {
        vector<int> res;
        string P = patterns[0];
        int t = (int)T.size(), p = (int)P.size();
        if (p <= t) {
            RollingHash rht(T);
            RollingHash rhp(P);
            long long hash_p = rhp.get(0, p);
            for (int i = 0; i <= t - p; ++i) {
                if (rht.get(i, i + p) == hash_p) res.emplace_back(i);
            }
        }
        res_map[patterns[0]] = res;
        return res_map;
    }
    // 3. パターンが複数ある場合（Aho-Corasick）
    AhoCorasick<128, 0> ac;
    for (int i = 0; i < (int)patterns.size(); ++i) {
        if (patterns[i].empty()) continue;
        ac.add(patterns[i], i);
        res_map
            [patterns
                 [i]]; // ヒットしなかった単語もキーとして存在させる場合はここで初期化
    }
    ac.build();
    int now = 0;
    for (int i = 0; i < (int)T.size(); ++i) {
        now = ac.next(now, T[i]);
        int temp = now;
        while (temp > 0 && ac.count[temp] > 0) {
            for (int id : ac.nodes[temp].accept) {
                res_map[patterns[id]].push_back(i - (int)patterns[id].size() +
                                                1);
            }
            temp = ac.failure[temp];
        }
    }
    return res_map;
}
