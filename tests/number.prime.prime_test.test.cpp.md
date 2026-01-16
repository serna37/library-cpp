---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/number/prime/prime_test.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    document_title: "\u7D20\u6570\u5224\u5B9A\u306E\u30C6\u30B9\u30C8"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
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
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n#include \"template/template.hpp\"\n#include \"library/number/prime/prime_test.hpp\"\
    \n/**\n * @brief \u7D20\u6570\u5224\u5B9A\u306E\u30C6\u30B9\u30C8\n */\nvoid solve()\
    \ {\n    int N;\n    cin >> N;\n    int ans = 0;\n    for (int i = 0; i < N; ++i)\
    \ {\n        int n;\n        cin >> n;\n        bool is_prime = prime_test(n);\n\
    \        if (is_prime) ++ans;\n    }\n    print(ans);\n}\n"
  dependsOn:
  - template/template.hpp
  - library/number/prime/prime_test.hpp
  isVerificationFile: true
  path: tests/number.prime.prime_test.test.cpp
  requiredBy: []
  timestamp: '2026-01-16 12:40:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/number.prime.prime_test.test.cpp
layout: document
redirect_from:
- /verify/tests/number.prime.prime_test.test.cpp
- /verify/tests/number.prime.prime_test.test.cpp.html
title: "\u7D20\u6570\u5224\u5B9A\u306E\u30C6\u30B9\u30C8"
---
