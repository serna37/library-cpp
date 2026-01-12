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
  bundledCode: "#line 2 \"library/string/split_multi.hpp\"\nvector<string> split_multi(const\
    \ string &S, const string &seps) {\n    vector<string> res = {\"\"};\n    for\
    \ (auto &&v : S) {\n        if (count(all(seps), v)) {\n            res.emplace_back(\"\
    \");\n        } else {\n            res.back() += v;\n        }\n    }\n    return\
    \ res;\n}\n"
  code: "#pragma once\nvector<string> split_multi(const string &S, const string &seps)\
    \ {\n    vector<string> res = {\"\"};\n    for (auto &&v : S) {\n        if (count(all(seps),\
    \ v)) {\n            res.emplace_back(\"\");\n        } else {\n            res.back()\
    \ += v;\n        }\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/split_multi.hpp
  requiredBy: []
  timestamp: '2026-01-12 19:33:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/string/split_multi.hpp
layout: document
title: "\u6587\u5B57\u5217\u3092\u533A\u5207\u308B \u8907\u6570"
---

# 文字列を区切る 複数

## できること
- 複数の区切り文字で区切る
- 区切り文字がない場合空文字

## 計算量
$O(|S| * |sep|)$

## 使い方
```cpp
vector<string> list = split_multi(S, ",./");
```
