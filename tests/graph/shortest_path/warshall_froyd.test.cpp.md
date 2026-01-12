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
    path: library/graph/shortest_path/warshall_froyd.hpp
    title: Warshall Froyd
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    document_title: "\u30B0\u30E9\u30D5 - WarshallFroyd\u306E\u30C6\u30B9\u30C8"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
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
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n#include \"template/template.hpp\"\n#include \"library/graph/shortest_path/warshall_froyd.hpp\"\
    \n/**\n * @brief \u30B0\u30E9\u30D5 - WarshallFroyd\u306E\u30C6\u30B9\u30C8\n\
    \ */\nvoid solve() {\n    int V, E;\n    cin >> V >> E;\n    Graph G(V);\n   \
    \ G.read(E, 0, true, true);\n    auto [dis, negativeCycle] = warshall_froyd(G);\n\
    \    if (negativeCycle) {\n        print(\"NEGATIVE CYCLE\");\n        return;\n\
    \    }\n    vec2<string> ans = make_vec2<string>(V, V, \"\");\n    for (int i\
    \ = 0; i < V; ++i) {\n        for (int j = 0; j < V; ++j) {\n            ans[i][j]\
    \ = dis[i][j] == INF ? \"INF\" : int_to_string(dis[i][j]);\n        }\n    }\n\
    \    print(ans);\n}\n"
  dependsOn:
  - template/template.hpp
  - library/graph/shortest_path/warshall_froyd.hpp
  - library/graph/base/graph.hpp
  - library/graph/base/edge.hpp
  isVerificationFile: true
  path: tests/graph/shortest_path/warshall_froyd.test.cpp
  requiredBy: []
  timestamp: '2026-01-12 19:45:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/graph/shortest_path/warshall_froyd.test.cpp
layout: document
redirect_from:
- /verify/tests/graph/shortest_path/warshall_froyd.test.cpp
- /verify/tests/graph/shortest_path/warshall_froyd.test.cpp.html
title: "\u30B0\u30E9\u30D5 - WarshallFroyd\u306E\u30C6\u30B9\u30C8"
---
