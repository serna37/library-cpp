---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: bits/stdc++.h
    title: "\u30AB\u30B9\u30BF\u30E0stdc++.h"
  - icon: ':x:'
    path: library/def/common.hpp
    title: "\u5171\u901A"
  - icon: ':x:'
    path: library/def/const.hpp
    title: "\u5B9A\u6570"
  - icon: ':x:'
    path: library/def/io.hpp
    title: "IO\u95A2\u9023"
  - icon: ':x:'
    path: library/def/type.hpp
    title: "\u578B"
  - icon: ':x:'
    path: library/util/number.hpp
    title: "\u6570\u306E\u6027\u8CEA"
  - icon: ':x:'
    path: library/util/search.hpp
    title: "\u63A2\u7D22"
  - icon: ':x:'
    path: library/util/sequence.hpp
    title: "\u914D\u5217\u30FB\u96C6\u5408\u30FB\u6570\u5217"
  - icon: ':x:'
    path: template/template.hpp
    title: "\u0E05^>\u03C9<^\u0E05"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
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
    \n#include \"template/template.hpp\"\nsigned main() {\n    cout << \"Hello World\"\
    \ << endl;\n    /*\n    template.hpp\u304B\u3089\u547C\u3093\u3067\u3044\u308B\
    \n    library/util/xxx.hpp\u306E\u30E6\u30CB\u30C3\u30C8\u30C6\u30B9\u30C8\n \
    \   */\n    // ===== library/util/common.hpp =====\n    // chmin\n    int i =\
    \ 6, j = 3;\n    chmin(i, j);\n    assert(i == 3);\n    i = 3, j = 6;\n    chmin(i,\
    \ j);\n    assert(i == 3);\n    // chmax\n    i = 5, j = 3;\n    chmax(i, j);\n\
    \    assert(i == 5);\n    i = 3, j = 5;\n    chmax(i, j);\n    assert(i == 5);\n\
    \    // ===== library/util/type.hpp =====\n    // int_to_char\n    assert('3'\
    \ == int_to_char(3));\n    // int_to_alph\n    assert('d' == int_to_alph(3));\n\
    \    // char_to_int\n    assert(3 == char_to_int('3'));\n    // toString\n   \
    \ assert(\"3\" == int_to_string(3));\n    // toInteger\n    assert(3 == string_to_int(\"\
    3\"));\n    // ===== library/util/seq.hpp =====\n    vector<int> v{1, 3, 2, 4,\
    \ 5, 5};\n    // len\n    assert(6 == len(v));\n    // min\n    assert(1 == min(v));\n\
    \    // max\n    assert(5 == max(v));\n    // sum\n    assert(20 == sum(v));\n\
    \    // allMatch\n    assert(all_match(v, [](int x) { return x < 6; }));\n   \
    \ // nonMatch\n    assert(!none_match(v, [](int x) { return x < 6; }));\n    //\
    \ anyMatch\n    assert(any_match(v, [](int x) { return x < 6; }));\n    // sort_asc\n\
    \    sort_asc(v);\n    vector<int> asc{1, 2, 3, 4, 5, 5};\n    assert(v == asc);\n\
    \    // sort_desc\n    sort_desc(v);\n    vector<int> desc{5, 5, 4, 3, 2, 1};\n\
    \    assert(v == desc);\n    // reverse\n    reverse(v);\n    assert(v == asc);\n\
    \    // distinct\n    distinct(v);\n    vector<int> dis{1, 2, 3, 4, 5};\n    assert(v\
    \ == dis);\n    // erase (set)\n    set<int> st{1, 2, 3, 4, 5};\n    int val =\
    \ 3;\n    erase(st, val);\n    set<int> exp{1, 2, 4, 5};\n    assert(st == exp);\n\
    \    // erase (multiset)\n    multiset<int> mst{1, 2, 3, 4, 5};\n    erase(mst,\
    \ val);\n    multiset<int> mexp{1, 2, 4, 5};\n    assert(mst == mexp);\n    //\
    \ transpose\n    int H = 4, W = 4;\n    vec2<int> G = make_vec2(H, W);\n    int\
    \ t = 0;\n    for (auto &&r : G) {\n        ++t;\n        for (auto &&e : r) {\n\
    \            e = t++;\n        }\n    }\n    auto P = transpose(G);\n    vec2<int>\
    \ expP{\n        {1, 6, 11, 16}, {2, 7, 12, 17}, {3, 8, 13, 18}, {4, 9, 14, 19}};\n\
    \    assert(P == expP);\n    // unpack\n    vec2<int> tmp{{1, 2}, {3, 4}};\n \
    \   auto [a, b] = unpack<2>(move(tmp));\n    vector<int> expa{1, 2};\n    vector<int>\
    \ expb{3, 4};\n    assert(a == expa);\n    assert(b == expb);\n    // coordinate\n\
    \    vector<int> arr{2, 3, 5, 7, 11, 13};\n    vector<int> co = coordinate(arr);\n\
    \    for (int k = 1; k < 13; ++k) {\n        int cnt =\n            k == 2 or\
    \ k == 3 or k == 5 or k == 7 or k == 11 or k == 13 ? 1 : 0;\n        assert(co[k]\
    \ == cnt);\n    }\n    // ===== library/util/math.hpp =====\n    // divCeil\n\
    \    assert(2 == div_ceil(5, 3));\n    assert(2 == div_ceil(-5, -3));\n    //\
    \ divFloor\n    assert(1 == div_floor(5, 3));\n    assert(1 == div_floor(-5, -3));\n\
    \    // ===== library/util/search.hpp =====\n    // search_permu\n    vector<int>\
    \ permA{1, 2, 3};\n    vec2<int> permB;\n    search_permu(permA, [&]() { permB.push_back(permA);\
    \ });\n    vec2<int> expPermB{{1, 2, 3}, {1, 3, 2}, {2, 1, 3},\n             \
    \          {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};\n    assert(permB == expPermB);\n\
    \    // search_bit\n    vector<int> bitA{1, 2, 3};\n    vec2<int> bitB = search_bit(bitA);\n\
    \    vec2<int> expBitB{{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}};\n\
    \    assert(bitB == expBitB);\n}\n"
  dependsOn:
  - template/template.hpp
  - bits/stdc++.h
  - library/def/common.hpp
  - library/def/io.hpp
  - library/def/type.hpp
  - library/def/const.hpp
  - library/util/sequence.hpp
  - library/util/number.hpp
  - library/util/search.hpp
  isVerificationFile: true
  path: tests/template.test.cpp
  requiredBy: []
  timestamp: '2025-12-24 17:14:06+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/template.test.cpp
layout: document
redirect_from:
- /verify/tests/template.test.cpp
- /verify/tests/template.test.cpp.html
title: tests/template.test.cpp
---
