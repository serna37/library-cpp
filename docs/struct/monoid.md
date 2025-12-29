---
title: モノイド
documentation_of: //library/struct/monoid.hpp
---


カスタム性として

```cpp
Monoid m(-1e9, [](int a, int b) { return max(a, b); });
```

その他、有名なモノイドを作っておく

