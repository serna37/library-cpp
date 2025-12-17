---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: bits/stdc++.h
    title: "\u30AB\u30B9\u30BF\u30E0stdc++.h"
  - icon: ':warning:'
    path: library/const.hpp
    title: "\u5B9A\u6570"
  - icon: ':warning:'
    path: library/io.hpp
    title: "IO\u95A2\u9023"
  - icon: ':warning:'
    path: library/util.hpp
    title: "\u30E6\u30FC\u30C6\u30A3\u30EA\u30C6\u30A3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u0E05^>\u03C9<^\u0E05"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.cpp: line 6: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "/**\n * @brief \u0E05^>\u03C9<^\u0E05\n * @author serna37\n */\n#ifdef LOCAL\n\
    #include \"template/debug.hpp\"\n#else\n#define debug(...)\n#endif\n#include <bits/stdc++.h>\n\
    using namespace std;\n#include \"library/io.hpp\"\n#include \"library/const.hpp\"\
    \n#include \"library/util.hpp\"\n//#include \"library/string.hpp\"\n//#include\
    \ \"library/geo.hpp\"\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n   \
    \ cout << fixed << setprecision(20);\n}\n"
  dependsOn:
  - bits/stdc++.h
  - library/io.hpp
  - library/const.hpp
  - library/util.hpp
  isVerificationFile: false
  path: template/template.cpp
  requiredBy: []
  timestamp: '2025-12-17 23:43:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/template.cpp
layout: document
redirect_from:
- /library/template/template.cpp
- /library/template/template.cpp.html
title: "\u0E05^>\u03C9<^\u0E05"
---
