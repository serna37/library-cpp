---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/util.test.cpp
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
    \ s;\n    }\n    // \u7D50\u5408\n    string join(const vector<string> &v, const\
    \ string &sep) {\n        string res;\n        for (int i = 0; i < (int)v.size();\
    \ ++i) {\n            if (0 < i) res += sep;\n            res += v[i];\n     \
    \   }\n        return res;\n    }\n    /**\n     * \u6587\u5B57\u5217T\u306E\u4E2D\
    \u306B\u3042\u308BS\u306E\u4E00\u81F4\u5834\u6240\u3092\u5168\u3066\u53D6\u5F97\
    \n     * \u30DE\u30C3\u30C1\u3057\u305F\u982D\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\u3092\u8FD4\u3059\n     */\n    vector<int> finds(const string &T, const\
    \ string &S) {\n        vector<int> pos;\n        auto p = T.find(S);\n      \
    \  while (p != string::npos) {\n            pos.emplace_back(p);\n           \
    \ p = T.find(S, p + 1);\n        }\n        return pos;\n    }\n    // \u533A\u5207\
    \u308A\u6587\u5B57(1\u6587\u5B57)\u3067\u533A\u5207\u308B\n    vector<string>\
    \ split(const string &S, const char &sep) {\n        vector<string> res = {\"\"\
    };\n        for (auto &&v : S) {\n            if (v == sep) {\n              \
    \  res.emplace_back(\"\");\n            } else {\n                res.back() +=\
    \ v;\n            }\n        }\n        return res;\n    }\n    // \u8907\u6570\
    \u306E\u533A\u5207\u308A\u6587\u5B57\u3067\u533A\u5207\u308B \u533A\u5207\u308A\
    \u6587\u5B57\u304C\u306A\u3044\u5834\u5408\u7A7A\u6587\u5B57\n    vector<string>\
    \ split_multi(const string &S, const string &seps) {\n        vector<string> res\
    \ = {\"\"};\n        for (auto &&v : S) {\n            if (count(all(seps), v))\
    \ {\n                res.emplace_back(\"\");\n            } else {\n         \
    \       res.back() += v;\n            }\n        }\n        return res;\n    }\n\
    \    // \u6587\u5B57\u5217\u306E\u533A\u9593[A, B]\u3092\u53D6\u5F97\n    string\
    \ str_range(const string &S, int A, int B) {\n        if (A > B or A >= (int)S.size())\
    \ return \"\";\n        return S.substr(A, B - A + 1);\n    }\n    // \u30E9\u30F3\
    \u30EC\u30F3\u30B0\u30B9\u5727\u7E2E O(N)\n    vector<pair<char, int>> run_length(const\
    \ string &S) {\n        vector<pair<char, int>> res;\n        for (auto &&x :\
    \ S) {\n            if (res.empty() or res.back().first != x) res.emplace_back(x,\
    \ 0);\n            ++res.back().second;\n        }\n        return res;\n    }\n\
    };\n"
  code: "#pragma once\n/**\n * @brief \u6587\u5B57\u5217\n */\nclass String {\n  public:\n\
    \    bool is_low(char c) {\n        return islower(c) != 0;\n    }\n    bool is_upp(char\
    \ c) {\n        return isupper(c) != 0;\n    }\n    // \u5C0F\u6587\u5B57\u306B\
    \u5909\u63DB\n    string transform_lower(string s) {\n        std::transform(all(s),\
    \ s.begin(), ::tolower);\n        return s;\n    }\n    // \u5927\u6587\u5B57\u306B\
    \u5909\u63DB\n    string transform_upper(string s) {\n        std::transform(all(s),\
    \ s.begin(), ::toupper);\n        return s;\n    }\n    // \u7D50\u5408\n    string\
    \ join(const vector<string> &v, const string &sep) {\n        string res;\n  \
    \      for (int i = 0; i < (int)v.size(); ++i) {\n            if (0 < i) res +=\
    \ sep;\n            res += v[i];\n        }\n        return res;\n    }\n    /**\n\
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
    \ + 1);\n    }\n    // \u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E O(N)\n\
    \    vector<pair<char, int>> run_length(const string &S) {\n        vector<pair<char,\
    \ int>> res;\n        for (auto &&x : S) {\n            if (res.empty() or res.back().first\
    \ != x) res.emplace_back(x, 0);\n            ++res.back().second;\n        }\n\
    \        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/util/string.hpp
  requiredBy: []
  timestamp: '2026-01-06 20:47:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/util.test.cpp
documentation_of: library/util/string.hpp
layout: document
redirect_from:
- /library/library/util/string.hpp
- /library/library/util/string.hpp.html
title: "\u6587\u5B57\u5217"
---
