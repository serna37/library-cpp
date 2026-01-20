---
title: Z Algorithm
documentation_of: //library/string/z_algorithm.hpp
---

# Z Algorithm

## できること
- 文字列 $S$ が与えられたとき、それぞれの $i$ について $S$ と $S[i, \vert S \vert ]$ の最長共通接頭辞の長さを記録した配列を、線形時間で構築する
- 参考: https://heno239.hatenablog.com/entry/2020/07/07/140651
- 参考: https://ei1333.github.io/library/string/z-algorithm.hpp

```
aaabaaaab
921034210
```

## 計算量
- 空文字列で初期化 `ZAlgorithm()`: $O(1)$
- 文字列sで初期化 `ZAlgorithm(s)`: $O(N)$
- 文字列の末尾にcを追加 `add(c)`: $O(1)$
- 現在の文字列 $S$ と $S[i, \vert S \vert ]$ の最長共通接頭辞の長さを返す `get(k)`: $O(1)$
- 全ての $i$ についてgetする `get()`: $O(N)$

## 使い方
```cpp
string S = "abacaba";
ZAlgorithm za(S);

// get(k) で S[k..] と S[0..] の共通接頭辞の長さを取得
for (int i = 0; i < (int)S.size(); ++i) za.get(i);
auto all = za.get();
print(all);
```

```cpp
```

