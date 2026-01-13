---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/string/finds.hpp
    title: "\u6587\u5B57\u5217\u691C\u7D22 \u8907\u6570"
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
    document_title: "\u6587\u5B57\u5217\u691C\u7D22 \u8907\u6570\u306E\u30C6\u30B9\
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
    \n#include \"template/template.hpp\"\n#include \"library/string/finds.hpp\"\n\
    void test_finds() {\n    // \u30B1\u30FC\u30B91: \u8907\u6570\u56DE\u51FA\u73FE\
    \u3059\u308B\u5834\u5408\n    // \"banana\" \u306E\u4E2D\u306B \"ana\" \u306F\
    \ 0\u6587\u5B57\u76EE(ana)na \u3068 2\u6587\u5B57\u76EE ban(ana) \u306B\u3042\u308B\
    \n    string T1 = \"banana\";\n    string S1 = \"ana\";\n    vector<int> expected1\
    \ = {1, 3}; // b(ana)na, ban(ana)\n    assert(finds(T1, S1) == expected1);\n \
    \   // \u30B1\u30FC\u30B92: 1\u56DE\u3060\u3051\u51FA\u73FE\u3059\u308B\u5834\u5408\
    \n    string T2 = \"hello world\";\n    string S2 = \"world\";\n    vector<int>\
    \ expected2 = {6};\n    assert(finds(T2, S2) == expected2);\n    // \u30B1\u30FC\
    \u30B93: \u5168\u304F\u51FA\u73FE\u3057\u306A\u3044\u5834\u5408\n    string T3\
    \ = \"apple\";\n    string S3 = \"orange\";\n    vector<int> expected3 = {};\n\
    \    assert(finds(T3, S3) == expected3);\n    // \u30B1\u30FC\u30B94: \u91CD\u306A\
    \u308B\u51FA\u73FE\u306E\u78BA\u8A8D\n    // \"aaaaa\" \u306E\u4E2D\u306B \"aa\"\
    \ \u306F 0, 1, 2, 3 \u6587\u5B57\u76EE\u306B\u3042\u308B\n    string T4 = \"aaaaa\"\
    ;\n    string S4 = \"aa\";\n    vector<int> expected4 = {0, 1, 2, 3};\n    assert(finds(T4,\
    \ S4) == expected4);\n    // \u30B1\u30FC\u30B95: \u691C\u7D22\u6587\u5B57\u5217\
    \u304C\u7A7A\u306E\u5834\u5408\n    // string::find(\"\") \u306F\u901A\u5E38 0\
    \ \u3092\u8FD4\u3059\u304C\u3001\u30EB\u30FC\u30D7\u306E\u4ED5\u65B9\u306B\u4F9D\
    \u5B58\u3059\u308B\n    // \u3053\u306E\u5B9F\u88C5\u3067\u306F 0, 1, 2, ... T.size()\
    \ \u307E\u3067\u8FD4\u308B\u6319\u52D5\u306B\u306A\u308B\n    string T5 = \"abc\"\
    ;\n    string S5 = \"\";\n    vector<int> result5 = finds(T5, S5);\n    assert(!result5.empty());\n\
    \    assert(result5[0] == 0);\n}\n/**\n * @brief \u6587\u5B57\u5217\u691C\u7D22\
    \ \u8907\u6570\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n    print(\"Hello\
    \ World\");\n    test_finds();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/string/finds.hpp
  isVerificationFile: true
  path: tests/string/join.test.cpp
  requiredBy: []
  timestamp: '2026-01-13 20:35:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/string/join.test.cpp
layout: document
redirect_from:
- /verify/tests/string/join.test.cpp
- /verify/tests/string/join.test.cpp.html
title: "\u6587\u5B57\u5217\u691C\u7D22 \u8907\u6570\u306E\u30C6\u30B9\u30C8"
---
