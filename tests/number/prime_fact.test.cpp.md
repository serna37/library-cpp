---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/number/prime_fact.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
    document_title: "\u7D20\u56E0\u6570\u5206\u89E3\u306E\u30C6\u30B9\u30C8"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
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
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \n#include \"template/template.hpp\"\n#include \"library/number/prime_fact.hpp\"\
    \n/**\n * @brief \u7D20\u56E0\u6570\u5206\u89E3\u306E\u30C6\u30B9\u30C8\n */\n\
    void solve() {\n    int N;\n    cin >> N;\n    cout << N << \":\";\n    map<int,\
    \ int> pf = prime_fact(N);\n    for (auto &&[k, v] : pf) {\n        for (int i\
    \ = 0; i < v; ++i) {\n            cout << \" \" << k;\n        }\n    }\n    cout\
    \ << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - library/number/prime_fact.hpp
  isVerificationFile: true
  path: tests/number/prime_fact.test.cpp
  requiredBy: []
  timestamp: '2026-01-14 18:38:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/number/prime_fact.test.cpp
layout: document
redirect_from:
- /verify/tests/number/prime_fact.test.cpp
- /verify/tests/number/prime_fact.test.cpp.html
title: "\u7D20\u56E0\u6570\u5206\u89E3\u306E\u30C6\u30B9\u30C8"
---
