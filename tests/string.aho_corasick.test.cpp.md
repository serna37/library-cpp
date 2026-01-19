---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/string/aho_corasick.hpp
    title: Aho Corasick
  - icon: ':x:'
    path: library/string/trie.hpp
    title: "Trie\u6728"
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
    PROBLEM: https://yukicoder.me/problems/no/430
    document_title: "Aho Corasick\u306E\u30C6\u30B9\u30C8"
    links:
    - https://yukicoder.me/problems/no/430
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
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/430\"\n#include \"template/template.hpp\"\
    \n#include \"library/string/aho_corasick.hpp\"\n/**\n * @brief Aho Corasick\u306E\
    \u30C6\u30B9\u30C8\n */\nvoid solve() {\n    string S;\n    cin >> S;\n    int\
    \ M;\n    cin >> M;\n    AhoCorasick<26, 'A'> ac;\n    for (int i = 0; i < M;\
    \ ++i) {\n        string C;\n        cin >> C;\n        ac.add(C, i);\n    }\n\
    \    ac.build();\n    long long ans = ac.count_all(S);\n    print(ans);\n}\n"
  dependsOn:
  - template/template.hpp
  - library/string/aho_corasick.hpp
  - library/string/trie.hpp
  isVerificationFile: true
  path: tests/string.aho_corasick.test.cpp
  requiredBy: []
  timestamp: '2026-01-19 15:38:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/string.aho_corasick.test.cpp
layout: document
redirect_from:
- /verify/tests/string.aho_corasick.test.cpp
- /verify/tests/string.aho_corasick.test.cpp.html
title: "Aho Corasick\u306E\u30C6\u30B9\u30C8"
---
