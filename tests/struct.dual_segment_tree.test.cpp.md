---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bits/stdc++.h
    title: "\u30AB\u30B9\u30BF\u30E0stdc++.h"
  - icon: ':question:'
    path: library/def/common.hpp
    title: "\u5171\u901A"
  - icon: ':question:'
    path: library/def/const.hpp
    title: "\u5B9A\u6570"
  - icon: ':question:'
    path: library/def/io.hpp
    title: "IO\u95A2\u9023"
  - icon: ':question:'
    path: library/def/type.hpp
    title: "\u578B"
  - icon: ':x:'
    path: library/struct/dual_segment_tree.hpp
    title: "Dual Segment Tree \u533A\u9593\u66F4\u65B0 1\u70B9\u53D6\u5F97"
  - icon: ':x:'
    path: library/struct/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9"
  - icon: ':question:'
    path: template/template.hpp
    title: "\u0E05^>\u03C9<^\u0E05"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
    document_title: "\u53CC\u5BFE\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RUQ"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
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
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n#include \"template/template.hpp\"\n#include \"library/struct/monoid.hpp\"\n\
    #include \"library/struct/dual_segment_tree.hpp\"\n/**\n * @brief \u53CC\u5BFE\
    \u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RUQ\n */\nvoid solve() {\n    int N,\
    \ Q;\n    cin >> N >> Q;\n    DualSegmentTree<int> seg(Monoid::Set::op, Monoid::Set::e,\
    \ N);\n    while (Q--) {\n        int com;\n        cin >> com;\n        if (com\
    \ == 0) {\n            int l, r, x;\n            cin >> l >> r >> x;\n       \
    \     seg.apply(l, r + 1, x);\n        }\n        if (com == 1) {\n          \
    \  int k;\n            cin >> k;\n            print(seg[k]);\n        }\n    }\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - bits/stdc++.h
  - library/def/common.hpp
  - library/def/io.hpp
  - library/def/type.hpp
  - library/def/const.hpp
  - library/struct/monoid.hpp
  - library/struct/dual_segment_tree.hpp
  isVerificationFile: true
  path: tests/struct.dual_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2026-01-03 21:07:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/struct.dual_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/tests/struct.dual_segment_tree.test.cpp
- /verify/tests/struct.dual_segment_tree.test.cpp.html
title: "\u53CC\u5BFE\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RUQ"
---
