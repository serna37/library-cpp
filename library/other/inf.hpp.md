---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/monoid/min.hpp
    title: "\u6700\u5C0F\u5024\u30E2\u30CE\u30A4\u30C9"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "INF\u5B9A\u6570"
    links: []
  bundledCode: "#line 2 \"library/other/inf.hpp\"\n\n/**\n * @brief INF\u5B9A\u6570\
    \n */\ntemplate <class T> constexpr T inf = 0;\ntemplate <> constexpr int inf<int>\
    \ = 1e9;\ntemplate <> constexpr long long inf<long long> = 1e18;\n"
  code: "#pragma once\n\n/**\n * @brief INF\u5B9A\u6570\n */\ntemplate <class T> constexpr\
    \ T inf = 0;\ntemplate <> constexpr int inf<int> = 1e9;\ntemplate <> constexpr\
    \ long long inf<long long> = 1e18;\n"
  dependsOn: []
  isVerificationFile: false
  path: library/other/inf.hpp
  requiredBy:
  - library/monoid/min.hpp
  timestamp: '2025-12-14 21:43:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/other/inf.hpp
layout: document
redirect_from:
- /library/library/other/inf.hpp
- /library/library/other/inf.hpp.html
title: "INF\u5B9A\u6570"
---
