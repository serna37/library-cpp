---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/number/combination.hpp
    title: "\u7D44\u307F\u5408\u308F\u305B nCk"
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
    document_title: "\u7D44\u307F\u5408\u308F\u305B nCk\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/number/combination.hpp\"\
    \nvoid test_combination() {\n    // \u30B1\u30FC\u30B91: \u57FA\u672C\u7684\u306A\
    \u7D44\u307F\u5408\u308F\u305B\n    // 5C2 = (5 * 4) / (2 * 1) = 10\n    assert(combination(5,\
    \ 2) == 10ll);\n    // \u30B1\u30FC\u30B92: nC0 \u3068 nCn \u306F\u5E38\u306B\
    \ 1\n    assert(combination(5, 0) == 1ll);\n    assert(combination(5, 5) == 1ll);\n\
    \    // \u30B1\u30FC\u30B93: k > n \u306E\u5834\u5408\u306F 0 (\u5B9A\u7FA9\u306B\
    \u57FA\u3065\u304F)\n    assert(combination(3, 5) == 0ll);\n    // \u30B1\u30FC\
    \u30B94: k < 0 \u306E\u5834\u5408\u306F 0\n    assert(combination(5, -1) == 0ll);\n\
    \    // \u30B1\u30FC\u30B95: nC1 \u306F n\n    assert(combination(10, 1) == 10ll);\n\
    \    // \u30B1\u30FC\u30B96: \u5C11\u3057\u5927\u304D\u3081\u306E\u5024\n    //\
    \ 15C7 = 6435\n    assert(combination(15, 7) == 6435ll);\n    // \u30B1\u30FC\u30B9\
    7: \u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62\u306E\u5BFE\u79F0\u6027 (nCk\
    \ == nC(n-k))\n    // 10C3 == 10C7 == 120\n    assert(combination(10, 3) == 120ll);\n\
    \    assert(combination(10, 7) == 120ll);\n}\n/**\n * @brief \u7D44\u307F\u5408\
    \u308F\u305B nCk\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n    print(\"Hello\
    \ World\");\n    test_combination();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/number/combination.hpp
  isVerificationFile: true
  path: tests/number.combination.test.cpp
  requiredBy: []
  timestamp: '2026-01-19 15:56:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/number.combination.test.cpp
layout: document
redirect_from:
- /verify/tests/number.combination.test.cpp
- /verify/tests/number.combination.test.cpp.html
title: "\u7D44\u307F\u5408\u308F\u305B nCk\u306E\u30C6\u30B9\u30C8"
---
