---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/number/mod/montgomery_mod_int.hpp
    title: "\u30E2\u30B8\u30E5\u30ED\u6F14\u7B97"
  - icon: ':x:'
    path: library/polynomial/fft/convolution_arbitrary_mod.hpp
    title: "\u7573\u307F\u8FBC\u307F \u4EFB\u610FMOD"
  - icon: ':question:'
    path: library/polynomial/fft/fast_fourier_transform.hpp
    title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB"
  - icon: ':x:'
    path: library/polynomial/fps/bernoulli_number.hpp
    title: "\u30D9\u30EB\u30CC\u30FC\u30A4\u6570"
  - icon: ':x:'
    path: library/polynomial/fps/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bernoulli_number
    document_title: "\u30D9\u30EB\u30CC\u30FC\u30A4\u6570\u306E\u30C6\u30B9\u30C8"
    links:
    - https://judge.yosupo.jp/problem/bernoulli_number
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bernoulli_number\"\n#include\
    \ \"template/template.hpp\"\n#include \"library/polynomial/fps/bernoulli_number.hpp\"\
    \n/**\n * @brief \u30D9\u30EB\u30CC\u30FC\u30A4\u6570\u306E\u30C6\u30B9\u30C8\n\
    \ */\nvoid solve() {\n    int N;\n    cin >> N;\n    print(bernoulli_number<FPS,\
    \ modint998244353>(N));\n}\n"
  dependsOn:
  - template/template.hpp
  - library/polynomial/fps/bernoulli_number.hpp
  - library/polynomial/fps/formal_power_series.hpp
  - library/polynomial/fft/convolution_arbitrary_mod.hpp
  - library/number/mod/montgomery_mod_int.hpp
  - library/polynomial/fft/fast_fourier_transform.hpp
  isVerificationFile: true
  path: tests/polynomial.fps.bernoulli_number.test.cpp
  requiredBy: []
  timestamp: '2026-01-19 14:50:54+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/polynomial.fps.bernoulli_number.test.cpp
layout: document
redirect_from:
- /verify/tests/polynomial.fps.bernoulli_number.test.cpp
- /verify/tests/polynomial.fps.bernoulli_number.test.cpp.html
title: "\u30D9\u30EB\u30CC\u30FC\u30A4\u6570\u306E\u30C6\u30B9\u30C8"
---
