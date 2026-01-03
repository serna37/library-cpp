---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: "main\u30D5\u30A1\u30A4\u30EB"
  - icon: ':question:'
    path: template/lib.hpp
    title: "library/util/*.hpp\u306Einclude\u7528"
  - icon: ':question:'
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
  - icon: ':x:'
    path: tests/template.test.cpp
    title: "library/util/xxx.hpp\u306E\u30E6\u30CB\u30C3\u30C8\u30C6\u30B9\u30C8"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ library/util/number.hpp: line 5: #pragma once found in a non-first line\n"
  code: "\n/** ======================================= */\n/**           \u6570\u306E\
    \u6027\u8CEA                      */\n/** =======================================\
    \ */\n#pragma once\nclass Number {\n  private:\n    // mod\u968E\u4E57\u306E\u30E1\
    \u30E2\u914D\u5217\n    vector<long long> _mf;\n\n  public:\n    // \u5272\u308A\
    \u4E0B\u3052\uFF08\u8CA0\u306E\u5834\u54080\u5074\u3078\u4E38\u3081\u306A\u3044\
    \uFF09\n    template <typename T> T div_ceil(T a, T b) {\n        return a / b\
    \ + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);\n    }\n    // \u5272\u308A\u4E0A\u3052\
    \uFF08\u8CA0\u306E\u5834\u54080\u5074\u3078\u4E38\u3081\u306A\u3044\uFF09\n  \
    \  template <typename T> T div_floor(T a, T b) {\n        return a / b - (((a\
    \ ^ b) < 0 and a % b != 0) ? 1 : 0);\n    }\n    // \u968E\u4E57 \u30CA\u30A4\u30FC\
    \u30D6\n    long long factorial(int N) {\n        long long res = 1;\n       \
    \ while (N > 0) res *= N--;\n        return res;\n    }\n    // nCk\n    long\
    \ long combination(int n, int k) {\n        if (k < 0 || n < k) return 0ll;\n\
    \        long long res = 1;\n        for (int i = 1; i <= k; ++i) {\n        \
    \    res *= n--;\n            res /= i;\n        }\n        return res;\n    }\n\
    \    // \u6841\u548C\n    int digit_sum(int a, int N = 10) {\n        int res\
    \ = 0;\n        while (a != 0) {\n            res += a % N;\n            a /=\
    \ N;\n        }\n        return res;\n    }\n    // \u9032\u6570\u5909\u63DB from\u3068\
    to\u306F10\u3092\u8D85\u3048\u306A\u3044\u3053\u3068\n    string base_convert(string\
    \ a, int from, int to) {\n        long long cvt = 0ll; // 10\u9032\u6570\u306B\
    \u76F4\u3059\n        for (auto &&v : a) cvt = cvt * from + (int)(v - '0');\n\
    \        if (cvt == 0) return \"0\";\n        string res = \"\"; // to\u9032\u6570\
    \u306B\u76F4\u3059\n        while (cvt) {    // 10\u9032\u6570\u3067\u8868\u305B\
    \u308B\u7BC4\u56F2\u306E\u6587\u5B57\u3057\u304B\u6271\u3063\u3066\u3044\u306A\
    \u3044\n            res = (char)(cvt % to + '0') + res;\n            cvt /= to;\n\
    \        }\n        return res;\n    }\n    // \u7D04\u6570\u5217\u6319\n    vector<int>\
    \ divisors(int a) {\n        vector<int> res;\n        for (int i = 1; i * i <=\
    \ a; ++i) {\n            if (a % i != 0) continue;\n            res.push_back(i);\n\
    \            if (a / i != i) res.push_back(a / i);\n        }\n        return\
    \ res;\n    }\n    // \u7D20\u6570\u5224\u5B9A\n    bool prime_test(int N) {\n\
    \        if (N == 2) return true;\n        if (N == 1 or N % 2 == 0) return false;\n\
    \        for (int i = 3; i * i <= N; i += 2) {\n            if (N % i == 0) return\
    \ false;\n        }\n        return true;\n    }\n    // \u7D20\u56E0\u6570\u5206\
    \u89E3\n    map<int, int> prime_fact(int N) {\n        map<int, int> P;\n    \
    \    for (int i = 2; i * i <= N; ++i) {\n            while (N % i == 0) {\n  \
    \              ++P[i];\n                N /= i;\n            }\n        }\n  \
    \      if (N > 1) ++P[N];\n        return P;\n    }\n    // \u4E8C\u5206\u7D2F\
    \u4E57(mod)\n    long long modpow(long long a, long long n, long long m) {\n \
    \       long long res = 1ll;\n        while (n > 0) {\n            if (n & 1)\
    \ res = res * a % m;\n            a = a * a % m;\n            n >>= 1ll;\n   \
    \     }\n        return res;\n    }\n    // Fermat\u306E\u5C0F\u5B9A\u7406 \u9006\
    \u5143\u3092\u6C42\u3081\u308B\n    long long modinv(long long a, long long m)\
    \ {\n        return modpow(a, m - 2, m);\n    }\n    // mod\u968E\u4E57\n    long\
    \ long modfact(int x, long long m) {\n        if ((int)_mf.size() > x) return\
    \ _mf[x];\n        if (_mf.empty()) _mf.push_back(1);\n        for (int i = _mf.size();\
    \ i <= x; ++i) _mf.push_back(_mf.back() * i % m);\n        return _mf[x];\n  \
    \  }\n    // mod\u7D44\u307F\u5408\u308F\u305BnCk\n    long long mod_combination(int\
    \ n, int k, long long m) {\n        return modfact(n, m) * modinv(modfact(k, m),\
    \ m) % m *\n               modinv(modfact(n - k, m), m) % m;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/util/number.hpp
  requiredBy:
  - template/lib.hpp
  - template/template.hpp
  - main.cpp
  timestamp: '2026-01-03 21:52:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/struct.lazy_segment_tree.test.cpp
  - tests/struct.fenwick_tree.test.cpp
  - tests/template.test.cpp
  - tests/struct.dual_segment_tree.test.cpp
  - tests/struct.segment_tree.test.cpp
  - tests/struct.union_find.test.cpp
documentation_of: library/util/number.hpp
layout: document
title: "\u6570\u306E\u6027\u8CEA"
---

数値計算や数の性質などをまとめる
