---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/search/binary_search/bi_le_val.hpp
    title: "\u4E8C\u5206\u63A2\u7D22 \u914D\u5217\u4E2D \u4EE5\u4E0B\u306E\u6700\u5927\
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
    document_title: "\u4E8C\u5206\u63A2\u7D22 \u914D\u5217\u4E2D \u4EE5\u4E0B\u306E\
      \u6700\u5927\u5024\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/search/binary_search/bi_le_val.hpp\"\
    \nvoid test_bi_le_val() {\n    // --- Vector\u7248\u306E\u30C6\u30B9\u30C8 ---\n\
    \    vector<int> v = {10, 20, 30, 40, 50};\n    // x=25 \u306E\u3068\u304D\u3001\
    25\u4EE5\u4E0B\u306E\u6700\u5927\u5024\u306F 20\n    assert(bi_le_val(v, 25ll)\
    \ == 20);\n    // x=20 \u306E\u3068\u304D\u300120\u4EE5\u4E0B\u306E\u6700\u5927\
    \u5024\u306F 20 (\u3061\u3087\u3046\u3069\u3092\u542B\u3080)\n    assert(bi_le_val(v,\
    \ 20ll) == 20);\n    // \u6700\u5927\u8981\u7D20\u3088\u308A\u5927\u304D\u3044\
    \u5834\u5408\u3001\u6700\u5927\u8981\u7D20\u304C\u8FD4\u308B\n    assert(bi_le_val(v,\
    \ 100ll) == 50);\n    // \u6700\u5C0F\u8981\u7D20\u3088\u308A\u5C0F\u3055\u3044\
    \u5834\u5408\u3001-INF \u304C\u8FD4\u308B\n    assert(bi_le_val(v, 5ll) == -INF);\n\
    \    // --- Set\u7248\u306E\u30C6\u30B9\u30C8 ---\n    set<int> st = {10, 20,\
    \ 30, 40, 50};\n    assert(bi_le_val(st, 30ll) == 30);\n    assert(bi_le_val(st,\
    \ 39ll) == 30);\n    assert(bi_le_val(st, 9ll) == -INF);\n    // --- \u91CD\u8907\
    \u8981\u7D20\u304C\u3042\u308B\u5834\u5408\u306E\u6319\u52D5\u78BA\u8A8D ---\n\
    \    vector<int> v_dup = {10, 20, 20, 20, 30};\n    // upper_bound\u306F20\u3092\
    \u8D85\u3048\u308B\u6700\u521D\u306E\u4F4D\u7F6E(30\u306E\u4F4D\u7F6E)\u3092\u6307\
    \u3057\u3001\u305D\u306E\u4E00\u3064\u524D\u306F20\n    assert(bi_le_val(v_dup,\
    \ 20ll) == 20);\n}\n/**\n * @brief \u4E8C\u5206\u63A2\u7D22 \u914D\u5217\u4E2D\
    \ \u4EE5\u4E0B\u306E\u6700\u5927\u5024\u306E\u30C6\u30B9\u30C8\n */\nvoid solve()\
    \ {\n    print(\"Hello World\");\n    test_bi_le_val();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/search/binary_search/bi_le_val.hpp
  isVerificationFile: true
  path: tests/search.binary_search.bi_le_val.test.cpp
  requiredBy: []
  timestamp: '2026-01-15 17:34:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/search.binary_search.bi_le_val.test.cpp
layout: document
redirect_from:
- /verify/tests/search.binary_search.bi_le_val.test.cpp
- /verify/tests/search.binary_search.bi_le_val.test.cpp.html
title: "\u4E8C\u5206\u63A2\u7D22 \u914D\u5217\u4E2D \u4EE5\u4E0B\u306E\u6700\u5927\
  \u5024\u306E\u30C6\u30B9\u30C8"
---
