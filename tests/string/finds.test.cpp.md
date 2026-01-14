---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/string/join.hpp
    title: "\u6587\u5B57\u5217\u7D50\u5408"
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
    document_title: "\u6587\u5B57\u5217\u7D50\u5408\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/string/join.hpp\"\nvoid\
    \ test_join() {\n    // \u30B1\u30FC\u30B91: \u8907\u6570\u306E\u8981\u7D20\u3092\
    \u30AB\u30F3\u30DE\u3067\u9023\u7D50\n    vector<string> v1 = {\"apple\", \"banana\"\
    , \"cherry\"};\n    assert(join(v1, \",\") == \"apple,banana,cherry\");\n    //\
    \ \u30B1\u30FC\u30B92: \u533A\u5207\u308A\u6587\u5B57\u304C\u8907\u6570\u306E\u6587\
    \u5B57\uFF08\u6587\u5B57\u5217\uFF09\u306E\u5834\u5408\n    vector<string> v2\
    \ = {\"2026\", \"01\", \"12\"};\n    assert(join(v2, \" / \") == \"2026 / 01 /\
    \ 12\");\n    // \u30B1\u30FC\u30B93: \u8981\u7D20\u304C1\u3064\u3060\u3051\u306E\
    \u5834\u5408\uFF08\u533A\u5207\u308A\u6587\u5B57\u306F\u73FE\u308C\u306A\u3044\
    \uFF09\n    vector<string> v3 = {\"single\"};\n    assert(join(v3, \"-\") == \"\
    single\");\n    // \u30B1\u30FC\u30B94: \u7A7A\u306E\u30D9\u30AF\u30BF\u30FC\u306E\
    \u5834\u5408\n    vector<string> v4 = {};\n    assert(join(v4, \"!\") == \"\"\
    );\n    // \u30B1\u30FC\u30B95: \u8981\u7D20\u304C\u7A7A\u6587\u5B57\u5217\u3092\
    \u542B\u3080\u5834\u5408\n    vector<string> v5 = {\"a\", \"\", \"b\"};\n    assert(join(v5,\
    \ \",\") == \"a,,b\");\n    // \u30B1\u30FC\u30B96: \u533A\u5207\u308A\u6587\u5B57\
    \u304C\u7A7A\u306E\u5834\u5408\n    vector<string> v6 = {\"H\", \"e\", \"l\",\
    \ \"l\", \"o\"};\n    assert(join(v6, \"\") == \"Hello\");\n}\n/**\n * @brief\
    \ \u6587\u5B57\u5217\u7D50\u5408\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n\
    \    print(\"Hello World\");\n    test_join();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/string/join.hpp
  isVerificationFile: true
  path: tests/string/finds.test.cpp
  requiredBy: []
  timestamp: '2026-01-14 18:38:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/string/finds.test.cpp
layout: document
redirect_from:
- /verify/tests/string/finds.test.cpp
- /verify/tests/string/finds.test.cpp.html
title: "\u6587\u5B57\u5217\u7D50\u5408\u306E\u30C6\u30B9\u30C8"
---
