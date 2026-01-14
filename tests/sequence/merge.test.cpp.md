---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/sequence/merge.hpp
    title: "\u30DE\u30FC\u30B8\u30C6\u30AF"
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
    document_title: "\u30DE\u30FC\u30B8\u30C6\u30AF\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/sequence/merge.hpp\"\n\
    void run_merge_tests() {\n    // \u30B1\u30FC\u30B91: vector \u306E\u30DE\u30FC\
    \u30B8\n    {\n        vector<int> A = {1, 2};\n        vector<int> B = {3, 4,\
    \ 5};\n        // A\u306E\u65B9\u304C\u5C0F\u3055\u3044\u306E\u3067 B \u306B\u8FFD\
    \u52A0\u3055\u308C\u308B\u306F\u305A\n        merge(A, B);\n        assert(A.empty());\n\
    \        assert(B.size() == 5);\n        // \u5185\u5BB9\u306E\u78BA\u8A8D\uFF08\
    \u9806\u5E8F\u306F 3, 4, 5, 1, 2 \u306B\u306A\u308B\uFF09\n        vector<int>\
    \ expected = {3, 4, 5, 1, 2};\n        for (int i = 0; i < 5; i++) assert(B[i]\
    \ == expected[i]);\n    }\n    // \u30B1\u30FC\u30B92: vector \u306E\u30DE\u30FC\
    \u30B8 (swap\u304C\u767A\u751F\u3059\u308B\u5834\u5408)\n    {\n        vector<int>\
    \ A = {1, 2, 3};\n        vector<int> B = {4, 5};\n        // A\u306E\u65B9\u304C\
    \u5927\u304D\u3044\u306E\u3067 swap \u3057\u3066\u304B\u3089 A(\u5143B) \u3092\
    \ B(\u5143A) \u306B\u30DE\u30FC\u30B8\u3059\u308B\n        merge(A, B);\n    \
    \    assert(A.empty());\n        assert(B.size() == 5);\n        // swap\u306B\
    \u3088\u308A\u5143A\u304C\u30D9\u30FC\u30B9\u306B\u306A\u308B\u305F\u3081\u3001\
    \u7D50\u679C\u306F 1, 2, 3, 4, 5 \u3068\u306A\u308B\n        vector<int> expected\
    \ = {1, 2, 3, 4, 5};\n        for (int i = 0; i < 5; i++) assert(B[i] == expected[i]);\n\
    \    }\n    // \u30B1\u30FC\u30B93: set \u306E\u30DE\u30FC\u30B8 (\u91CD\u8907\
    \u3042\u308A)\n    {\n        set<int> A = {10, 20};\n        set<int> B = {20,\
    \ 30, 40};\n        merge(A, B);\n        assert(A.empty());\n        assert(B.size()\
    \ == 4); // 20\u304C\u91CD\u8907\u3057\u3066\u3044\u308B\u306E\u3067 {10, 20,\
    \ 30, 40}\n        assert(B.count(10) && B.count(20) && B.count(30) && B.count(40));\n\
    \    }\n    // \u30B1\u30FC\u30B94: \u6C4E\u7528\u30DE\u30FC\u30B8 (map \u3078\
    \u306E\u30DE\u30FC\u30B8\u3092\u30AB\u30B9\u30BF\u30E0\u95A2\u6570\u3067\u884C\
    \u3046)\n    {\n        map<string, int> A = {{\"apple\", 1}};\n        map<string,\
    \ int> B = {{\"banana\", 2}, {\"cherry\", 3}};\n        // \u30E9\u30E0\u30C0\u5F0F\
    \u3067 map \u3078\u306E\u633F\u5165\u30EB\u30FC\u30EB\u3092\u5B9A\u7FA9\n    \
    \    auto f = [](map<string, int> &target, pair<const string, int> &entry) {\n\
    \            target[entry.first] += entry.second;\n        };\n        merge(A,\
    \ B, f);\n        assert(A.empty());\n        assert(B.size() == 3);\n       \
    \ assert(B[\"apple\"] == 1);\n        assert(B[\"banana\"] == 2);\n    }\n}\n\
    /**\n * @brief \u30DE\u30FC\u30B8\u30C6\u30AF\u306E\u30C6\u30B9\u30C8\n */\nvoid\
    \ solve() {\n    print(\"Hello World\");\n    run_merge_tests();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/sequence/merge.hpp
  isVerificationFile: true
  path: tests/sequence/merge.test.cpp
  requiredBy: []
  timestamp: '2026-01-14 18:38:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/sequence/merge.test.cpp
layout: document
redirect_from:
- /verify/tests/sequence/merge.test.cpp
- /verify/tests/sequence/merge.test.cpp.html
title: "\u30DE\u30FC\u30B8\u30C6\u30AF\u306E\u30C6\u30B9\u30C8"
---
