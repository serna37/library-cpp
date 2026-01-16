---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/number/factorial.hpp
    title: "\u968E\u4E57"
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
    document_title: "\u968E\u4E57\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/number/factorial.hpp\"\
    \nvoid test_factorial() {\n    // \u30B1\u30FC\u30B91: \u57FA\u672C\u7684\u306A\
    \u968E\u4E57\n    // 3! = 3 * 2 * 1 = 6\n    assert(factorial(3) == 6ll);\n  \
    \  // 5! = 5 * 4 * 3 * 2 * 1 = 120\n    assert(factorial(5) == 120ll);\n    //\
    \ \u30B1\u30FC\u30B92: 0\u306E\u968E\u4E57 (\u6570\u5B66\u7684\u5B9A\u7FA9\u306B\
    \u3088\u308A 0! = 1)\n    assert(factorial(0) == 1ll);\n    // \u30B1\u30FC\u30B9\
    3: 1\u306E\u968E\u4E57\n    assert(factorial(1) == 1ll);\n    // \u30B1\u30FC\u30B9\
    4: \u5C11\u3057\u5927\u304D\u3081\u306E\u5024\n    // 10! = 3,628,800\n    assert(factorial(10)\
    \ == 3628800ll);\n    // \u30B1\u30FC\u30B95: long long \u306E\u9650\u754C\u306B\
    \u8FD1\u3044\u5024\n    // 20! = 2,432,902,008,176,640,000\n    // (\u3053\u308C\
    \u4EE5\u4E0A\uFF0821!\uFF09\u306F 64bit\u6574\u6570\u306E\u7BC4\u56F2\u3092\u8D85\
    \u3048\u3066\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u307E\u3059)\n  \
    \  assert(factorial(20) == 2432902008176640000ll);\n    // \u30B1\u30FC\u30B9\
    6: \u8CA0\u306E\u5165\u529B\u306B\u5BFE\u3059\u308B\u6319\u52D5\n    // \u73FE\
    \u5728\u306E\u5B9F\u88C5\u3067\u306F while (N > 0) \u306A\u306E\u3067\u3001\u8CA0\
    \u306E\u6570\u3092\u5165\u308C\u308B\u3068 res = 1 \u304C\u8FD4\u308B\n    assert(factorial(-5)\
    \ == 1ll);\n}\n/**\n * @brief \u968E\u4E57\u306E\u30C6\u30B9\u30C8\n */\nvoid\
    \ solve() {\n    print(\"Hello World\");\n    test_factorial();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/number/factorial.hpp
  isVerificationFile: true
  path: tests/number.factorial.test.cpp
  requiredBy: []
  timestamp: '2026-01-16 14:13:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/number.factorial.test.cpp
layout: document
redirect_from:
- /verify/tests/number.factorial.test.cpp
- /verify/tests/number.factorial.test.cpp.html
title: "\u968E\u4E57\u306E\u30C6\u30B9\u30C8"
---
