---
title: Rolling Hash
documentation_of: //library/string/rolling_hash.hpp
---

# Rolling Hash

## できること
- 文字列Sをハッシュに変換する
- `get(0, 5)`: 0~5文字目の部分文字列のハッシュを取得
- ハッシュが同じであれば、文字列が同じである

## 計算量
$O(|S|)$

## 使い方
```cpp
string S = "xxx";
RollingHash rh(S);
// ハッシュで比較
if (rh.get(0, 4) == rh.get(7, 11)) {}
```

```cpp
string S = "xxxaaa";
RollingHash rh(S);
long long h_1 = rh.get(0, 2);
long long h_2 = rh.get(2, 5); // bの長さ3
// ハッシュをマージ
if (RollingHash::merge(h_1, h_2, 3) == rh.get(0, 5)) {}
```
