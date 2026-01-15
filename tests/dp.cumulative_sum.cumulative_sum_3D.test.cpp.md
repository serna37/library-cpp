---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/dp/cumulative_sum/cumulative_sum_3D.hpp
    title: "3\u6B21\u5143\u7D2F\u7A4D\u548C"
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
    document_title: "3\u6B21\u5143\u7D2F\u7A4D\u548C\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/dp/cumulative_sum/cumulative_sum_3D.hpp\"\
    \nvoid run_cumulative_sum_3D_tests() {\n    // \u30B1\u30FC\u30B91: 2x2x2 \u306E\
    \u7ACB\u65B9\u4F53\n    // \u3059\u3079\u3066\u306E\u8981\u7D20\u304C 1 \u306E\
    \u5834\u5408\n    {\n        int X = 2, Y = 2, Z = 2;\n        vector<vector<vector<int>>>\
    \ A(\n            X, vector<vector<int>>(Y, vector<int>(Z, 1)));\n        auto\
    \ S = cumulative_sum_3D(A);\n        // \u30B5\u30A4\u30BA\u78BA\u8A8D (X+1, Y+1,\
    \ Z+1)\n        assert(S.size() == 3);\n        assert(S[0].size() == 3);\n  \
    \      assert(S[0][0].size() == 3);\n        // \u5883\u754C\uFF080\u9762\uFF09\
    \u306F\u3059\u3079\u3066 0 \u3067\u3042\u308B\u3079\u304D\n        assert(S[0][0][0]\
    \ == 0);\n        assert(S[0][2][2] == 0);\n        assert(S[2][0][2] == 0);\n\
    \        // \u5404\u5EA7\u6A19\u306E\u7D2F\u7A4D\u548C\u3092\u78BA\u8A8D\n   \
    \     // S[1][1][1] \u306F A[0][0][0] \u306E\u307F = 1\n        assert(S[1][1][1]\
    \ == 1);\n        // S[2][1][1] \u306F A[0][0][0] + A[1][0][0] = 2\n        assert(S[2][1][1]\
    \ == 2);\n        // S[2][2][2] \u306F\u5168\u8981\u7D20\u306E\u548C = 2*2*2 =\
    \ 8\n        assert(S[2][2][2] == 8);\n    }\n    // \u30B1\u30FC\u30B92: \u7279\
    \u5B9A\u306E1\u7B87\u6240\u3060\u3051\u306B\u5024\u304C\u3042\u308B\u5834\u5408\
    \n    {\n        vector<vector<vector<int>>> A(\n            2, vector<vector<int>>(2,\
    \ vector<int>(2, 0)));\n        A[1][1][1] = 5; // \u53F3\u7AEF\u306E\u5965\u306B\
    \u914D\u7F6E\n        auto S = cumulative_sum_3D(A);\n        // A[1][1][1] \u304C\
    \u542B\u307E\u308C\u306A\u3044\u7BC4\u56F2\u306F 0\n        assert(S[1][1][1]\
    \ == 0);\n        assert(S[2][2][1] == 0);\n        assert(S[2][1][2] == 0);\n\
    \        // A[1][1][1] \u304C\u542B\u307E\u308C\u308B\u552F\u4E00\u306E\u70B9\n\
    \        assert(S[2][2][2] == 5);\n    }\n    // \u30B1\u30FC\u30B93: \u7570\u306A\
    \u308B\u5024\u306E\u7D44\u307F\u5408\u308F\u305B\n    {\n        // 1x1x2 \u306E\
    \u76F4\u65B9\u4F53\n        // A[0][0][0]=1, A[0][0][1]=2\n        vector<vector<vector<int>>>\
    \ A = {{{1, 2}}};\n        auto S = cumulative_sum_3D(A);\n        assert(S[1][1][1]\
    \ == 1);\n        assert(S[1][1][2] == 3);\n    }\n}\n/**\n * @brief 3\u6B21\u5143\
    \u7D2F\u7A4D\u548C\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n    print(\"\
    Hello World\");\n    run_cumulative_sum_3D_tests();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/dp/cumulative_sum/cumulative_sum_3D.hpp
  isVerificationFile: true
  path: tests/dp.cumulative_sum.cumulative_sum_3D.test.cpp
  requiredBy: []
  timestamp: '2026-01-15 17:22:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/dp.cumulative_sum.cumulative_sum_3D.test.cpp
layout: document
redirect_from:
- /verify/tests/dp.cumulative_sum.cumulative_sum_3D.test.cpp
- /verify/tests/dp.cumulative_sum.cumulative_sum_3D.test.cpp.html
title: "3\u6B21\u5143\u7D2F\u7A4D\u548C\u306E\u30C6\u30B9\u30C8"
---
