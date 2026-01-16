---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/number/base_convert.hpp
    title: "\u9032\u6570\u5909\u63DB"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0233
    document_title: "\u9032\u6570\u5909\u63DB\u306E\u30C6\u30B9\u30C8"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0233
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
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0233\"\
    \n#include \"template/template.hpp\"\n#include \"library/number/base_convert.hpp\"\
    \n/**\n * @brief \u9032\u6570\u5909\u63DB\u306E\u30C6\u30B9\u30C8\n */\nvoid solve()\
    \ {\n    while (1) {\n        int x;\n        cin >> x;\n        if (x == 0) break;\n\
    \        vector<int> cvt = base_convert(x, -10);\n        for (auto &&v : cvt)\
    \ {\n            cout << v;\n        }\n        cout << endl;\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - library/number/base_convert.hpp
  isVerificationFile: true
  path: tests/number.base_convert.test.cpp
  requiredBy: []
  timestamp: '2026-01-16 16:23:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/number.base_convert.test.cpp
layout: document
redirect_from:
- /verify/tests/number.base_convert.test.cpp
- /verify/tests/number.base_convert.test.cpp.html
title: "\u9032\u6570\u5909\u63DB\u306E\u30C6\u30B9\u30C8"
---
