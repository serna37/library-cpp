---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/sequence/collection_util.hpp
    title: "\u914D\u5217\u7CFBUtil"
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
    document_title: "\u914D\u5217\u7CFBUtil\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/sequence/collection_util.hpp\"\
    \nvoid test_collection_class() {\n    vector<int> v = {3, 1, 4, 1, 5};\n    //\
    \ min / max / sum\n    assert(collection.min(v) == 1);\n    assert(collection.max(v)\
    \ == 5);\n    assert(collection.sum(v) == 14);\n    // match\u7CFB (\u5F15\u6570\
    : \u5024, \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9)\n    assert(collection.all_match(v,\
    \ [](int x, int _) { return x > 0; }) == true);\n    assert(collection.any_match(v,\
    \ [](int x, int _) { return x == 5; }) ==\n           true);\n    assert(collection.none_match(v,\
    \ [](int x, int _) { return x == 100; }) ==\n           true);\n    // sorting\
    \ / distinct\n    vector<int> v2 = {3, 1, 2, 1};\n    collection.asc(v2);\n  \
    \  assert(v2 == vector<int>({1, 1, 2, 3}));\n    collection.distinct(v2);\n  \
    \  assert(v2 == vector<int>({1, 2, 3}));\n    collection.desc(v2);\n    assert(v2\
    \ == vector<int>({3, 2, 1}));\n    collection.reverse(v2);\n    assert(v2 == vector<int>({1,\
    \ 2, 3}));\n    // sequence\n    vector<int> v3(3);\n    collection.sequence(v3,\
    \ 10ll); // 10, 11, 12\n    assert(v3[0] == 10 && v3[2] == 12);\n    // erase\
    \ (set / multiset)\n    multiset<int> ms = {1, 2, 2, 3};\n    collection.erase(ms,\
    \ 2ll); // 1\u3064\u3060\u3051\u6D88\u3059\u306F\u305A\n    assert(ms.count(2)\
    \ == 1);\n}\n/**\n * @brief \u914D\u5217\u7CFBUtil\u306E\u30C6\u30B9\u30C8\n */\n\
    void solve() {\n    print(\"Hello World\");\n    test_collection_class();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/sequence/collection_util.hpp
  isVerificationFile: true
  path: tests/sequence/collection_util.test.cpp
  requiredBy: []
  timestamp: '2026-01-14 15:04:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/sequence/collection_util.test.cpp
layout: document
redirect_from:
- /verify/tests/sequence/collection_util.test.cpp
- /verify/tests/sequence/collection_util.test.cpp.html
title: "\u914D\u5217\u7CFBUtil\u306E\u30C6\u30B9\u30C8"
---
