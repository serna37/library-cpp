---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/segtree/starry_sky_tree.hpp
    title: Starry Sky Tree
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
    document_title: "\u661F\u7A7A\u6728\u306E\u30C6\u30B9\u30C8:RMQ RAQ"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
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
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H\"\
    \n#include \"template/template.hpp\"\n#include \"library/segtree/starry_sky_tree.hpp\"\
    \n/**\n * @brief \u661F\u7A7A\u6728\u306E\u30C6\u30B9\u30C8:RMQ RAQ\n */\nvoid\
    \ solve() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> a(N, 0);\n   \
    \ StarrySkyTree sst(a);\n    while (Q--) {\n        int com, s, t;\n        cin\
    \ >> com >> s >> t;\n        ++t;\n        if (com == 0) {\n            int x;\n\
    \            cin >> x;\n            sst.apply(s, t, x);\n        }\n        if\
    \ (com == 1) {\n            print(sst.prod(s, t));\n        }\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - library/segtree/starry_sky_tree.hpp
  isVerificationFile: true
  path: tests/segtree/starry_sky_tree.test.cpp
  requiredBy: []
  timestamp: '2026-01-13 20:35:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/segtree/starry_sky_tree.test.cpp
layout: document
redirect_from:
- /verify/tests/segtree/starry_sky_tree.test.cpp
- /verify/tests/segtree/starry_sky_tree.test.cpp.html
title: "\u661F\u7A7A\u6728\u306E\u30C6\u30B9\u30C8:RMQ RAQ"
---
