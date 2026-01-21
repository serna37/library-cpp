---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/number/ext_gcd.hpp
    title: "\u62E1\u5F35Euclid\u306E\u4E92\u9664\u6CD5"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
    document_title: "\u62E1\u5F35Euclid\u306E\u4E92\u9664\u6CD5\u306E\u30C6\u30B9\u30C8"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
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
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n#include \"template/template.hpp\"\n#include \"library/number/ext_gcd.hpp\"\n\
    /**\n * @brief \u62E1\u5F35Euclid\u306E\u4E92\u9664\u6CD5\u306E\u30C6\u30B9\u30C8\
    \n */\nvoid solve() {\n    int a, b, x, y;\n    cin >> a >> b;\n    ext_gcd(a,\
    \ b, x, y);\n    cout << x << \" \" << y << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - library/number/ext_gcd.hpp
  isVerificationFile: true
  path: tests/number.ext_gcd.test.cpp
  requiredBy: []
  timestamp: '2026-01-20 19:53:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/number.ext_gcd.test.cpp
layout: document
redirect_from:
- /verify/tests/number.ext_gcd.test.cpp
- /verify/tests/number.ext_gcd.test.cpp.html
title: "\u62E1\u5F35Euclid\u306E\u4E92\u9664\u6CD5\u306E\u30C6\u30B9\u30C8"
---
