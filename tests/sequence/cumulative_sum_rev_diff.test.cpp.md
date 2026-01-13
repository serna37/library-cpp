---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/sequence/cumulative_sum_rev_diff.hpp
    title: "\u4E8C\u9805\u5DEE\u3067\u306E\u7D2F\u7A4D\u548C \u53CD\u8EE2"
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
    document_title: "\u4E8C\u9805\u5DEE\u3067\u306E\u7D2F\u7A4D\u548C \u53CD\u8EE2\
      \u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/sequence/cumulative_sum_rev_diff.hpp\"\
    \nvoid run_cumulative_sum_rev_diff_tests() {\n    // \u30B1\u30FC\u30B91: \u57FA\
    \u672C\u7684\u306A\u52D5\u4F5C\uFF08\u8981\u7D20\u65704: \u5076\u6570\uFF09\n\
    \    {\n        vector<int> A = {1, 5, 2, 10};\n        // \u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\u3068\u8A08\u7B97\u306E\u63A8\u79FB (\u5F8C\u308D\u304B\u3089):\n\
    \        // i=3 (\u5947\u6570): R[3] = R[4] + abs(0 - A[3]) = 0 + abs(0-10) =\
    \ 10\n        // i=2 (\u5076\u6570): R[2] = R[3] = 10\n        // i=1 (\u5947\u6570\
    ): R[1] = R[2] + abs(A[2] - A[1]) = 10 + abs(2-5) = 10 + 3 =\n        // 13 i=0\
    \ (\u5076\u6570): R[0] = R[1] = 13 \u671F\u5F85\u5024 R: {13, 13, 10, 10, 0}\n\
    \        vector<long long> expected = {13, 13, 10, 10, 0};\n        auto R = cumulative_sum_rev_diff(A);\n\
    \        assert(R.size() == 5);\n        for (int i = 0; i < 5; i++) {\n     \
    \       assert(R[i] == expected[i]);\n        }\n    }\n    // \u30B1\u30FC\u30B9\
    2: \u8981\u7D20\u65703\uFF08\u5947\u6570\uFF09\n    {\n        vector<int> A =\
    \ {3, 8, 5};\n        // i=2 (\u5076\u6570): R[2] = R[3] = 0\n        // i=1 (\u5947\
    \u6570): R[1] = R[2] + abs(A[2] - A[1]) = 0 + abs(5-8) = 3\n        // i=0 (\u5076\
    \u6570): R[0] = R[1] = 3\n        // \u671F\u5F85\u5024 R: {3, 3, 0, 0}\n    \
    \    vector<long long> expected = {3, 3, 0, 0};\n        auto R = cumulative_sum_rev_diff(A);\n\
    \        assert(R.size() == 4);\n        for (int i = 0; i < 4; i++) {\n     \
    \       assert(R[i] == expected[i]);\n        }\n    }\n    // \u30B1\u30FC\u30B9\
    3: \u8CA0\u306E\u6570\u3092\u542B\u3080\u5834\u5408\n    {\n        vector<int>\
    \ A = {1, -5};\n        // i=1 (\u5947\u6570): R[1] = abs(0 - (-5)) = 5\n    \
    \    // i=0 (\u5076\u6570): R[0] = 5\n        auto R = cumulative_sum_rev_diff(A);\n\
    \        assert(R[0] == 5);\n        assert(R[1] == 5);\n    }\n    // \u30B1\u30FC\
    \u30B94: \u7A7A\u306E\u914D\u5217\n    {\n        vector<int> A = {};\n      \
    \  auto R = cumulative_sum_rev_diff(A);\n        assert(R.size() == 1);\n    \
    \    assert(R[0] == 0);\n    }\n}\n/**\n * @brief \u4E8C\u9805\u5DEE\u3067\u306E\
    \u7D2F\u7A4D\u548C \u53CD\u8EE2\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n\
    \    print(\"Hello World\");\n    run_cumulative_sum_rev_diff_tests();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/sequence/cumulative_sum_rev_diff.hpp
  isVerificationFile: true
  path: tests/sequence/cumulative_sum_rev_diff.test.cpp
  requiredBy: []
  timestamp: '2026-01-13 20:35:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/sequence/cumulative_sum_rev_diff.test.cpp
layout: document
redirect_from:
- /verify/tests/sequence/cumulative_sum_rev_diff.test.cpp
- /verify/tests/sequence/cumulative_sum_rev_diff.test.cpp.html
title: "\u4E8C\u9805\u5DEE\u3067\u306E\u7D2F\u7A4D\u548C \u53CD\u8EE2\u306E\u30C6\u30B9\
  \u30C8"
---
