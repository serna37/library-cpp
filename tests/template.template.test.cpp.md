---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    document_title: "template\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n/**\n * @brief template\u306E\u30C6\u30B9\
    \u30C8\n */\nvoid solve() {\n    print(\"Hello World\");\n    auto G = make_vec2<string>(3,\
    \ 2, \"tmp\");\n    vec2<string> T = {{\"tmp\", \"tmp\"}, {\"tmp\", \"tmp\"},\
    \ {\"tmp\", \"tmp\"}};\n    assert(G == T);\n    int A = 5, B = 7;\n    chmin(A,\
    \ B);\n    assert(A == 5ll);\n    A = 7, B = 5;\n    chmin(A, B);\n    assert(A\
    \ == 5ll);\n    A = 7, B = 5;\n    chmax(A, B);\n    assert(A == 7ll);\n    A\
    \ = 5, B = 7;\n    chmax(A, B);\n    assert(A == 7ll);\n}\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: true
  path: tests/template.template.test.cpp
  requiredBy: []
  timestamp: '2026-01-19 15:21:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/template.template.test.cpp
layout: document
redirect_from:
- /verify/tests/template.template.test.cpp
- /verify/tests/template.template.test.cpp.html
title: "template\u306E\u30C6\u30B9\u30C8"
---
