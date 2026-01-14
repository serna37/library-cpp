---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/sequence/inversion_number.hpp
    title: "\u8EE2\u5012\u6570"
  - icon: ':heavy_check_mark:'
    path: library/sequence/zip_coordinate.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
    document_title: "\u8EE2\u5012\u6570\u30FB\u5EA7\u6A19\u5727\u7E2E\u306E\u30C6\u30B9\
      \u30C8"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
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
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n#include \"template/template.hpp\"\n#include \"library/sequence/inversion_number.hpp\"\
    \n/**\n * @brief \u8EE2\u5012\u6570\u30FB\u5EA7\u6A19\u5727\u7E2E\u306E\u30C6\u30B9\
    \u30C8\n */\nvoid solve() {\n    int N;\n    cin >> N;\n    vector<int> A(N);\n\
    \    cin >> A;\n    long long inv = inversion_number(A);\n    print(inv);\n}\n"
  dependsOn:
  - template/template.hpp
  - library/sequence/inversion_number.hpp
  - library/sequence/zip_coordinate.hpp
  isVerificationFile: true
  path: tests/sequence/inversion_number.test.cpp
  requiredBy: []
  timestamp: '2026-01-14 09:15:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/sequence/inversion_number.test.cpp
layout: document
redirect_from:
- /verify/tests/sequence/inversion_number.test.cpp
- /verify/tests/sequence/inversion_number.test.cpp.html
title: "\u8EE2\u5012\u6570\u30FB\u5EA7\u6A19\u5727\u7E2E\u306E\u30C6\u30B9\u30C8"
---
