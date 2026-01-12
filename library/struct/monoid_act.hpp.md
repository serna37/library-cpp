---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/struct/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/segtree/lazy_segment_tree.hpp
    title: Lazy Segment Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/segtree/lazy_segment_tree.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RUQ"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30E2\u30CE\u30A4\u30C9\u4F5C\u7528\u7D20"
    links: []
  bundledCode: "#line 2 \"library/struct/monoid.hpp\"\n/**\n * @brief \u30E2\u30CE\
    \u30A4\u30C9\n */\nstruct Monoid {\n    // \u6700\u5C0F\u5024\n    struct Min\
    \ {\n        static constexpr int e = INT_MAX;\n        static int op(int x, int\
    \ y) {\n            return min(x, y);\n        }\n    };\n    // \u6700\u5927\u5024\
    \n    struct Max {\n        static constexpr int e = -INT_MAX;\n        static\
    \ int op(int x, int y) {\n            return max(x, y);\n        }\n    };\n \
    \   // \u52A0\u7B97\n    struct Add {\n        static constexpr int e = 0;\n \
    \       static int op(int x, int y) {\n            return x + y;\n        }\n\
    \    };\n    // \u4E57\u7B97\n    struct Mul {\n        static constexpr int e\
    \ = 1;\n        static int op(int x, int y) {\n            return x * y;\n   \
    \     }\n    };\n    // \u4EE3\u5165\n    struct Set {\n        static constexpr\
    \ int e = INT_MAX;\n        static int op(int x, int y) {\n            return\
    \ y == INT_MAX ? x : y;\n        }\n    };\n    // \u6700\u5927\u516C\u7D04\u6570\
    \n    struct Gcd {\n        static constexpr int e = 0;\n        static int op(int\
    \ x, int y) {\n            return gcd(x, y);\n        }\n    };\n    // \u6700\
    \u5C0F\u516C\u500D\u6570\n    struct Lcm {\n        static constexpr int e = 1;\n\
    \        static int op(int x, int y) {\n            return lcm(x, y);\n      \
    \  }\n    };\n    // \u6392\u4ED6\u7684\u8AD6\u7406\u548C\n    struct Xor {\n\
    \        static constexpr int e = 0;\n        static int op(int x, int y) {\n\
    \            return x ^ y;\n        }\n    };\n};\n#line 3 \"library/struct/monoid_act.hpp\"\
    \n/**\n * @brief \u30E2\u30CE\u30A4\u30C9\u4F5C\u7528\u7D20\n */\nstruct MonoidAct\
    \ {\n    // \u6F14\u7B97: \u52A0\u7B97  \u66F4\u65B0: \u52A0\u7B97\n    struct\
    \ AddAdd {\n        static constexpr int op(const int &node, const int &a,\n \
    \                               const int &size) {\n            return node +\
    \ a * size;\n        }\n    };\n    // \u6F14\u7B97: \u52A0\u7B97  \u66F4\u65B0\
    : \u4EE3\u5165\n    struct AddSet {\n        static constexpr int op(const int\
    \ &node, const int &a,\n                                const int &size) {\n \
    \           return a == Monoid::Set::e ? node : a * size;\n        }\n    };\n\
    \    // \u6F14\u7B97: \u52A0\u7B97  \u66F4\u65B0: \u6700\u5C0F\u5024\n    struct\
    \ AddMin {\n        static constexpr int op(const int &node, const int &a,\n \
    \                               const int &size) {\n            (void)size; //\
    \ unused\n            return min(node, a);\n        }\n    };\n    // \u6F14\u7B97\
    : \u52A0\u7B97  \u66F4\u65B0: \u6700\u5927\u5024\n    struct AddMax {\n      \
    \  static constexpr int op(const int &node, const int &a,\n                  \
    \              const int &size) {\n            (void)size; // unused\n       \
    \     return max(node, a);\n        }\n    };\n    // \u6F14\u7B97: \u6700\u5C0F\
    \u5024  \u66F4\u65B0: \u52A0\u7B97\n    struct MinAdd {\n        static constexpr\
    \ int op(const int &node, const int &a,\n                                const\
    \ int &size) {\n            (void)size; // unused\n            return node ==\
    \ Monoid::Min::e ? node : node + a;\n        }\n    };\n    // \u6F14\u7B97: \u6700\
    \u5C0F\u5024  \u66F4\u65B0: \u4EE3\u5165\n    struct MinSet {\n        static\
    \ constexpr int op(const int &node, const int &a,\n                          \
    \      const int &size) {\n            (void)size; // unused\n            return\
    \ a == Monoid::Set::e ? node : a;\n        }\n    };\n    // \u6F14\u7B97: \u6700\
    \u5C0F\u5024  \u66F4\u65B0: \u6700\u5C0F\u5024\n    struct MinMin {\n        static\
    \ constexpr int op(const int &node, const int &a,\n                          \
    \      const int &size) {\n            (void)size; // unused\n            return\
    \ min(node, a);\n        }\n    };\n    // \u6F14\u7B97: \u6700\u5C0F\u5024  \u66F4\
    \u65B0: \u6700\u5927\u5024\n    struct MinMax {\n        static constexpr int\
    \ op(const int &node, const int &a,\n                                const int\
    \ &size) {\n            (void)size; // unused\n            return max(node, a);\n\
    \        }\n    };\n    // \u6F14\u7B97: \u6700\u5927\u5024  \u66F4\u65B0: \u52A0\
    \u7B97\n    struct MaxAdd {\n        static constexpr int op(const int &node,\
    \ const int &a,\n                                const int &size) {\n        \
    \    (void)size; // unused\n            return node == Monoid::Max::e ? node :\
    \ node + a;\n        }\n    };\n    // \u6F14\u7B97: \u6700\u5927\u5024  \u66F4\
    \u65B0: \u4EE3\u5165\n    struct MaxSet {\n        static constexpr int op(const\
    \ int &node, const int &a,\n                                const int &size) {\n\
    \            (void)size; // unused\n            return a == Monoid::Set::e ? node\
    \ : a;\n        }\n    };\n    // \u6F14\u7B97: \u6700\u5927\u5024  \u66F4\u65B0\
    : \u6700\u5C0F\u5024\n    struct MaxMin {\n        static constexpr int op(const\
    \ int &node, const int &a,\n                                const int &size) {\n\
    \            (void)size; // unused\n            return min(node, a);\n       \
    \ }\n    };\n    // \u6F14\u7B97: \u6700\u5927\u5024  \u66F4\u65B0: \u6700\u5927\
    \u5024\n    struct MaxMax {\n        static constexpr int op(const int &node,\
    \ const int &a,\n                                const int &size) {\n        \
    \    (void)size; // unused\n            return max(node, a);\n        }\n    };\n\
    };\n"
  code: "#pragma once\n#include \"library/struct/monoid.hpp\"\n/**\n * @brief \u30E2\
    \u30CE\u30A4\u30C9\u4F5C\u7528\u7D20\n */\nstruct MonoidAct {\n    // \u6F14\u7B97\
    : \u52A0\u7B97  \u66F4\u65B0: \u52A0\u7B97\n    struct AddAdd {\n        static\
    \ constexpr int op(const int &node, const int &a,\n                          \
    \      const int &size) {\n            return node + a * size;\n        }\n  \
    \  };\n    // \u6F14\u7B97: \u52A0\u7B97  \u66F4\u65B0: \u4EE3\u5165\n    struct\
    \ AddSet {\n        static constexpr int op(const int &node, const int &a,\n \
    \                               const int &size) {\n            return a == Monoid::Set::e\
    \ ? node : a * size;\n        }\n    };\n    // \u6F14\u7B97: \u52A0\u7B97  \u66F4\
    \u65B0: \u6700\u5C0F\u5024\n    struct AddMin {\n        static constexpr int\
    \ op(const int &node, const int &a,\n                                const int\
    \ &size) {\n            (void)size; // unused\n            return min(node, a);\n\
    \        }\n    };\n    // \u6F14\u7B97: \u52A0\u7B97  \u66F4\u65B0: \u6700\u5927\
    \u5024\n    struct AddMax {\n        static constexpr int op(const int &node,\
    \ const int &a,\n                                const int &size) {\n        \
    \    (void)size; // unused\n            return max(node, a);\n        }\n    };\n\
    \    // \u6F14\u7B97: \u6700\u5C0F\u5024  \u66F4\u65B0: \u52A0\u7B97\n    struct\
    \ MinAdd {\n        static constexpr int op(const int &node, const int &a,\n \
    \                               const int &size) {\n            (void)size; //\
    \ unused\n            return node == Monoid::Min::e ? node : node + a;\n     \
    \   }\n    };\n    // \u6F14\u7B97: \u6700\u5C0F\u5024  \u66F4\u65B0: \u4EE3\u5165\
    \n    struct MinSet {\n        static constexpr int op(const int &node, const\
    \ int &a,\n                                const int &size) {\n            (void)size;\
    \ // unused\n            return a == Monoid::Set::e ? node : a;\n        }\n \
    \   };\n    // \u6F14\u7B97: \u6700\u5C0F\u5024  \u66F4\u65B0: \u6700\u5C0F\u5024\
    \n    struct MinMin {\n        static constexpr int op(const int &node, const\
    \ int &a,\n                                const int &size) {\n            (void)size;\
    \ // unused\n            return min(node, a);\n        }\n    };\n    // \u6F14\
    \u7B97: \u6700\u5C0F\u5024  \u66F4\u65B0: \u6700\u5927\u5024\n    struct MinMax\
    \ {\n        static constexpr int op(const int &node, const int &a,\n        \
    \                        const int &size) {\n            (void)size; // unused\n\
    \            return max(node, a);\n        }\n    };\n    // \u6F14\u7B97: \u6700\
    \u5927\u5024  \u66F4\u65B0: \u52A0\u7B97\n    struct MaxAdd {\n        static\
    \ constexpr int op(const int &node, const int &a,\n                          \
    \      const int &size) {\n            (void)size; // unused\n            return\
    \ node == Monoid::Max::e ? node : node + a;\n        }\n    };\n    // \u6F14\u7B97\
    : \u6700\u5927\u5024  \u66F4\u65B0: \u4EE3\u5165\n    struct MaxSet {\n      \
    \  static constexpr int op(const int &node, const int &a,\n                  \
    \              const int &size) {\n            (void)size; // unused\n       \
    \     return a == Monoid::Set::e ? node : a;\n        }\n    };\n    // \u6F14\
    \u7B97: \u6700\u5927\u5024  \u66F4\u65B0: \u6700\u5C0F\u5024\n    struct MaxMin\
    \ {\n        static constexpr int op(const int &node, const int &a,\n        \
    \                        const int &size) {\n            (void)size; // unused\n\
    \            return min(node, a);\n        }\n    };\n    // \u6F14\u7B97: \u6700\
    \u5927\u5024  \u66F4\u65B0: \u6700\u5927\u5024\n    struct MaxMax {\n        static\
    \ constexpr int op(const int &node, const int &a,\n                          \
    \      const int &size) {\n            (void)size; // unused\n            return\
    \ max(node, a);\n        }\n    };\n};\n"
  dependsOn:
  - library/struct/monoid.hpp
  isVerificationFile: false
  path: library/struct/monoid_act.hpp
  requiredBy:
  - library/segtree/lazy_segment_tree.hpp
  timestamp: '2026-01-12 16:39:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/segtree/lazy_segment_tree.test.cpp
documentation_of: library/struct/monoid_act.hpp
layout: document
title: "\u30E2\u30CE\u30A4\u30C9\u4F5C\u7528\u7D20"
---

# モノイド作用素

## できること
- 二項演算を定義してるだけ

## 計算量
$O(1)$

## 使い方
```cpp
LazySegmentTree<int, int> seg(Monoid::Min::op, Monoid::Min::e, Monoid::Add::op, Monoid::Add::e, MonoidAct::MinAdd::op N);
```
