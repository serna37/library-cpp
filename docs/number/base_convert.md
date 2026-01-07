---
title: 進数変換
documentation_of: //library/number/base_convert.hpp
---

# 進数変換

## できること
- 進数を変換する
- fromとtoは10を超えないこと

## 計算量
$O(|S|)$

## 使い方
```cpp
// 10進数から2進数に変換
string T = base_convert(S, 10, 2);
```
