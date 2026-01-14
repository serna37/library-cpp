---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/sequence/dispersion.hpp
    title: "\u6570\u76F4\u7DDA\u4E0A\u3067\u306E\u500B\u6570\u5206\u5E03"
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
    document_title: "\u6570\u76F4\u7DDA\u4E0A\u3067\u306E\u500B\u6570\u5206\u5E03\u306E\
      \u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/sequence/dispersion.hpp\"\
    \nvoid test_dispersion() {\n    // \u30B1\u30FC\u30B91: \u57FA\u672C\u7684\u306A\
    \u30AB\u30A6\u30F3\u30C8\n    vector<int> v1 = {1, 2, 2, 3, 3, 3};\n    vector<int>\
    \ res1 = dispersion(v1);\n    assert(res1[1] == 1);\n    assert(res1[2] == 2);\n\
    \    assert(res1[3] == 3);\n    assert(res1[0] == 0); // \u73FE\u308C\u3066\u3044\
    \u306A\u3044\u6570\u306F0\n    assert(res1[4] == 0);\n    // \u30B1\u30FC\u30B9\
    2: \u5883\u754C\u5024\u4ED8\u8FD1\u306E\u30AB\u30A6\u30F3\u30C8\n    // 2e6 -\
    \ 1 = 1,999,999\n    int limit = 1999999;\n    vector<int> v2 = {limit, limit,\
    \ 0};\n    vector<int> res2 = dispersion(v2);\n    assert(res2[limit] == 2);\n\
    \    assert(res2[0] == 1);\n    // \u30B1\u30FC\u30B93: \u7A7A\u306E\u914D\u5217\
    \n    vector<int> v3 = {};\n    vector<int> res3 = dispersion(v3);\n    // \u5168\
    \u3066\u306E\u8981\u7D20\u304C0\u3067\u3042\u308B\u3053\u3068\u3092\u78BA\u8A8D\
    \ (\u4E00\u90E8\u30B5\u30F3\u30D7\u30EA\u30F3\u30B0)\n    assert(res3[0] == 0);\n\
    \    assert(res3[100] == 0);\n    // \u30B1\u30FC\u30B94: \u540C\u3058\u5024\u304C\
    \u305F\u304F\u3055\u3093\u3042\u308B\u5834\u5408\n    vector<int> v4(100, 500);\
    \ // 500\u304C100\u500B\n    vector<int> res4 = dispersion(v4);\n    assert(res4[500]\
    \ == 100);\n}\n/**\n * @brief \u6570\u76F4\u7DDA\u4E0A\u3067\u306E\u500B\u6570\
    \u5206\u5E03\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n    print(\"Hello World\"\
    );\n    test_dispersion();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/sequence/dispersion.hpp
  isVerificationFile: true
  path: tests/sequence/dispersion.test.cpp
  requiredBy: []
  timestamp: '2026-01-14 09:03:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/sequence/dispersion.test.cpp
layout: document
redirect_from:
- /verify/tests/sequence/dispersion.test.cpp
- /verify/tests/sequence/dispersion.test.cpp.html
title: "\u6570\u76F4\u7DDA\u4E0A\u3067\u306E\u500B\u6570\u5206\u5E03\u306E\u30C6\u30B9\
  \u30C8"
---
