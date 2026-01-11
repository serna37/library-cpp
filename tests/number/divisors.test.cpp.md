---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/number/divisors.hpp
    title: "\u7D04\u6570\u5217\u6319"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D
    document_title: "\u7D04\u6570\u5217\u6319\u306E\u30C6\u30B9\u30C8"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D
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
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D\"\
    \n#include \"template/template.hpp\"\n#include \"library/number/divisors.hpp\"\
    \n/**\n * @brief \u7D04\u6570\u5217\u6319\u306E\u30C6\u30B9\u30C8\n */\nvoid solve()\
    \ {\n    int a, b, c;\n    cin >> a >> b >> c;\n    int ans = 0;\n    vector<int>\
    \ divs = divisors(c);\n    for (auto &&v : divs) {\n        if (a <= v and v <=\
    \ b) {\n            ++ans;\n        }\n    }\n    print(ans);\n}\n"
  dependsOn:
  - template/template.hpp
  - library/number/divisors.hpp
  isVerificationFile: true
  path: tests/number/divisors.test.cpp
  requiredBy: []
  timestamp: '2026-01-11 18:34:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/number/divisors.test.cpp
layout: document
redirect_from:
- /verify/tests/number/divisors.test.cpp
- /verify/tests/number/divisors.test.cpp.html
title: "\u7D04\u6570\u5217\u6319\u306E\u30C6\u30B9\u30C8"
---
