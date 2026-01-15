---
title: 進数変換
documentation_of: //library/number/base_convert.hpp
---

# 進数変換

## できること
- to進数に変換する
- 結果が`42`の場合、`4, 2`と配列で返す

## 計算量
$O(log_{\vert to \vert} x)$

## 使い方
```cpp
vector<int> cvt = base_convert(x, 10);
```
