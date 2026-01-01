---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: "\U0001F36A\U0001F9F8\U0001F43E"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u0E05^>\u03C9<^\u0E05"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/template.test.cpp
    title: tests/template.test.cpp
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
    \ */\n#pragma once\ntemplate <typename U, typename F> struct Monoid {\n    using\
    \ T = U;\n\n  private:\n    T _e;\n    F _op;\n\n  public:\n    Monoid(T e, F\
    \ op) : _e(e), _op(op) {\n    }\n    T op(const T &x, const T &y) {\n        return\
    \ _op(x, y);\n    }\n    T e() {\n        return _e;\n    }\n};\ntemplate <typename\
    \ U = int> struct MonoidMin {\n    using T = U;\n    T op(const T &x, const T\
    \ &y) {\n        return min(x, y);\n    }\n    T e() {\n        return INF;\n\
    \    }\n};\ntemplate <typename U = int> struct MonoidMax {\n    using T = U;\n\
    \    T op(const T &x, const T &y) {\n        return max(x, y);\n    }\n    T e()\
    \ {\n        return -INF;\n    }\n};\ntemplate <typename U = int> struct MonoidAdd\
    \ {\n    using T = U;\n    T op(const T &x, const T &y) {\n        return x +\
    \ y;\n    }\n    T e() {\n        return 0ll;\n    }\n};\ntemplate <typename U\
    \ = int> struct MonoidMul {\n    using T = U;\n    T op(const T &x, const T &y)\
    \ {\n        return x * y;\n    }\n    T e() {\n        return 1ll;\n    }\n};\n\
    template <typename U = int> struct MonoidGcd {\n    using T = U;\n    T op(const\
    \ T &x, const T &y) {\n        return gcd(x, y);\n    }\n    T e() {\n       \
    \ return 0ll;\n    }\n};\ntemplate <typename U = int> struct MonoidLcm {\n   \
    \ using T = U;\n    T op(const T &x, const T &y) {\n        return lcm(x, y);\n\
    \    }\n    T e() {\n        return 1ll;\n    }\n};\ntemplate <typename U = int>\
    \ struct MonoidXor {\n    using T = U;\n    T op(const T &x, const T &y) {\n \
    \       return x ^ y;\n    }\n    T e() {\n        return 0ll;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/struct/monoid.hpp
  requiredBy:
  - template/template.hpp
  - main.cpp
  timestamp: '2026-01-01 11:08:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/template.test.cpp
documentation_of: library/struct/monoid.hpp
layout: document
title: "\u30E2\u30CE\u30A4\u30C9"
---


カスタム性として

```cpp
Monoid m(-1e9, [](int a, int b) { return max(a, b); });
```

その他、有名なモノイドを作っておく

