---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/search/bit_search.hpp
    title: "bit\u5168\u63A2\u7D22"
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
    document_title: "bit\u5168\u63A2\u7D22\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/search/bit_search.hpp\"\
    \nvoid test_bit_search() {\n    // \u30B1\u30FC\u30B91: 3\u3064\u306E\u8981\u7D20\
    \ {1, 2, 3} \u306E\u90E8\u5206\u96C6\u5408\n    // 2^3 = 8\u901A\u308A\u306E\u90E8\
    \u5206\u96C6\u5408\u304C\u751F\u6210\u3055\u308C\u308B\u306F\u305A\n    vector<int>\
    \ v1 = {1, 2, 3};\n    vector<vector<int>> res1 = bit_search(v1);\n    assert(res1.size()\
    \ == 8);\n    // \u7A7A\u96C6\u5408\u304C\u542B\u307E\u308C\u3066\u3044\u308B\u304B\
    \n    bool has_empty = false;\n    // \u7279\u5B9A\u306E\u90E8\u5206\u96C6\u5408\
    \ {1, 3} \u304C\u542B\u307E\u308C\u3066\u3044\u308B\u304B\n    bool has_1_3 =\
    \ false;\n    for (const auto &subset : res1) {\n        if (subset.empty()) has_empty\
    \ = true;\n        if (subset == vector<int>{1, 3}) has_1_3 = true;\n    }\n \
    \   assert(has_empty);\n    assert(has_1_3);\n    // \u30B1\u30FC\u30B92: 1\u3064\
    \u306E\u8981\u7D20 {10}\n    // {\u7A7A}, {10} \u306E2\u901A\u308A\n    vector<int>\
    \ v2 = {10};\n    vector<vector<int>> res2 = bit_search(v2);\n    assert(res2.size()\
    \ == 2);\n    assert(res2[0].empty());\n    assert(res2[1] == vector<int>{10});\n\
    \    // \u30B1\u30FC\u30B93: \u7A7A\u306E\u914D\u5217\n    // 2^0 = 1\u901A\u308A\
    \ (\u7A7A\u96C6\u5408\u306E\u307F)\n    vector<int> v3 = {};\n    vector<vector<int>>\
    \ res3 = bit_search(v3);\n    assert(res3.size() == 1);\n    assert(res3[0].empty());\n\
    \    // \u30B1\u30FC\u30B94: \u6587\u5B57\u5217\u306E\u96C6\u5408\n    vector<string>\
    \ v4 = {\"A\", \"B\"};\n    vector<vector<string>> res4 = bit_search(v4);\n  \
    \  // {\"\"}, {\"A\"}, {\"B\"}, {\"A\", \"B\"}\n    assert(res4.size() == 4);\n\
    \    assert(res4[3] == vector<string>({\"A\", \"B\"}));\n}\n/**\n * @brief bit\u5168\
    \u63A2\u7D22\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n    print(\"Hello World\"\
    );\n    test_bit_search();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/search/bit_search.hpp
  isVerificationFile: true
  path: tests/search.bit_search.test.cpp
  requiredBy: []
  timestamp: '2026-01-16 14:13:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/search.bit_search.test.cpp
layout: document
redirect_from:
- /verify/tests/search.bit_search.test.cpp
- /verify/tests/search.bit_search.test.cpp.html
title: "bit\u5168\u63A2\u7D22\u306E\u30C6\u30B9\u30C8"
---
