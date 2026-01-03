---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: "main\u30D5\u30A1\u30A4\u30EB"
  - icon: ':question:'
    path: template/template.hpp
    title: "\u0E05^>\u03C9<^\u0E05"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/struct.dual_segment_tree.test.cpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/struct.fenwick_tree.test.cpp
    title: "Fenwick Tree\u306E\u30C6\u30B9\u30C8:RSQ"
  - icon: ':heavy_check_mark:'
    path: tests/struct.lazy_segment_tree.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/struct.segment_tree.test.cpp
    title: "\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ"
  - icon: ':heavy_check_mark:'
    path: tests/struct.union_find.test.cpp
    title: "Union Find\u306E\u30C6\u30B9\u30C8"
  - icon: ':x:'
    path: tests/template.test.cpp
    title: "library/util/xxx.hpp\u306E\u30E6\u30CB\u30C3\u30C8\u30C6\u30B9\u30C8"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 1 "template/includes.hpp"

    #include <algorithm>

    #include <array>

    #include <bitset>

    #include <cassert>

    #include <complex>

    #include <chrono>

    #include <deque>

    #include <functional>

    #include <iomanip>

    #include <iostream>

    #include <limits.h>

    #include <map>

    #include <math.h>

    #include <numeric>

    #include <queue>

    #include <random>

    #include <set>

    #include <sstream>

    #include <stack>

    #include <string>

    #include <tuple>

    #include <unordered_map>

    #include <unordered_set>

    #include <utility>

    #include <vector>

    // -----------------------------------------

    // #include "template/includes.hpp" is done.

    // -----------------------------------------

    '
  code: '#include <algorithm>

    #include <array>

    #include <bitset>

    #include <cassert>

    #include <complex>

    #include <chrono>

    #include <deque>

    #include <functional>

    #include <iomanip>

    #include <iostream>

    #include <limits.h>

    #include <map>

    #include <math.h>

    #include <numeric>

    #include <queue>

    #include <random>

    #include <set>

    #include <sstream>

    #include <stack>

    #include <string>

    #include <tuple>

    #include <unordered_map>

    #include <unordered_set>

    #include <utility>

    #include <vector>

    // -----------------------------------------

    // #include "template/includes.hpp" is done.

    // -----------------------------------------

    '
  dependsOn: []
  isVerificationFile: false
  path: template/includes.hpp
  requiredBy:
  - template/template.hpp
  - main.cpp
  timestamp: '2026-01-03 21:52:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/struct.lazy_segment_tree.test.cpp
  - tests/struct.fenwick_tree.test.cpp
  - tests/template.test.cpp
  - tests/struct.dual_segment_tree.test.cpp
  - tests/struct.segment_tree.test.cpp
  - tests/struct.union_find.test.cpp
documentation_of: template/includes.hpp
layout: document
title: "\u57FA\u672Cinclude\u7528"
---

`bits/stdc++.h`で良いはずだが、C++23で明示的にincludeしてないとエラー等もあったので

とりあえず必要なもの書いておく用

