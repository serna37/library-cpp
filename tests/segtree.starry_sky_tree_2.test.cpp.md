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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    document_title: "\u661F\u7A7A\u6728\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/segtree/starry_sky_tree.hpp\"\
    \nvoid test_starry_sky_tree() {\n    // \u30C7\u30FC\u30BF\u6E96\u5099\n    vector<int>\
    \ initial_data = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};\n    // ---------------------------------------------------------\n\
    \    // Case 1: \u533A\u9593\u6700\u5927\u5024 (Max Mode)\n    // ---------------------------------------------------------\n\
    \    {\n        StarrySkyTree<false> sst_max(initial_data);\n        // \u521D\
    \u671F\u72B6\u614B\u306E\u30C1\u30A7\u30C3\u30AF\n        assert(sst_max.prod(0,\
    \ 10) == 9); // \u5168\u4F53\u6700\u5927\u5024\n        assert(sst_max.prod(0,\
    \ 4) == 4);  // {3, 1, 4, 1} \u306E\u6700\u5927\u5024\n        assert(sst_max[5]\
    \ == 9);          // \u30A4\u30F3\u30C7\u30C3\u30AF\u30B95\u306E\u5024\n     \
    \   // \u533A\u9593\u52A0\u7B97: [0, 5) \u306B +10 -> {13, 11, 14, 11, 15, 9,\
    \ 2, 6, 5, 3}\n        sst_max.apply(0, 5, 10);\n        assert(sst_max.prod(0,\
    \ 5) == 15);\n        assert(sst_max.prod(4, 6) == 15); // 15 \u3068 9 \u306E\u6BD4\
    \u8F03\n        assert(sst_max.prod(5, 10) == 9); // \u52A0\u7B97\u7BC4\u56F2\u5916\
    \n        // \u5358\u70B9\u66F4\u65B0\uFF08set\uFF09: index 5 \u3092 0 \u306B\u5909\
    \u66F4\n        sst_max.set(5, 0);\n        assert(sst_max[5] == 0);\n       \
    \ assert(sst_max.prod(0, 10) == 15);\n    }\n    // ---------------------------------------------------------\n\
    \    // Case 2: \u533A\u9593\u6700\u5C0F\u5024 (Min Mode)\n    // ---------------------------------------------------------\n\
    \    {\n        StarrySkyTree<true> sst_min(initial_data);\n        // \u521D\u671F\
    \u72B6\u614B\u306E\u30C1\u30A7\u30C3\u30AF\n        assert(sst_min.prod(0, 10)\
    \ == 1); // \u5168\u4F53\u6700\u5C0F\u5024\n        assert(sst_min.prod(4, 6)\
    \ == 5);  // {5, 9} \u306E\u6700\u5C0F\u5024\n        // \u533A\u9593\u52A0\u7B97\
    : [2, 8) \u306B -20 -> {3, 1, -16, -19, -15, -11, -18, -14, 5, 3}\n        sst_min.apply(2,\
    \ 8, -20);\n        assert(sst_min.prod(0, 10) == -19); // \u5168\u4F53\u6700\u5C0F\
    \u5024\n        assert(sst_min.prod(0, 2) == 1);    // \u52A0\u7B97\u7BC4\u56F2\
    \u5916\n        assert(sst_min[3] == -19);\n        // \u533A\u9593\u52A0\u7B97\
    : [0, 10) \u5168\u4F53\u306B +100\n        sst_min.apply(0, 10, 100);\n      \
    \  assert(sst_min.prod(0, 10) == 81); // -19 + 100\n        assert(sst_min[3]\
    \ == 81);\n    }\n    // ---------------------------------------------------------\n\
    \    // Case 3: \u8CA0\u306E\u5024\u3092\u542B\u3080\u8907\u96D1\u306A\u30B1\u30FC\
    \u30B9\n    // ---------------------------------------------------------\n   \
    \ {\n        vector<int> negative_data = {-10, -20, -30, -40};\n        StarrySkyTree<true>\
    \ sst_neg(negative_data);\n        assert(sst_neg.prod(0, 4) == -40);\n      \
    \  sst_neg.apply(0, 2, 50); // {40, 30, -30, -40}\n        assert(sst_neg.prod(0,\
    \ 4) == -40);\n        assert(sst_neg.prod(0, 2) == 30);\n    }\n}\n/**\n * @brief\
    \ \u661F\u7A7A\u6728\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n    print(\"\
    Hello World\");\n    test_starry_sky_tree();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/segtree/starry_sky_tree.hpp
  isVerificationFile: true
  path: tests/segtree.starry_sky_tree_2.test.cpp
  requiredBy: []
  timestamp: '2026-01-16 12:40:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/segtree.starry_sky_tree_2.test.cpp
layout: document
redirect_from:
- /verify/tests/segtree.starry_sky_tree_2.test.cpp
- /verify/tests/segtree.starry_sky_tree_2.test.cpp.html
title: "\u661F\u7A7A\u6728\u306E\u30C6\u30B9\u30C8"
---
