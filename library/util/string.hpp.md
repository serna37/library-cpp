---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: "main\u30D5\u30A1\u30A4\u30EB"
  - icon: ':heavy_check_mark:'
    path: template/lib.hpp
    title: "library/util/*.hpp\u306Einclude\u7528"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/segtree.dual_segment_tree.test.cpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree.fenwick_tree.test.cpp
    title: "Fenwick Tree\u306E\u30C6\u30B9\u30C8:RSQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree.lazy_segment_tree.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/segtree.segment_tree.test.cpp
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
    document_title: "\u6587\u5B57\u5217"
    links: []
  bundledCode: "#line 2 \"library/util/string.hpp\"\n/**\n * @brief \u6587\u5B57\u5217\
    \n */\nclass String {\n  public:\n    bool is_low(char c) {\n        return islower(c)\
    \ != 0;\n    }\n    bool is_upp(char c) {\n        return isupper(c) != 0;\n \
    \   }\n    // \u5C0F\u6587\u5B57\u306B\u5909\u63DB\n    string transform_lower(string\
    \ s) {\n        std::transform(all(s), s.begin(), ::tolower);\n        return\
    \ s;\n    }\n    // \u5927\u6587\u5B57\u306B\u5909\u63DB\n    string transform_upper(string\
    \ s) {\n        std::transform(all(s), s.begin(), ::toupper);\n        return\
    \ s;\n    }\n    // \u300C0000ABCDE\u300D\u5DE6\u5074\u3092\u57CB\u3081\u305F\
    size\u6841\u306E\u6587\u5B57\n    string lpad(const string &S, int size, char\
    \ ch = '0') {\n        int N = S.size();\n        if (N >= size) return S;\n \
    \       return string(size - N, ch) + S;\n    }\n    // \u300CABCDE0000\u300D\u53F3\
    \u3092\u57CB\u3081\u305Fsize\u6841\u306E\u6587\u5B57\n    string rpad(const string\
    \ &S, int size, char ch = '0') {\n        int N = S.size();\n        if (N >=\
    \ size) return S;\n        return S + string(size - N, ch);\n    }\n    /**\n\
    \     * \u6587\u5B57\u5217T\u306E\u4E2D\u306B\u3042\u308BS\u306E\u4E00\u81F4\u5834\
    \u6240\u3092\u5168\u3066\u53D6\u5F97\n     * \u30DE\u30C3\u30C1\u3057\u305F\u982D\
    \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u8FD4\u3059\n     */\n    vector<int>\
    \ finds(const string &T, const string &S) {\n        vector<int> pos;\n      \
    \  auto p = T.find(S);\n        while (p != string::npos) {\n            pos.emplace_back(p);\n\
    \            p = T.find(S, p + 1);\n        }\n        return pos;\n    }\n  \
    \  // \u533A\u5207\u308A\u6587\u5B57(1\u6587\u5B57)\u3067\u533A\u5207\u308B\n\
    \    vector<string> split(const string &S, const char &sep) {\n        vector<string>\
    \ res = {\"\"};\n        for (auto &&v : S) {\n            if (v == sep) {\n \
    \               res.emplace_back(\"\");\n            } else {\n              \
    \  res.back() += v;\n            }\n        }\n        return res;\n    }\n  \
    \  // \u8907\u6570\u306E\u533A\u5207\u308A\u6587\u5B57\u3067\u533A\u5207\u308B\
    \ \u533A\u5207\u308A\u6587\u5B57\u304C\u306A\u3044\u5834\u5408\u7A7A\u6587\u5B57\
    \n    vector<string> split_multi(const string &S, const string &seps) {\n    \
    \    vector<string> res = {\"\"};\n        for (auto &&v : S) {\n            if\
    \ (count(all(seps), v)) {\n                res.emplace_back(\"\");\n         \
    \   } else {\n                res.back() += v;\n            }\n        }\n   \
    \     return res;\n    }\n    // \u6587\u5B57\u5217\u306E\u533A\u9593[A, B]\u3092\
    \u53D6\u5F97\n    string str_range(const string &S, int A, int B) {\n        if\
    \ (A > B or A >= (int)S.size()) return \"\";\n        return S.substr(A, B - A\
    \ + 1);\n    }\n    // \u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\n    vector<pair<char,\
    \ int>> run_length(const string &S) {\n        vector<pair<char, int>> res;\n\
    \        for (auto &&x : S) {\n            if (res.empty() or res.back().first\
    \ != x) res.emplace_back(x, 0);\n            ++res.back().second;\n        }\n\
    \        return res;\n    }\n    // Z-Algorithm: S\u3068S[i:|S|]\u306E\u6700\u5927\
    \u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\n    vector<int> z_algo(const\
    \ string &S) {\n        int n = S.size();\n        if (n == 0) return {};\n  \
    \      vector<int> z(n);\n        z[0] = n;\n        for (int i = 1, j = 0; i\
    \ < n; ++i) {\n            int &k = z[i];\n            k = (j + z[j] <= i) ? 0\
    \ : min(j + z[j] - i, z[i - j]);\n            while (i + k < n and S[k] == S[i\
    \ + k]) ++k;\n            if (j + z[j] < i + z[i]) j = i;\n        }\n       \
    \ return z;\n    }\n};\n"
  code: "#pragma once\n/**\n * @brief \u6587\u5B57\u5217\n */\nclass String {\n  public:\n\
    \    bool is_low(char c) {\n        return islower(c) != 0;\n    }\n    bool is_upp(char\
    \ c) {\n        return isupper(c) != 0;\n    }\n    // \u5C0F\u6587\u5B57\u306B\
    \u5909\u63DB\n    string transform_lower(string s) {\n        std::transform(all(s),\
    \ s.begin(), ::tolower);\n        return s;\n    }\n    // \u5927\u6587\u5B57\u306B\
    \u5909\u63DB\n    string transform_upper(string s) {\n        std::transform(all(s),\
    \ s.begin(), ::toupper);\n        return s;\n    }\n    // \u300C0000ABCDE\u300D\
    \u5DE6\u5074\u3092\u57CB\u3081\u305Fsize\u6841\u306E\u6587\u5B57\n    string lpad(const\
    \ string &S, int size, char ch = '0') {\n        int N = S.size();\n        if\
    \ (N >= size) return S;\n        return string(size - N, ch) + S;\n    }\n   \
    \ // \u300CABCDE0000\u300D\u53F3\u3092\u57CB\u3081\u305Fsize\u6841\u306E\u6587\
    \u5B57\n    string rpad(const string &S, int size, char ch = '0') {\n        int\
    \ N = S.size();\n        if (N >= size) return S;\n        return S + string(size\
    \ - N, ch);\n    }\n    /**\n     * \u6587\u5B57\u5217T\u306E\u4E2D\u306B\u3042\
    \u308BS\u306E\u4E00\u81F4\u5834\u6240\u3092\u5168\u3066\u53D6\u5F97\n     * \u30DE\
    \u30C3\u30C1\u3057\u305F\u982D\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\
    \u8FD4\u3059\n     */\n    vector<int> finds(const string &T, const string &S)\
    \ {\n        vector<int> pos;\n        auto p = T.find(S);\n        while (p !=\
    \ string::npos) {\n            pos.emplace_back(p);\n            p = T.find(S,\
    \ p + 1);\n        }\n        return pos;\n    }\n    // \u533A\u5207\u308A\u6587\
    \u5B57(1\u6587\u5B57)\u3067\u533A\u5207\u308B\n    vector<string> split(const\
    \ string &S, const char &sep) {\n        vector<string> res = {\"\"};\n      \
    \  for (auto &&v : S) {\n            if (v == sep) {\n                res.emplace_back(\"\
    \");\n            } else {\n                res.back() += v;\n            }\n\
    \        }\n        return res;\n    }\n    // \u8907\u6570\u306E\u533A\u5207\u308A\
    \u6587\u5B57\u3067\u533A\u5207\u308B \u533A\u5207\u308A\u6587\u5B57\u304C\u306A\
    \u3044\u5834\u5408\u7A7A\u6587\u5B57\n    vector<string> split_multi(const string\
    \ &S, const string &seps) {\n        vector<string> res = {\"\"};\n        for\
    \ (auto &&v : S) {\n            if (count(all(seps), v)) {\n                res.emplace_back(\"\
    \");\n            } else {\n                res.back() += v;\n            }\n\
    \        }\n        return res;\n    }\n    // \u6587\u5B57\u5217\u306E\u533A\u9593\
    [A, B]\u3092\u53D6\u5F97\n    string str_range(const string &S, int A, int B)\
    \ {\n        if (A > B or A >= (int)S.size()) return \"\";\n        return S.substr(A,\
    \ B - A + 1);\n    }\n    // \u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\n\
    \    vector<pair<char, int>> run_length(const string &S) {\n        vector<pair<char,\
    \ int>> res;\n        for (auto &&x : S) {\n            if (res.empty() or res.back().first\
    \ != x) res.emplace_back(x, 0);\n            ++res.back().second;\n        }\n\
    \        return res;\n    }\n    // Z-Algorithm: S\u3068S[i:|S|]\u306E\u6700\u5927\
    \u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\n    vector<int> z_algo(const\
    \ string &S) {\n        int n = S.size();\n        if (n == 0) return {};\n  \
    \      vector<int> z(n);\n        z[0] = n;\n        for (int i = 1, j = 0; i\
    \ < n; ++i) {\n            int &k = z[i];\n            k = (j + z[j] <= i) ? 0\
    \ : min(j + z[j] - i, z[i - j]);\n            while (i + k < n and S[k] == S[i\
    \ + k]) ++k;\n            if (j + z[j] < i + z[i]) j = i;\n        }\n       \
    \ return z;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/util/string.hpp
  requiredBy:
  - template/lib.hpp
  - template/template.hpp
  - main.cpp
  timestamp: '2026-01-05 20:31:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/segtree.dual_segment_tree.test.cpp
  - tests/segtree.segment_tree.test.cpp
  - tests/template.test.cpp
  - tests/segtree.lazy_segment_tree.test.cpp
  - tests/segtree.fenwick_tree.test.cpp
  - tests/struct.union_find.test.cpp
documentation_of: library/util/string.hpp
layout: document
redirect_from:
- /library/library/util/string.hpp
- /library/library/util/string.hpp.html
title: "\u6587\u5B57\u5217"
---
