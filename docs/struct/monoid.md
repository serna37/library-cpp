---
title: モノイド
documentation_of: //library/struct/monoid.hpp
---


有名なモノイドを作っておく。以下のように呼べる。

```cpp
SegmentTree<int> seg(Monoid::Min::op, Monoid::Min::e, N);
```


