---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: "main\u30D5\u30A1\u30A4\u30EB"
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
    \ library/def/const.hpp: line 5: #pragma once found in a non-first line\n"
  code: "\n/** ======================================= */\n/**              \u5B9A\
    \u6570                       */\n/** ======================================= */\n\
    #pragma once\nconst long long INF = 1e18;\nconst long long MAX = 2e6;\nconst long\
    \ long MOD = 998244353;\nconst long long MOD7 = 1e9 + 7;\nconst long double EPS\
    \ = 1e-14;\nconst double PI = acos(-1);\n// \u4E0B\u53F3\u4E0A\u5DE6 DRUL\nconst\
    \ vector<int> dx = {0, 1, 0, -1};\nconst vector<int> dy = {1, 0, -1, 0};\n// 8\u65B9\
    \u5411\nconst vector<int> dx8 = {0, 1, 0, -1, 1, -1, 1, -1};\nconst vector<int>\
    \ dy8 = {1, 0, -1, 0, 1, 1, -1, -1};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/def/const.hpp
  requiredBy:
  - template/template.hpp
  - main.cpp
  timestamp: '2026-01-02 11:22:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/template.test.cpp
documentation_of: library/def/const.hpp
layout: document
title: "\u5B9A\u6570"
---
