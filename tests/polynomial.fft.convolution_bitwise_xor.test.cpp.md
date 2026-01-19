---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/number/mod/montgomery_mod_int.hpp
    title: "\u30E2\u30B8\u30E5\u30ED\u6F14\u7B97"
  - icon: ':heavy_check_mark:'
    path: library/polynomial/fft/convolution_bitwise_xor.hpp
    title: "Bitwise\u7573\u307F\u8FBC\u307FXOR"
  - icon: ':heavy_check_mark:'
    path: library/polynomial/fft/fast_walsh_hadamard_transform.hpp
    title: "\u9AD8\u901FWalshHadamard\u5909\u63DB"
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
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    document_title: "Bitwise\u7573\u307F\u8FBC\u307FXOR\u306E\u30C6\u30B9\u30C8"
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n#include \"template/template.hpp\"\n#include \"library/number/mod/montgomery_mod_int.hpp\"\
    \n#include \"library/polynomial/fft/convolution_bitwise_xor.hpp\"\n/**\n * @brief\
    \ Bitwise\u7573\u307F\u8FBC\u307FXOR\u306E\u30C6\u30B9\u30C8\n */\nvoid solve()\
    \ {\n    int N;\n    cin >> N;\n    using mint = modint998244353;\n    vector<mint>\
    \ a(1 << N), b(1 << N);\n    cin >> a;\n    cin >> b;\n    auto c = convolution_bitwise_xor(a,\
    \ b);\n    print(c);\n}\n"
  dependsOn:
  - template/template.hpp
  - library/number/mod/montgomery_mod_int.hpp
  - library/polynomial/fft/convolution_bitwise_xor.hpp
  - library/polynomial/fft/fast_walsh_hadamard_transform.hpp
  isVerificationFile: true
  path: tests/polynomial.fft.convolution_bitwise_xor.test.cpp
  requiredBy: []
  timestamp: '2026-01-19 15:56:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/polynomial.fft.convolution_bitwise_xor.test.cpp
layout: document
redirect_from:
- /verify/tests/polynomial.fft.convolution_bitwise_xor.test.cpp
- /verify/tests/polynomial.fft.convolution_bitwise_xor.test.cpp.html
title: "Bitwise\u7573\u307F\u8FBC\u307FXOR\u306E\u30C6\u30B9\u30C8"
---
