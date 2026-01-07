---
title: ランレングス圧縮
documentation_of: //library/string/run_length.hpp
---

# ランレングス圧縮

## できること
- 文字の連続数で圧縮する
```
AAAABBBCDDDD
↓
{ [A, 4], [B, 3], [C, 1], [D, 4] }
```

## 計算量
$O(|S|)$

## 使い方
```cpp
vector<pair<char, int>> R = run_length(S);
```
