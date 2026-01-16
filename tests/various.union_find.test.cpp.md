---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/various/union_find.hpp
    title: "UnionFind \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    document_title: "Union Find\u306E\u30C6\u30B9\u30C8"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
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
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#include \"template/template.hpp\"\n#include \"library/various/union_find.hpp\"\
    \n/**\n * @brief Union Find\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n   \
    \ int N, Q;\n    cin >> N >> Q;\n    UnionFind uf(N);\n    while (Q--) {\n   \
    \     int com, x, y;\n        cin >> com >> x >> y;\n        if (com == 0) {\n\
    \            uf.unite(x, y);\n        }\n        if (com == 1) {\n           \
    \ print(uf.find(x) == uf.find(y) ? 1 : 0);\n        }\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - library/various/union_find.hpp
  isVerificationFile: true
  path: tests/various.union_find.test.cpp
  requiredBy: []
  timestamp: '2026-01-16 11:55:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/various.union_find.test.cpp
layout: document
redirect_from:
- /verify/tests/various.union_find.test.cpp
- /verify/tests/various.union_find.test.cpp.html
title: "Union Find\u306E\u30C6\u30B9\u30C8"
---
