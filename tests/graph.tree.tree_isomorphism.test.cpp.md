---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/base/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: library/graph/base/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: library/graph/tree/centroid.hpp
    title: "\u6728\u306E\u91CD\u5FC3"
  - icon: ':heavy_check_mark:'
    path: library/graph/tree/tree_isomorphism.hpp
    title: "\u6728\u306E\u540C\u578B\u6027\u5224\u5B9A"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2821
    document_title: "\u6728 - \u6728\u306E\u540C\u578B\u6027\u5224\u5B9A\u306E\u30C6\
      \u30B9\u30C8"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2821
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
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2821\"\
    \n#include \"template/template.hpp\"\n#include \"library/graph/tree/tree_isomorphism.hpp\"\
    \n#include \"library/various/union_find.hpp\"\n/**\n * @brief \u6728 - \u6728\u306E\
    \u540C\u578B\u6027\u5224\u5B9A\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n\
    \    int N, M;\n    cin >> N >> M;\n    vector<int> U(M), V(M);\n    UnionFind\
    \ uf(N);\n    for (int i = 0; i < M; ++i) {\n        cin >> U[i] >> V[i];\n  \
    \      --U[i], --V[i];\n        uf.unite(U[i], V[i]);\n    }\n    vector<vector<int>>\
    \ belong_v(N), belong_e(N);\n    for (int i = 0; i < N; ++i) {\n        belong_v[uf.find(i)].emplace_back(i);\n\
    \    }\n    for (int i = 0; i < M; ++i) {\n        belong_e[uf.find(U[i])].emplace_back(i);\n\
    \    }\n    cin >> N;\n    Graph t(N);\n    t.read(N - 1);\n    int ret = 0;\n\
    \    vector<int> id(belong_v.size());\n    for (int i = 0; i < (int)belong_v.size();\
    \ ++i) {\n        if (uf.find(i) == i) {\n            Graph g(belong_v[i].size());\n\
    \            int ptr = 0;\n            for (auto &p : belong_v[i]) id[p] = ptr++;\n\
    \            for (auto &j : belong_e[i]) {\n                g.add_both(id[U[j]],\
    \ id[V[j]]);\n            }\n            ret += tree_isomorphism(t, g);\n    \
    \    }\n    }\n    print(ret);\n}\n"
  dependsOn:
  - template/template.hpp
  - library/graph/tree/tree_isomorphism.hpp
  - library/graph/base/graph.hpp
  - library/graph/base/edge.hpp
  - library/graph/tree/centroid.hpp
  - library/various/union_find.hpp
  isVerificationFile: true
  path: tests/graph.tree.tree_isomorphism.test.cpp
  requiredBy: []
  timestamp: '2026-01-21 19:52:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/graph.tree.tree_isomorphism.test.cpp
layout: document
redirect_from:
- /verify/tests/graph.tree.tree_isomorphism.test.cpp
- /verify/tests/graph.tree.tree_isomorphism.test.cpp.html
title: "\u6728 - \u6728\u306E\u540C\u578B\u6027\u5224\u5B9A\u306E\u30C6\u30B9\u30C8"
---
