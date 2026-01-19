---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/string/split_multi.hpp
    title: "\u6587\u5B57\u5217\u3092\u533A\u5207\u308B \u8907\u6570"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    document_title: "\u6587\u5B57\u5217\u3092\u533A\u5207\u308B \u8907\u6570\u306E\
      \u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/string/split_multi.hpp\"\
    \nvoid test_split_multi() {\n    // \u30B1\u30FC\u30B91: \u8907\u6570\u306E\u533A\
    \u5207\u308A\u6587\u5B57\uFF08\u30B9\u30DA\u30FC\u30B9\u3001\u30AB\u30F3\u30DE\
    \u3001\u30BB\u30DF\u30B3\u30ED\u30F3\uFF09\n    string s1 = \"apple banana,cherry;orange\"\
    ;\n    string seps1 = \" ,;\";\n    vector<string> expected1 = {\"apple\", \"\
    banana\", \"cherry\", \"orange\"};\n    assert(split_multi(s1, seps1) == expected1);\n\
    \    // \u30B1\u30FC\u30B92: \u533A\u5207\u308A\u6587\u5B57\u304C\u9023\u7D9A\u3059\
    \u308B\u5834\u5408\uFF08\u7A7A\u8981\u7D20\u304C\u751F\u6210\u3055\u308C\u308B\
    \uFF09\n    string s2 = \"a,, b\";\n    string seps2 = \", \";\n    // 'a' ->\
    \ ','(\u5206\u5272) -> ','(\u5206\u5272) -> ' '(\u5206\u5272) -> 'b'\n    vector<string>\
    \ expected2 = {\"a\", \"\", \"\", \"b\"};\n    assert(split_multi(s2, seps2) ==\
    \ expected2);\n    // \u30B1\u30FC\u30B93: \u6570\u5024\u3092\u533A\u5207\u308A\
    \u6587\u5B57\u306B\u3059\u308B\n    string s3 = \"123a456b789\";\n    string seps3\
    \ = \"ab\";\n    vector<string> expected3 = {\"123\", \"456\", \"789\"};\n   \
    \ assert(split_multi(s3, seps3) == expected3);\n    // \u30B1\u30FC\u30B94: \u533A\
    \u5207\u308A\u6587\u5B57\u304C\u6587\u5B57\u5217\u306B\u542B\u307E\u308C\u306A\
    \u3044\u5834\u5408\n    string s4 = \"hello\";\n    string seps4 = \"xyz\";\n\
    \    vector<string> expected4 = {\"hello\"};\n    assert(split_multi(s4, seps4)\
    \ == expected4);\n    // \u30B1\u30FC\u30B95: \u5148\u982D\u3084\u672B\u5C3E\u304C\
    \u533A\u5207\u308A\u6587\u5B57\u306E\u5834\u5408\n    string s5 = \"/usr/bin/\"\
    ;\n    string seps5 = \"/\";\n    vector<string> expected5 = {\"\", \"usr\", \"\
    bin\", \"\"};\n    assert(split_multi(s5, seps5) == expected5);\n    // \u30B1\
    \u30FC\u30B96: \u7A7A\u306E\u6587\u5B57\u5217\u3068\u7A7A\u306E\u533A\u5207\u308A\
    \u6587\u5B57\n    assert(split_multi(\"\", \",\") == vector<string>({\"\"}));\n\
    \    assert(split_multi(\"abc\", \"\") == vector<string>({\"abc\"}));\n}\n/**\n\
    \ * @brief \u6587\u5B57\u5217\u3092\u533A\u5207\u308B \u8907\u6570\u306E\u30C6\
    \u30B9\u30C8\n */\nvoid solve() {\n    print(\"Hello World\");\n    test_split_multi();\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - library/string/split_multi.hpp
  isVerificationFile: true
  path: tests/string.split_multi.test.cpp
  requiredBy: []
  timestamp: '2026-01-19 14:50:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/string.split_multi.test.cpp
layout: document
redirect_from:
- /verify/tests/string.split_multi.test.cpp
- /verify/tests/string.split_multi.test.cpp.html
title: "\u6587\u5B57\u5217\u3092\u533A\u5207\u308B \u8907\u6570\u306E\u30C6\u30B9\u30C8"
---
