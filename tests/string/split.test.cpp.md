---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/string/split.hpp
    title: "\u6587\u5B57\u5217\u3092\u533A\u5207\u308B"
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
    document_title: "\u6587\u5B57\u5217\u3092\u533A\u5207\u308B\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/string/split.hpp\"\n\
    void test_split() {\n    // \u30B1\u30FC\u30B91: \u57FA\u672C\u7684\u306A\u30AB\
    \u30F3\u30DE\u533A\u5207\u308A\n    string s1 = \"apple,banana,cherry\";\n   \
    \ vector<string> expected1 = {\"apple\", \"banana\", \"cherry\"};\n    assert(split(s1,\
    \ ',') == expected1);\n    // \u30B1\u30FC\u30B92: \u30BB\u30D1\u30EC\u30FC\u30BF\
    \u304C\u9023\u7D9A\u3059\u308B\u5834\u5408\uFF08\u7A7A\u306E\u8981\u7D20\u304C\
    \u4F5C\u3089\u308C\u308B\uFF09\n    string s2 = \"a,,b\";\n    vector<string>\
    \ expected2 = {\"a\", \"\", \"b\"};\n    assert(split(s2, ',') == expected2);\n\
    \    // \u30B1\u30FC\u30B93: \u5148\u982D\u3084\u672B\u5C3E\u306B\u30BB\u30D1\u30EC\
    \u30FC\u30BF\u304C\u3042\u308B\u5834\u5408\n    string s3 = \",a,b,\";\n    vector<string>\
    \ expected3 = {\"\", \"a\", \"b\", \"\"};\n    assert(split(s3, ',') == expected3);\n\
    \    // \u30B1\u30FC\u30B94: \u30BB\u30D1\u30EC\u30FC\u30BF\u304C\u542B\u307E\u308C\
    \u306A\u3044\u5834\u5408\n    string s4 = \"hello\";\n    vector<string> expected4\
    \ = {\"hello\"};\n    assert(split(s4, ',') == expected4);\n    // \u30B1\u30FC\
    \u30B95: \u7A7A\u6587\u5B57\u5217\u306E\u5834\u5408\n    string s5 = \"\";\n \
    \   vector<string> expected5 = {\n        \"\"}; // \u521D\u671F\u5024\u304C {\"\
    \"} \u306A\u306E\u3067\u8981\u7D20\u65701\u306E\u7A7A\u6587\u5B57\u304C\u8FD4\u308B\
    \n    assert(split(s5, ',') == expected5);\n    // \u30B1\u30FC\u30B96: \u30BB\
    \u30D1\u30EC\u30FC\u30BF\u306E\u307F\u306E\u6587\u5B57\u5217\n    string s6 =\
    \ \",,\";\n    vector<string> expected6 = {\"\", \"\", \"\"};\n    assert(split(s6,\
    \ ',') == expected6);\n}\n/**\n * @brief \u6587\u5B57\u5217\u3092\u533A\u5207\u308B\
    \u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n    print(\"Hello World\");\n \
    \   test_split();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/string/split.hpp
  isVerificationFile: true
  path: tests/string/split.test.cpp
  requiredBy: []
  timestamp: '2026-01-14 20:12:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/string/split.test.cpp
layout: document
redirect_from:
- /verify/tests/string/split.test.cpp
- /verify/tests/string/split.test.cpp.html
title: "\u6587\u5B57\u5217\u3092\u533A\u5207\u308B\u306E\u30C6\u30B9\u30C8"
---
