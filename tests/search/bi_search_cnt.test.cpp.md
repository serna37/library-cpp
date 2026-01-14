---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/search/bi_ge_cnt.hpp
    title: "\u4E8C\u5206\u63A2\u7D22 \u914D\u5217\u4E2D \u4EE5\u4E0A\u306E\u8981\u7D20\
      \u6570"
  - icon: ':heavy_check_mark:'
    path: library/search/bi_gt_cnt.hpp
    title: "\u4E8C\u5206\u63A2\u7D22 \u914D\u5217\u4E2D \u3088\u308A\u4E0A\u306E\u8981\
      \u7D20\u6570"
  - icon: ':heavy_check_mark:'
    path: library/search/bi_le_cnt.hpp
    title: "\u4E8C\u5206\u63A2\u7D22 \u914D\u5217\u4E2D \u4EE5\u4E0B\u306E\u8981\u7D20\
      \u6570"
  - icon: ':heavy_check_mark:'
    path: library/search/bi_lt_cnt.hpp
    title: "\u4E8C\u5206\u63A2\u7D22 \u914D\u5217\u4E2D \u672A\u6E80\u306E\u8981\u7D20\
      \u6570"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B
    document_title: "\u4E8C\u5206\u63A2\u7D22 \u8981\u7D20\u6570\u306E\u30C6\u30B9\
      \u30C8"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B
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
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B\"\
    \n#include \"template/template.hpp\"\n#include \"library/search/bi_ge_cnt.hpp\"\
    \n#include \"library/search/bi_gt_cnt.hpp\"\n#include \"library/search/bi_le_cnt.hpp\"\
    \n#include \"library/search/bi_lt_cnt.hpp\"\n/**\n * @brief \u4E8C\u5206\u63A2\
    \u7D22 \u8981\u7D20\u6570\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n    int\
    \ N;\n    cin >> N;\n    vector<int> A(N);\n    cin >> A;\n    sort(A.begin(),\
    \ A.end());\n    int Q;\n    cin >> Q;\n    int ans = 0;\n    while (Q--) {\n\
    \        int x;\n        cin >> x;\n        // \u4EE5\u4E0A\u306E\u6570 - \u3088\
    \u308A\u5927\u304D\u3044\u6570\n        int cnt_ge = bi_ge_cnt(A, x);\n      \
    \  int cnt_gt = bi_gt_cnt(A, x);\n        int match_cnt = cnt_ge - cnt_gt;\n \
    \       if (0 < match_cnt) ++ans;\n        // \u4EE5\u4E0B\u306E\u6570 - \u3088\
    \u308A\u5C0F\u3055\u3044\u6570\n        int cnt_le = bi_le_cnt(A, x);\n      \
    \  int cnt_lt = bi_lt_cnt(A, x);\n        int match_cnt2 = cnt_le - cnt_lt;\n\
    \        assert(match_cnt == match_cnt2);\n    }\n    print(ans);\n}\n"
  dependsOn:
  - template/template.hpp
  - library/search/bi_ge_cnt.hpp
  - library/search/bi_gt_cnt.hpp
  - library/search/bi_le_cnt.hpp
  - library/search/bi_lt_cnt.hpp
  isVerificationFile: true
  path: tests/search/bi_search_cnt.test.cpp
  requiredBy: []
  timestamp: '2026-01-14 22:20:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/search/bi_search_cnt.test.cpp
layout: document
redirect_from:
- /verify/tests/search/bi_search_cnt.test.cpp
- /verify/tests/search/bi_search_cnt.test.cpp.html
title: "\u4E8C\u5206\u63A2\u7D22 \u8981\u7D20\u6570\u306E\u30C6\u30B9\u30C8"
---
