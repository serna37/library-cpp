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
    path: library/graph/route_restore.hpp
    title: "\u7D4C\u8DEF\u5FA9\u5143"
  - icon: ':heavy_check_mark:'
    path: library/graph/shortest_path/dijkstra.hpp
    title: Dijkstra
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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    document_title: "\u30B0\u30E9\u30D5 - \u7D4C\u8DEF\u5FA9\u5143\u306E\u30C6\u30B9\
      \u30C8"
    links:
    - https://judge.yosupo.jp/problem/shortest_path
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ \"template/template.hpp\"\n#include \"library/graph/shortest_path/dijkstra.hpp\"\
    \n#include \"library/graph/route_restore.hpp\"\n/**\n * @brief \u30B0\u30E9\u30D5\
    \ - \u7D4C\u8DEF\u5FA9\u5143\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n  \
    \  int N, M, s, t;\n    cin >> N >> M >> s >> t;\n    Graph G(N);\n    G.read(M,\
    \ 0, true, true);\n    auto [dis, route] = dijkstra(G, {s});\n    if (dis[t] ==\
    \ INF) {\n        print(-1);\n        return;\n    }\n    vector<int> pth = route_restore(route,\
    \ t);\n    cout << dis[t] << \" \" << pth.size() - 1 << endl;\n    for (int i\
    \ = 0; i < (int)pth.size() - 1; ++i) {\n        cout << pth[i] << \" \" << pth[i\
    \ + 1] << endl;\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - library/graph/shortest_path/dijkstra.hpp
  - library/graph/base/graph.hpp
  - library/graph/base/edge.hpp
  - library/graph/route_restore.hpp
  isVerificationFile: true
  path: tests/graph.route_restore.test.cpp
  requiredBy: []
  timestamp: '2026-01-19 13:31:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/graph.route_restore.test.cpp
layout: document
redirect_from:
- /verify/tests/graph.route_restore.test.cpp
- /verify/tests/graph.route_restore.test.cpp.html
title: "\u30B0\u30E9\u30D5 - \u7D4C\u8DEF\u5FA9\u5143\u306E\u30C6\u30B9\u30C8"
---
