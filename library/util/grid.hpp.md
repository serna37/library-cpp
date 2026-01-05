---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: "main\u30D5\u30A1\u30A4\u30EB"
  - icon: ':heavy_check_mark:'
    path: template/lib.hpp
    title: "library/util/*.hpp\u306Einclude\u7528"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/segtree.dual_segment_tree.test.cpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree.fenwick_tree.test.cpp
    title: "Fenwick Tree\u306E\u30C6\u30B9\u30C8:RSQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree.lazy_segment_tree.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree.segment_tree.test.cpp
    title: "\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ"
  - icon: ':heavy_check_mark:'
    path: tests/struct.union_find.test.cpp
    title: "Union Find\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/template.test.cpp
    title: "library/util/xxx.hpp\u306E\u30E6\u30CB\u30C3\u30C8\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30AF\u3099\u30EA\u30C3\u30C8\u3099"
    links: []
  bundledCode: "#line 2 \"library/util/grid.hpp\"\n/**\n * @brief \u30AF\u3099\u30EA\
    \u30C3\u30C8\u3099\n */\nclass Grid {\n  public:\n    // \u884C\u5217\u306E\u8EE2\
    \u7F6E\n    template <typename T>\n    vector<vector<T>> transpose(const vector<vector<T>>\
    \ &G) {\n        int H = G.size(), W = G[0].size();\n        vector<vector<T>>\
    \ _G(W, vector<T>(H));\n        for (int i = 0; i < H; ++i) {\n            for\
    \ (int j = 0; j < W; ++j) {\n                _G[j][i] = G[i][j];\n           \
    \ }\n        }\n        return _G;\n    }\n    // \u30B0\u30EA\u30C3\u30C94\u65B9\
    \u3092\u898B\u308BBFS \u5F15\u6570f(y, x)\n    template <typename T, typename\
    \ F> void bfs(vector<vector<T>> &G, F f) {\n        int H = G.size(), W = G[0].size();\n\
    \        for (int i = 0; i < H; ++i) {\n            for (int j = 0; j < W; ++j)\
    \ {\n                for (int k = 0; k < 4; ++k) {\n                    int y\
    \ = i + dy[k], x = j + dx[k];\n                    if (y < 0 or x < 0 or H <=\
    \ y or W <= x) continue;\n                    f(y, x);\n                }\n  \
    \          }\n        }\n    }\n    // \u30B0\u30EA\u30C3\u30C98\u65B9\u3092\u898B\
    \u308BBFS \u5F15\u6570f(y, x)\n    template <typename T, typename F> void bfs8(vector<vector<T>>\
    \ &G, F f) {\n        int H = G.size(), W = G[0].size();\n        for (int i =\
    \ 0; i < H; ++i) {\n            for (int j = 0; j < W; ++j) {\n              \
    \  for (int k = 0; k < 8; ++k) {\n                    int y = i + dy8[k], x =\
    \ j + dx8[k];\n                    if (y < 0 or x < 0 or H <= y or W <= x) continue;\n\
    \                    f(y, x);\n                }\n            }\n        }\n \
    \   }\n};\n"
  code: "#pragma once\n/**\n * @brief \u30AF\u3099\u30EA\u30C3\u30C8\u3099\n */\n\
    class Grid {\n  public:\n    // \u884C\u5217\u306E\u8EE2\u7F6E\n    template <typename\
    \ T>\n    vector<vector<T>> transpose(const vector<vector<T>> &G) {\n        int\
    \ H = G.size(), W = G[0].size();\n        vector<vector<T>> _G(W, vector<T>(H));\n\
    \        for (int i = 0; i < H; ++i) {\n            for (int j = 0; j < W; ++j)\
    \ {\n                _G[j][i] = G[i][j];\n            }\n        }\n        return\
    \ _G;\n    }\n    // \u30B0\u30EA\u30C3\u30C94\u65B9\u3092\u898B\u308BBFS \u5F15\
    \u6570f(y, x)\n    template <typename T, typename F> void bfs(vector<vector<T>>\
    \ &G, F f) {\n        int H = G.size(), W = G[0].size();\n        for (int i =\
    \ 0; i < H; ++i) {\n            for (int j = 0; j < W; ++j) {\n              \
    \  for (int k = 0; k < 4; ++k) {\n                    int y = i + dy[k], x = j\
    \ + dx[k];\n                    if (y < 0 or x < 0 or H <= y or W <= x) continue;\n\
    \                    f(y, x);\n                }\n            }\n        }\n \
    \   }\n    // \u30B0\u30EA\u30C3\u30C98\u65B9\u3092\u898B\u308BBFS \u5F15\u6570\
    f(y, x)\n    template <typename T, typename F> void bfs8(vector<vector<T>> &G,\
    \ F f) {\n        int H = G.size(), W = G[0].size();\n        for (int i = 0;\
    \ i < H; ++i) {\n            for (int j = 0; j < W; ++j) {\n                for\
    \ (int k = 0; k < 8; ++k) {\n                    int y = i + dy8[k], x = j + dx8[k];\n\
    \                    if (y < 0 or x < 0 or H <= y or W <= x) continue;\n     \
    \               f(y, x);\n                }\n            }\n        }\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: library/util/grid.hpp
  requiredBy:
  - template/lib.hpp
  - template/template.hpp
  - main.cpp
  timestamp: '2026-01-05 20:19:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/segtree.dual_segment_tree.test.cpp
  - tests/segtree.segment_tree.test.cpp
  - tests/template.test.cpp
  - tests/segtree.lazy_segment_tree.test.cpp
  - tests/segtree.fenwick_tree.test.cpp
  - tests/struct.union_find.test.cpp
documentation_of: library/util/grid.hpp
layout: document
redirect_from:
- /library/library/util/grid.hpp
- /library/library/util/grid.hpp.html
title: "\u30AF\u3099\u30EA\u30C3\u30C8\u3099"
---
