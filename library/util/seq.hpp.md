---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: main.cpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u0E05^>\u03C9<^\u0E05"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/template.test.cpp
    title: tests/template.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/util/seq.hpp\"\nauto len = []<class T>(vector<T>\
    \ &v) { return (int)v.size(); };\ntemplate <typename T> T min(vector<T> &v) {\n\
    \    return *min_element(all(v));\n}\ntemplate <typename T> T max(vector<T> &v)\
    \ {\n    return *max_element(all(v));\n}\nauto sum = [](vector<long long> &v)\
    \ { return accumulate(all(v), 0ll); };\nauto allMatch = []<class T, class F>(vector<T>\
    \ &v, F f) {\n    return all_of(all(v), f);\n};\nauto noneMatch = []<class T,\
    \ class F>(vector<T> &v, F f) {\n    return none_of(all(v), f);\n};\nauto anyMatch\
    \ = []<class T, class F>(vector<T> &v, F f) {\n    return any_of(all(v), f);\n\
    };\nauto sort_asc = []<class T>(vector<T> &v) { sort(all(v)); };\nauto sort_desc\
    \ = []<class T>(vector<T> &v) { sort(rall(v)); };\ntemplate <typename T> void\
    \ reverse(vector<T> &v) {\n    reverse(all(v));\n}\nauto distinct = []<class T>(vector<T>\
    \ &v) {\n    sort(all(v));\n    v.erase(unique(all(v)), v.end());\n};\n// set\u304B\
    \u3089\u8981\u7D20\u524A\u9664\ntemplate <typename T> void erase(set<T> &st, T\
    \ &v) {\n    st.erase(st.find(v));\n}\n// multiset\u304B\u3089\u8981\u7D20\u524A\
    \u9664\ntemplate <typename T> void erase(multiset<T> &st, T &v) {\n    st.erase(st.find(v));\n\
    }\n// \u884C\u5217\u306E\u8EE2\u7F6E\nauto transpose = []<class T>(vector<vector<T>>\
    \ &G) {\n    int H = G.size(), W = G[0].size();\n    vector<vector<T>> _G(W, vector<T>(H));\n\
    \    for (int i = 0; i < H; ++i) {\n        for (int j = 0; j < W; ++j) {\n  \
    \          _G[j][i] = G[i][j];\n        }\n    }\n    return _G;\n};\n/**\n *\
    \ \u5206\u5272\u4EE3\u5165\u3067\u304D\u308B\u3088\u3046\u306B\u3059\u308B\n *\
    \ G\u306F\u7834\u58CA\u3002\n * auto [a,b] = unpack<2>(move(G));\n */\ntemplate\
    \ <int N, typename T> auto unpack(vector<T> &&G) {\n    array<T, N> res; // vector\
    \ -> array\u5909\u63DB\u3059\u308B\u3060\u3051\n    for (int i = 0; i < N; ++i)\
    \ res[i] = move(G[i]);\n    return res;\n}\n// TODO \u30DE\u30FC\u30B8\u30C6\u30AF\
    \n// \u6570\u76F4\u7DDA\u4E0A\u3067\u306E\u500B\u6570\u306B\u306A\u304A\u3059\n\
    vector<int> coordinate(vector<int> &A) {\n    vector<int> res(MAX);\n    for (auto\
    \ &&v : A) ++res[v];\n    return res;\n}\n// TODO \u5EA7\u6A19\u5727\u7E2E\n//\
    \ TODO \u8EE2\u5012\u6570\n// TODO \u7D2F\u7A4D\u548C\u7CFB\n"
  code: "#pragma once\nauto len = []<class T>(vector<T> &v) { return (int)v.size();\
    \ };\ntemplate <typename T> T min(vector<T> &v) {\n    return *min_element(all(v));\n\
    }\ntemplate <typename T> T max(vector<T> &v) {\n    return *max_element(all(v));\n\
    }\nauto sum = [](vector<long long> &v) { return accumulate(all(v), 0ll); };\n\
    auto allMatch = []<class T, class F>(vector<T> &v, F f) {\n    return all_of(all(v),\
    \ f);\n};\nauto noneMatch = []<class T, class F>(vector<T> &v, F f) {\n    return\
    \ none_of(all(v), f);\n};\nauto anyMatch = []<class T, class F>(vector<T> &v,\
    \ F f) {\n    return any_of(all(v), f);\n};\nauto sort_asc = []<class T>(vector<T>\
    \ &v) { sort(all(v)); };\nauto sort_desc = []<class T>(vector<T> &v) { sort(rall(v));\
    \ };\ntemplate <typename T> void reverse(vector<T> &v) {\n    reverse(all(v));\n\
    }\nauto distinct = []<class T>(vector<T> &v) {\n    sort(all(v));\n    v.erase(unique(all(v)),\
    \ v.end());\n};\n// set\u304B\u3089\u8981\u7D20\u524A\u9664\ntemplate <typename\
    \ T> void erase(set<T> &st, T &v) {\n    st.erase(st.find(v));\n}\n// multiset\u304B\
    \u3089\u8981\u7D20\u524A\u9664\ntemplate <typename T> void erase(multiset<T> &st,\
    \ T &v) {\n    st.erase(st.find(v));\n}\n// \u884C\u5217\u306E\u8EE2\u7F6E\nauto\
    \ transpose = []<class T>(vector<vector<T>> &G) {\n    int H = G.size(), W = G[0].size();\n\
    \    vector<vector<T>> _G(W, vector<T>(H));\n    for (int i = 0; i < H; ++i) {\n\
    \        for (int j = 0; j < W; ++j) {\n            _G[j][i] = G[i][j];\n    \
    \    }\n    }\n    return _G;\n};\n/**\n * \u5206\u5272\u4EE3\u5165\u3067\u304D\
    \u308B\u3088\u3046\u306B\u3059\u308B\n * G\u306F\u7834\u58CA\u3002\n * auto [a,b]\
    \ = unpack<2>(move(G));\n */\ntemplate <int N, typename T> auto unpack(vector<T>\
    \ &&G) {\n    array<T, N> res; // vector -> array\u5909\u63DB\u3059\u308B\u3060\
    \u3051\n    for (int i = 0; i < N; ++i) res[i] = move(G[i]);\n    return res;\n\
    }\n// TODO \u30DE\u30FC\u30B8\u30C6\u30AF\n// \u6570\u76F4\u7DDA\u4E0A\u3067\u306E\
    \u500B\u6570\u306B\u306A\u304A\u3059\nvector<int> coordinate(vector<int> &A) {\n\
    \    vector<int> res(MAX);\n    for (auto &&v : A) ++res[v];\n    return res;\n\
    }\n// TODO \u5EA7\u6A19\u5727\u7E2E\n// TODO \u8EE2\u5012\u6570\n// TODO \u7D2F\
    \u7A4D\u548C\u7CFB\n"
  dependsOn: []
  isVerificationFile: false
  path: library/util/seq.hpp
  requiredBy:
  - template/template.hpp
  - main.cpp
  timestamp: '2025-12-19 22:18:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/template.test.cpp
documentation_of: library/util/seq.hpp
layout: document
title: "\u914D\u5217\u30FB\u96C6\u5408\u30FB\u6570\u5217"
---

よくある配列操作をより直感的に使うため`C++`特有のSTLをラップしたり。

