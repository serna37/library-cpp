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
  bundledCode: "#line 2 \"library/search/dfs_memo.hpp\"\n// \u30E1\u30E2\u5316\u518D\
    \u5E30 !!\u30B3\u30D4\u30DA\u7528!! \u95A2\u6570\u5185\u3092\u30DA\u30FC\u30B9\
    \u30C8\u3057\u3066\u66F8\u304D\u63DB\u3048\u3066\u4F7F\u3046\nvoid dfs_memo()\
    \ {\n    map<int, int> memo; // \u30E1\u30E2\n    auto dfs = [&](auto f, int n)\
    \ {\n        if (n <= 1) return n;                       // \u30D9\u30FC\u30B9\
    \u30B1\u30FC\u30B9\n        if (memo.count(n)) return memo[n];          // \u30E1\
    \u30E2\u306B\u3042\u308C\u3070\u63A1\u7528\n        return memo[n] = f(f, n -\
    \ 1) + f(f, n - 2); // \u30E1\u30E2\u3057\u3064\u3064\u3001\u518D\u5E30\u3057\u3066\
    \u8A08\u7B97\n    };\n    (void)dfs; // unused\n    // int ans = dfs(dfs, N);\n\
    }\n"
  code: "#pragma once\n// \u30E1\u30E2\u5316\u518D\u5E30 !!\u30B3\u30D4\u30DA\u7528\
    !! \u95A2\u6570\u5185\u3092\u30DA\u30FC\u30B9\u30C8\u3057\u3066\u66F8\u304D\u63DB\
    \u3048\u3066\u4F7F\u3046\nvoid dfs_memo() {\n    map<int, int> memo; // \u30E1\
    \u30E2\n    auto dfs = [&](auto f, int n) {\n        if (n <= 1) return n;   \
    \                    // \u30D9\u30FC\u30B9\u30B1\u30FC\u30B9\n        if (memo.count(n))\
    \ return memo[n];          // \u30E1\u30E2\u306B\u3042\u308C\u3070\u63A1\u7528\
    \n        return memo[n] = f(f, n - 1) + f(f, n - 2); // \u30E1\u30E2\u3057\u3064\
    \u3064\u3001\u518D\u5E30\u3057\u3066\u8A08\u7B97\n    };\n    (void)dfs; // unused\n\
    \    // int ans = dfs(dfs, N);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/search/dfs_memo.hpp
  requiredBy: []
  timestamp: '2026-01-13 09:23:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/search/dfs_memo.hpp
layout: document
title: "\u30E1\u30E2\u5316\u518D\u5E30(\u30B3\u30D4\u30DA\u7528)"
---

# メモ化再帰

## できること
- メモしながら再帰する

## 計算量
$O(NlogN)$

## 使い方
コピペして使う
