---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/monoid/min.hpp
    title: library/monoid/min.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 2 "library/other/inf.hpp"


    template <class T> constexpr T inf = 0;

    template <> constexpr int inf<int> = 1e9;

    template <> constexpr long long inf<long long> = 1e18;

    '
  code: '#pragma once


    template <class T> constexpr T inf = 0;

    template <> constexpr int inf<int> = 1e9;

    template <> constexpr long long inf<long long> = 1e18;

    '
  dependsOn: []
  isVerificationFile: false
  path: library/other/inf.hpp
  requiredBy:
  - library/monoid/min.hpp
  timestamp: '2025-12-14 19:40:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/other/inf.hpp
layout: document
redirect_from:
- /library/library/other/inf.hpp
- /library/library/other/inf.hpp.html
title: library/other/inf.hpp
---
