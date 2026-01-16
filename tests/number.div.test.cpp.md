---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/number/div.hpp
    title: "\u5272\u308A\u7B97"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    document_title: "\u5272\u308A\u7B97\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/number/div.hpp\"\nvoid\
    \ test_math_functions() {\n    // div_ceil (a/b \u3067\u5207\u308A\u4E0A\u3052\
    )\n    assert(div_ceil(10, 3) == 4);\n    assert(div_ceil(10, 5) == 2);\n    assert(div_ceil(-10,\
    \ 3) == -3); // 0\u65B9\u5411\u3067\u306F\u306A\u304F\u8CA0\u306E\u7121\u9650\u5927\
    \u65B9\u5411\u3078\u306E\u5207\u308A\u4E0A\u3052\n    // div_floor (a/b \u3067\
    \u5207\u308A\u6368\u3066)\n    assert(div_floor(10, 3) == 3);\n    assert(div_floor(-10,\
    \ 3) == -4);\n}\n/**\n * @brief \u5272\u308A\u7B97\u306E\u30C6\u30B9\u30C8\n */\n\
    void solve() {\n    print(\"Hello World\");\n    test_math_functions();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/number/div.hpp
  isVerificationFile: true
  path: tests/number.div.test.cpp
  requiredBy: []
  timestamp: '2026-01-16 13:01:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/number.div.test.cpp
layout: document
redirect_from:
- /verify/tests/number.div.test.cpp
- /verify/tests/number.div.test.cpp.html
title: "\u5272\u308A\u7B97\u306E\u30C6\u30B9\u30C8"
---
