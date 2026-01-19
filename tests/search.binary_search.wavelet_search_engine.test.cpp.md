---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/search/binary_search/wavelet_search_engine.hpp
    title: Wavelet Search Engine
  - icon: ':question:'
    path: library/sequence/bit_dict.hpp
    title: "\u5B8C\u5099\u8F9E\u66F8"
  - icon: ':question:'
    path: library/sequence/compressor.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  - icon: ':question:'
    path: library/sequence/wavelet_matrix.hpp
    title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217"
  - icon: ':question:'
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
    document_title: "WaveletSearchEngine\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/search/binary_search/wavelet_search_engine.hpp\"\
    \n\nvoid test_wavelet_search_engine() {\n    // \u30C6\u30B9\u30C8\u30C7\u30FC\
    \u30BF: \u8CA0\u6570\u3001\u91CD\u8907\u3001\u5927\u304D\u306A\u5024\u3092\u542B\
    \u3080\n    vector<int> data = {10, -5, 20, 10, 30, -5, 15};\n    WaveletSearchEngine\
    \ engine(data);\n\n    // access \u306E\u30C6\u30B9\u30C8\n    assert(engine.access(0)\
    \ == 10);\n    assert(engine.access(1) == -5);\n    assert(engine.access(6) ==\
    \ 15);\n\n    // count \u7CFB (\u533A\u9593 [1, 5) : {-5, 20, 10, 30})\n    int\
    \ l = 1, r = 5;\n    assert(engine.count_x(l, r, 10) == 1);\n    assert(engine.count_x(l,\
    \ r, -5) == 1);\n    assert(engine.count_lt(l, r, 10) == 1);  // {-5}\n    assert(engine.count_le(l,\
    \ r, 10) == 2);  // {-5, 10}\n    assert(engine.count_gt(l, r, 10) == 2);  //\
    \ {20, 30}\n    assert(engine.count_ge(l, r, 10) == 3);  // {20, 10, 30}\n\n \
    \   // kth \u7CFB (\u533A\u9593 [0, 7) \u5168\u4F53 : {-5, -5, 10, 10, 15, 20,\
    \ 30} \u203B\u30BD\u30FC\u30C8\u6642)\n    assert(engine.kth_smallest(0, 7, 0)\
    \ == -5);\n    assert(engine.kth_smallest(0, 7, 1) == -5);\n    assert(engine.kth_smallest(0,\
    \ 7, 2) == 10);\n    assert(engine.kth_largest(0, 7, 0) == 30);\n    assert(engine.kth_largest(0,\
    \ 7, 1) == 20);\n\n    // find \u7CFB (\u533A\u9593 [4, 7) : {30, -5, 15})\n \
    \   l = 4, r = 7;\n    assert(engine.find_ge(l, r, 10) == 15);\n    assert(engine.find_gt(l,\
    \ r, 15) == 30);\n    assert(engine.find_le(l, r, 14) == -5);\n    assert(engine.find_lt(l,\
    \ r, -5) == -engine.INF_VAL); // \u5B58\u5728\u3057\u306A\u3044\n\n    // range_freq\
    \ (\u533A\u9593 [0, 7), \u5024 [-5, 20)) \n    // \u5BFE\u8C61: {-5, -5, 10, 10,\
    \ 15}\n    assert(engine.range_freq(0, 7, -5, 20) == 5);\n    assert(engine.range_freq(0,\
    \ 7, 10, 11) == 2); // count_x \u3068\u540C\u7B49\n}\n\nvoid test_with_single_element()\
    \ {\n    vector<int> data = {100};\n    WaveletSearchEngine engine(data);\n  \
    \  \n    assert(engine.access(0) == 100);\n    assert(engine.count_x(0, 1, 100)\
    \ == 1);\n    assert(engine.find_ge(0, 1, 100) == 100);\n    assert(engine.find_gt(0,\
    \ 1, 100) == engine.INF_VAL);\n}\n/**\n * @brief WaveletSearchEngine\u306E\u30C6\
    \u30B9\u30C8\n */\nvoid solve() {\n    print(\"Hello World\");\n    test_wavelet_search_engine();\n\
    \    test_with_single_element();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/search/binary_search/wavelet_search_engine.hpp
  - library/sequence/compressor.hpp
  - library/sequence/wavelet_matrix.hpp
  - library/sequence/bit_dict.hpp
  isVerificationFile: true
  path: tests/search.binary_search.wavelet_search_engine.test.cpp
  requiredBy: []
  timestamp: '2026-01-19 15:38:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/search.binary_search.wavelet_search_engine.test.cpp
layout: document
redirect_from:
- /verify/tests/search.binary_search.wavelet_search_engine.test.cpp
- /verify/tests/search.binary_search.wavelet_search_engine.test.cpp.html
title: "WaveletSearchEngine\u306E\u30C6\u30B9\u30C8"
---
