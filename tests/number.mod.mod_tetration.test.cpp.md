---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/number/euler_phi.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: library/number/mod/mod_pow.hpp
    title: "MOD \u4E8C\u5206\u7D2F\u4E57"
  - icon: ':heavy_check_mark:'
    path: library/number/mod/mod_tetration.hpp
    title: "\u30C6\u30C8\u30EC\u30FC\u30B7\u30E7\u30F3"
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
    PROBLEM: https://judge.yosupo.jp/problem/tetration_mod
    document_title: "MOD \u30C6\u30C8\u30EC\u30FC\u30B7\u30E7\u30F3\u306E\u30C6\u30B9\
      \u30C8"
    links:
    - https://judge.yosupo.jp/problem/tetration_mod
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tetration_mod\"\n#include\
    \ \"template/template.hpp\"\n#include \"library/number/mod/mod_tetration.hpp\"\
    \n/**\n * @brief MOD \u30C6\u30C8\u30EC\u30FC\u30B7\u30E7\u30F3\u306E\u30C6\u30B9\
    \u30C8\n */\nvoid solve() {\n    int T;\n    cin >> T;\n    while (T--) {\n  \
    \      int a, b, m;\n        cin >> a >> b >> m;\n        long long ans = mod_tetration(a,\
    \ b, m) % m;\n        print(ans);\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - library/number/mod/mod_tetration.hpp
  - library/number/euler_phi.hpp
  - library/number/mod/mod_pow.hpp
  isVerificationFile: true
  path: tests/number.mod.mod_tetration.test.cpp
  requiredBy: []
  timestamp: '2026-01-19 15:21:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/number.mod.mod_tetration.test.cpp
layout: document
redirect_from:
- /verify/tests/number.mod.mod_tetration.test.cpp
- /verify/tests/number.mod.mod_tetration.test.cpp.html
title: "MOD \u30C6\u30C8\u30EC\u30FC\u30B7\u30E7\u30F3\u306E\u30C6\u30B9\u30C8"
---
