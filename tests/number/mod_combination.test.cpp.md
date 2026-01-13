---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/number/mod_combination.hpp
    title: "MOD \u7D44\u307F\u5408\u308F\u305B nCk"
  - icon: ':heavy_check_mark:'
    path: library/number/mod_factorial.hpp
    title: "MOD \u968E\u4E57"
  - icon: ':heavy_check_mark:'
    path: library/number/mod_inverse.hpp
    title: "MOD Fermat\u306E\u5C0F\u5B9A\u7406"
  - icon: ':heavy_check_mark:'
    path: library/number/mod_pow.hpp
    title: "MOD \u4E8C\u5206\u7D2F\u4E57"
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
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    document_title: "MOD \u7D44\u307F\u5408\u308F\u305B nCk\u306E\u30C6\u30B9\u30C8"
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n#include \"template/template.hpp\"\n#include \"library/number/mod_combination.hpp\"\
    \n/**\n * @brief MOD \u7D44\u307F\u5408\u308F\u305B nCk\u306E\u30C6\u30B9\u30C8\
    \n */\nvoid solve() {\n    int T, m;\n    cin >> T >> m;\n    while (T--) {\n\
    \        int n, k;\n        cin >> n >> k;\n        long long comb = mod_combination(n,\
    \ k, m);\n        print(comb);\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - library/number/mod_combination.hpp
  - library/number/mod_inverse.hpp
  - library/number/mod_pow.hpp
  - library/number/mod_factorial.hpp
  isVerificationFile: true
  path: tests/number/mod_combination.test.cpp
  requiredBy: []
  timestamp: '2026-01-13 19:33:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/number/mod_combination.test.cpp
layout: document
redirect_from:
- /verify/tests/number/mod_combination.test.cpp
- /verify/tests/number/mod_combination.test.cpp.html
title: "MOD \u7D44\u307F\u5408\u308F\u305B nCk\u306E\u30C6\u30B9\u30C8"
---
