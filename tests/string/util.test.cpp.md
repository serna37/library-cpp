---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/string/util.hpp
    title: "\u6587\u5B57\u5217Util"
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
    document_title: "\u6587\u5B57\u5217Util\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/string/util.hpp\"\nvoid\
    \ test_string_manipulation() {\n    // string_to_lower\n    assert(string_to_lower(\"\
    AbC12\") == \"abc12\");\n    // string_to_upper\n    assert(string_to_upper(\"\
    abc12\") == \"ABC12\");\n    // char_is_lower / upper\n    assert(char_is_lower('a')\
    \ == true);\n    assert(char_is_lower('A') == false);\n    assert(char_is_upper('Z')\
    \ == true);\n    assert(char_is_upper('z') == false);\n}\n/**\n * @brief \u6587\
    \u5B57\u5217Util\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n    print(\"Hello\
    \ World\");\n    test_string_manipulation();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/string/util.hpp
  isVerificationFile: true
  path: tests/string/util.test.cpp
  requiredBy: []
  timestamp: '2026-01-15 10:11:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/string/util.test.cpp
layout: document
redirect_from:
- /verify/tests/string/util.test.cpp
- /verify/tests/string/util.test.cpp.html
title: "\u6587\u5B57\u5217Util\u306E\u30C6\u30B9\u30C8"
---
