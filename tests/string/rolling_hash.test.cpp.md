---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/string/rolling_hash.hpp
    title: Rolling Hash
  - icon: ':heavy_check_mark:'
    path: library/various/random.hpp
    title: "\u64EC\u4F3C\u4E71\u6570\u751F\u6210"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    document_title: "\u30ED\u30EA\u30CF\u306E\u30C6\u30B9\u30C8"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
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
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n#include \"template/template.hpp\"\n#include \"library/string/rolling_hash.hpp\"\
    \n/**\n * @brief \u30ED\u30EA\u30CF\u306E\u30C6\u30B9\u30C8\n */\nvoid solve()\
    \ {\n    string T, P;\n    cin >> T >> P;\n    int t = T.size();\n    int p =\
    \ P.size();\n    RollingHash rht(T);\n    RollingHash rhp(P);\n    if (t < p)\
    \ return;\n    long long hash_p = rhp.get(0, p);\n    for (int i = 0; i < t -\
    \ p + 1; ++i) {\n        if (rht.get(i, i + p) == hash_p) {\n            print(i);\n\
    \        }\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - library/string/rolling_hash.hpp
  - library/various/random.hpp
  isVerificationFile: true
  path: tests/string/rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2026-01-14 15:04:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/string/rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/tests/string/rolling_hash.test.cpp
- /verify/tests/string/rolling_hash.test.cpp.html
title: "\u30ED\u30EA\u30CF\u306E\u30C6\u30B9\u30C8"
---
