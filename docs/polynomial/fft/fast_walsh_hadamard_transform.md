---
title: 高速WalshHadamard変換
documentation_of: //library/polynomial/fft/fast_walsh_hadamard_transform.hpp
---

# 高速WalshHadamard変換
[詳しい説明](https://qiita.com/izu_nori/items/7810fc2bc0423c8d407f)

## できること
- 行列とベクトルの積を高速に計算するための変換

<img width="350" height="327" alt="Image" src="https://github.com/user-attachments/assets/26e220ba-fb48-4020-8368-0af5cb5a6ad0" />

## 計算量
$O(NlogN)$

## 使い方
```cpp
fast_walsh_hadamard_transform(f, false);
```

