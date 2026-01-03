---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/segtree/dual_segment_tree.hpp
    title: "Dual Segment Tree \u533A\u9593\u66F4\u65B0 1\u70B9\u53D6\u5F97"
  - icon: ':heavy_check_mark:'
    path: library/segtree/lazy_segment_tree.hpp
    title: "Lazy Segment Tree \u533A\u9593\u66F4\u65B0 \u533A\u9593\u53D6\u5F97"
  - icon: ':heavy_check_mark:'
    path: library/segtree/segment_tree.hpp
    title: "Segment Tree 1\u70B9\u66F4\u65B0 \u533A\u9593\u53D6\u5F97"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/segtree.dual_segment_tree.test.cpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree.lazy_segment_tree.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree.segment_tree.test.cpp
    title: "\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30E2\u30CE\u30A4\u30C9"
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
    \            return x ^ y;\n        }\n    };\n};\n/**\n * @brief \u30E2\u30CE\
    \u30A4\u30C9\u4F5C\u7528\n */\nstruct MonoidAct {\n    // \u6F14\u7B97: \u52A0\
    \u7B97  \u66F4\u65B0: \u52A0\u7B97\n    struct AddAdd {\n        static constexpr\
    \ int op(const int &node, const int &a,\n                                const\
    \ int &size) {\n            return node + a * size;\n        }\n    };\n    //\
    \ \u6F14\u7B97: \u52A0\u7B97  \u66F4\u65B0: \u4EE3\u5165\n    struct AddSet {\n\
    \        static constexpr int op(const int &node, const int &a,\n            \
    \                    const int &size) {\n            return a == Monoid::Set::e\
    \ ? node : a * size;\n        }\n    };\n    // \u6F14\u7B97: \u6700\u5C0F\u5024\
    \  \u66F4\u65B0: \u52A0\u7B97\n    struct MinAdd {\n        static constexpr int\
    \ op(const int &node, const int &a,\n                                const int\
    \ &size) {\n            (void)size; // unused\n            return node == Monoid::Min::e\
    \ ? node : node + a;\n        }\n    };\n    // \u6F14\u7B97: \u6700\u5C0F\u5024\
    \  \u66F4\u65B0: \u4EE3\u5165\n    struct MinSet {\n        static constexpr int\
    \ op(const int &node, const int &a,\n                                const int\
    \ &size) {\n            (void)size; // unused\n            return a == Monoid::Set::e\
    \ ? node : a;\n        }\n    };\n    // TODO \u3082\u3063\u3068\u5897\u3084\u3059\
    \n};\n"
  code: "#pragma once\n/**\n * @brief \u30E2\u30CE\u30A4\u30C9\n */\nstruct Monoid\
    \ {\n    // \u6700\u5C0F\u5024\n    struct Min {\n        static constexpr int\
    \ e = INT_MAX;\n        static int op(int x, int y) {\n            return min(x,\
    \ y);\n        }\n    };\n    // \u6700\u5927\u5024\n    struct Max {\n      \
    \  static constexpr int e = -INT_MAX;\n        static int op(int x, int y) {\n\
    \            return max(x, y);\n        }\n    };\n    // \u52A0\u7B97\n    struct\
    \ Add {\n        static constexpr int e = 0;\n        static int op(int x, int\
    \ y) {\n            return x + y;\n        }\n    };\n    // \u4E57\u7B97\n  \
    \  struct Mul {\n        static constexpr int e = 1;\n        static int op(int\
    \ x, int y) {\n            return x * y;\n        }\n    };\n    // \u4EE3\u5165\
    \n    struct Set {\n        static constexpr int e = INT_MAX;\n        static\
    \ int op(int x, int y) {\n            return y == INT_MAX ? x : y;\n        }\n\
    \    };\n    // \u6700\u5927\u516C\u7D04\u6570\n    struct Gcd {\n        static\
    \ constexpr int e = 0;\n        static int op(int x, int y) {\n            return\
    \ gcd(x, y);\n        }\n    };\n    // \u6700\u5C0F\u516C\u500D\u6570\n    struct\
    \ Lcm {\n        static constexpr int e = 1;\n        static int op(int x, int\
    \ y) {\n            return lcm(x, y);\n        }\n    };\n    // \u6392\u4ED6\u7684\
    \u8AD6\u7406\u548C\n    struct Xor {\n        static constexpr int e = 0;\n  \
    \      static int op(int x, int y) {\n            return x ^ y;\n        }\n \
    \   };\n};\n/**\n * @brief \u30E2\u30CE\u30A4\u30C9\u4F5C\u7528\n */\nstruct MonoidAct\
    \ {\n    // \u6F14\u7B97: \u52A0\u7B97  \u66F4\u65B0: \u52A0\u7B97\n    struct\
    \ AddAdd {\n        static constexpr int op(const int &node, const int &a,\n \
    \                               const int &size) {\n            return node +\
    \ a * size;\n        }\n    };\n    // \u6F14\u7B97: \u52A0\u7B97  \u66F4\u65B0\
    : \u4EE3\u5165\n    struct AddSet {\n        static constexpr int op(const int\
    \ &node, const int &a,\n                                const int &size) {\n \
    \           return a == Monoid::Set::e ? node : a * size;\n        }\n    };\n\
    \    // \u6F14\u7B97: \u6700\u5C0F\u5024  \u66F4\u65B0: \u52A0\u7B97\n    struct\
    \ MinAdd {\n        static constexpr int op(const int &node, const int &a,\n \
    \                               const int &size) {\n            (void)size; //\
    \ unused\n            return node == Monoid::Min::e ? node : node + a;\n     \
    \   }\n    };\n    // \u6F14\u7B97: \u6700\u5C0F\u5024  \u66F4\u65B0: \u4EE3\u5165\
    \n    struct MinSet {\n        static constexpr int op(const int &node, const\
    \ int &a,\n                                const int &size) {\n            (void)size;\
    \ // unused\n            return a == Monoid::Set::e ? node : a;\n        }\n \
    \   };\n    // TODO \u3082\u3063\u3068\u5897\u3084\u3059\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/struct/monoid.hpp
  requiredBy:
  - library/segtree/segment_tree.hpp
  - library/segtree/lazy_segment_tree.hpp
  - library/segtree/dual_segment_tree.hpp
  timestamp: '2026-01-03 23:10:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/segtree.dual_segment_tree.test.cpp
  - tests/segtree.segment_tree.test.cpp
  - tests/segtree.lazy_segment_tree.test.cpp
documentation_of: library/struct/monoid.hpp
layout: document
title: "\u30E2\u30CE\u30A4\u30C9"
---


有名なモノイドを作っておく。以下のように呼べる。

```cpp
SegmentTree<int> seg(Monoid::Min::op, Monoid::Min::e, N);
```


