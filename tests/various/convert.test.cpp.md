---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/various/convert.hpp
    title: "\u578B\u5909\u63DB"
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
    document_title: "\u578B\u5909\u63DB\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/various/convert.hpp\"\
    \nvoid test_conversions() {\n    // int_to_char\n    assert(int_to_char(4) ==\
    \ '4');\n    assert(int_to_char(0) == '0');\n    // int_to_alph\n    assert(int_to_alph(0)\
    \ == 'a');\n    assert(int_to_alph(25) == 'z');\n    // char_to_int\n    assert(char_to_int('7')\
    \ == 7);\n    assert(char_to_int('0') == 0);\n    // int_to_string\n    assert(int_to_string(123LL)\
    \ == \"123\");\n    assert(int_to_string(-45LL) == \"-45\");\n    // string_to_int\n\
    \    assert(string_to_int(\"9876543210\") == 9876543210LL);\n}\n/**\n * @brief\
    \ \u578B\u5909\u63DB\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n    print(\"\
    Hello World\");\n    test_conversions();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/various/convert.hpp
  isVerificationFile: true
  path: tests/various/convert.test.cpp
  requiredBy: []
  timestamp: '2026-01-15 11:46:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/various/convert.test.cpp
layout: document
redirect_from:
- /verify/tests/various/convert.test.cpp
- /verify/tests/various/convert.test.cpp.html
title: "\u578B\u5909\u63DB\u306E\u30C6\u30B9\u30C8"
---
