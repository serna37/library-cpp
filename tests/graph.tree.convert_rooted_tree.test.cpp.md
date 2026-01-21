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
    path: library/graph/tree/convert_rooted_tree.hpp
    title: "\u6839\u4ED8\u304D\u6728\u5909\u63DB"
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
    document_title: "\u6728 - \u6839\u4ED8\u304D\u6728\u5909\u63DB\u306E\u30C6\u30B9\
      \u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/graph/tree/convert_rooted_tree.hpp\"\
    \n// --- \u30C6\u30B9\u30C8\u7528\u95A2\u6570 ---\nvoid test_rooted_tree() {\n\
    \    /*\n        \u4EE5\u4E0B\u306E\u6728\u69CB\u9020\u3092\u4F5C\u6210 (0\u3092\
    \u6839\u3068\u3059\u308B)\n             0\n           /   \\\n          1    \
    \ 2\n         / \\\n        3   4\n    */\n    int N = 5;\n    Graph G(N);\n \
    \   G.add_both(0, 1);\n    G.add_both(0, 2);\n    G.add_both(1, 3);\n    G.add_both(1,\
    \ 4);\n    // 0\u3092\u6839\u3068\u3057\u3066\u5909\u63DB\n    Graph rg = convert_rooted_tree(G,\
    \ 0);\n    // \u5404\u9802\u70B9\u306E\u5B50\u306E\u6570\u3092\u78BA\u8A8D\n \
    \   assert(rg[0].size() == 2ll); // 1, 2\n    assert(rg[1].size() == 2ll); //\
    \ 3, 4\n    assert(rg[2].size() == 0ll); // \u8449\n    assert(rg[3].size() ==\
    \ 0ll); // \u8449\n    assert(rg[4].size() == 0ll); // \u8449\n    // \u5177\u4F53\
    \u7684\u306A\u89AA\u5B50\u95A2\u4FC2\u3092\u30C1\u30A7\u30C3\u30AF\n    auto has_child\
    \ = [&](const Graph &g, int parent, int child) {\n        for (auto &&e : g[parent])\
    \ {\n            if (e.to == child) return true;\n        }\n        return false;\n\
    \    };\n    assert(has_child(rg, 0, 1));\n    assert(has_child(rg, 0, 2));\n\
    \    assert(has_child(rg, 1, 3));\n    assert(has_child(rg, 1, 4));\n    // \u9006\
    \u65B9\u5411\uFF08\u5B50\u304B\u3089\u89AA\uFF09\u306E\u8FBA\u304C\u5B58\u5728\
    \u3057\u306A\u3044\u3053\u3068\u3092\u78BA\u8A8D\n    assert(!has_child(rg, 1,\
    \ 0));\n    assert(!has_child(rg, 3, 1));\n    /*\n        \u6839\u3092\u5909\u3048\
    \u3066\u30C6\u30B9\u30C8 (3\u3092\u6839\u3068\u3059\u308B)\n             3\n \
    \            |\n             1\n           / | \\\n          0  4  (\u623B\u308B\
    \u8FBA\u306A\u3057)\n          |\n          2\n    */\n    Graph rg3 = convert_rooted_tree(G,\
    \ 3);\n    assert(rg3[3].size() == 1ll); // 3 -> 1\n    assert(has_child(rg3,\
    \ 3, 1));\n    assert(rg3[1].size() == 2ll); // 1 -> 0, 1 -> 4\n    assert(has_child(rg3,\
    \ 1, 0));\n    assert(has_child(rg3, 1, 4));\n    assert(rg3[0].size() == 1ll);\
    \ // 0 -> 2\n    assert(has_child(rg3, 0, 2));\n}\n/**\n * @brief \u6728 - \u6839\
    \u4ED8\u304D\u6728\u5909\u63DB\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n\
    \    print(\"Hello World\");\n    test_rooted_tree();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/graph/tree/convert_rooted_tree.hpp
  - library/graph/base/graph.hpp
  - library/graph/base/edge.hpp
  isVerificationFile: true
  path: tests/graph.tree.convert_rooted_tree.test.cpp
  requiredBy: []
  timestamp: '2026-01-21 14:59:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/graph.tree.convert_rooted_tree.test.cpp
layout: document
redirect_from:
- /verify/tests/graph.tree.convert_rooted_tree.test.cpp
- /verify/tests/graph.tree.convert_rooted_tree.test.cpp.html
title: "\u6728 - \u6839\u4ED8\u304D\u6728\u5909\u63DB\u306E\u30C6\u30B9\u30C8"
---
