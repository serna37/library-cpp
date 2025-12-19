---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: main.cpp
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
  bundledCode: "#line 2 \"library/util/io.hpp\"\nstruct IoSetup {\n    IoSetup() {\n\
    \        cin.tie(0)->sync_with_stdio(0);\n        cout << fixed << setprecision(20);\n\
    \        cerr << fixed << setprecision(10);\n    }\n} iosetup;\ntemplate <typename\
    \ T> istream &operator>>(istream &s, vector<T> &v) {\n    for (auto &&e : v) s\
    \ >> e;\n    return s;\n}\ntemplate <typename T> ostream &operator<<(ostream &s,\
    \ vector<T> &v) {\n    int i = 0;\n    for (auto &&e : v) {\n        if (i++)\
    \ s << \" \";\n        s << e;\n    }\n    s << endl;\n    return s;\n}\n// \u884C\
    \u5217\u3092\u51FA\u529B\nauto coutGrid = []<class T>(vector<vector<T>> &G) {\n\
    \    for (auto &&v : G) cout << v;\n};\nvoid yn(bool o) {\n    cout << (o ? \"\
    Yes\" : \"No\") << endl;\n}\nvoid YN(bool o) {\n    cout << (o ? \"YES\" : \"\
    NO\") << endl;\n}\n"
  code: "#pragma once\nstruct IoSetup {\n    IoSetup() {\n        cin.tie(0)->sync_with_stdio(0);\n\
    \        cout << fixed << setprecision(20);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\ntemplate <typename T> istream &operator>>(istream &s, vector<T>\
    \ &v) {\n    for (auto &&e : v) s >> e;\n    return s;\n}\ntemplate <typename\
    \ T> ostream &operator<<(ostream &s, vector<T> &v) {\n    int i = 0;\n    for\
    \ (auto &&e : v) {\n        if (i++) s << \" \";\n        s << e;\n    }\n   \
    \ s << endl;\n    return s;\n}\n// \u884C\u5217\u3092\u51FA\u529B\nauto coutGrid\
    \ = []<class T>(vector<vector<T>> &G) {\n    for (auto &&v : G) cout << v;\n};\n\
    void yn(bool o) {\n    cout << (o ? \"Yes\" : \"No\") << endl;\n}\nvoid YN(bool\
    \ o) {\n    cout << (o ? \"YES\" : \"NO\") << endl;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/util/io.hpp
  requiredBy:
  - template/template.hpp
  - main.cpp
  timestamp: '2025-12-19 22:18:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/template.test.cpp
documentation_of: library/util/io.hpp
layout: document
title: "IO\u95A2\u9023"
---

`vector`を`cin >> A`や`cout << A`できるようにする。

2次元はリダイレクトだけでは無理
