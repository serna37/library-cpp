---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/string/range.hpp
    title: "\u6587\u5B57\u5217\u306E\u533A\u9593\u53D6\u5F97"
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
    document_title: "\u6587\u5B57\u5217\u306E\u533A\u9593\u53D6\u5F97\u306E\u30C6\u30B9\
      \u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/string/range.hpp\"\n\
    void test_range() {\n    string s = \"programming\"; // \u9577\u3055 11\n    //\
    \ \u30B1\u30FC\u30B91: \u6587\u5B57\u5217\u306E\u4E2D\u9593\u3092\u62BD\u51FA\n\
    \    // index: 3(g) \u304B\u3089 6(a)\n    assert(range(s, 3, 6) == \"gram\");\n\
    \    // \u30B1\u30FC\u30B92: 1\u6587\u5B57\u3060\u3051\u62BD\u51FA\n    assert(range(s,\
    \ 0, 0) == \"p\");\n    // \u30B1\u30FC\u30B93: \u6700\u5F8C\u307E\u3067\u62BD\
    \u51FA\n    assert(range(s, 7, 10) == \"ming\");\n    // \u30B1\u30FC\u30B94:\
    \ A > B \u306E\u5834\u5408 (\u7A7A\u6587\u5B57\u3092\u671F\u5F85)\n    assert(range(s,\
    \ 5, 2) == \"\");\n    // \u30B1\u30FC\u30B95: A \u304C\u6587\u5B57\u5217\u306E\
    \u30B5\u30A4\u30BA\u4EE5\u4E0A\u306E\u5834\u5408 (\u7A7A\u6587\u5B57\u3092\u671F\
    \u5F85)\n    assert(range(s, 15, 20) == \"\");\n    // \u30B1\u30FC\u30B96: B\
    \ \u304C\u6587\u5B57\u5217\u306E\u30B5\u30A4\u30BA\u3092\u8D85\u3048\u308B\u5834\
    \u5408\n    // std::string::substr \u306F\u9577\u3055\u304C\u7BC4\u56F2\u3092\u8D85\
    \u3048\u308B\u3068\u672B\u5C3E\u307E\u3067\u3092\u8FD4\u3057\u307E\u3059\n   \
    \ assert(range(s, 8, 20) == \"ing\");\n    // \u30B1\u30FC\u30B97: \u7A7A\u6587\
    \u5B57\u5217\u306B\u5BFE\u3059\u308B\u64CD\u4F5C\n    assert(range(\"\", 0, 0)\
    \ == \"\");\n}\n/**\n * @brief \u6587\u5B57\u5217\u306E\u533A\u9593\u53D6\u5F97\
    \u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n    print(\"Hello World\");\n \
    \   test_range();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/string/range.hpp
  isVerificationFile: true
  path: tests/string.range.test.cpp
  requiredBy: []
  timestamp: '2026-01-19 13:52:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/string.range.test.cpp
layout: document
redirect_from:
- /verify/tests/string.range.test.cpp
- /verify/tests/string.range.test.cpp.html
title: "\u6587\u5B57\u5217\u306E\u533A\u9593\u53D6\u5F97\u306E\u30C6\u30B9\u30C8"
---
