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
    \ library/def/common.hpp: line 5: #pragma once found in a non-first line\n"
  code: "\n/** ======================================= */\n/**              \u5171\
    \u901A                       */\n/** ======================================= */\n\
    #pragma once\n#define int long long\n#define all(x) begin(x), end(x)\n#define\
    \ rall(x) rbegin(x), rend(x)\n#define $(idx) (std::get<(idx)>(std::forward_as_tuple(_args...)))\n\
    // lambda($(0) + $(1))\u3068\u3067\u304D\u308B\n#define lambda(...) ([&](auto\
    \ &&..._args) { return (__VA_ARGS__); })\nauto chmin = []<class T>(T &i, const\
    \ T &j) { return i > j && (i = j, true); };\nauto chmax = []<class T>(T &i, const\
    \ T &j) { return i < j && (i = j, true); };\n"
  dependsOn: []
  isVerificationFile: false
  path: library/def/common.hpp
  requiredBy:
  - template/template.hpp
  - main.cpp
  timestamp: '2025-12-27 21:28:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/template.test.cpp
documentation_of: library/def/common.hpp
layout: document
title: "\u5171\u901A"
---

# 共通

`int`は`long long`として扱います。

管理内容
- マクロなど、全体を通して利用するもの
- その他 的なカテゴリのもの
