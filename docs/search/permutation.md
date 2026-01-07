---
title: 順列全探索
documentation_of: //library/search/permutation.hpp
---

# 順列全探索

## できること
- 順列の全パターンを探索する

## 計算量
$O(N!)$ Nは10〜12程度まで

## 使い方
```cpp
permutation(A, [&](){
    print(A);
});
```
