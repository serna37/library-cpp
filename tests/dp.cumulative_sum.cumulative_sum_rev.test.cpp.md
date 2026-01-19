---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/dp/cumulative_sum/cumulative_sum_rev.hpp
    title: "\u7D2F\u7A4D\u548C \u53CD\u8EE2"
  - icon: ':question:'
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
    document_title: "\u7D2F\u7A4D\u548C \u53CD\u8EE2\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/dp/cumulative_sum/cumulative_sum_rev.hpp\"\
    \nvoid run_cumulative_sum_rev_tests() {\n    // \u30B1\u30FC\u30B91: \u57FA\u672C\
    \u7684\u306A\u6570\u5217\n    {\n        vector<int> A = {1, 2, 3, 4};\n     \
    \   // \u671F\u5F85\u3055\u308C\u308B\u7D50\u679C:\n        // R[4] = 0\n    \
    \    // R[3] = A[3] = 4\n        // R[2] = A[3]+A[2] = 7\n        // R[1] = A[3]+A[2]+A[1]\
    \ = 9\n        // R[0] = A[3]+A[2]+A[1]+A[0] = 10\n        vector<long long> expected\
    \ = {10, 9, 7, 4, 0};\n        auto R = cumulative_sum_rev(A);\n        assert(R.size()\
    \ == 5);\n        for (int i = 0; i < 5; i++) {\n            assert(R[i] == expected[i]);\n\
    \        }\n    }\n    // \u30B1\u30FC\u30B92: \u7A7A\u306E\u914D\u5217\n    {\n\
    \        vector<int> A = {};\n        auto R = cumulative_sum_rev(A);\n      \
    \  assert(R.size() == 1);\n        assert(R[0] == 0);\n    }\n    // \u30B1\u30FC\
    \u30B93: \u8CA0\u306E\u6570\u3092\u542B\u3080\u914D\u5217\n    {\n        vector<int>\
    \ A = {10, -3, 5};\n        // R[3]=0, R[2]=5, R[1]=2, R[0]=12\n        auto R\
    \ = cumulative_sum_rev(A);\n        assert(R[0] == 12);\n        assert(R[1] ==\
    \ 2);\n        assert(R[2] == 5);\n        assert(R[3] == 0);\n    }\n    // \u30B1\
    \u30FC\u30B94: 1\u8981\u7D20\u306E\u307F\n    {\n        vector<int> A = {7};\n\
    \        auto R = cumulative_sum_rev(A);\n        assert(R[0] == 7);\n       \
    \ assert(R[1] == 0);\n    }\n}\n/**\n * @brief \u7D2F\u7A4D\u548C \u53CD\u8EE2\
    \u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n    print(\"Hello World\");\n \
    \   run_cumulative_sum_rev_tests();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/dp/cumulative_sum/cumulative_sum_rev.hpp
  isVerificationFile: true
  path: tests/dp.cumulative_sum.cumulative_sum_rev.test.cpp
  requiredBy: []
  timestamp: '2026-01-19 15:05:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/dp.cumulative_sum.cumulative_sum_rev.test.cpp
layout: document
redirect_from:
- /verify/tests/dp.cumulative_sum.cumulative_sum_rev.test.cpp
- /verify/tests/dp.cumulative_sum.cumulative_sum_rev.test.cpp.html
title: "\u7D2F\u7A4D\u548C \u53CD\u8EE2\u306E\u30C6\u30B9\u30C8"
---
