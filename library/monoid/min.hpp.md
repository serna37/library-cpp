---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/const.hpp
    title: "\u5B9A\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/const.hpp\"\n/**\n * @file const.hpp\n * @brief\
    \ \u5B9A\u6570\n */\ntemplate <class T> constexpr T inf = 0;\ntemplate <> constexpr\
    \ int inf<int> = 1e9;\ntemplate <> constexpr long long inf<long long> = 1e18;\n\
    const int INF = 1e9;\nconst long long INFL = 1e18;\nconst long long MOD = 998244353;\n\
    const long long MOD7 = 1000000007;\nconst long double EPS = 1e-14;\nconst int\
    \ MAX = 2e6;\nconst long long MAXL = 2e6;\nconst double PI = acos(-1);\n// \u4E0B\
    \u53F3\u4E0A\u5DE6 DRUL\nconst vector<int> dx = {0, 1, 0, -1};\nconst vector<int>\
    \ dy = {1, 0, -1, 0};\n// 8\u65B9\u5411\nconst vector<int> dx8 = {0, 1, 0, -1,\
    \ 1, -1, 1, -1};\nconst vector<int> dy8 = {1, 0, -1, 0, 1, 1, -1, -1};\n#line\
    \ 3 \"library/monoid/min.hpp\"\n// \u6700\u5C0F\u5024\u30E2\u30CE\u30A4\u30C9\n\
    template <typename T> struct Mmin {\n    using value_type = T;\n    static constexpr\
    \ T e = inf<T>;\n    static constexpr T op(const T &x, const T &y) noexcept {\n\
    \        return min(x, y);\n    }\n};\n"
  code: "#pragma once\n#include \"library/const.hpp\"\n// \u6700\u5C0F\u5024\u30E2\
    \u30CE\u30A4\u30C9\ntemplate <typename T> struct Mmin {\n    using value_type\
    \ = T;\n    static constexpr T e = inf<T>;\n    static constexpr T op(const T\
    \ &x, const T &y) noexcept {\n        return min(x, y);\n    }\n};\n"
  dependsOn:
  - library/const.hpp
  isVerificationFile: false
  path: library/monoid/min.hpp
  requiredBy: []
  timestamp: '2025-12-17 23:43:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/monoid/min.hpp
layout: document
redirect_from:
- /library/library/monoid/min.hpp
- /library/library/monoid/min.hpp.html
title: library/monoid/min.hpp
---
