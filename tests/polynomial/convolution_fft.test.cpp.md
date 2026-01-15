---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/polynomial/convolution_fft.hpp
    title: "\u7573\u307F\u8FBC\u307F FFT"
  - icon: ':heavy_check_mark:'
    path: library/polynomial/fft.hpp
    title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB"
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
    document_title: "\u7573\u307F\u8FBC\u307FFFT\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/polynomial/convolution_fft.hpp\"\
    \nvoid run_unit_tests() {\n    // \u30B1\u30FC\u30B91: \u57FA\u672C\u7684\u306A\
    \u7573\u307F\u8FBC\u307F (1 + 2x + 3x^2) * (4 + 5x + 6x^2)\n    {\n        vector<int>\
    \ a = {1, 2, 3};\n        vector<int> b = {4, 5, 6};\n        vector<long long>\
    \ expected = {4, 13, 28, 27, 18};\n        vector<long long> res = convolution_fft(a,\
    \ b);\n        assert(res.size() == expected.size());\n        for (int i = 0;\
    \ i < (int)res.size(); i++) {\n            assert(res[i] == expected[i]);\n  \
    \      }\n    }\n    // \u30B1\u30FC\u30B92: \u9577\u3055\u304C\u7570\u306A\u308B\
    \u6570\u5217\u306E\u7573\u307F\u8FBC\u307F\n    {\n        vector<int> a = {1,\
    \ 1, 1, 1};\n        vector<int> b = {1, 2};\n        // (1+x+x^2+x^3)*(1+2x)\
    \ = 1 + 3x + 3x^2 + 3x^3 + 2x^4\n        vector<long long> expected = {1, 3, 3,\
    \ 3, 2};\n        vector<long long> res = convolution_fft(a, b);\n        assert(res.size()\
    \ == expected.size());\n        for (int i = 0; i < (int)res.size(); i++) {\n\
    \            assert(res[i] == expected[i]);\n        }\n    }\n    // \u30B1\u30FC\
    \u30B93: 0\u3092\u542B\u3080\u30B1\u30FC\u30B9\n    {\n        vector<int> a =\
    \ {0, 5, 0};\n        vector<int> b = {0, 2};\n        // (5x) * (2x) = 10x^2\n\
    \        vector<long long> expected = {0, 0, 10, 0};\n        vector<long long>\
    \ res = convolution_fft(a, b);\n        assert(res.size() == expected.size());\n\
    \        for (int i = 0; i < (int)res.size(); i++) {\n            assert(res[i]\
    \ == expected[i]);\n        }\n    }\n    // \u30B1\u30FC\u30B94: \u5927\u304D\
    \u306A\u5024\u306E\u7CBE\u5EA6\u78BA\u8A8D (10^6 * 10^6 = 10^12)\n    {\n    \
    \    vector<long long> a = {1000000};\n        vector<long long> b = {1000000};\n\
    \        vector<long long> res = convolution_fft(a, b);\n        assert(res[0]\
    \ == 1000000000000LL);\n    }\n}\n/**\n * @brief \u7573\u307F\u8FBC\u307FFFT\u306E\
    \u30C6\u30B9\u30C8\n */\nvoid solve() {\n    print(\"Hello World\");\n    run_unit_tests();\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - library/polynomial/convolution_fft.hpp
  - library/polynomial/fft.hpp
  isVerificationFile: true
  path: tests/polynomial/convolution_fft.test.cpp
  requiredBy: []
  timestamp: '2026-01-15 14:36:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/polynomial/convolution_fft.test.cpp
layout: document
redirect_from:
- /verify/tests/polynomial/convolution_fft.test.cpp
- /verify/tests/polynomial/convolution_fft.test.cpp.html
title: "\u7573\u307F\u8FBC\u307FFFT\u306E\u30C6\u30B9\u30C8"
---
