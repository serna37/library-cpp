---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/number/digit_sum.hpp
    title: "\u6841\u548C"
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
    document_title: "\u6841\u548C\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/number/digit_sum.hpp\"\
    \nvoid test_digit_sum() {\n    // \u30B1\u30FC\u30B91: 10\u9032\u6570\u3067\u306E\
    \u57FA\u672C\u7684\u306A\u8A08\u7B97\n    // 123 -> 1 + 2 + 3 = 6\n    assert(digit_sum(123)\
    \ == 6);\n    // \u30B1\u30FC\u30B92: 10\u9032\u6570\u30670\u304C\u542B\u307E\u308C\
    \u308B\u5834\u5408\n    // 1005 -> 1 + 0 + 0 + 5 = 6\n    assert(digit_sum(1005)\
    \ == 6);\n    // \u30B1\u30FC\u30B93: 1\u6841\u306E\u6570\u5B57\n    assert(digit_sum(9)\
    \ == 9);\n    assert(digit_sum(0) == 0);\n    // \u30B1\u30FC\u30B94: 2\u9032\u6570\
    \u3067\u306E\u8A08\u7B97 (base_number = 2)\n    // 7 \u306F 2\u9032\u6570\u3067\
    \ \"111\" -> 1 + 1 + 1 = 3\n    assert(digit_sum(7, 2) == 3);\n    // 8 \u306F\
    \ 2\u9032\u6570\u3067 \"1000\" -> 1 + 0 + 0 + 0 = 1\n    assert(digit_sum(8, 2)\
    \ == 1);\n    // \u30B1\u30FC\u30B95: 16\u9032\u6570\u3067\u306E\u8A08\u7B97 (base_number\
    \ = 16)\n    // 255 (0xFF) -> 15 + 15 = 30\n    assert(digit_sum(255, 16) == 30);\n\
    \    // \u30B1\u30FC\u30B96: \u8CA0\u306E\u6570\u306B\u5BFE\u3059\u308B\u6319\u52D5\
    \n    // \u73FE\u5728\u306E\u5B9F\u88C5\u3067\u306F N % base_number \u304C\u8CA0\
    \u306B\u306A\u308B\u53EF\u80FD\u6027\u304C\u3042\u308B\u305F\u3081\u78BA\u8A8D\
    \n    // -123 -> (-3) + (-2) + (-1) = -6 (C++\u306E\u4ED5\u69D8\u306B\u4F9D\u5B58\
    )\n    assert(digit_sum(-123) == -6);\n}\n/**\n * @brief \u6841\u548C\u306E\u30C6\
    \u30B9\u30C8\n */\nvoid solve() {\n    print(\"Hello World\");\n    test_digit_sum();\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - library/number/digit_sum.hpp
  isVerificationFile: true
  path: tests/number/digit_sum.test.cpp
  requiredBy: []
  timestamp: '2026-01-14 15:04:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/number/digit_sum.test.cpp
layout: document
redirect_from:
- /verify/tests/number/digit_sum.test.cpp
- /verify/tests/number/digit_sum.test.cpp.html
title: "\u6841\u548C\u306E\u30C6\u30B9\u30C8"
---
