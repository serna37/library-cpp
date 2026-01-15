---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/search/binary_search/bi_ge_val.hpp
    title: "\u4E8C\u5206\u63A2\u7D22 \u914D\u5217\u4E2D \u4EE5\u4E0A\u306E\u6700\u5C0F\
      \u5024"
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
    document_title: "\u4E8C\u5206\u63A2\u7D22 \u914D\u5217\u4E2D \u4EE5\u4E0A\u306E\
      \u6700\u5C0F\u5024\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/search/binary_search/bi_ge_val.hpp\"\
    \nvoid test_bi_ge_val() {\n    // --- Vector\u7248\u306E\u30C6\u30B9\u30C8 ---\n\
    \    // lower_bound\u3092\u4F7F\u3046\u305F\u3081\u3001\u4E8B\u524D\u306B\u30BD\
    \u30FC\u30C8\u3055\u308C\u3066\u3044\u308B\u5FC5\u8981\u304C\u3042\u308B\n   \
    \ vector<int> v = {10, 20, 30, 40, 50};\n    assert(bi_ge_val(v, 25ll) == 30);\
    \  // 25\u4EE5\u4E0A\u306E\u6700\u5C0F\u5024\n    assert(bi_ge_val(v, 20ll) ==\
    \ 20);  // 20\u3061\u3087\u3046\u3069\n    assert(bi_ge_val(v, 5ll) == 10);  \
    \ // \u6700\u5C0F\u8981\u7D20\u3088\u308A\u5C0F\u3055\u3044\u5834\u5408\n    assert(bi_ge_val(v,\
    \ 55ll) == INF); // \u6700\u5927\u8981\u7D20\u3088\u308A\u5927\u304D\u3044\u5834\
    \u5408\n    // --- Set\u7248\u306E\u30C6\u30B9\u30C8 ---\n    // set\u306F\u5185\
    \u90E8\u3067\u5E38\u306B\u30BD\u30FC\u30C8\u3055\u308C\u3066\u3044\u308B\n   \
    \ set<int> st = {10, 20, 30, 40, 50};\n    assert(bi_ge_val(st, 25ll) == 30);\n\
    \    assert(bi_ge_val(st, 20ll) == 20);\n    assert(bi_ge_val(st, 60ll) == INF);\n\
    \    // --- \u578B\u306E\u67D4\u8EDF\u6027\u30C6\u30B9\u30C8 (double) ---\n  \
    \  vector<double> vd = {1.1, 2.2, 3.3};\n    // 2.0 \u4EE5\u4E0A\u306E\u6700\u5C0F\
    \u5024\u306F 2.2\n    assert(abs(bi_ge_val(vd, 2.0) - 2.2) < 1e-9);\n}\n/**\n\
    \ * @brief \u4E8C\u5206\u63A2\u7D22 \u914D\u5217\u4E2D \u4EE5\u4E0A\u306E\u6700\
    \u5C0F\u5024\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n    print(\"Hello World\"\
    );\n    test_bi_ge_val();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/search/binary_search/bi_ge_val.hpp
  isVerificationFile: true
  path: tests/search/binary_search/bi_ge_val.test.cpp
  requiredBy: []
  timestamp: '2026-01-15 10:11:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/search/binary_search/bi_ge_val.test.cpp
layout: document
redirect_from:
- /verify/tests/search/binary_search/bi_ge_val.test.cpp
- /verify/tests/search/binary_search/bi_ge_val.test.cpp.html
title: "\u4E8C\u5206\u63A2\u7D22 \u914D\u5217\u4E2D \u4EE5\u4E0A\u306E\u6700\u5C0F\
  \u5024\u306E\u30C6\u30B9\u30C8"
---
