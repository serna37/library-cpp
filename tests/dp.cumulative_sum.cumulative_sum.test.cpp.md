---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/dp/cumulative_sum/cumulative_sum.hpp
    title: "\u7D2F\u7A4D\u548C"
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    document_title: "\u7D2F\u7A4D\u548C\u306E\u30C6\u30B9\u30C8"
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ \"template/template.hpp\"\n#include \"library/dp/cumulative_sum/cumulative_sum.hpp\"\
    \n/**\n * @brief \u7D2F\u7A4D\u548C\u306E\u30C6\u30B9\u30C8\n */\nvoid solve()\
    \ {\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> A(N);\n    cin >> A;\n\
    \    vector<long long> S = cumulative_sum(A);\n    while (Q--) {\n        int\
    \ l, r;\n        cin >> l >> r;\n        print(S[r] - S[l]);\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - library/dp/cumulative_sum/cumulative_sum.hpp
  isVerificationFile: true
  path: tests/dp.cumulative_sum.cumulative_sum.test.cpp
  requiredBy: []
  timestamp: '2026-01-15 17:22:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/dp.cumulative_sum.cumulative_sum.test.cpp
layout: document
redirect_from:
- /verify/tests/dp.cumulative_sum.cumulative_sum.test.cpp
- /verify/tests/dp.cumulative_sum.cumulative_sum.test.cpp.html
title: "\u7D2F\u7A4D\u548C\u306E\u30C6\u30B9\u30C8"
---
