---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/string/aho_corasick.hpp
    title: Aho Corasick
  - icon: ':heavy_check_mark:'
    path: library/string/finds.hpp
    title: "\u6587\u5B57\u5217\u8907\u6570 \u7D71\u5408\u691C\u7D22\u30A8\u30F3\u30B8\
      \u30F3"
  - icon: ':heavy_check_mark:'
    path: library/string/rolling_hash.hpp
    title: Rolling Hash
  - icon: ':heavy_check_mark:'
    path: library/string/trie.hpp
    title: "Trie\u6728"
  - icon: ':heavy_check_mark:'
    path: library/various/random.hpp
    title: "\u64EC\u4F3C\u4E71\u6570\u751F\u6210"
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
    document_title: "\u6587\u5B57\u5217\u8907\u6570 \u7D71\u5408\u691C\u7D22\u30A8\
      \u30F3\u30B8\u30F3\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/string/finds.hpp\"\n\
    void test_finds() {\n    // \u30B1\u30FC\u30B91: \u5358\u4E00\u30D1\u30BF\u30FC\
    \u30F3\u30FB\u77ED\u3044\n    {\n        string T = \"banana\";\n        vector<string>\
    \ P = {\"ana\"};\n        auto res = finds(T, P);\n        assert(res[\"ana\"\
    ] == vector<int>({1ll, 3ll}));\n    }\n\n    // \u30B1\u30FC\u30B92: \u5358\u4E00\
    \u30D1\u30BF\u30FC\u30F3\u30FB\u9577\u3044\n    {\n        string T = \"abracadabra_abracadabra\"\
    ;\n        string pattern = \"abracadabra\";\n        vector<string> P = {pattern};\n\
    \        auto res = finds(T, P);\n        assert(res[pattern] == vector<int>({0ll,\
    \ 12ll}));\n    }\n\n    // \u30B1\u30FC\u30B93: \u8907\u6570\u30D1\u30BF\u30FC\
    \u30F3\n    {\n        string T = \"abracadabra\";\n        vector<string> P =\
    \ {\"abr\", \"ra\", \"a\"};\n        auto res = finds(T, P);\n        assert(res[\"\
    abr\"] == vector<int>({0ll, 7ll}));\n        assert(res[\"ra\"] == vector<int>({2ll,\
    \ 9ll}));\n        assert(res[\"a\"] == vector<int>({0ll, 3ll, 5ll, 7ll, 10ll}));\n\
    \    }\n\n    // \u30B1\u30FC\u30B94: \u30D2\u30C3\u30C8\u3057\u306A\u3044\u5834\
    \u5408\n    {\n        string T = \"hello\";\n        vector<string> P = {\"world\"\
    };\n        auto res = finds(T, P);\n        assert(res[\"world\"].empty());\n\
    \    }\n}\n/**\n * @brief \u6587\u5B57\u5217\u8907\u6570 \u7D71\u5408\u691C\u7D22\
    \u30A8\u30F3\u30B8\u30F3\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n    print(\"\
    Hello World\");\n    test_finds();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/string/finds.hpp
  - library/string/rolling_hash.hpp
  - library/various/random.hpp
  - library/string/aho_corasick.hpp
  - library/string/trie.hpp
  isVerificationFile: true
  path: tests/string.finds.test.cpp
  requiredBy: []
  timestamp: '2026-01-16 15:08:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/string.finds.test.cpp
layout: document
redirect_from:
- /verify/tests/string.finds.test.cpp
- /verify/tests/string.finds.test.cpp.html
title: "\u6587\u5B57\u5217\u8907\u6570 \u7D71\u5408\u691C\u7D22\u30A8\u30F3\u30B8\u30F3\
  \u306E\u30C6\u30B9\u30C8"
---
