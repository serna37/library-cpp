---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/sequence/bit_dict.hpp
    title: "\u5B8C\u5099\u8F9E\u66F8"
  - icon: ':heavy_check_mark:'
    path: library/sequence/wavelet_matrix.hpp
    title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217"
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
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    document_title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217\u306E\u30C6\
      \u30B9\u30C8"
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\
    #include \"template/template.hpp\"\n#include \"library/sequence/wavelet_matrix.hpp\"\
    \n/**\n * @brief \u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217\u306E\u30C6\
    \u30B9\u30C8\n */\nvoid solve() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<int>\
    \ A(N);\n    cin >> A;\n    WaveletMatrix wm(A);\n    while (Q--) {\n        int\
    \ l, r, k;\n        cin >> l >> r >> k;\n        print(wm.kth_smallest(l, r, k));\n\
    \    }\n}\n"
  dependsOn:
  - template/template.hpp
  - library/sequence/wavelet_matrix.hpp
  - library/sequence/bit_dict.hpp
  isVerificationFile: true
  path: tests/sequence.wavelet_matrix.test.cpp
  requiredBy: []
  timestamp: '2026-01-16 15:19:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/sequence.wavelet_matrix.test.cpp
layout: document
redirect_from:
- /verify/tests/sequence.wavelet_matrix.test.cpp
- /verify/tests/sequence.wavelet_matrix.test.cpp.html
title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217\u306E\u30C6\u30B9\u30C8"
---
