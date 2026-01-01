---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: "\U0001F36A\U0001F9F8\U0001F43E"
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
    document_title: UnionFind
    links: []
  bundledCode: "#line 2 \"library/struct/union_find.hpp\"\n/**\n * @brief UnionFind\n\
    \ */\nstruct UnionFind {\n  private:\n    int N;\n    vector<int> parent, size;\n\
    \n  public:\n    UnionFind(int N) : N(N) {\n        parent.assign(N, -1);\n  \
    \      size.assign(N, 1);\n    }\n    // \u81EA\u5206\u306E\u30B0\u30EB\u30FC\u30D7\
    \u306E\u30B5\u30A4\u30BA\n    int operator[](int p) {\n        return size[find(p)];\n\
    \    }\n    // p\u306E\u89AA\u3092\u898B\u3064\u3051\u308B\n    int find(int p)\
    \ {\n        return !~parent[p] ? p : (parent[p] = find(parent[p]));\n    }\n\
    \    // a\u3068b\u3092\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\u3059\u308B \u64CD\
    \u4F5C\u3057\u305F\u3089true\n    bool unite(int a, int b) {\n        int x =\
    \ find(a), y = find(b);\n        if (x == y) return false;\n        if (size[x]\
    \ > size[y]) swap(x, y);\n        parent[x] = y, size[y] += size[x];\n       \
    \ return true;\n    }\n};\n"
  code: "#pragma once\n/**\n * @brief UnionFind\n */\nstruct UnionFind {\n  private:\n\
    \    int N;\n    vector<int> parent, size;\n\n  public:\n    UnionFind(int N)\
    \ : N(N) {\n        parent.assign(N, -1);\n        size.assign(N, 1);\n    }\n\
    \    // \u81EA\u5206\u306E\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\n \
    \   int operator[](int p) {\n        return size[find(p)];\n    }\n    // p\u306E\
    \u89AA\u3092\u898B\u3064\u3051\u308B\n    int find(int p) {\n        return !~parent[p]\
    \ ? p : (parent[p] = find(parent[p]));\n    }\n    // a\u3068b\u3092\u540C\u3058\
    \u30B0\u30EB\u30FC\u30D7\u306B\u3059\u308B \u64CD\u4F5C\u3057\u305F\u3089true\n\
    \    bool unite(int a, int b) {\n        int x = find(a), y = find(b);\n     \
    \   if (x == y) return false;\n        if (size[x] > size[y]) swap(x, y);\n  \
    \      parent[x] = y, size[y] += size[x];\n        return true;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/struct/union_find.hpp
  requiredBy:
  - template/template.hpp
  - main.cpp
  timestamp: '2026-01-01 11:05:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/template.test.cpp
documentation_of: library/struct/union_find.hpp
layout: document
redirect_from:
- /library/library/struct/union_find.hpp
- /library/library/struct/union_find.hpp.html
title: UnionFind
---
