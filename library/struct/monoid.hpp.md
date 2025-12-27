---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ U> struct MonoidMin {\n    using T = U;\n    T op(const T &x, const T &y) {\n\
    \        return min(x, y);\n    }\n    T e() {\n        return INF;\n    }\n};\n\
    // TODO \u307B\u304B\u306E\u3082\n"
  dependsOn: []
  isVerificationFile: false
  path: library/struct/monoid.hpp
  requiredBy: []
  timestamp: '2025-12-27 21:21:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/struct/monoid.hpp
layout: document
redirect_from:
- /library/library/struct/monoid.hpp
- /library/library/struct/monoid.hpp.html
title: library/struct/monoid.hpp
---
