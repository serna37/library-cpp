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
    document_title: "\u30E6\u30FC\u30C6\u30A3\u30EA\u30C6\u30A3"
    links: []
  bundledCode: "#line 2 \"library/util.hpp\"\n/**\n * @file util.hpp\n * @brief \u30E6\
    \u30FC\u30C6\u30A3\u30EA\u30C6\u30A3\n */\n#define all(x) begin(x), end(x)\n#define\
    \ rall(x) rbegin(x), rend(x)\n// \u91CD\u8907\u524A\u9664\ntemplate <typename\
    \ T> void distinct(vector<T> &v) {\n    sort(all(v));\n    v.erase(unique(all(v)),\
    \ v.end());\n}\n// int \u2192 char\nchar int_to_char(int x) {\n    return (char)(x\
    \ + '0');\n}\n// char \u2192 int\nint char_to_int(char c) {\n    return (int)(c\
    \ - '0');\n}\n// \u884C\u5217\u306E\u8EE2\u7F6E\ntemplate <typename T> vector<vector<T>>\
    \ transpose(vector<vector<T>> G) {\n    int H = G.size(), W = G[0].size();\n \
    \   vector<vector<T>> _G(W, vector<T>(H));\n    for (int i = 0; i < H; ++i) {\n\
    \        for (int j = 0; j < W; ++j) {\n            _G[j][i] = G[i][j];\n    \
    \    }\n    }\n    return _G;\n}\n"
  code: "#pragma once\n/**\n * @file util.hpp\n * @brief \u30E6\u30FC\u30C6\u30A3\u30EA\
    \u30C6\u30A3\n */\n#define all(x) begin(x), end(x)\n#define rall(x) rbegin(x),\
    \ rend(x)\n// \u91CD\u8907\u524A\u9664\ntemplate <typename T> void distinct(vector<T>\
    \ &v) {\n    sort(all(v));\n    v.erase(unique(all(v)), v.end());\n}\n// int \u2192\
    \ char\nchar int_to_char(int x) {\n    return (char)(x + '0');\n}\n// char \u2192\
    \ int\nint char_to_int(char c) {\n    return (int)(c - '0');\n}\n// \u884C\u5217\
    \u306E\u8EE2\u7F6E\ntemplate <typename T> vector<vector<T>> transpose(vector<vector<T>>\
    \ G) {\n    int H = G.size(), W = G[0].size();\n    vector<vector<T>> _G(W, vector<T>(H));\n\
    \    for (int i = 0; i < H; ++i) {\n        for (int j = 0; j < W; ++j) {\n  \
    \          _G[j][i] = G[i][j];\n        }\n    }\n    return _G;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/util.hpp
  requiredBy:
  - template/template.cpp
  timestamp: '2025-12-17 23:43:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/util.hpp
layout: document
redirect_from:
- /library/library/util.hpp
- /library/library/util.hpp.html
title: "\u30E6\u30FC\u30C6\u30A3\u30EA\u30C6\u30A3"
---
