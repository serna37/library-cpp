---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "library/util/xxx.hpp\u306E\u30E6\u30CB\u30C3\u30C8\u30C6\u30B9\
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
    \n#include \"template/template.hpp\"\n/**\n * @brief library/util/xxx.hpp\u306E\
    \u30E6\u30CB\u30C3\u30C8\u30C6\u30B9\u30C8\n * \u51FA\u529B\u3059\u308B\u3068\u554F\
    \u984C\u306B\u6B63\u89E3\u3067\u304D\u306A\u3044\u306E\u3067assert\u306E\u307F\
    \n */\n// ===== library/util/number.hpp =====\n#include \"library/util/number.hpp\"\
    \nvoid test_number() {\n    Number num;\n    assert(num.div_ceil(10, 2) == 5);\n\
    \    assert(num.div_ceil(11, 2) == 6);\n    assert(num.div_floor(10, 2) == 5);\n\
    \    assert(num.div_floor(11, 2) == 5);\n    assert(num.factorial(0) == 1);\n\
    \    assert(num.factorial(1) == 1);\n    assert(num.factorial(2) == 2);\n    assert(num.factorial(3)\
    \ == 6);\n    assert(num.combination(0, 0) == 1);\n    assert(num.combination(1,\
    \ 0) == 1);\n    assert(num.combination(1, 1) == 1);\n    assert(num.combination(2,\
    \ 0) == 1);\n    assert(num.combination(3, 2) == 3);\n    assert(num.digit_sum(1234)\
    \ == 10);\n    assert(num.base_convert(\"1001\", 2, 10) == \"9\");\n    vector<int>\
    \ val_divisors = num.divisors(12);\n    sort(all(val_divisors));\n    vector<int>\
    \ exp_divisors = {1, 2, 3, 4, 6, 12};\n    assert(val_divisors == exp_divisors);\n\
    \    assert(num.prime_test(57) == false); // Grothendieck\n    assert(num.prime_test(97)\
    \ == true);\n    map<int, int> val_prime_fact = num.prime_fact(100);\n    map<int,\
    \ int> exp_prime_fact = {{2, 2}, {5, 2}};\n    assert(val_prime_fact == exp_prime_fact);\n\
    \    assert(num.modpow(2, 10, MOD) == 1024);\n    assert(num.modinv(2, MOD) ==\
    \ 499122177);\n    assert(num.modfact(10, MOD) == 3628800);\n    assert(num.mod_combination(10,\
    \ 5, MOD) == 252);\n}\n// ===== library/util/string.hpp =====\n#include \"library/util/string.hpp\"\
    \nvoid test_string() {\n    String str;\n    assert(str.is_low('A') == false);\n\
    \    assert(str.is_low('a') == true);\n    assert(str.is_upp('A') == true);\n\
    \    assert(str.is_upp('a') == false);\n    assert(str.transform_lower(\"AbC\"\
    ) == \"abc\");\n    assert(str.transform_upper(\"AbC\") == \"ABC\");\n    vector<string>\
    \ val_join = {\"aa\", \"bb\", \"cc\"};\n    assert(str.join(val_join, \",\") ==\
    \ \"aa,bb,cc\");\n    vector<int> exp_finds = {0, 3, 6, 9};\n    assert(str.finds(\"\
    abcaefahia\", \"a\") == exp_finds);\n    vector<string> exp_split = {\"aa\", \"\
    bb\", \"cc\"};\n    assert(str.split(\"aa,bb,cc\", ',') == exp_split);\n    assert(str.split_multi(\"\
    aa,bb/cc\", \",/\") == exp_split);\n    assert(str.str_range(\"abc123abc\", 3,\
    \ 6) == \"123a\");\n    vector<pair<char, int>> exp_runlen = {{'a', 3}, {'b',\
    \ 2}, {'c', 1}};\n    assert(str.run_length(\"aaabbc\") == exp_runlen);\n}\n//\
    \ ===== library/util/sequence.hpp =====\n#include \"library/util/sequence.hpp\"\
    \nvoid test_sequence() {\n    Sequence seq;\n    vector<int> A = {1, 3, 2, 5,\
    \ 8, 13, 2, 9, 3, 5};\n    assert(seq.min(A) == 1);\n    assert(seq.max(A) ==\
    \ 13);\n    assert(seq.sum(A) == 51);\n    vector<int> evens = {0, 2, 4, 6};\n\
    \    vector<int> odds = {1, 3, 5, 7};\n    auto is_even = [](int x) { return x\
    \ % 2 == 0; };\n    assert(seq.all_match(evens, is_even));\n    assert(seq.none_match(odds,\
    \ is_even));\n    assert(seq.any_match(A, is_even));\n    vector<int> exp_distinct\
    \ = {1, 2, 3, 5, 8, 9, 13};\n    seq.distinct(A);\n    assert(A == exp_distinct);\n\
    \    A = {1, 3, 2, 5, 8, 13, 2, 9, 3, 5};\n    vector<int> exp_asc = {1, 2, 2,\
    \ 3, 3, 5, 5, 8, 9, 13};\n    seq.sort_asc(A);\n    assert(A == exp_asc);\n  \
    \  A = {1, 3, 2, 5, 8, 13, 2, 9, 3, 5};\n    vector<int> exp_desc = {13, 9, 8,\
    \ 5, 5, 3, 3, 2, 2, 1};\n    seq.sort_desc(A);\n    assert(A == exp_desc);\n \
    \   A = {1, 3, 2, 5, 8, 13, 2, 9, 3, 5};\n    vector<int> exp_rev = {5, 3, 9,\
    \ 2, 13, 8, 5, 2, 3, 1};\n    seq.reverse(A);\n    assert(A == exp_rev);\n   \
    \ set<int> st = {1, 2, 3, 4, 6, 7, 9, 11};\n    set<int> exp_erase = {1, 2, 3,\
    \ 6, 7, 9, 11};\n    seq.erase(st, 4ll);\n    assert(st == exp_erase);\n    multiset<int>\
    \ mst = {1, 2, 3, 4, 4, 4, 6, 7, 9, 11};\n    multiset<int> exp_merase = {1, 2,\
    \ 3, 4, 4, 6, 7, 9, 11};\n    seq.erase(mst, 4ll);\n    assert(mst == exp_merase);\n\
    \    A = {1, 2};\n    auto [a, b] = seq.unpack<2>(move(A));\n    assert(a == 1\
    \ and b == 2);\n    vector<int> val_renban(10);\n    vector<int> exp_renban =\
    \ {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};\n    seq.renban(val_renban);\n    assert(val_renban\
    \ == exp_renban);\n    A = {1, 2, 3};\n    vector<int> B = {1, 2, 3, 4, 5};\n\
    \    seq.merge(A, B);\n    vector<int> exp_merge_vec = {1, 2, 3, 4, 5, 1, 2, 3};\n\
    \    assert(B == exp_merge_vec);\n    set<int> stA = {1, 2, 3};\n    set<int>\
    \ stB = {1, 2, 3, 4, 5};\n    set<int> exp_merge_set = {1, 1, 2, 2, 3, 3, 4, 5};\n\
    \    seq.merge(stA, stB);\n    assert(stB == exp_merge_set);\n    map<int, int>\
    \ mpA = {{1, 1}, {2, 2}};\n    map<int, int> mpB = {{1, 1}, {2, 2}, {3, 3}};\n\
    \    auto mergeF = [&](map<int, int> &B, pair<int, int> v) {\n        return B[v.first]\
    \ += v.second;\n    };\n    seq.merge(mpA, mpB, mergeF);\n    map<int, int> exp_merge_map\
    \ = {{1, 2}, {2, 4}, {3, 3}};\n    assert(mpB == exp_merge_map);\n    A = {1,\
    \ 2, 2, 5, 6};\n    vector<int> val_coordinate = seq.coordinate(A);\n    vector<int>\
    \ exp_coordinate = {0, 1, 2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0};\n    for (int i =\
    \ 0; i < 10; ++i) {\n        assert(val_coordinate[i] == exp_coordinate[i]);\n\
    \    }\n    A = {1, 2, 2, 8, 10, 88};\n    int zip_cnt = seq.zip_coordinate(A);\n\
    \    assert(zip_cnt == 5);\n    vector<int> exp_zip = {0, 1, 1, 2, 3, 4};\n  \
    \  assert(A == exp_zip);\n    A = {1, 3, 9, 3, 8, 2, 99, 4};\n    int inv = seq.inversion_number(A);\n\
    \    assert(inv == 9);\n    A = {1, 2, 5, 8, 3, 2, 9};\n    vector<int> S = seq.zeta(A);\n\
    \    vector<int> exp_zeta = {0, 1, 3, 8, 16, 19, 21, 30};\n    assert(S == exp_zeta);\n\
    \    S = seq.zeta_rev(A);\n    vector<int> exp_zeta_rev = {30, 29, 27, 22, 14,\
    \ 11, 9, 0};\n    assert(S == exp_zeta_rev);\n    S = seq.zeta_diff(A);\n    vector<int>\
    \ exp_zeta_diff = {0, 0, 1, 1, 4, 4, 5, 5};\n    assert(S == exp_zeta_diff);\n\
    \    S = seq.zeta_rev_diff(A);\n    vector<int> exp_zeta_rev_diff = {15, 15, 12,\
    \ 12, 7, 7, 0, 0};\n    assert(S == exp_zeta_rev_diff);\n    vector<vector<int>>\
    \ G = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};\n    vector<vector<int>> S2 = seq.zeta_2D(G);\n\
    \    vector<vector<int>> exp_zeta_2D = {\n        {0, 0, 0, 0}, {0, 1, 3, 6},\
    \ {0, 5, 12, 21}, {0, 12, 27, 45}};\n    assert(S2 == exp_zeta_2D);\n    vector<vector<vector<int>>>\
    \ G3 = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},\n                                 \
    \     {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},\n                                   \
    \   {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};\n    auto S3 = seq.zeta_3D(G3);\n    vector<vector<vector<int>>>\
    \ exp_zeta_3D = {\n        {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,\
    \ 0}},\n        {{0, 0, 0, 0}, {0, 1, 3, 6}, {0, 5, 12, 21}, {0, 12, 27, 45}},\n\
    \        {{0, 0, 0, 0}, {0, 2, 6, 12}, {0, 10, 24, 42}, {0, 24, 54, 90}},\n  \
    \      {{0, 0, 0, 0}, {0, 3, 9, 18}, {0, 15, 36, 63}, {0, 36, 81, 135}}};\n  \
    \  assert(S3 == exp_zeta_3D);\n    vector<int> R = seq.moebius(A);\n    vector<int>\
    \ exp_moebius = {1, 3, 3, -5, -1, 7};\n    assert(R == exp_moebius);\n}\n// =====\
    \ library/util/search.hpp =====\n#include \"library/util/search.hpp\"\nvoid test_search()\
    \ {\n    Search search;\n    vector<int> A = {1, 2, 3};\n    vector<vector<int>>\
    \ val_perm;\n    vector<vector<int>> exp_perm = {{1, 2, 3}, {1, 3, 2}, {2, 1,\
    \ 3},\n                                    {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};\n\
    \    search.perm(A, [&]() { val_perm.push_back(A); });\n    assert(val_perm ==\
    \ exp_perm);\n    A = {1, 2, 3};\n    vector<vector<int>> val_bit = search.bit(A);\n\
    \    vector<vector<int>> exp_bit = {{},  {1},    {2},    {1, 2},\n           \
    \                        {3}, {1, 3}, {2, 3}, {1, 2, 3}};\n    assert(val_bit\
    \ == exp_bit);\n    auto [L, R] = search.bi([](int x) { return x >= 5; });\n \
    \   assert(L == 4 and R == 5);\n    auto [l, r] = search.bi_real([](int x) { return\
    \ x >= 3.5; });\n    assert(l < 4.1 and r < 4.1);\n    A = {1, 2, 3, 4, 5, 6,\
    \ 8, 9, 10};\n    set<int> st = {1, 2, 3, 4, 5, 6, 8, 9, 10};\n    assert(search.bi_le_cnt(A,\
    \ 7ll) == 6);\n    assert(search.bi_le_val(A, 7ll) == 6);\n    assert(search.bi_le_val(A,\
    \ 0ll) == -INF);\n    assert(search.bi_le_val(st, 7ll) == 6);\n    assert(search.bi_le_val(st,\
    \ 0ll) == -INF);\n    assert(search.bi_ge_cnt(A, 7ll) == 3);\n    assert(search.bi_ge_val(A,\
    \ 7ll) == 8);\n    assert(search.bi_ge_val(A, 11ll) == INF);\n    assert(search.bi_ge_val(st,\
    \ 7ll) == 8);\n    assert(search.bi_ge_val(st, 11ll) == INF);\n    assert(search.bi_lt_cnt(A,\
    \ 7ll) == 6);\n    assert(search.bi_lt_val(A, 7ll) == 6);\n    assert(search.bi_lt_val(A,\
    \ 0ll) == -INF);\n    assert(search.bi_lt_val(st, 7ll) == 6);\n    assert(search.bi_lt_val(st,\
    \ 0ll) == -INF);\n    assert(search.bi_gt_cnt(A, 7ll) == 3);\n    assert(search.bi_gt_val(A,\
    \ 7ll) == 8);\n    assert(search.bi_gt_val(A, 11ll) == INF);\n    assert(search.bi_gt_val(st,\
    \ 7ll) == 8);\n    assert(search.bi_gt_val(st, 11ll) == INF);\n}\n// ===== library/util/grid.hpp\
    \ =====\n#include \"library/util/grid.hpp\"\nvoid test_grid() {\n    Grid grid;\n\
    \    vector<vector<int>> G = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};\n    auto T =\
    \ grid.transpose(G);\n    vector<vector<int>> exp_tx = {{1, 4, 7}, {2, 5, 8},\
    \ {3, 6, 9}};\n    assert(T == exp_tx);\n    int cnt = 0;\n    auto f = [&](int\
    \ y, int x) {\n        if (G[y][x] == 5) ++cnt;\n    };\n    grid.bfs(G, f);\n\
    \    assert(cnt == 4);\n    cnt = 0;\n    grid.bfs8(G, f);\n    assert(cnt ==\
    \ 8);\n}\n// ===== library/util/geometry.hpp =====\n#include \"library/util/geometry.hpp\"\
    \nvoid test_geometry() {\n    Geometry geo;\n    assert(geo.rad_to_deg(geo.deg_to_rad(45))\
    \ == 45);\n    assert(geo.rad_to_deg(geo.deg_to_rad(361)) < 361); // \u8AA4\u5DEE\
    \u304C\u3042\u308B\u306E\u3067\u4E0D\u7B49\u5F0F\n    assert(geo.arc_tan(24, 35)\
    \ < 0.97);\n    assert(geo.area_triangle(1, 1, 2, 3, 5, 6) == 1.5);\n    assert(geo.area_square(1,\
    \ 1, 2, 2, 4, 4, 7, 7) == 15);\n}\nvoid solve() {\n    // URL\u306E\u554F\u984C\
    \u306E\u7B54\u3048\u306F\u3053\u308C\u3060\u3051\n    print(\"Hello World\");\n\
    \    test_number();\n    test_string();\n    test_sequence();\n    test_search();\n\
    \    test_grid();\n    test_geometry();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: tests/util.testXXXX.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tests/util.testXXXX.cpp
layout: document
redirect_from:
- /library/tests/util.testXXXX.cpp
- /library/tests/util.testXXXX.cpp.html
title: "library/util/xxx.hpp\u306E\u30E6\u30CB\u30C3\u30C8\u30C6\u30B9\u30C8"
---
