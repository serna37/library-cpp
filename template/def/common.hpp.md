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
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/def/common.hpp: line 5: #pragma once found in a non-first line\n"
  code: "\n/** ======================================= */\n/**              \u5171\
    \u901A                       */\n/** ======================================= */\n\
    #pragma once\n#define int long long\n#define all(x) begin(x), end(x)\n#define\
    \ rall(x) rbegin(x), rend(x)\n#define $(idx) (std::get<(idx)>(std::forward_as_tuple(_args...)))\n\
    // lambda($(0) + $(1))\u3068\u3067\u304D\u308B\n#define lambda(...) ([&](auto\
    \ &&..._args) { return (__VA_ARGS__); })\nauto chmin = []<class T>(T &i, const\
    \ T &j) { return i > j && (i = j, true); };\nauto chmax = []<class T>(T &i, const\
    \ T &j) { return i < j && (i = j, true); };\n// [a, b)\u3067\u4E71\u6570\u751F\
    \u6210 \u30E1\u30EB\u30BB\u30F3\u30CC\u30C4\u30A4\u30B9\u30BF\nauto random_mersenne_twister\
    \ = [](int a = 1, int b = 1e5 + 1) {\n    uniform_int_distribution<int> dist(a,\
    \ b - 1);\n    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    return dist(mt);\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: template/def/common.hpp
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
documentation_of: template/def/common.hpp
layout: document
title: "\u5171\u901A"
---

# 共通

`int`は`long long`として扱います。

管理内容
- マクロなど、全体を通して利用するもの
- その他 的なカテゴリのもの
