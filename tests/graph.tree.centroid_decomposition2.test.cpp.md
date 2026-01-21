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
    path: library/graph/tree/centroid_decomposition.hpp
    title: "\u91CD\u5FC3\u5206\u89E3"
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
    PROBLEM: https://yukicoder.me/problems/no/1002
    document_title: "\u6728 - \u91CD\u5FC3\u5206\u89E3\u306E\u30C6\u30B9\u30C82"
    links:
    - https://yukicoder.me/problems/no/1002
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
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1002\"\n#include \"template/template.hpp\"\
    \n#include \"library/graph/tree/centroid_decomposition.hpp\"\n/**\n * @brief \u6728\
    \ - \u91CD\u5FC3\u5206\u89E3\u306E\u30C6\u30B9\u30C82\n */\nvoid solve() {\n \
    \   int N, K;\n    cin >> N >> K;\n    CentroidDecomposition G(N);\n    G.read(N\
    \ - 1, -1, true);\n    int root = G.build();\n    int ans = 0;\n    vector<int>\
    \ used(N);\n    map<pair<int, int>, int> mp;\n    int all;\n    map<int, int>\
    \ mp2, mp3;\n    auto get_vec = [&](auto self, int idx, int par, int a, int b)\
    \ -> void {\n        if (!~b) {\n            ans += all - mp2[a];\n          \
    \  ans += mp3[a];\n        } else {\n            ans++;\n            ans += mp2[a]\
    \ + mp2[b];\n            ans += mp[minmax(a, b)];\n        }\n        for (auto\
    \ &&e : G.G[idx]) {\n            if (e.to == par) continue;\n            if (used[e.to])\
    \ continue;\n            if (a == e.cost) {\n                self(self, e.to,\
    \ idx, e.cost, b);\n            } else if (!~b or b == e.cost) {\n           \
    \     self(self, e.to, idx, a, e.cost);\n            }\n        }\n    };\n  \
    \  auto add_vec = [&](auto self, int idx, int par, int a, int b) -> void {\n \
    \       if (!~b) {\n            mp2[a]++;\n            all++;\n        } else\
    \ {\n            mp[minmax(a, b)]++;\n            mp3[a]++;\n            mp3[b]++;\n\
    \        }\n        for (auto &&e : G.G[idx]) {\n            if (e.to == par)\
    \ continue;\n            if (used[e.to]) continue;\n            if (a == e.cost)\
    \ {\n                self(self, e.to, idx, e.cost, b);\n            } else if\
    \ (!~b or b == e.cost) {\n                self(self, e.to, idx, a, e.cost);\n\
    \            }\n        }\n    };\n    auto rec = [&](auto self, int idx) -> void\
    \ {\n        used[idx] = true;\n        mp.clear();\n        mp2.clear();\n  \
    \      mp3.clear();\n        all = 0;\n        for (auto &&e : G.G[idx]) {\n \
    \           if (used[e.to]) continue;\n            get_vec(get_vec, e.to, idx,\
    \ e.cost, -1);\n            add_vec(add_vec, e.to, idx, e.cost, -1);\n       \
    \ }\n        for (auto &&e : G.tree.G[idx]) {\n            self(self, e.to);\n\
    \        }\n        used[idx] = false;\n    };\n    rec(rec, root);\n    print(ans);\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - library/graph/tree/centroid_decomposition.hpp
  - library/graph/base/graph.hpp
  - library/graph/base/edge.hpp
  isVerificationFile: true
  path: tests/graph.tree.centroid_decomposition2.test.cpp
  requiredBy: []
  timestamp: '2026-01-21 19:52:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/graph.tree.centroid_decomposition2.test.cpp
layout: document
redirect_from:
- /verify/tests/graph.tree.centroid_decomposition2.test.cpp
- /verify/tests/graph.tree.centroid_decomposition2.test.cpp.html
title: "\u6728 - \u91CD\u5FC3\u5206\u89E3\u306E\u30C6\u30B9\u30C82"
---
