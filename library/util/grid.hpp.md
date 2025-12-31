---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/util/grid.hpp: line 5: #pragma once found in a non-first line\n"
  code: "\n/** ======================================= */\n/**               \u30B0\
    \u30EA\u30C3\u30C9                  */\n/** =======================================\
    \ */\n#pragma once\nclass Grid {\n  public:\n    // \u884C\u5217\u306E\u8EE2\u7F6E\
    \n    template <typename T>\n    vector<vector<T>> transpose(const vector<vector<T>>\
    \ &G) {\n        int H = G.size(), W = G[0].size();\n        vector<vector<T>>\
    \ _G(W, vector<T>(H));\n        for (int i = 0; i < H; ++i) {\n            for\
    \ (int j = 0; j < W; ++j) {\n                _G[j][i] = G[i][j];\n           \
    \ }\n        }\n        return _G;\n    }\n    // XXX \u4EE5\u4E0B\u3092\u3044\
    \u3044\u611F\u3058\u306B\u3057\u305F\u3082\u306E\u306B\u3001\u6539\u826F\u3059\
    \u308B!\n    // TODO 4\u65B9 or 8\u65B9\u306B\u884C\u304F\u30EB\u30FC\u30D7\u51E6\
    \u7406\n    // TODO \u9818\u57DF\u5916\u3001\u884C\u3051\u306A\u3044\u30DE\u30B9\
    \u306E\u30D5\u30A3\u30EB\u30BF\u51E6\u7406\n    // TODO \u884C\u3063\u305F\u7D50\
    \u679C\u3069\u3046\u3059\u308B\uFF1F\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\
    \u308B or \u30E9\u30E0\u30C0\u306B\u3059\u308B\n    template <typename T, typename\
    \ F> void bfs(vector<vector<T>> &G, F f) {\n        int H = G.size(), W = G[0].size();\n\
    \        for (int i = 0; i < H; ++i) {\n            for (int j = 0; j < W; ++j)\
    \ {\n                for (int k = 0; k < 4; ++k) {\n                    int y\
    \ = i + dy[k], x = j + dx[k];\n                    if (y < 0 or x < 0 or H <=\
    \ y or W <= x) continue;\n                    f();\n                }\n      \
    \      }\n        }\n    }\n    template <typename T, typename F>\n    void bfs(vector<string>\
    \ &G, string alw, F f) {\n        int H = G.size(), W = G[0].size();\n       \
    \ for (int i = 0; i < H; ++i) {\n            for (int j = 0; j < W; ++j) {\n \
    \               for (int k = 0; k < 4; ++k) {\n                    int y = i +\
    \ dy[k], x = j + dx[k];\n                    if (y < 0 or x < 0 or H <= y or W\
    \ <= x) continue;\n                    if (alw.find(G[y][x]) == string::npos)\
    \ continue;\n                    f();\n                }\n            }\n    \
    \    }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/util/grid.hpp
  requiredBy: []
  timestamp: '2025-12-31 17:06:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/util/grid.hpp
layout: document
title: "\u30B0\u30EA\u30C3\u30C9"
---

グリッド上の動き。グラフというよりマス目的な平面上でのもの


