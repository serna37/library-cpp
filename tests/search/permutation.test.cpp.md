---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/search/permutation.hpp
    title: "\u9806\u5217\u5168\u63A2\u7D22"
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
    document_title: "\u9806\u5217\u5168\u63A2\u7D22\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/search/permutation.hpp\"\
    \nvoid test_permutation() {\n    // \u30B1\u30FC\u30B91: \u7279\u5B9A\u306E\u4E26\
    \u3073\u9806\u304C\u5B58\u5728\u3059\u308B\u304B\u30C1\u30A7\u30C3\u30AF\n   \
    \ // {1, 2, 3} \u306E\u4E26\u3073\u66FF\u3048\u3067 {3, 2, 1} \u306B\u306A\u308B\
    \u77AC\u9593\u304C\u3042\u308B\u304B\n    vector<int> v1 = {1, 2, 3};\n    auto\
    \ f1 = [&]() { return v1[0] == 3 && v1[1] == 2 && v1[2] == 1; };\n    assert(permutation(v1,\
    \ f1) == true);\n    // \u30B1\u30FC\u30B92: \u6761\u4EF6\u3092\u6E80\u305F\u3059\
    \u4E26\u3073\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\n    // {1, 2, 3}\
    \ \u306E\u4E26\u3073\u66FF\u3048\u3067 \u5408\u8A08\u304C 10 \u306B\u306A\u308B\
    \u3053\u3068\u306F\u306A\u3044\n    vector<int> v2 = {1, 2, 3};\n    auto f2 =\
    \ [&]() {\n        int sum = 0;\n        for (int x : v2) sum += x;\n        return\
    \ sum == 10;\n    };\n    assert(permutation(v2, f2) == false);\n    // \u30B1\
    \u30FC\u30B93: \u91CD\u8907\u306E\u3042\u308B\u8981\u7D20\n    // {1, 1, 2} \u306E\
    \u5168\u9806\u5217\u306F {1,1,2}, {1,2,1}, {2,1,1} \u306E3\u901A\u308A\n    vector<int>\
    \ v3 = {2, 1, 1};\n    int count = 0;\n    auto f3 = [&]() {\n        count++;\n\
    \        return false; // \u6700\u5F8C\u307E\u3067\u56DE\u3055\u305B\u308B\n \
    \   };\n    permutation(v3, f3);\n    assert(count == 3);\n    // \u30B1\u30FC\
    \u30B94: \u6587\u5B57\u5217\u306E\u4E26\u3073\u66FF\u3048\n    // \"abc\" \u3092\
    \u4E26\u3073\u66FF\u3048\u3066 \"cba\" \u306B\u3067\u304D\u308B\u304B\n    vector<char>\
    \ v4 = {'a', 'b', 'c'};\n    auto f4 = [&]() { return v4[0] == 'c' && v4[1] ==\
    \ 'b' && v4[2] == 'a'; };\n    assert(permutation(v4, f4) == true);\n    // \u30B1\
    \u30FC\u30B95: \u8981\u7D20\u304C1\u3064\u306E\u5834\u5408\n    vector<int> v5\
    \ = {1};\n    int count5 = 0;\n    permutation(v5, [&]() {\n        count5++;\n\
    \        return false;\n    });\n    assert(count5 == 1);\n}\n/**\n * @brief \u9806\
    \u5217\u5168\u63A2\u7D22\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n    print(\"\
    Hello World\");\n    test_permutation();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/search/permutation.hpp
  isVerificationFile: true
  path: tests/search/permutation.test.cpp
  requiredBy: []
  timestamp: '2026-01-13 14:30:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/search/permutation.test.cpp
layout: document
redirect_from:
- /verify/tests/search/permutation.test.cpp
- /verify/tests/search/permutation.test.cpp.html
title: "\u9806\u5217\u5168\u63A2\u7D22\u306E\u30C6\u30B9\u30C8"
---
