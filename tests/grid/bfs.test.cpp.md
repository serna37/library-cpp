---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/grid/bfs.hpp
    title: "\u30B0\u30EA\u30C3\u30C9BFS"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    document_title: "\u30B0\u30EA\u30C3\u30C9BFS\u306E\u30C6\u30B9\u30C8"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
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
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"template/template.hpp\"\n#include \"library/grid/bfs.hpp\"\nvoid\
    \ run_generic_bfs_tests() {\n    // \u30C6\u30B9\u30C8\u7528\u306E\u5171\u901A\
    \u30DE\u30C3\u30D7\n    // S . .\n    // . # .\n    // . . G\n    vector<vector<char>>\
    \ G = {\n        {'S', '.', '.'}, {'.', '#', '.'}, {'.', '.', '.'}};\n    // \u30B1\
    \u30FC\u30B91: d=4 (4\u8FD1\u508D) \u306E\u691C\u8A3C\n    {\n        auto res4\
    \ = bfs(G, 'S', 4ll);\n        // (0,0)\u304B\u3089(2,2)\u3078\u306F\u3001\u58C1\
    \u3092\u907F\u3051\u30664\u30B9\u30C6\u30C3\u30D7\u304B\u304B\u308B\n        //\
    \ (0,0)->(1,0)->(2,0)->(2,1)->(2,2) \u306A\u3069\n        assert(res4[0][0] ==\
    \ 0);\n        assert(res4[2][2] == 4);\n        assert(res4[1][1] == -1); //\
    \ \u58C1\u306F\u901A\u308C\u306A\u3044\n    }\n    // \u30B1\u30FC\u30B92: d=8\
    \ (8\u8FD1\u508D) \u306E\u691C\u8A3C\n    {\n        auto res8 = bfs(G, 'S', 8ll);\n\
    \        // 8\u8FD1\u508D\u306A\u3089\u3001\u659C\u3081\u79FB\u52D5\u3092\u4F7F\
    \u3063\u30662\u30B9\u30C6\u30C3\u30D7\u3067\u5230\u9054\u53EF\u80FD\n        //\
    \ (0,0)->(1,1)\u306F\u58C1\u3060\u304C\u3001(0,0)->(0,1)->(1,2)\u306A\u3069\u306F\
    \u53EF\u80FD\n        // \u4ECA\u56DE\u306E\u30DE\u30C3\u30D7\u306A\u3089 (0,0)->(1,0)->(2,1)\
    \ \u307E\u305F\u306F\n        // (0,0)\u304B\u3089\u5468\u56F2\u3092\u7D4C\u7531\
    \u3057\u30662\u30B9\u30C6\u30C3\u30D7\n        assert(res8[0][0] == 0);\n    \
    \    assert(res8[2][2] == 3);\n    }\n    // \u30B1\u30FC\u30B93: \u58C1\u306E\
    \u30D6\u30ED\u30C3\u30AD\u30F3\u30B0\u6319\u52D5\u306E\u5DEE\n    {\n        //\
    \ S #\n        // # .\n        vector<vector<char>> G2 = {{'S', '#'}, {'#', '.'}};\n\
    \        // 4\u8FD1\u508D\u3067\u306F\u53F3\u4E0B\u306B\u884C\u3051\u306A\u3044\
    \n        auto res4 = bfs(G2, 'S', 4ll);\n        assert(res4[1][1] == -1);\n\
    \        // 8\u8FD1\u508D\u3067\u3082\u3001\u659C\u3081\u5148\u304C\u58C1\u3067\
    \u306A\u3051\u308C\u3070\u884C\u3051\u308B\u304C\u3001\n        // \u3053\u306E\
    \u30B3\u30FC\u30C9\u306E\u5B9F\u88C5\u3067\u306F\u300C\u79FB\u52D5\u5148\u304C\
    \u58C1\u304B\u3069\u3046\u304B\u300D\u3092\u898B\u308B\u305F\u3081\u3001\n   \
    \     // (1,1)\u304C '.' \u306A\u3089\u3001(0,0)\u304B\u3089\u30C0\u30A4\u30EC\
    \u30AF\u30C8\u306B\u659C\u3081\u79FB\u52D5\u3067\u5230\u9054\u3067\u304D\u308B\
    \n        auto res8 = bfs(G2, 'S', 8ll);\n        assert(res8[1][1] == 1);\n \
    \   }\n    // \u30B1\u30FC\u30B94: \u7BC4\u56F2\u5916\u306E d \u304C\u6E21\u3055\
    \u308C\u305F\u5834\u5408\u306E\u5B89\u5168\u78BA\u8A8D\n    {\n        // d=1\
    \ \u306A\u3069\u306E\u5834\u5408\u3001\u30EB\u30FC\u30D7\u304C i=0 \u306E\u307F\
    \u56DE\u308A\u3001dx[0], dy[0] (\u53F3\u307E\u305F\u306F\u4E0B)\n        // \u306E\
    \u307F\u304C\u63A2\u7D22\u3055\u308C\u308B\n        auto res1 = bfs(G, 'S', 1ll);\n\
    \        assert(res1[0][1] == 1 || res1[1][0] == 1);\n    }\n    // \u30B1\u30FC\
    \u30B95: \u6587\u5B57\u5217\u6307\u5B9A\u306E\u58C1\n    {\n        vector<vector<char>>\
    \ G3 = {{'S', 'X', '.'}, {'Y', '.', '.'}};\n        // X \u3068 Y \u3092\u58C1\
    \u306B\u3059\u308B\n        auto res = bfs(G3, 'S', 4ll, \"XY\");\n        assert(res[0][1]\
    \ == -1);\n        assert(res[1][0] == -1);\n        assert(res[1][1] == -1);\
    \ // \u3069\u3053\u306B\u3082\u884C\u3051\u306A\u3044\n    }\n}\n/**\n * @brief\
    \ \u30B0\u30EA\u30C3\u30C9BFS\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n \
    \   print(\"Hello World\");\n    run_generic_bfs_tests();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/grid/bfs.hpp
  isVerificationFile: true
  path: tests/grid/bfs.test.cpp
  requiredBy: []
  timestamp: '2026-01-14 18:38:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/grid/bfs.test.cpp
layout: document
redirect_from:
- /verify/tests/grid/bfs.test.cpp
- /verify/tests/grid/bfs.test.cpp.html
title: "\u30B0\u30EA\u30C3\u30C9BFS\u306E\u30C6\u30B9\u30C8"
---
