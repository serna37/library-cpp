---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/struct.dual_segment_tree.test.cpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/struct.lazy_segment_tree.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/struct.segment_tree.test.cpp
    title: "\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/struct/monoid.hpp: line 5: #pragma once found in a non-first line\n"
  code: "\n/** ======================================= */\n/**              \u30E2\
    \u30CE\u30A4\u30C9                   */\n/** =======================================\
    \ */\n#pragma once\nstruct Monoid {\n    // \u6700\u5C0F\u5024\n    struct Min\
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
    \            return x ^ y;\n        }\n    };\n};\nstruct MonoidAct {\n    //\
    \ \u6F14\u7B97: \u52A0\u7B97  \u66F4\u65B0: \u52A0\u7B97\n    struct AddAdd {\n\
    \        static constexpr int op(const int &node, const int &a,\n            \
    \                    const int &size) {\n            return node + a * size;\n\
    \        }\n    };\n    // \u6F14\u7B97: \u52A0\u7B97  \u66F4\u65B0: \u4EE3\u5165\
    \n    struct AddSet {\n        static constexpr int op(const int &node, const\
    \ int &a,\n                                const int &size) {\n            return\
    \ a == Monoid::Set::e ? node : a * size;\n        }\n    };\n    // \u6F14\u7B97\
    : \u6700\u5C0F\u5024  \u66F4\u65B0: \u52A0\u7B97\n    struct MinAdd {\n      \
    \  static constexpr int op(const int &node, const int &a,\n                  \
    \              const int &size) {\n            (void)size; // unused\n       \
    \     return node == Monoid::Min::e ? node : node + a;\n        }\n    };\n  \
    \  // \u6F14\u7B97: \u6700\u5C0F\u5024  \u66F4\u65B0: \u4EE3\u5165\n    struct\
    \ MinSet {\n        static constexpr int op(const int &node, const int &a,\n \
    \                               const int &size) {\n            (void)size; //\
    \ unused\n            return a == Monoid::Set::e ? node : a;\n        }\n    };\n\
    \    // TODO \u3082\u3063\u3068\u5897\u3084\u3059\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/struct/monoid.hpp
  requiredBy: []
  timestamp: '2026-01-03 21:39:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/struct.lazy_segment_tree.test.cpp
  - tests/struct.dual_segment_tree.test.cpp
  - tests/struct.segment_tree.test.cpp
documentation_of: library/struct/monoid.hpp
layout: document
title: "\u30E2\u30CE\u30A4\u30C9"
---


有名なモノイドを作っておく。以下のように呼べる。

```cpp
SegmentTree<int> seg(Monoid::Min::op, Monoid::Min::e, N);
```


