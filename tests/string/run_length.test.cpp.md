---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/string/run_length.hpp
    title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E"
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
    document_title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\u306E\u30C6\u30B9\
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
    \n#include \"template/template.hpp\"\n#include \"library/string/run_length.hpp\"\
    \nvoid test_run_length() {\n    // \u30B1\u30FC\u30B91: \u57FA\u672C\u7684\u306A\
    \u9023\u7D9A\u6587\u5B57\n    // \"aaabbc\" -> [('a', 3), ('b', 2), ('c', 1)]\n\
    \    string s1 = \"aaabbc\";\n    vector<pair<char, int>> res1 = run_length(s1);\n\
    \    assert(res1.size() == 3ll);\n    assert(res1[0] == make_pair('a', 3ll));\n\
    \    assert(res1[1] == make_pair('b', 2ll));\n    assert(res1[2] == make_pair('c',\
    \ 1ll));\n    // \u30B1\u30FC\u30B92: \u5168\u3066\u540C\u3058\u6587\u5B57\n \
    \   string s2 = \"aaaaa\";\n    vector<pair<char, int>> res2 = run_length(s2);\n\
    \    assert(res2.size() == 1ll);\n    assert(res2[0] == make_pair('a', 5ll));\n\
    \    // \u30B1\u30FC\u30B93: \u4EA4\u4E92\u306B\u73FE\u308C\u308B\u6587\u5B57\n\
    \    // \"abab\" -> [('a', 1), ('b', 1), ('a', 1), ('b', 1)]\n    string s3 =\
    \ \"abab\";\n    vector<pair<char, int>> res3 = run_length(s3);\n    assert(res3.size()\
    \ == 4ll);\n    assert(res3[2].first == 'a' && res3[2].second == 1ll);\n    //\
    \ \u30B1\u30FC\u30B94: \u7A7A\u6587\u5B57\u5217\n    string s4 = \"\";\n    vector<pair<char,\
    \ int>> res4 = run_length(s4);\n    assert(res4.empty());\n    // \u30B1\u30FC\
    \u30B95: 1\u6587\u5B57\u3060\u3051\n    string s5 = \"z\";\n    vector<pair<char,\
    \ int>> res5 = run_length(s5);\n    assert(res5.size() == 1ll);\n    assert(res5[0].first\
    \ == 'z' && res5[0].second == 1ll);\n}\n/**\n * @brief \u30E9\u30F3\u30EC\u30F3\
    \u30B0\u30B9\u5727\u7E2E\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n    print(\"\
    Hello World\");\n    test_run_length();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/string/run_length.hpp
  isVerificationFile: true
  path: tests/string/run_length.test.cpp
  requiredBy: []
  timestamp: '2026-01-13 10:09:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/string/run_length.test.cpp
layout: document
redirect_from:
- /verify/tests/string/run_length.test.cpp
- /verify/tests/string/run_length.test.cpp.html
title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\u306E\u30C6\u30B9\u30C8"
---
