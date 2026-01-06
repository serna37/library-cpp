---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: "main\u30D5\u30A1\u30A4\u30EB"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph/bellman_ford.test.cpp
    title: "\u30B0\u30E9\u30D5 - BellmanFord\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/bfs.test.cpp
    title: "\u30B0\u30E9\u30D5 - BFS\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/connected_components.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u9023\u7D50\u6210\u5206\u5206\u89E3\u306E\u30C6\u30B9\
      \u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/cycle_detect.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u9589\u8DEF\u691C\u51FA\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/dijkstra.test.cpp
    title: "\u30B0\u30E9\u30D5 - Dijkstra\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/mst_kruskal.test.cpp
    title: "\u6700\u5C0F\u5168\u57DF\u6728 - \u30AF\u30E9\u30B9\u30AB\u30EB\u306E\u30C6\
      \u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/route_restore.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u7D4C\u8DEF\u5FA9\u5143\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/strongly_connected_components.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\u306E\u30C6\
      \u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/topological_sort.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
      \u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/graph/warshall_froyd.test.cpp
    title: "\u30B0\u30E9\u30D5 - WarshallFroyd\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/segtree/dual_segment_tree.test.cpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree/fenwick_tree.test.cpp
    title: "Fenwick Tree\u306E\u30C6\u30B9\u30C8:RSQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree/lazy_segment_tree.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree/segment_tree.test.cpp
    title: "\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ"
  - icon: ':heavy_check_mark:'
    path: tests/struct/union_find.test.cpp
    title: "Union Find\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/util.test.cpp
    title: "template/util/xxx.hpp\u306E\u30E6\u30CB\u30C3\u30C8\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6587\u5B57\u5217"
    links: []
  bundledCode: "#line 2 \"template/util/string.hpp\"\n/**\n * @brief \u6587\u5B57\u5217\
    \n */\nclass String {\n  public:\n    bool is_low(char c) {\n        return islower(c)\
    \ != 0;\n    }\n    bool is_upp(char c) {\n        return isupper(c) != 0;\n \
    \   }\n    // \u5C0F\u6587\u5B57\u306B\u5909\u63DB\n    string transform_lower(string\
    \ s) {\n        std::transform(all(s), s.begin(), ::tolower);\n        return\
    \ s;\n    }\n    // \u5927\u6587\u5B57\u306B\u5909\u63DB\n    string transform_upper(string\
    \ s) {\n        std::transform(all(s), s.begin(), ::toupper);\n        return\
    \ s;\n    }\n    // \u7D50\u5408\n    string join(const vector<string> &v, const\
    \ string &sep) {\n        string res;\n        for (int i = 0; i < (int)v.size();\
    \ ++i) {\n            if (0 < i) res += sep;\n            res += v[i];\n     \
    \   }\n        return res;\n    }\n    /**\n     * \u6587\u5B57\u5217T\u306E\u4E2D\
    \u306B\u3042\u308BS\u306E\u4E00\u81F4\u5834\u6240\u3092\u5168\u3066\u53D6\u5F97\
    \n     * \u30DE\u30C3\u30C1\u3057\u305F\u982D\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\u3092\u8FD4\u3059\n     */\n    vector<int> finds(const string &T, const\
    \ string &S) {\n        vector<int> pos;\n        auto p = T.find(S);\n      \
    \  while (p != string::npos) {\n            pos.emplace_back(p);\n           \
    \ p = T.find(S, p + 1);\n        }\n        return pos;\n    }\n    // \u533A\u5207\
    \u308A\u6587\u5B57(1\u6587\u5B57)\u3067\u533A\u5207\u308B\n    vector<string>\
    \ split(const string &S, const char &sep) {\n        vector<string> res = {\"\"\
    };\n        for (auto &&v : S) {\n            if (v == sep) {\n              \
    \  res.emplace_back(\"\");\n            } else {\n                res.back() +=\
    \ v;\n            }\n        }\n        return res;\n    }\n    // \u8907\u6570\
    \u306E\u533A\u5207\u308A\u6587\u5B57\u3067\u533A\u5207\u308B \u533A\u5207\u308A\
    \u6587\u5B57\u304C\u306A\u3044\u5834\u5408\u7A7A\u6587\u5B57\n    vector<string>\
    \ split_multi(const string &S, const string &seps) {\n        vector<string> res\
    \ = {\"\"};\n        for (auto &&v : S) {\n            if (count(all(seps), v))\
    \ {\n                res.emplace_back(\"\");\n            } else {\n         \
    \       res.back() += v;\n            }\n        }\n        return res;\n    }\n\
    \    // \u6587\u5B57\u5217\u306E\u533A\u9593[A, B]\u3092\u53D6\u5F97\n    string\
    \ str_range(const string &S, int A, int B) {\n        if (A > B or A >= (int)S.size())\
    \ return \"\";\n        return S.substr(A, B - A + 1);\n    }\n    // \u30E9\u30F3\
    \u30EC\u30F3\u30B0\u30B9\u5727\u7E2E O(N)\n    vector<pair<char, int>> run_length(const\
    \ string &S) {\n        vector<pair<char, int>> res;\n        for (auto &&x :\
    \ S) {\n            if (res.empty() or res.back().first != x) res.emplace_back(x,\
    \ 0);\n            ++res.back().second;\n        }\n        return res;\n    }\n\
    };\n"
  code: "#pragma once\n/**\n * @brief \u6587\u5B57\u5217\n */\nclass String {\n  public:\n\
    \    bool is_low(char c) {\n        return islower(c) != 0;\n    }\n    bool is_upp(char\
    \ c) {\n        return isupper(c) != 0;\n    }\n    // \u5C0F\u6587\u5B57\u306B\
    \u5909\u63DB\n    string transform_lower(string s) {\n        std::transform(all(s),\
    \ s.begin(), ::tolower);\n        return s;\n    }\n    // \u5927\u6587\u5B57\u306B\
    \u5909\u63DB\n    string transform_upper(string s) {\n        std::transform(all(s),\
    \ s.begin(), ::toupper);\n        return s;\n    }\n    // \u7D50\u5408\n    string\
    \ join(const vector<string> &v, const string &sep) {\n        string res;\n  \
    \      for (int i = 0; i < (int)v.size(); ++i) {\n            if (0 < i) res +=\
    \ sep;\n            res += v[i];\n        }\n        return res;\n    }\n    /**\n\
    \     * \u6587\u5B57\u5217T\u306E\u4E2D\u306B\u3042\u308BS\u306E\u4E00\u81F4\u5834\
    \u6240\u3092\u5168\u3066\u53D6\u5F97\n     * \u30DE\u30C3\u30C1\u3057\u305F\u982D\
    \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u8FD4\u3059\n     */\n    vector<int>\
    \ finds(const string &T, const string &S) {\n        vector<int> pos;\n      \
    \  auto p = T.find(S);\n        while (p != string::npos) {\n            pos.emplace_back(p);\n\
    \            p = T.find(S, p + 1);\n        }\n        return pos;\n    }\n  \
    \  // \u533A\u5207\u308A\u6587\u5B57(1\u6587\u5B57)\u3067\u533A\u5207\u308B\n\
    \    vector<string> split(const string &S, const char &sep) {\n        vector<string>\
    \ res = {\"\"};\n        for (auto &&v : S) {\n            if (v == sep) {\n \
    \               res.emplace_back(\"\");\n            } else {\n              \
    \  res.back() += v;\n            }\n        }\n        return res;\n    }\n  \
    \  // \u8907\u6570\u306E\u533A\u5207\u308A\u6587\u5B57\u3067\u533A\u5207\u308B\
    \ \u533A\u5207\u308A\u6587\u5B57\u304C\u306A\u3044\u5834\u5408\u7A7A\u6587\u5B57\
    \n    vector<string> split_multi(const string &S, const string &seps) {\n    \
    \    vector<string> res = {\"\"};\n        for (auto &&v : S) {\n            if\
    \ (count(all(seps), v)) {\n                res.emplace_back(\"\");\n         \
    \   } else {\n                res.back() += v;\n            }\n        }\n   \
    \     return res;\n    }\n    // \u6587\u5B57\u5217\u306E\u533A\u9593[A, B]\u3092\
    \u53D6\u5F97\n    string str_range(const string &S, int A, int B) {\n        if\
    \ (A > B or A >= (int)S.size()) return \"\";\n        return S.substr(A, B - A\
    \ + 1);\n    }\n    // \u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E O(N)\n\
    \    vector<pair<char, int>> run_length(const string &S) {\n        vector<pair<char,\
    \ int>> res;\n        for (auto &&x : S) {\n            if (res.empty() or res.back().first\
    \ != x) res.emplace_back(x, 0);\n            ++res.back().second;\n        }\n\
    \        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: template/util/string.hpp
  requiredBy:
  - template/template.hpp
  - main.cpp
  timestamp: '2026-01-06 20:15:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/segtree/lazy_segment_tree.test.cpp
  - tests/segtree/fenwick_tree.test.cpp
  - tests/segtree/segment_tree.test.cpp
  - tests/segtree/dual_segment_tree.test.cpp
  - tests/graph/bfs.test.cpp
  - tests/graph/topological_sort.test.cpp
  - tests/graph/bellman_ford.test.cpp
  - tests/graph/dijkstra.test.cpp
  - tests/graph/cycle_detect.test.cpp
  - tests/graph/mst_kruskal.test.cpp
  - tests/graph/route_restore.test.cpp
  - tests/graph/strongly_connected_components.test.cpp
  - tests/graph/warshall_froyd.test.cpp
  - tests/graph/connected_components.test.cpp
  - tests/struct/union_find.test.cpp
  - tests/util.test.cpp
documentation_of: template/util/string.hpp
layout: document
redirect_from:
- /library/template/util/string.hpp
- /library/template/util/string.hpp.html
title: "\u6587\u5B57\u5217"
---
