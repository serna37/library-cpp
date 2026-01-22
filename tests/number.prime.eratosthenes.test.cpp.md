---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/number/divisors.hpp
    title: "\u7D04\u6570\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: library/number/prime/eratosthenes.hpp
    title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
  - icon: ':heavy_check_mark:'
    path: library/number/prime/euler_phi.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: library/number/prime/prime_fact.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: library/number/prime/prime_test.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
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
    document_title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\u306E\u30C6\
      \u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/number/prime/eratosthenes.hpp\"\
    \n#include \"library/number/prime/prime_test.hpp\"\n#include \"library/number/prime/prime_fact.hpp\"\
    \n#include \"library/number/prime/euler_phi.hpp\"\n#include \"library/number/divisors.hpp\"\
    \n/**\n * @brief \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\u306E\u30C6\
    \u30B9\u30C8\n */\nvoid test() {\n    int N = 1000000;\n    Eratosthenes er(N);\n\
    \    int x = 999982;\n    // \u7D20\u6570\u5224\u5B9A\n    bool is_p = er.is_prime(x);\n\
    \    assert(is_p == prime_test(x));\n    // \u7D20\u56E0\u6570\u5206\u89E3 <\u7D20\
    \u56E0\u6570: \u500B\u6570>\n    vector<pair<int, int>> factors = er.factorize(x);\n\
    \    map<int, int> mp = prime_fact(x);\n    for (auto &&[p, cnt] : factors) {\n\
    \        assert(mp[p] == cnt);\n    }\n    // \u7D04\u6570\u5217\u6319 (\u30BD\
    \u30FC\u30C8\u3055\u308C\u3066\u306A\u3044\u3088)\n    vector<int> divs = er.calc_divisors(x);\n\
    \    vector<int> exp = divisors(x);\n    sort(all(divs));\n    sort(all(exp));\n\
    \    assert(divs == exp);\n    // \u6700\u5C0F\u7D20\u56E0\u6570\n    int lpf\
    \ = er.lpf(x);\n    assert(lpf == 2ll);\n    // \u03C6(x)\n    int phi = er.euler_phi(x);\n\
    \    assert(phi == euler_phi(x));\n}\nvoid solve() {\n    print(\"Hello World\"\
    );\n    test();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/number/prime/eratosthenes.hpp
  - library/number/prime/prime_test.hpp
  - library/number/prime/prime_fact.hpp
  - library/number/prime/euler_phi.hpp
  - library/number/divisors.hpp
  isVerificationFile: true
  path: tests/number.prime.eratosthenes.test.cpp
  requiredBy: []
  timestamp: '2026-01-22 14:26:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/number.prime.eratosthenes.test.cpp
layout: document
redirect_from:
- /verify/tests/number.prime.eratosthenes.test.cpp
- /verify/tests/number.prime.eratosthenes.test.cpp.html
title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\u306E\u30C6\u30B9\u30C8"
---
