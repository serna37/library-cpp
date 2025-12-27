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
    \ }\n        }\n        return _G;\n    }\n    // TODO \u30B0\u30EA\u30C3\u30C9\
    \u4E2D\u3067\u306E4\u65B9\u5411\u3068\u304B8\u65B9\u5411\u306EBFS\u3068\u304B\u307B\
    \u3057\u3044\u304B\u306A\u3041\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: library/util/grid.hpp
  requiredBy: []
  timestamp: '2025-12-27 21:21:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/util/grid.hpp
layout: document
redirect_from:
- /library/library/util/grid.hpp
- /library/library/util/grid.hpp.html
title: library/util/grid.hpp
---
