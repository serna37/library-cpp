---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bits/stdc++.h
    title: "\u30AB\u30B9\u30BF\u30E0stdc++.h"
  - icon: ':heavy_check_mark:'
    path: template/def/common.hpp
    title: "\u5171\u901A"
  - icon: ':heavy_check_mark:'
    path: template/def/const.hpp
    title: "\u5B9A\u6570"
  - icon: ':heavy_check_mark:'
    path: template/def/io.hpp
    title: "IO\u95A2\u9023"
  - icon: ':heavy_check_mark:'
    path: template/def/type.hpp
    title: "\u578B"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: template/util/geometry.hpp
    title: "\u5E7E\u4F55"
  - icon: ':heavy_check_mark:'
    path: template/util/grid.hpp
    title: "\u30AF\u3099\u30EA\u30C3\u30C8\u3099"
  - icon: ':heavy_check_mark:'
    path: template/util/number.hpp
    title: "\u6570\u306E\u6027\u8CEA"
  - icon: ':heavy_check_mark:'
    path: template/util/search.hpp
    title: "\u63A2\u7D22"
  - icon: ':heavy_check_mark:'
    path: template/util/sequence.hpp
    title: "\u914D\u5217\u30FB\u6570\u5217"
  - icon: ':heavy_check_mark:'
    path: template/util/string.hpp
    title: "\u6587\u5B57\u5217"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    document_title: "template/util/xxx.hpp\u306E\u30E6\u30CB\u30C3\u30C8\u30C6\u30B9\
      \u30C8"
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
    \n#include \"template/template.hpp\"\n/**\n * @brief template/util/xxx.hpp\u306E\
    \u30E6\u30CB\u30C3\u30C8\u30C6\u30B9\u30C8\n * \u51FA\u529B\u3059\u308B\u3068\u554F\
    \u984C\u306B\u6B63\u89E3\u3067\u304D\u306A\u3044\u306E\u3067assert\u306E\u307F\
    \n */\n// ===== template/util/number.hpp =====\nvoid test_number() {\n    assert(lib::num.div_ceil(10,\
    \ 2) == 5);\n    assert(lib::num.div_ceil(11, 2) == 6);\n    assert(lib::num.div_floor(10,\
    \ 2) == 5);\n    assert(lib::num.div_floor(11, 2) == 5);\n    assert(lib::num.factorial(0)\
    \ == 1);\n    assert(lib::num.factorial(1) == 1);\n    assert(lib::num.factorial(2)\
    \ == 2);\n    assert(lib::num.factorial(3) == 6);\n    assert(lib::num.combination(0,\
    \ 0) == 1);\n    assert(lib::num.combination(1, 0) == 1);\n    assert(lib::num.combination(1,\
    \ 1) == 1);\n    assert(lib::num.combination(2, 0) == 1);\n    assert(lib::num.combination(3,\
    \ 2) == 3);\n    assert(lib::num.digit_sum(1234) == 10);\n    assert(lib::num.base_convert(\"\
    1001\", 2, 10) == \"9\");\n    vector<int> val_divisors = lib::num.divisors(12);\n\
    \    lib::seq.sort_asc(val_divisors);\n    vector<int> exp_divisors = {1, 2, 3,\
    \ 4, 6, 12};\n    assert(val_divisors == exp_divisors);\n    assert(lib::num.prime_test(57)\
    \ == false); // Grothendieck\n    assert(lib::num.prime_test(97) == true);\n \
    \   map<int, int> val_prime_fact = lib::num.prime_fact(100);\n    map<int, int>\
    \ exp_prime_fact = {{2, 2}, {5, 2}};\n    assert(val_prime_fact == exp_prime_fact);\n\
    \    assert(lib::num.modpow(2, 10, MOD) == 1024);\n    assert(lib::num.modinv(2,\
    \ MOD) == 499122177);\n    assert(lib::num.modfact(10, MOD) == 3628800);\n   \
    \ assert(lib::num.mod_combination(10, 5, MOD) == 252);\n}\n// ===== template/util/string.hpp\
    \ =====\nvoid test_string() {\n    assert(lib::str.is_low('A') == false);\n  \
    \  assert(lib::str.is_low('a') == true);\n    assert(lib::str.is_upp('A') == true);\n\
    \    assert(lib::str.is_upp('a') == false);\n    assert(lib::str.transform_lower(\"\
    AbC\") == \"abc\");\n    assert(lib::str.transform_upper(\"AbC\") == \"ABC\");\n\
    \    vector<string> val_join = {\"aa\", \"bb\", \"cc\"};\n    assert(lib::str.join(val_join,\
    \ \",\") == \"aa,bb,cc\");\n    vector<int> exp_finds = {0, 3, 6, 9};\n    assert(lib::str.finds(\"\
    abcaefahia\", \"a\") == exp_finds);\n    vector<string> exp_split = {\"aa\", \"\
    bb\", \"cc\"};\n    assert(lib::str.split(\"aa,bb,cc\", ',') == exp_split);\n\
    \    assert(lib::str.split_multi(\"aa,bb/cc\", \",/\") == exp_split);\n    assert(lib::str.str_range(\"\
    abc123abc\", 3, 6) == \"123a\");\n    vector<pair<char, int>> exp_runlen = {{'a',\
    \ 3}, {'b', 2}, {'c', 1}};\n    assert(lib::str.run_length(\"aaabbc\") == exp_runlen);\n\
    }\n// ===== template/util/sequence.hpp =====\nvoid test_sequence() {\n    vector<int>\
    \ A = {1, 3, 2, 5, 8, 13, 2, 9, 3, 5};\n    assert(lib::seq.min(A) == 1);\n  \
    \  assert(lib::seq.max(A) == 13);\n    assert(lib::seq.sum(A) == 51);\n    vector<int>\
    \ evens = {0, 2, 4, 6};\n    vector<int> odds = {1, 3, 5, 7};\n    auto is_even\
    \ = [](int x) { return x % 2 == 0; };\n    assert(lib::seq.all_match(evens, is_even));\n\
    \    assert(lib::seq.none_match(odds, is_even));\n    assert(lib::seq.any_match(A,\
    \ is_even));\n    vector<int> exp_distinct = {1, 2, 3, 5, 8, 9, 13};\n    lib::seq.distinct(A);\n\
    \    assert(A == exp_distinct);\n    A = {1, 3, 2, 5, 8, 13, 2, 9, 3, 5};\n  \
    \  vector<int> exp_asc = {1, 2, 2, 3, 3, 5, 5, 8, 9, 13};\n    lib::seq.sort_asc(A);\n\
    \    assert(A == exp_asc);\n    A = {1, 3, 2, 5, 8, 13, 2, 9, 3, 5};\n    vector<int>\
    \ exp_desc = {13, 9, 8, 5, 5, 3, 3, 2, 2, 1};\n    lib::seq.sort_desc(A);\n  \
    \  assert(A == exp_desc);\n    A = {1, 3, 2, 5, 8, 13, 2, 9, 3, 5};\n    vector<int>\
    \ exp_rev = {5, 3, 9, 2, 13, 8, 5, 2, 3, 1};\n    lib::seq.reverse(A);\n    assert(A\
    \ == exp_rev);\n    set<int> st = {1, 2, 3, 4, 6, 7, 9, 11};\n    set<int> exp_erase\
    \ = {1, 2, 3, 6, 7, 9, 11};\n    lib::seq.erase(st, 4ll);\n    assert(st == exp_erase);\n\
    \    multiset<int> mst = {1, 2, 3, 4, 4, 4, 6, 7, 9, 11};\n    multiset<int> exp_merase\
    \ = {1, 2, 3, 4, 4, 6, 7, 9, 11};\n    lib::seq.erase(mst, 4ll);\n    assert(mst\
    \ == exp_merase);\n    A = {1, 2};\n    auto [a, b] = lib::seq.unpack<2>(move(A));\n\
    \    assert(a == 1 and b == 2);\n    vector<int> val_renban(10);\n    vector<int>\
    \ exp_renban = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};\n    lib::seq.renban(val_renban);\n\
    \    assert(val_renban == exp_renban);\n    A = {1, 2, 3};\n    vector<int> B\
    \ = {1, 2, 3, 4, 5};\n    lib::seq.merge(A, B);\n    vector<int> exp_merge_vec\
    \ = {1, 2, 3, 4, 5, 1, 2, 3};\n    assert(B == exp_merge_vec);\n    set<int> stA\
    \ = {1, 2, 3};\n    set<int> stB = {1, 2, 3, 4, 5};\n    set<int> exp_merge_set\
    \ = {1, 1, 2, 2, 3, 3, 4, 5};\n    lib::seq.merge(stA, stB);\n    assert(stB ==\
    \ exp_merge_set);\n    map<int, int> mpA = {{1, 1}, {2, 2}};\n    map<int, int>\
    \ mpB = {{1, 1}, {2, 2}, {3, 3}};\n    auto mergeF = [&](map<int, int> &B, pair<int,\
    \ int> v) {\n        return B[v.first] += v.second;\n    };\n    lib::seq.merge(mpA,\
    \ mpB, mergeF);\n    map<int, int> exp_merge_map = {{1, 2}, {2, 4}, {3, 3}};\n\
    \    assert(mpB == exp_merge_map);\n    A = {1, 2, 2, 5, 6};\n    vector<int>\
    \ val_coordinate = lib::seq.coordinate(A);\n    vector<int> exp_coordinate = {0,\
    \ 1, 2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0};\n    for (int i = 0; i < 10; ++i) {\n \
    \       assert(val_coordinate[i] == exp_coordinate[i]);\n    }\n    A = {1, 2,\
    \ 2, 8, 10, 88};\n    int zip_cnt = lib::seq.zip_coordinate(A);\n    assert(zip_cnt\
    \ == 5);\n    vector<int> exp_zip = {0, 1, 1, 2, 3, 4};\n    assert(A == exp_zip);\n\
    \    A = {1, 3, 9, 3, 8, 2, 99, 4};\n    int inv = lib::seq.inversion_number(A);\n\
    \    assert(inv == 9);\n    A = {1, 2, 5, 8, 3, 2, 9};\n    vector<int> S = lib::seq.zeta(A);\n\
    \    vector<int> exp_zeta = {0, 1, 3, 8, 16, 19, 21, 30};\n    assert(S == exp_zeta);\n\
    \    S = lib::seq.zeta_rev(A);\n    vector<int> exp_zeta_rev = {30, 29, 27, 22,\
    \ 14, 11, 9, 0};\n    assert(S == exp_zeta_rev);\n    S = lib::seq.zeta_diff(A);\n\
    \    vector<int> exp_zeta_diff = {0, 0, 1, 1, 4, 4, 5, 5};\n    assert(S == exp_zeta_diff);\n\
    \    S = lib::seq.zeta_rev_diff(A);\n    vector<int> exp_zeta_rev_diff = {15,\
    \ 15, 12, 12, 7, 7, 0, 0};\n    assert(S == exp_zeta_rev_diff);\n    vector<vector<int>>\
    \ G = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};\n    vector<vector<int>> S2 = lib::seq.zeta_2D(G);\n\
    \    vector<vector<int>> exp_zeta_2D = {\n        {0, 0, 0, 0}, {0, 1, 3, 6},\
    \ {0, 5, 12, 21}, {0, 12, 27, 45}};\n    assert(S2 == exp_zeta_2D);\n    vector<vector<vector<int>>>\
    \ G3 = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},\n                                 \
    \     {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},\n                                   \
    \   {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};\n    auto S3 = lib::seq.zeta_3D(G3);\n\
    \    vector<vector<vector<int>>> exp_zeta_3D = {\n        {{0, 0, 0, 0}, {0, 0,\
    \ 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},\n        {{0, 0, 0, 0}, {0, 1, 3, 6}, {0,\
    \ 5, 12, 21}, {0, 12, 27, 45}},\n        {{0, 0, 0, 0}, {0, 2, 6, 12}, {0, 10,\
    \ 24, 42}, {0, 24, 54, 90}},\n        {{0, 0, 0, 0}, {0, 3, 9, 18}, {0, 15, 36,\
    \ 63}, {0, 36, 81, 135}}};\n    assert(S3 == exp_zeta_3D);\n    vector<int> R\
    \ = lib::seq.moebius(A);\n    vector<int> exp_moebius = {1, 3, 3, -5, -1, 7};\n\
    \    assert(R == exp_moebius);\n}\n// ===== template/util/search.hpp =====\nvoid\
    \ test_search() {\n    vector<int> A = {1, 2, 3};\n    vector<vector<int>> val_perm;\n\
    \    vector<vector<int>> exp_perm = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3},\n      \
    \                              {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};\n    lib::search.perm(A,\
    \ [&]() { val_perm.push_back(A); });\n    assert(val_perm == exp_perm);\n    A\
    \ = {1, 2, 3};\n    vector<vector<int>> val_bit = lib::search.bit(A);\n    vector<vector<int>>\
    \ exp_bit = {{},  {1},    {2},    {1, 2},\n                                  \
    \ {3}, {1, 3}, {2, 3}, {1, 2, 3}};\n    assert(val_bit == exp_bit);\n    auto\
    \ [L, R] = lib::search.bi([](int x) { return x >= 5; });\n    assert(L == 4 and\
    \ R == 5);\n    auto [l, r] = lib::search.bi_real([](int x) { return x >= 3.5;\
    \ });\n    assert(l < 4.1 and r < 4.1);\n    A = {1, 2, 3, 4, 5, 6, 8, 9, 10};\n\
    \    set<int> st = {1, 2, 3, 4, 5, 6, 8, 9, 10};\n    assert(lib::search.bi_le_cnt(A,\
    \ 7ll) == 6);\n    assert(lib::search.bi_le_val(A, 7ll) == 6);\n    assert(lib::search.bi_le_val(A,\
    \ 0ll) == -INF);\n    assert(lib::search.bi_le_val(st, 7ll) == 6);\n    assert(lib::search.bi_le_val(st,\
    \ 0ll) == -INF);\n    assert(lib::search.bi_ge_cnt(A, 7ll) == 3);\n    assert(lib::search.bi_ge_val(A,\
    \ 7ll) == 8);\n    assert(lib::search.bi_ge_val(A, 11ll) == INF);\n    assert(lib::search.bi_ge_val(st,\
    \ 7ll) == 8);\n    assert(lib::search.bi_ge_val(st, 11ll) == INF);\n    assert(lib::search.bi_lt_cnt(A,\
    \ 7ll) == 6);\n    assert(lib::search.bi_lt_val(A, 7ll) == 6);\n    assert(lib::search.bi_lt_val(A,\
    \ 0ll) == -INF);\n    assert(lib::search.bi_lt_val(st, 7ll) == 6);\n    assert(lib::search.bi_lt_val(st,\
    \ 0ll) == -INF);\n    assert(lib::search.bi_gt_cnt(A, 7ll) == 3);\n    assert(lib::search.bi_gt_val(A,\
    \ 7ll) == 8);\n    assert(lib::search.bi_gt_val(A, 11ll) == INF);\n    assert(lib::search.bi_gt_val(st,\
    \ 7ll) == 8);\n    assert(lib::search.bi_gt_val(st, 11ll) == INF);\n}\n// =====\
    \ template/util/grid.hpp =====\nvoid test_grid() {\n    vector<vector<int>> G\
    \ = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};\n    auto T = lib::grid.transpose(G);\n\
    \    vector<vector<int>> exp_tx = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};\n    assert(T\
    \ == exp_tx);\n    int cnt = 0;\n    auto f = [&](int y, int x) {\n        if\
    \ (G[y][x] == 5) ++cnt;\n    };\n    lib::grid.bfs(G, f);\n    assert(cnt == 4);\n\
    \    cnt = 0;\n    lib::grid.bfs8(G, f);\n    assert(cnt == 8);\n}\n// ===== template/util/gepmetry.hpp\
    \ =====\nvoid test_geometry() {\n    assert(lib::geo.rad_to_deg(lib::geo.deg_to_rad(45))\
    \ == 45);\n    assert(lib::geo.rad_to_deg(lib::geo.deg_to_rad(361)) <\n      \
    \     361); // \u8AA4\u5DEE\u304C\u3042\u308B\u306E\u3067\u4E0D\u7B49\u5F0F\n\
    \    assert(lib::geo.arc_tan(24, 35) < 0.97);\n    assert(lib::geo.area_triangle(1,\
    \ 1, 2, 3, 5, 6) == 1.5);\n    assert(lib::geo.area_square(1, 1, 2, 2, 4, 4, 7,\
    \ 7) == 15);\n}\nvoid solve() {\n    // URL\u306E\u554F\u984C\u306E\u7B54\u3048\
    \u306F\u3053\u308C\u3060\u3051\n    print(\"Hello World\");\n    test_number();\n\
    \    test_string();\n    test_sequence();\n    test_search();\n    test_grid();\n\
    \    test_geometry();\n}\n"
  dependsOn:
  - template/template.hpp
  - bits/stdc++.h
  - template/def/common.hpp
  - template/def/io.hpp
  - template/def/type.hpp
  - template/def/const.hpp
  - template/util/number.hpp
  - template/util/string.hpp
  - template/util/sequence.hpp
  - template/util/search.hpp
  - template/util/grid.hpp
  - template/util/geometry.hpp
  isVerificationFile: true
  path: tests/util.test.cpp
  requiredBy: []
  timestamp: '2026-01-06 20:15:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/util.test.cpp
layout: document
redirect_from:
- /verify/tests/util.test.cpp
- /verify/tests/util.test.cpp.html
title: "template/util/xxx.hpp\u306E\u30E6\u30CB\u30C3\u30C8\u30C6\u30B9\u30C8"
---
