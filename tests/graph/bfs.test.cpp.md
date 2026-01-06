---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bits/stdc++.h
    title: "\u30AB\u30B9\u30BF\u30E0stdc++.h"
  - icon: ':heavy_check_mark:'
    path: library/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: library/graph/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: template/def/common.hpp
    title: "\u5171\u901A"
  - icon: ':heavy_check_mark:'
    path: template/def/const.hpp
    title: "\u5B9A\u6570"
  - icon: ':heavy_check_mark:'
    path: template/def/io.hpp
    title: "IO\u95A2\u9023"
  - icon: ':heavy_check_mark:'
    path: template/def/type.hpp
    title: "\u578B"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: template/util/geometry.hpp
    title: "\u5E7E\u4F55"
  - icon: ':heavy_check_mark:'
    path: template/util/grid.hpp
    title: "\u30AF\u3099\u30EA\u30C3\u30C8\u3099"
  - icon: ':heavy_check_mark:'
    path: template/util/number.hpp
    title: "\u6570\u306E\u6027\u8CEA"
  - icon: ':heavy_check_mark:'
    path: template/util/search.hpp
    title: "\u63A2\u7D22"
  - icon: ':heavy_check_mark:'
    path: template/util/sequence.hpp
    title: "\u914D\u5217\u30FB\u6570\u5217"
  - icon: ':heavy_check_mark:'
    path: template/util/string.hpp
    title: "\u6587\u5B57\u5217"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
    document_title: "\u30B0\u30E9\u30D5 - BFS\u306E\u30C6\u30B9\u30C8"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
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
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n#include \"template/template.hpp\"\n#include \"library/graph/graph.hpp\"\n/**\n\
    \ * @brief \u30B0\u30E9\u30D5 - BFS\u306E\u30C6\u30B9\u30C8\n */\nvoid solve()\
    \ {\n    int N;\n    cin >> N;\n    Graph G(N);\n    for (int i = 0; i < N; ++i)\
    \ {\n        int U, K;\n        cin >> U >> K;\n        --U;\n        for (int\
    \ j = 0; j < K; ++j) {\n            int v;\n            cin >> v;\n          \
    \  --v;\n            G.add(U, v);\n        }\n    }\n    auto [dis, route] = G.bfs();\n\
    \    for (int i = 0; i < N; ++i) {\n        cout << i + 1 << \" \";\n        print(dis[i]);\n\
    \    }\n}\n"
  dependsOn:
  - template/template.hpp
  - bits/stdc++.h
  - template/def/common.hpp
  - template/def/io.hpp
  - template/def/type.hpp
  - template/def/const.hpp
  - template/util/number.hpp
  - template/util/string.hpp
  - template/util/sequence.hpp
  - template/util/search.hpp
  - template/util/grid.hpp
  - template/util/geometry.hpp
  - library/graph/graph.hpp
  - library/graph/edge.hpp
  isVerificationFile: true
  path: tests/graph/bfs.test.cpp
  requiredBy: []
  timestamp: '2026-01-06 20:15:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/graph/bfs.test.cpp
layout: document
redirect_from:
- /verify/tests/graph/bfs.test.cpp
- /verify/tests/graph/bfs.test.cpp.html
title: "\u30B0\u30E9\u30D5 - BFS\u306E\u30C6\u30B9\u30C8"
---
