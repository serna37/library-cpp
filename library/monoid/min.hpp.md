---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/other/inf.hpp
    title: library/other/inf.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/monoid/min.hpp\"\n\n#line 2 \"library/other/inf.hpp\"\
    \n\ntemplate <class T> constexpr T inf = 0;\ntemplate <> constexpr int inf<int>\
    \ = 1e9;\ntemplate <> constexpr long long inf<long long> = 1e18;\n#line 4 \"library/monoid/min.hpp\"\
    \n\n/**\n * \u6700\u5C0F\u5024\u30E2\u30CE\u30A4\u30C9\n */\ntemplate <typename\
    \ T> struct Mmin {\n    using value_type = T;\n    static constexpr T e = inf<T>;\n\
    \    static constexpr T op(const T &x, const T &y) noexcept {\n        return\
    \ min(x, y);\n    }\n};\n"
  code: "#pragma once\n\n#include \"library/other/inf.hpp\"\n\n/**\n * \u6700\u5C0F\
    \u5024\u30E2\u30CE\u30A4\u30C9\n */\ntemplate <typename T> struct Mmin {\n   \
    \ using value_type = T;\n    static constexpr T e = inf<T>;\n    static constexpr\
    \ T op(const T &x, const T &y) noexcept {\n        return min(x, y);\n    }\n\
    };\n"
  dependsOn:
  - library/other/inf.hpp
  isVerificationFile: false
  path: library/monoid/min.hpp
  requiredBy: []
  timestamp: '2025-12-14 19:49:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/monoid/min.hpp
layout: document
redirect_from:
- /library/library/monoid/min.hpp
- /library/library/monoid/min.hpp.html
title: library/monoid/min.hpp
---
