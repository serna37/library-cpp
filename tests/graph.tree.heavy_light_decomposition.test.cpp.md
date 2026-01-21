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
    path: library/graph/tree/heavy_light_decomposition.hpp
    title: "\u91CD\u8EFD\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: library/segtree/lazy_segment_tree.hpp
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: library/various/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: library/various/monoid_act.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u4F5C\u7528\u7D20"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2450
    document_title: "\u6728 - HLD\u306E\u30C6\u30B9\u30C8 \u6728\u4E0A\u30AF\u30A8\
      \u30EA:\u6700\u5927\u9023\u7D9A\u90E8\u5206\u5217\u548C"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2450
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
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2450\"\
    \n#include \"template/template.hpp\"\n#include \"library/graph/tree/heavy_light_decomposition.hpp\"\
    \n#include \"library/segtree/lazy_segment_tree.hpp\"\n/**\n * @brief \u6728 -\
    \ HLD\u306E\u30C6\u30B9\u30C8 \u6728\u4E0A\u30AF\u30A8\u30EA:\u6700\u5927\u9023\
    \u7D9A\u90E8\u5206\u5217\u548C\n */\nvoid solve() {\n    int N, Q;\n    cin >>\
    \ N >> Q;\n    vector<int> S(N);\n    cin >> S;\n    HeavyLightDecomposition HLD(N);\n\
    \    HLD.read(N - 1);\n    HLD.build();\n    // \u8F09\u305B\u308B\u69CB\u9020\
    \u4F53\n    struct Node {\n        int ans, _all, left, right, length;\n     \
    \   Node() : ans(-INF), _all(0), left(-INF), right(-INF), length(0) {}\n     \
    \   Node(int val, int len) {\n            length = len;\n            _all = val\
    \ * len;\n            ans = left = right = (0 < val ? _all : val);\n        }\n\
    \        Node operator+(const Node &s) const {\n            Node res;\n      \
    \      res.length = length + s.length;\n            res.ans = max({ans, s.ans,\
    \ right + s.left});\n            res._all = _all + s._all;\n            res.left\
    \ = max(left, _all + s.left);\n            res.right = max(s.right, right + s._all);\n\
    \            return res;\n        }\n    };\n    // \u30BB\u30B0\u6728\n    vector<Node>\
    \ A(N);\n    for (int i = 0; i < N; ++i) {\n        A[i] = {S[HLD.rev[i]], 1ll};\n\
    \    }\n    auto prod_op = [](const Node &x, const Node &y) -> Node { return x\
    \ + y; };\n    auto prod_e = Node();\n    auto apply_op = [](int f, int g) { return\
    \ g; };\n    auto apply_e = INF;\n    auto act_op = [](const Node &x, int a, int\
    \ sz) -> Node {\n        (void)sz;\n        return {a, x.length};\n    };\n  \
    \  LazySegmentTree<Node, int> seg(prod_op, prod_e, apply_op, apply_e, act_op,\n\
    \                                   A);\n    // \u30AF\u30A8\u30EA\n    while\
    \ (Q--) {\n        int com, u, v, cost;\n        cin >> com >> u >> v >> cost;\n\
    \        --u, --v;\n        if (com == 1ll) {\n            HLD.add(u, v, [&](int\
    \ l, int r) {\n                seg.apply(l, r, cost);\n            });\n     \
    \   }\n        if (com == 2ll) {\n            Node res = HLD.query(u, v, Node(),\n\
    \                [&](int l, int r) { return seg.prod(l, r); },\n             \
    \   [](const Node &a, const Node &b) { return a + b; },\n                [](Node\
    \ l, const Node &r) {\n                    swap(l.left, l.right);\n          \
    \          return l + r;\n                }\n            );\n            print(res.ans);\n\
    \        }\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - library/graph/tree/heavy_light_decomposition.hpp
  - library/graph/base/graph.hpp
  - library/graph/base/edge.hpp
  - library/segtree/lazy_segment_tree.hpp
  - library/various/monoid.hpp
  - library/various/monoid_act.hpp
  isVerificationFile: true
  path: tests/graph.tree.heavy_light_decomposition.test.cpp
  requiredBy: []
  timestamp: '2026-01-21 14:35:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/graph.tree.heavy_light_decomposition.test.cpp
layout: document
redirect_from:
- /verify/tests/graph.tree.heavy_light_decomposition.test.cpp
- /verify/tests/graph.tree.heavy_light_decomposition.test.cpp.html
title: "\u6728 - HLD\u306E\u30C6\u30B9\u30C8 \u6728\u4E0A\u30AF\u30A8\u30EA:\u6700\
  \u5927\u9023\u7D9A\u90E8\u5206\u5217\u548C"
---
