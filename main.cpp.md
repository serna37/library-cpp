---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bits/stdc++.h
    title: "\u30AB\u30B9\u30BF\u30E0stdc++.h"
  - icon: ':heavy_check_mark:'
    path: library/util/common.hpp
    title: "\u5171\u901A"
  - icon: ':heavy_check_mark:'
    path: library/util/const.hpp
    title: "\u5B9A\u6570"
  - icon: ':heavy_check_mark:'
    path: library/util/io.hpp
    title: "IO\u95A2\u9023"
  - icon: ':heavy_check_mark:'
    path: library/util/math.hpp
    title: "\u6570\u5B66\u7CFB"
  - icon: ':heavy_check_mark:'
    path: library/util/search.hpp
    title: "\u63A2\u7D22"
  - icon: ':heavy_check_mark:'
    path: library/util/seq.hpp
    title: "\u914D\u5217\u30FB\u96C6\u5408\u30FB\u6570\u5217"
  - icon: ':heavy_check_mark:'
    path: library/util/type.hpp
    title: "\u578B"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u0E05^>\u03C9<^\u0E05"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.hpp: line 7: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: '#include "template/template.hpp"

    signed main() {

    }

    '
  dependsOn:
  - template/template.hpp
  - bits/stdc++.h
  - library/util/common.hpp
  - library/util/io.hpp
  - library/util/type.hpp
  - library/util/const.hpp
  - library/util/seq.hpp
  - library/util/math.hpp
  - library/util/search.hpp
  isVerificationFile: false
  path: main.cpp
  requiredBy: []
  timestamp: '2025-12-19 22:18:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: main.cpp
layout: document
redirect_from:
- /library/main.cpp
- /library/main.cpp.html
title: main.cpp
---
