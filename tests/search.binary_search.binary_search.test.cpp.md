---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/search/binary_search/binary_search.hpp
    title: "\u6574\u6570\u4E0A\u306E\u4E8C\u5206\u63A2\u7D22"
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
    document_title: "\u6574\u6570\u4E0A\u306E\u4E8C\u5206\u63A2\u7D22\u306E\u30C6\u30B9\
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
    \n#include \"template/template.hpp\"\n#include \"library/search/binary_search/binary_search.hpp\"\
    \nvoid test_binary_search() {\n    // \u30B1\u30FC\u30B91: \u5358\u7D14\u306A\u95BE\
    \u5024 (x >= 100 \u3067 true)\n    auto f1 = [](long long x) { return x >= 100;\
    \ };\n    auto [L1, R1] = binary_search(f1);\n    // L\u306Ffalse(99), R\u306F\
    true(100)\u306B\u306A\u308B\u306F\u305A\n    assert(L1 == 99 && R1 == 100);\n\
    \    // \u30B1\u30FC\u30B92: \u5883\u754C\u304C\u975E\u5E38\u306B\u5C0F\u3055\u3044\
    \u5834\u5408 (x >= 1 \u3067 true)\n    auto f2 = [](long long x) { return x >=\
    \ 1; };\n    auto [L2, R2] = binary_search(f2);\n    assert(L2 == 0 && R2 == 1);\n\
    \    // \u30B1\u30FC\u30B93: \u5883\u754C\u304C 0 \u306E\u5834\u5408\n    // \u95A2\
    \u6570\u5185\u3067\u306E\u521D\u671F\u5024\u304C L=0, R=1 \u306A\u306E\u3067\u3001\
    f(1)\u306F\u5FC5\u305Atrue\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\n \
    \   auto f3 = [](long long x) { return x >= 0; };\n    // R=1\u3067\u6700\u521D\
    \u304B\u3089f(R)\u304Ctrue\u306B\u306A\u308B\u305F\u3081\u3001\u305D\u306E\u307E\
    \u307E\u4E8C\u5206\u63A2\u7D22\u3078\n    auto [L3, R3] = binary_search(f3);\n\
    \    assert(R3 == 0 ||\n           R3 == 1); // \u5B9F\u88C5\u306B\u3088\u308A\
    \u307E\u3059\u304C\u30010\u4EE5\u4E0A\u3067\u5E38\u306Btrue\u306A\u3089R\u306F\
    \u6700\u5C0F\u306Etrue\u5730\u70B9\n    // \u30B1\u30FC\u30B94: \u5883\u754C\u304C\
    \u975E\u5E38\u306B\u5927\u304D\u3044\u5834\u5408\n    long long target = 1LL <<\
    \ 40; // 2^40\n    auto f4 = [target](long long x) { return x >= target; };\n\
    \    auto [L4, R4] = binary_search(f4);\n    assert(L4 == target - 1 && R4 ==\
    \ target);\n    // \u30B1\u30FC\u30B95: \u4E8C\u6B21\u95A2\u6570\u306E\u95BE\u5024\
    \n    // x*x >= 1000000 (x >= 1000)\n    auto f5 = [](long long x) { return x\
    \ * x >= 1000000; };\n    auto [L5, R5] = binary_search(f5);\n    assert(L5 ==\
    \ 999 && R5 == 1000);\n}\n/**\n * @brief \u6574\u6570\u4E0A\u306E\u4E8C\u5206\u63A2\
    \u7D22\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n    print(\"Hello World\"\
    );\n    test_binary_search();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/search/binary_search/binary_search.hpp
  isVerificationFile: true
  path: tests/search.binary_search.binary_search.test.cpp
  requiredBy: []
  timestamp: '2026-01-19 13:31:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/search.binary_search.binary_search.test.cpp
layout: document
redirect_from:
- /verify/tests/search.binary_search.binary_search.test.cpp
- /verify/tests/search.binary_search.binary_search.test.cpp.html
title: "\u6574\u6570\u4E0A\u306E\u4E8C\u5206\u63A2\u7D22\u306E\u30C6\u30B9\u30C8"
---
