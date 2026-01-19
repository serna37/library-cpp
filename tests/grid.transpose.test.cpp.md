---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/grid/transpose.hpp
    title: "\u8EE2\u7F6E"
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
    document_title: "\u8EE2\u7F6E\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/grid/transpose.hpp\"\n\
    void test_transpose() {\n    // \u30B1\u30FC\u30B91: \u6B63\u65B9\u5F62\u306E\u884C\
    \u5217 (2x2)\n    vector<vector<int>> mat1 = {{1, 2}, {3, 4}};\n    vector<vector<int>>\
    \ expected1 = {{1, 3}, {2, 4}};\n    assert(transpose(mat1) == expected1);\n \
    \   // \u30B1\u30FC\u30B92: \u9577\u65B9\u5F62\u306E\u884C\u5217 (2x3)\n    vector<vector<int>>\
    \ mat2 = {{1, 2, 3}, {4, 5, 6}};\n    vector<vector<int>> expected2 = {{1, 4},\
    \ {2, 5}, {3, 6}};\n    assert(transpose(mat2) == expected2);\n    // \u30B1\u30FC\
    \u30B93: 1\u884C\u306E\u884C\u5217 (1x3)\n    vector<vector<int>> mat3 = {{1,\
    \ 2, 3}};\n    vector<vector<int>> expected3 = {{1}, {2}, {3}};\n    assert(transpose(mat3)\
    \ == expected3);\n    // \u30B1\u30FC\u30B94: \u6587\u5B57\u5217\u578B\u306E\u884C\
    \u5217\n    vector<vector<string>> mat4 = {{\"a\", \"b\"}, {\"c\", \"d\"}};\n\
    \    vector<vector<string>> expected4 = {{\"a\", \"c\"}, {\"b\", \"d\"}};\n  \
    \  assert(transpose(mat4) == expected4);\n}\n/**\n * @brief \u8EE2\u7F6E\u306E\
    \u30C6\u30B9\u30C8\n */\nvoid solve() {\n    print(\"Hello World\");\n    test_transpose();\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - library/grid/transpose.hpp
  isVerificationFile: true
  path: tests/grid.transpose.test.cpp
  requiredBy: []
  timestamp: '2026-01-19 15:21:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/grid.transpose.test.cpp
layout: document
redirect_from:
- /verify/tests/grid.transpose.test.cpp
- /verify/tests/grid.transpose.test.cpp.html
title: "\u8EE2\u7F6E\u306E\u30C6\u30B9\u30C8"
---
