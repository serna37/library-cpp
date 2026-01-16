---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/search/binary_search/binary_search_real.hpp
    title: "\u5B9F\u6570\u4E0A\u306E\u4E8C\u5206\u63A2\u7D22"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    document_title: "\u5B9F\u6570\u4E0A\u306E\u4E8C\u5206\u63A2\u7D22\u306E\u30C6\u30B9\
      \u30C8"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
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
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"template/template.hpp\"\n#include \"library/search/binary_search/binary_search_real.hpp\"\
    \n// \u5224\u5B9A\u7528\u306E\u30D8\u30EB\u30D1\u30FC\uFF1A\u671F\u5F85\u5024\u3068\
    \u306E\u8AA4\u5DEE\u304C\u5341\u5206\u5C0F\u3055\u3044\u304B\u78BA\u8A8D\nbool\
    \ is_near(double val, double expected) {\n    return abs(val - expected) < 1e-10;\n\
    }\nvoid test_binary_search_real() {\n    // \u30B1\u30FC\u30B91: \u5E73\u65B9\u6839\
    \u306E\u8A08\u7B97 (x^2 >= 2)\n    // \u221A2 \u2252 1.41421356... \u3092\u63A2\
    \u3059\n    auto f1 = [](double x) { return x * x >= 2.0; };\n    auto [L1, R1]\
    \ = binary_search_real(f1);\n    assert(is_near(R1, sqrt(2.0)));\n    // \u30B1\
    \u30FC\u30B92: \u5883\u754C\u304C\u975E\u5E38\u306B\u5927\u304D\u3044\u5834\u5408\
    \n    // x >= 1e10\n    double target2 = 1e10;\n    auto f2 = [target2](double\
    \ x) { return x >= target2; };\n    auto [L2, R2] = binary_search_real(f2);\n\
    \    assert(is_near(R1, sqrt(2.0)));\n    // \u76F8\u5BFE\u8AA4\u5DEE(REL)\u306E\
    \u304A\u304B\u3052\u3067\u3001\u5927\u304D\u306A\u5024\u3067\u3082\u7CBE\u5EA6\
    \u826F\u304F\u6B62\u307E\u308B\n    double rel_error = abs(R2 - target2) / target2;\n\
    \    assert(rel_error < 1e-13);\n    // \u30B1\u30FC\u30B93: \u65B9\u7A0B\u5F0F\
    \u306E\u89E3 (x + exp(x) >= 2.0)\n    auto f3 = [](double x) { return x + exp(x)\
    \ >= 2.0; };\n    auto [L3, R3] = binary_search_real(f3);\n    // x \u2252 0.4428544...\n\
    \    assert(f3(R3) == true);\n    assert(f3(L3) == false);\n    // \u30B1\u30FC\
    \u30B94: \u5883\u754C\u304C1\u3088\u308A\u5C0F\u3055\u3044\u5834\u5408\n    //\
    \ x >= 0.001\n    auto f4 = [](double x) { return x >= 0.001; };\n    auto [L4,\
    \ R4] = binary_search_real(f4);\n    assert(is_near(R4, 0.001));\n}\n/**\n * @brief\
    \ \u5B9F\u6570\u4E0A\u306E\u4E8C\u5206\u63A2\u7D22\u306E\u30C6\u30B9\u30C8\n */\n\
    void solve() {\n    print(\"Hello World\");\n    test_binary_search_real();\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - library/search/binary_search/binary_search_real.hpp
  isVerificationFile: true
  path: tests/search.binary_search.binary_search_real.test.cpp
  requiredBy: []
  timestamp: '2026-01-16 15:08:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/search.binary_search.binary_search_real.test.cpp
layout: document
redirect_from:
- /verify/tests/search.binary_search.binary_search_real.test.cpp
- /verify/tests/search.binary_search.binary_search_real.test.cpp.html
title: "\u5B9F\u6570\u4E0A\u306E\u4E8C\u5206\u63A2\u7D22\u306E\u30C6\u30B9\u30C8"
---
