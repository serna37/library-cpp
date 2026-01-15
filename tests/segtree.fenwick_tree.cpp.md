---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/segtree/fenwick_tree.hpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Fenwick Tree\u306E\u30C6\u30B9\u30C8:RSQ"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
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
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n#include \"template/template.hpp\"\n#include \"library/segtree/fenwick_tree.hpp\"\
    \n/**\n * @brief Fenwick Tree\u306E\u30C6\u30B9\u30C8:RSQ\n */\nvoid solve() {\n\
    \    int N, Q;\n    cin >> N >> Q;\n    FenwickTree fwk(N);\n    while (Q--) {\n\
    \        int com, x, y;\n        cin >> com >> x >> y;\n        if (com == 0)\
    \ {\n            --x;\n            fwk.add(x, y);\n        }\n        if (com\
    \ == 1) {\n            --x, --y;\n            print(fwk.sum(y) - fwk.sum(x - 1));\n\
    \        }\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - library/segtree/fenwick_tree.hpp
  isVerificationFile: false
  path: tests/segtree.fenwick_tree.cpp
  requiredBy: []
  timestamp: '2026-01-15 17:22:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tests/segtree.fenwick_tree.cpp
layout: document
redirect_from:
- /library/tests/segtree.fenwick_tree.cpp
- /library/tests/segtree.fenwick_tree.cpp.html
title: "Fenwick Tree\u306E\u30C6\u30B9\u30C8:RSQ"
---
