---
title: Rolling Hash
documentation_of: //library/string/rolling_hash.hpp
---

# Rolling Hash

## できること
- 文字列Sをハッシュに変換する
- `get(0, 5)`: 0~5文字目の部分文字列のハッシュを取得
- ハッシュが同じであれば、文字列が同じである

<details><summary>詳しい説明</summary>

<iframe src="https://www.slideshare.net/slideshow/embed_code/key/rMMH0WkJ6WbZ0s" width="510" height="420"frameborder="0" marginwidth="0" marginheight="0" scrolling="no"style="border: var(--border-1) solid #CCC; border-width:1px; margin-bottom:5px; max-width:100%;"allowfullscreen></iframe><div style="margin-bottom:5px"><strong><a href="https://www.slideshare.net/slideshow/rolling-hash-60984153/60984153" title="rolling-hash-60984153" target="_blank">rolling-hash-60984153</a></strong>from <strong><a href="https://www.slideshare.net/hcpc_hokudai" target="_blank">HCPC: 北海道大学競技プログラミングサークル</a></strong></div>

</details>

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
