---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template/template.cpp
    title: "\u0E05^>\u03C9<^\u0E05"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "IO\u95A2\u9023"
    links: []
  bundledCode: "#line 2 \"library/io.hpp\"\n/**\n * @file io.hpp\n * @brief IO\u95A2\
    \u9023\n */\n// cin >> vector\u3067\u53D7\u3051\u53D6\u308B\ntemplate <typename\
    \ T> inline istream &operator>>(istream &s, vector<T> &v) {\n    for (T &t : v)\
    \ {\n        s >> t;\n    }\n    return s;\n}\n// Yes No \u51FA\u529B\ninline\
    \ void yn(bool isok) {\n    cout << (isok ? \"Yes\" : \"No\") << endl;\n}\n//\
    \ YES NO \u51FA\u529B\ninline void YN(bool isok) {\n    cout << (isok ? \"YES\"\
    \ : \"NO\") << endl;\n}\n// cout << vector\u3067\u51FA\u529B(1\u6B21\u5143\u307E\
    \u3067)\ntemplate <typename T>\ninline ostream &operator<<(ostream &s, const vector<T>\
    \ &v) {\n    int i = 0;\n    for (auto &&e : v) {\n        if (i++) s << \" \"\
    ;\n        s << e;\n    }\n    s << endl;\n    return s;\n}\n// \u884C\u5217\u3092\
    \u51FA\u529B\ntemplate <typename T> void coutGrid(vector<vector<T>> &G) {\n  \
    \  for (auto &&v : G) {\n        cout << v;\n    }\n}\n// TODO \u30B0\u30E9\u30D5\
    \u306Ecin\u3068\u304B\n"
  code: "#pragma once\n/**\n * @file io.hpp\n * @brief IO\u95A2\u9023\n */\n// cin\
    \ >> vector\u3067\u53D7\u3051\u53D6\u308B\ntemplate <typename T> inline istream\
    \ &operator>>(istream &s, vector<T> &v) {\n    for (T &t : v) {\n        s >>\
    \ t;\n    }\n    return s;\n}\n// Yes No \u51FA\u529B\ninline void yn(bool isok)\
    \ {\n    cout << (isok ? \"Yes\" : \"No\") << endl;\n}\n// YES NO \u51FA\u529B\
    \ninline void YN(bool isok) {\n    cout << (isok ? \"YES\" : \"NO\") << endl;\n\
    }\n// cout << vector\u3067\u51FA\u529B(1\u6B21\u5143\u307E\u3067)\ntemplate <typename\
    \ T>\ninline ostream &operator<<(ostream &s, const vector<T> &v) {\n    int i\
    \ = 0;\n    for (auto &&e : v) {\n        if (i++) s << \" \";\n        s << e;\n\
    \    }\n    s << endl;\n    return s;\n}\n// \u884C\u5217\u3092\u51FA\u529B\n\
    template <typename T> void coutGrid(vector<vector<T>> &G) {\n    for (auto &&v\
    \ : G) {\n        cout << v;\n    }\n}\n// TODO \u30B0\u30E9\u30D5\u306Ecin\u3068\
    \u304B\n"
  dependsOn: []
  isVerificationFile: false
  path: library/io.hpp
  requiredBy:
  - template/template.cpp
  timestamp: '2025-12-17 23:43:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/io.hpp
layout: document
redirect_from:
- /library/library/io.hpp
- /library/library/io.hpp.html
title: "IO\u95A2\u9023"
---
