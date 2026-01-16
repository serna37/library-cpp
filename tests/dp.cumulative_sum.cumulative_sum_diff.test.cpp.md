---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/dp/cumulative_sum/cumulative_sum_diff.hpp
    title: "\u4E8C\u9805\u5DEE\u3067\u306E\u7D2F\u7A4D\u548C"
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
    document_title: "\u4E8C\u9805\u5DEE\u3067\u306E\u7D2F\u7A4D\u548C\u306E\u30C6\u30B9\
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
    \n#include \"template/template.hpp\"\n#include \"library/dp/cumulative_sum/cumulative_sum_diff.hpp\"\
    \nvoid run_cumulative_sum_diff_tests() {\n    // \u30B1\u30FC\u30B91: \u57FA\u672C\
    \u7684\u306A\u52D5\u4F5C\uFF08\u8981\u7D20\u6570\u304C\u5076\u6570\uFF09\n   \
    \ {\n        vector<int> A = {1, 5, 2, 10};\n        // \u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\u3068\u8A08\u7B97\u306E\u63A8\u79FB:\n        // i=0: S[1] = S[0]\
    \ = 0 (i\u304C\u5076\u6570\u306A\u306E\u3067\u8DB3\u3055\u306A\u3044)\n      \
    \  // i=1: S[2] = S[1] + abs(5-1) = 4\n        // i=2: S[3] = S[2] = 4 (i\u304C\
    \u5076\u6570\u306A\u306E\u3067\u8DB3\u3055\u306A\u3044)\n        // i=3: S[4]\
    \ = S[3] + abs(10-2) = 4 + 8 = 12\n        vector<long long> expected = {0, 0,\
    \ 4, 4, 12};\n        auto S = cumulative_sum_diff(A);\n        assert(S.size()\
    \ == 5);\n        for (int i = 0; i < 5; i++) {\n            assert(S[i] == expected[i]);\n\
    \        }\n    }\n    // \u30B1\u30FC\u30B92: \u8981\u7D20\u6570\u304C\u5947\u6570\
    \n    {\n        vector<int> A = {3, 8, 5};\n        // i=0: S[1]=0\n        //\
    \ i=1: S[2]=0 + abs(8-3)=5\n        // i=2: S[3]=S[2]=5\n        vector<long long>\
    \ expected = {0, 0, 5, 5};\n        auto S = cumulative_sum_diff(A);\n       \
    \ assert(S.size() == 4);\n        assert(S[3] == 5);\n    }\n    // \u30B1\u30FC\
    \u30B93: \u8CA0\u306E\u6570\u3092\u542B\u3080\u5834\u5408\n    {\n        vector<int>\
    \ A = {-1, -5, 2};\n        // i=1: abs(-5 - (-1)) = abs(-4) = 4\n        auto\
    \ S = cumulative_sum_diff(A);\n        assert(S[2] == 4);\n    }\n    // \u30B1\
    \u30FC\u30B94: \u8981\u7D20\u304C1\u3064\u3060\u3051\n    {\n        vector<int>\
    \ A = {100};\n        auto S = cumulative_sum_diff(A);\n        assert(S.size()\
    \ == 2);\n        assert(S[0] == 0);\n        assert(S[1] == 0);\n    }\n    //\
    \ \u30B1\u30FC\u30B95: \u7A7A\u306E\u914D\u5217\n    {\n        vector<int> A\
    \ = {};\n        auto S = cumulative_sum_diff(A);\n        assert(S.size() ==\
    \ 1);\n        assert(S[0] == 0);\n    }\n}\n/**\n * @brief \u4E8C\u9805\u5DEE\
    \u3067\u306E\u7D2F\u7A4D\u548C\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n\
    \    print(\"Hello World\");\n    run_cumulative_sum_diff_tests();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/dp/cumulative_sum/cumulative_sum_diff.hpp
  isVerificationFile: true
  path: tests/dp.cumulative_sum.cumulative_sum_diff.test.cpp
  requiredBy: []
  timestamp: '2026-01-16 13:01:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/dp.cumulative_sum.cumulative_sum_diff.test.cpp
layout: document
redirect_from:
- /verify/tests/dp.cumulative_sum.cumulative_sum_diff.test.cpp
- /verify/tests/dp.cumulative_sum.cumulative_sum_diff.test.cpp.html
title: "\u4E8C\u9805\u5DEE\u3067\u306E\u7D2F\u7A4D\u548C\u306E\u30C6\u30B9\u30C8"
---
