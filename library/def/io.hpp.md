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
    path: tests/struct.dual_segment_tree.test.cpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/struct.fenwick_tree.test.cpp
    title: "Fenwick Tree\u306E\u30C6\u30B9\u30C8:RSQ"
  - icon: ':heavy_check_mark:'
    path: tests/struct.lazy_segment_tree.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/struct.segment_tree.test.cpp
    title: "\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ"
  - icon: ':heavy_check_mark:'
    path: tests/struct.union_find.test.cpp
    title: "Union Find\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/template.test.cpp
    title: "library/util/xxx.hpp\u306E\u30E6\u30CB\u30C3\u30C8\u30C6\u30B9\u30C8"
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
    \ library/def/io.hpp: line 5: #pragma once found in a non-first line\n"
  code: "\n/** ======================================= */\n/**                IO \
    \                      */\n/** ======================================= */\n#pragma\
    \ once\nstruct IoSetup {\n    IoSetup() {\n        cin.tie(0)->sync_with_stdio(0);\n\
    \        cout << fixed << setprecision(20);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\ntemplate <typename T> istream &operator>>(istream &s, vector<T>\
    \ &v) {\n    for (auto &&e : v) s >> e;\n    return s;\n}\ntemplate <typename\
    \ T> ostream &operator<<(ostream &s, const vector<T> &v) {\n    int i = 0;\n \
    \   for (auto &&e : v) s << (i++ ? \" \" : \"\") << e;\n    return s;\n}\ntemplate\
    \ <typename T> void print(const vector<vector<T>> &G) {\n    for (auto &&v : G)\
    \ cout << v << endl;\n}\ntemplate <typename T, typename U> void print(const pair<T,\
    \ U> &p) {\n    cout << p.first << \" \" << p.second << endl;\n}\ntemplate <typename\
    \ T> void print(const T &v) {\n    cout << v << endl;\n}\nvoid yn(bool o) {\n\
    \    cout << (o ? \"Yes\" : \"No\") << endl;\n}\nvoid YN(bool o) {\n    cout <<\
    \ (o ? \"YES\" : \"NO\") << endl;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/def/io.hpp
  requiredBy:
  - template/template.hpp
  - main.cpp
  timestamp: '2026-01-03 22:10:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/struct.lazy_segment_tree.test.cpp
  - tests/struct.fenwick_tree.test.cpp
  - tests/template.test.cpp
  - tests/struct.dual_segment_tree.test.cpp
  - tests/struct.segment_tree.test.cpp
  - tests/struct.union_find.test.cpp
documentation_of: library/def/io.hpp
layout: document
title: "IO\u95A2\u9023"
---

`vector`を`cin >> A`や`cout << A`できるようにする。

2次元はリダイレクトだけでは無理
