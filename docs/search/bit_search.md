---
title: bit全探索
documentation_of: //library/search/bit_search.hpp
---

# bit全探索

## できること
- 集合Aの全パターンの部分集合を返す
```
{1,2,3}
↓
{ {},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3} }
```


## 計算量
$O(2^N)$ Nは20前後まで

## 使い方
```cpp
vector<vector<int>> tmp = bit_search(A);
```
