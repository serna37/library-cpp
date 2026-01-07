---
title: 文字列を区切る 複数
documentation_of: //library/string/split_multi.hpp
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
