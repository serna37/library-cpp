---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/graph/route_restore.test.cpp
    title: "\u30B0\u30E9\u30D5 - \u7D4C\u8DEF\u5FA9\u5143\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/route_restore.hpp\"\nvector<int> route_restore(const\
    \ vector<int> &route, int goal) {\n    vector<int> path = {goal};\n    while (!!~route[path.back()])\
    \ path.push_back(route[path.back()]);\n    reverse(path.begin(), path.end());\n\
    \    return path;\n}\n"
  code: "#pragma once\nvector<int> route_restore(const vector<int> &route, int goal)\
    \ {\n    vector<int> path = {goal};\n    while (!!~route[path.back()]) path.push_back(route[path.back()]);\n\
    \    reverse(path.begin(), path.end());\n    return path;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/route_restore.hpp
  requiredBy: []
  timestamp: '2026-01-14 20:12:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/graph/route_restore.test.cpp
documentation_of: library/graph/route_restore.hpp
layout: document
title: "\u7D4C\u8DEF\u5FA9\u5143"
---

# 経路復元

## できること
- 経路を復元する

## 計算量
$O(L)$
- L: パスの長さ

## 使い方
```cpp
auto [dis, route] = dijkstra(G, {s});
vector<int> pth = route_restore(route, goal);
```
