---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/monoid/min.hpp
    title: library/monoid/min.hpp
  - icon: ':warning:'
    path: template/template.cpp
    title: "\u0E05^>\u03C9<^\u0E05"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5B9A\u6570"
    links: []
  bundledCode: "#line 2 \"library/const.hpp\"\n/**\n * @file const.hpp\n * @brief\
    \ \u5B9A\u6570\n */\ntemplate <class T> constexpr T inf = 0;\ntemplate <> constexpr\
    \ int inf<int> = 1e9;\ntemplate <> constexpr long long inf<long long> = 1e18;\n\
    const int INF = 1e9;\nconst long long INFL = 1e18;\nconst long long MOD = 998244353;\n\
    const long long MOD7 = 1000000007;\nconst long double EPS = 1e-14;\nconst int\
    \ MAX = 2e6;\nconst long long MAXL = 2e6;\nconst double PI = acos(-1);\n// \u4E0B\
    \u53F3\u4E0A\u5DE6 DRUL\nconst vector<int> dx = {0, 1, 0, -1};\nconst vector<int>\
    \ dy = {1, 0, -1, 0};\n// 8\u65B9\u5411\nconst vector<int> dx8 = {0, 1, 0, -1,\
    \ 1, -1, 1, -1};\nconst vector<int> dy8 = {1, 0, -1, 0, 1, 1, -1, -1};\n"
  code: "#pragma once\n/**\n * @file const.hpp\n * @brief \u5B9A\u6570\n */\ntemplate\
    \ <class T> constexpr T inf = 0;\ntemplate <> constexpr int inf<int> = 1e9;\n\
    template <> constexpr long long inf<long long> = 1e18;\nconst int INF = 1e9;\n\
    const long long INFL = 1e18;\nconst long long MOD = 998244353;\nconst long long\
    \ MOD7 = 1000000007;\nconst long double EPS = 1e-14;\nconst int MAX = 2e6;\nconst\
    \ long long MAXL = 2e6;\nconst double PI = acos(-1);\n// \u4E0B\u53F3\u4E0A\u5DE6\
    \ DRUL\nconst vector<int> dx = {0, 1, 0, -1};\nconst vector<int> dy = {1, 0, -1,\
    \ 0};\n// 8\u65B9\u5411\nconst vector<int> dx8 = {0, 1, 0, -1, 1, -1, 1, -1};\n\
    const vector<int> dy8 = {1, 0, -1, 0, 1, 1, -1, -1};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/const.hpp
  requiredBy:
  - template/template.cpp
  - library/monoid/min.hpp
  timestamp: '2025-12-17 23:43:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/const.hpp
layout: document
redirect_from:
- /library/library/const.hpp
- /library/library/const.hpp.html
title: "\u5B9A\u6570"
---
