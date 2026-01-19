---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/sequence/difference_sequence.hpp
    title: "\u968E\u5DEE\u6570\u5217"
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
    document_title: "\u968E\u5DEE\u6570\u5217\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/sequence/difference_sequence.hpp\"\
    \nvoid run_difference_sequence_tests() {\n    // \u30B1\u30FC\u30B91: \u57FA\u672C\
    \u7684\u306A\u6570\u5217\n    {\n        vector<int> A = {1, 3, 6, 10};\n    \
    \    // \u671F\u5F85\u3055\u308C\u308B\u7D50\u679C:\n        // D[0] = A[1] -\
    \ A[0] = 2\n        // D[1] = A[2] - A[1] = 3\n        // D[2] = A[3] - A[2] =\
    \ 4\n        vector<long long> expected = {2, 3, 4};\n        auto D = difference_sequence(A);\n\
    \        assert(D.size() == 3);\n        for (int i = 0; i < (int)D.size(); i++)\
    \ {\n            assert(D[i] == expected[i]);\n        }\n    }\n    // \u30B1\
    \u30FC\u30B92: \u5024\u304C\u6E1B\u5C11\u3059\u308B\u5834\u5408\n    {\n     \
    \   vector<int> A = {10, 7, 5, 5};\n        vector<long long> expected = {-3,\
    \ -2, 0};\n        auto D = difference_sequence(A);\n        for (int i = 0; i\
    \ < 3; i++) {\n            assert(D[i] == expected[i]);\n        }\n    }\n  \
    \  // \u30B1\u30FC\u30B93: \u8981\u7D20\u304C2\u3064\u306E\u5834\u5408 (\u6700\
    \u5C0F\u30B5\u30A4\u30BA)\n    {\n        vector<int> A = {1, 100};\n        auto\
    \ D = difference_sequence(A);\n        assert(D.size() == 1);\n        assert(D[0]\
    \ == 99);\n    }\n}\n/**\n * @brief \u968E\u5DEE\u6570\u5217\u306E\u30C6\u30B9\
    \u30C8\n */\nvoid solve() {\n    print(\"Hello World\");\n    run_difference_sequence_tests();\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - library/sequence/difference_sequence.hpp
  isVerificationFile: true
  path: tests/sequence.difference_sequence.test.cpp
  requiredBy: []
  timestamp: '2026-01-19 15:21:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/sequence.difference_sequence.test.cpp
layout: document
redirect_from:
- /verify/tests/sequence.difference_sequence.test.cpp
- /verify/tests/sequence.difference_sequence.test.cpp.html
title: "\u968E\u5DEE\u6570\u5217\u306E\u30C6\u30B9\u30C8"
---
