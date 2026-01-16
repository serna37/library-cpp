---
title: 座標圧縮
documentation_of: //library/sequence/compressor.hpp
---

# 座標圧縮

## できること
- 大きさの序列のみを保持したID配列（0-indexed）に圧縮する
- 巨大な値や負の値を含む配列を、要素の種類数（0 ～ size-1）の範囲に収められる
- 圧縮後のIDから元の値を復元できる
- 任意の値が「どのID相当か」を取得できる（二分探索を利用）

## 計算量
- 構築: $O(NlogN)$
- 圧縮 `get_id`: $O(logN)$
- 復元 `get_val`: $O(1)$

## 使い方
```cpp
vector<long long> A = {10, 40, 90, 90, 150, 420};

// 1. 構築
Compressor<long long> zip(A);

// 2. 種類数の取得
int sz = zip.size(); // 5

// 3. 値から ID への変換 (二分探索)
int id1 = zip.get_id(90);       // 2 (90 以上の最小 ID)
int id2 = zip.get_upper_id(90); // 3 (90 より大きい最小 ID)

// 4. ID から元の値への復元
long long val = zip.get_val(2); // 90

// 5. 元の配列をすべて圧縮変換する場合
vector<int> z = zip.get_all();
```
