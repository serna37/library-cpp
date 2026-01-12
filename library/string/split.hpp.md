---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/string/split.hpp\"\nvector<string> split(const string\
    \ &S, const char &sep) {\n    vector<string> res = {\"\"};\n    for (auto &&v\
    \ : S) {\n        if (v == sep) {\n            res.emplace_back(\"\");\n     \
    \   } else {\n            res.back() += v;\n        }\n    }\n    return res;\n\
    }\n"
  code: "#pragma once\nvector<string> split(const string &S, const char &sep) {\n\
    \    vector<string> res = {\"\"};\n    for (auto &&v : S) {\n        if (v ==\
    \ sep) {\n            res.emplace_back(\"\");\n        } else {\n            res.back()\
    \ += v;\n        }\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/split.hpp
  requiredBy: []
  timestamp: '2026-01-12 19:45:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/string/split.hpp
layout: document
title: "\u6587\u5B57\u5217\u3092\u533A\u5207\u308B"
---

# 文字列を区切る

## できること
- 区切り文字(1文字)で区切る

## 計算量
$O(|S|)$

## 使い方
```cpp
vector<string> list = split(S, ",");
```
