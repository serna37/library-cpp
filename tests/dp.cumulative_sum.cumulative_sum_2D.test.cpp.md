---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/dp/cumulative_sum/cumulative_sum_2D.hpp
    title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
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
    document_title: "2\u6B21\u5143\u7D2F\u7A4D\u548C\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/dp/cumulative_sum/cumulative_sum_2D.hpp\"\
    \nvoid run_cumulative_sum_tests() {\n    // \u30B1\u30FC\u30B91: \u57FA\u672C\u7684\
    \u306A 2x3 \u884C\u5217\n    {\n        vector<vector<int>> G = {{1, 2, 3}, {4,\
    \ 5, 6}};\n        // \u671F\u5F85\u3055\u308C\u308B\u7D2F\u7A4D\u548C S (H+1\
    \ x W+1)\n        // 0 0 0 0\n        // 0 1 3 6\n        // 0 5 12 21\n     \
    \   vector<vector<long long>> expected = {\n            {0, 0, 0, 0}, {0, 1, 3,\
    \ 6}, {0, 5, 12, 21}};\n        auto res = cumulative_sum_2D(G);\n        assert(res.size()\
    \ == 3);\n        assert(res[0].size() == 4);\n        for (int i = 0; i < 3;\
    \ i++) {\n            for (int j = 0; j < 4; j++) {\n                assert(res[i][j]\
    \ == expected[i][j]);\n            }\n        }\n    }\n    // \u30B1\u30FC\u30B9\
    2: \u6700\u5C0F\u30B5\u30A4\u30BA (1x1)\n    {\n        vector<vector<int>> G\
    \ = {{10}};\n        vector<vector<long long>> expected = {{0, 0}, {0, 10}};\n\
    \        auto res = cumulative_sum_2D(G);\n        assert(res[1][1] == 10);\n\
    \        assert(res[0][0] == 0);\n    }\n    // \u30B1\u30FC\u30B93: \u5168\u3066\
    \u306E\u8981\u7D20\u304C 0\n    {\n        vector<vector<int>> G(3, vector<int>(3,\
    \ 0));\n        auto res = cumulative_sum_2D(G);\n        for (int i = 0; i <=\
    \ 3; i++) {\n            for (int j = 0; j <= 3; j++) {\n                assert(res[i][j]\
    \ == 0);\n            }\n        }\n    }\n    // \u30B1\u30FC\u30B94: \u7E26\u306B\
    \u9577\u3044\u884C\u5217 (3x1)\n    {\n        vector<vector<int>> G = {{1}, {2},\
    \ {3}};\n        auto res = cumulative_sum_2D(G);\n        assert(res.size() ==\
    \ 4);\n        assert(res[3][1] == 6); // 1 + 2 + 3\n    }\n}\n/**\n * @brief\
    \ 2\u6B21\u5143\u7D2F\u7A4D\u548C\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n\
    \    print(\"Hello World\");\n    run_cumulative_sum_tests();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/dp/cumulative_sum/cumulative_sum_2D.hpp
  isVerificationFile: true
  path: tests/dp.cumulative_sum.cumulative_sum_2D.test.cpp
  requiredBy: []
  timestamp: '2026-01-16 15:19:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/dp.cumulative_sum.cumulative_sum_2D.test.cpp
layout: document
redirect_from:
- /verify/tests/dp.cumulative_sum.cumulative_sum_2D.test.cpp
- /verify/tests/dp.cumulative_sum.cumulative_sum_2D.test.cpp.html
title: "2\u6B21\u5143\u7D2F\u7A4D\u548C\u306E\u30C6\u30B9\u30C8"
---
