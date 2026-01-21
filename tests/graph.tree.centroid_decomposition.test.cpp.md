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
    path: library/polynomial/fft/fast_fourier_transform.hpp
    title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB"
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
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    document_title: "\u6728 - \u91CD\u5FC3\u5206\u89E3\u306E\u30C6\u30B9\u30C8"
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n#include \"template/template.hpp\"\n#include \"library/graph/tree/centroid_decomposition.hpp\"\
    \n#include \"library/polynomial/fft/fast_fourier_transform.hpp\"\n/**\n * @brief\
    \ \u6728 - \u91CD\u5FC3\u5206\u89E3\u306E\u30C6\u30B9\u30C8\n */\nvoid solve()\
    \ {\n    int N;\n    cin >> N;\n    CentroidDecomposition g(N);\n    g.read(N\
    \ - 1, 0);\n    int root = g.build();\n    vector<int> used(N), dist(N);\n   \
    \ auto rec = [&](auto self, int centroid) -> void {\n        used[centroid] =\
    \ true;\n        vector<int> cnt{1};\n        for (auto &&edge : g.G[centroid])\
    \ {\n            if (used[edge.to]) continue;\n            vector<int> num;\n\
    \            queue<tuple<int, int, int>> que;\n            que.emplace(edge.to\
    \ , centroid, 1);\n            while(!que.empty()) {\n                int idx,\
    \ par, dep;\n                tie(idx, par, dep) = que.front();\n             \
    \   que.pop();\n                if ((int)cnt.size() <= dep) cnt.resize(dep + 1,\
    \ 0);\n                if ((int)num.size() <= dep) num.resize(dep + 1, 0);\n \
    \               cnt[dep]++;\n                num[dep]++;\n                for\
    \ (auto &&edge : g.G[idx]) {\n                    if(edge.to == par or used[edge.to])\
    \ continue;\n                    que.emplace(edge.to, idx, dep + 1);\n       \
    \         }\n            }\n            auto ret = FFT::multiply(num, num);\n\
    \            for(int i = 0; i < (int)ret.size(); i++) dist[i] -= ret[i];\n   \
    \     }\n        auto ret = FFT::multiply(cnt, cnt);\n        for(int i = 0; i\
    \ < (int)ret.size(); ++i) dist[i] += ret[i];\n        for(auto &&[from, to, cost,\
    \ idx] : g.tree.G[centroid]) self(self, to);\n    };\n    rec(rec, root);\n  \
    \  dist.erase(begin(dist));\n    for(auto &&p : dist) p /= 2ll;\n    print(dist);\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - library/graph/tree/centroid_decomposition.hpp
  - library/graph/base/graph.hpp
  - library/graph/base/edge.hpp
  - library/polynomial/fft/fast_fourier_transform.hpp
  isVerificationFile: true
  path: tests/graph.tree.centroid_decomposition.test.cpp
  requiredBy: []
  timestamp: '2026-01-21 11:49:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/graph.tree.centroid_decomposition.test.cpp
layout: document
redirect_from:
- /verify/tests/graph.tree.centroid_decomposition.test.cpp
- /verify/tests/graph.tree.centroid_decomposition.test.cpp.html
title: "\u6728 - \u91CD\u5FC3\u5206\u89E3\u306E\u30C6\u30B9\u30C8"
---
