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
  bundledCode: "#line 2 \"library/sequence/two_pointer_approach_memo.hpp\"\n// \u5C3A\
    \u53D6\u308A\u6CD5 !!\u30B3\u30D4\u30DA\u7528!! \u95A2\u6570\u5185\u3092\u30DA\
    \u30FC\u30B9\u30C8\u3057\u3066\u66F8\u304D\u63DB\u3048\u3066\u4F7F\u3046\nvoid\
    \ two_pointer_approach(int N, auto test) {\n    int ans = 0;\n    //      \u5DE6\
    \u624B     \u53F3\u624B     \u4E0A\u9650\n    for (int l = 0, r = 0; l < N; ++l)\
    \ {\n        // \u4F38\u3070\u305B\u308B\u3060\u3051\u53F3\u624B\u3092\u4F38\u3070\
    \u3059\n        //               r\u304Ctest\u6761\u4EF6\u3092\u6E80\u305F\u3059\
    \u9593\u4F38\u3070\u3059\n        while (r < N and test) ++r;\n        // \u4F38\
    \u3070\u3057\u304D\u3063\u305F\u3089\u3001\u533A\u9593\u6570\u3067ans\u3092\u7DE9\
    \u548C\n        ans = max(ans, r - l);\n    }\n}\n"
  code: "#pragma once\n// \u5C3A\u53D6\u308A\u6CD5 !!\u30B3\u30D4\u30DA\u7528!! \u95A2\
    \u6570\u5185\u3092\u30DA\u30FC\u30B9\u30C8\u3057\u3066\u66F8\u304D\u63DB\u3048\
    \u3066\u4F7F\u3046\nvoid two_pointer_approach(int N, auto test) {\n    int ans\
    \ = 0;\n    //      \u5DE6\u624B     \u53F3\u624B     \u4E0A\u9650\n    for (int\
    \ l = 0, r = 0; l < N; ++l) {\n        // \u4F38\u3070\u305B\u308B\u3060\u3051\
    \u53F3\u624B\u3092\u4F38\u3070\u3059\n        //               r\u304Ctest\u6761\
    \u4EF6\u3092\u6E80\u305F\u3059\u9593\u4F38\u3070\u3059\n        while (r < N and\
    \ test) ++r;\n        // \u4F38\u3070\u3057\u304D\u3063\u305F\u3089\u3001\u533A\
    \u9593\u6570\u3067ans\u3092\u7DE9\u548C\n        ans = max(ans, r - l);\n    }\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/sequence/two_pointer_approach_memo.hpp
  requiredBy: []
  timestamp: '2026-02-09 15:31:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/sequence/two_pointer_approach_memo.hpp
layout: document
title: "\u5C3A\u53D6\u308A\u6CD5(\u30B3\u30D4\u30DA\u7528)"
---

# 尺取り法

## できること
- 条件を満たす連続な区間について、区間の最大数とかを求める

イメージ

```txt
配列  0 1 2 3 4 5 6 7 8 9 ....
t=0  l        r         rが条件を満たす限り、行けるだけ行く
t=1     l     r         rはそのままに、lを左にずらす
t=2     l          r    また、rを行けるだけ行く
t=3     <---------->    この区間長とかをchmaxとかしながら走査
...

※lとrが左から右に移動してるだけなので実質1周 = O(N)
※lをずらすたびにrを元に戻さないこと。
  既にみてるから省略できるぞ、というのが肝。
  rを元に戻すとただの2重ループと同じなので意味ないぞ。
```

## 計算量
$O(N)$

## 使い方
コピペして使う

