---
title: Rolling Hash
documentation_of: //library/string/rolling_hash.hpp
---

# Rolling Hash
[詳しい説明](https://www.slideshare.net/slideshow/rolling-hash-60984153/60984153)

## できること
- 文字列Sをハッシュに変換する
- `get(0, 5)`: 0~5文字目の部分文字列のハッシュを取得
- ハッシュが同じであれば、文字列が同じである
- ハッシュ衝突の危険性について
  - 法にメルセンヌ素数 $2^{61}-1$ を、基数に実行時疑似乱数を使用していますが、比較するハッシュ値の数が増えると衝突確率が急上昇します
    - 原因: 「誕生日パラドックス」
    - 衝突の目安: およそ $\sqrt M$ 個(約 $1.5 \cdot 10^{9}$ )個の異なるハッシュを生成して比較すると50%の確率で衝突する

## 計算量
- 構築: $O(\vert S \vert)$
- `get`: $O(1)$

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
