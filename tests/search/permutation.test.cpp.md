---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/search/permutation.hpp
    title: "\u9806\u5217\u5168\u63A2\u7D22"
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc425/tasks/abc425_b
    document_title: "\u9806\u5217\u5168\u63A2\u7D22\u306E\u30C6\u30B9\u30C8"
    links:
    - https://atcoder.jp/contests/abc425/tasks/abc425_b
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc425/tasks/abc425_b\"\n#include\
    \ \"template/template.hpp\"\n#include \"library/search/permutation.hpp\"\n/**\n\
    \ * @brief \u9806\u5217\u5168\u63A2\u7D22\u306E\u30C6\u30B9\u30C8\n */\nvoid solve()\
    \ {\n    int N;\n    cin >> N;\n    vector<int> A(N);\n    cin >> A;\n    vector<int>\
    \ P(N);\n    collection.sequence(P, 1ll);\n    bool is_loop_break = permutation(P,\
    \ [&]() {\n        bool alma = collection.all_match(\n            P, [&](int v,\
    \ int i) { return !~A[i] or A[i] == v; });\n        if (alma) {\n            print(\"\
    Yes\");\n            print(P);\n        }\n        return alma;\n    });\n   \
    \ if (!is_loop_break) {\n        print(\"No\");\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - library/search/permutation.hpp
  isVerificationFile: true
  path: tests/search/permutation.test.cpp
  requiredBy: []
  timestamp: '2026-01-12 19:33:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/search/permutation.test.cpp
layout: document
redirect_from:
- /verify/tests/search/permutation.test.cpp
- /verify/tests/search/permutation.test.cpp.html
title: "\u9806\u5217\u5168\u63A2\u7D22\u306E\u30C6\u30B9\u30C8"
---
