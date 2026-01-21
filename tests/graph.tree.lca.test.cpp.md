---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/dp/doubling.hpp
    title: "\u30C0\u30D6\u30EA\u30F3\u30B0"
  - icon: ':question:'
    path: library/graph/base/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: library/graph/base/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: library/graph/shortest_path/bfs.hpp
    title: BFS
  - icon: ':heavy_check_mark:'
    path: library/graph/tree/lca.hpp
    title: LCA
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    document_title: "\u6728 - LCA\u306E\u30C6\u30B9\u30C8"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
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
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n#include \"template/template.hpp\"\n#include \"library/graph/tree/lca.hpp\"\n\
    /**\n * @brief \u6728 - LCA\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n   \
    \ int N;\n    cin >> N;\n    Graph G(N);\n    for (int i = 0; i < N; ++i) {\n\
    \        int k;\n        cin >> k;\n        for (int j = 0; j < k; ++j) {\n  \
    \          int c;\n            cin >> c;\n            G.add_both(i, c);\n    \
    \    }\n    }\n    LCA tree(G);\n    int Q;\n    cin >> Q;\n    while (Q--) {\n\
    \        int u, v;\n        cin >> u >> v;\n        print(tree.get_lca(u, v));\n\
    \    }\n}\n"
  dependsOn:
  - template/template.hpp
  - library/graph/tree/lca.hpp
  - library/graph/shortest_path/bfs.hpp
  - library/graph/base/graph.hpp
  - library/graph/base/edge.hpp
  - library/dp/doubling.hpp
  isVerificationFile: true
  path: tests/graph.tree.lca.test.cpp
  requiredBy: []
  timestamp: '2026-01-21 11:49:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/graph.tree.lca.test.cpp
layout: document
redirect_from:
- /verify/tests/graph.tree.lca.test.cpp
- /verify/tests/graph.tree.lca.test.cpp.html
title: "\u6728 - LCA\u306E\u30C6\u30B9\u30C8"
---
