---
data:
  _extendedDependsOn:
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
    document_title: "template\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\nvoid test_conversions() {\n    // int_to_char\n\
    \    assert(int_to_char(4) == '4');\n    assert(int_to_char(0) == '0');\n    //\
    \ int_to_alph\n    assert(int_to_alph(0) == 'a');\n    assert(int_to_alph(25)\
    \ == 'z');\n    // char_to_int\n    assert(char_to_int('7') == 7);\n    assert(char_to_int('0')\
    \ == 0);\n    // int_to_string\n    assert(int_to_string(123LL) == \"123\");\n\
    \    assert(int_to_string(-45LL) == \"-45\");\n    // string_to_int\n    assert(string_to_int(\"\
    9876543210\") == 9876543210LL);\n}\nvoid test_string_manipulation() {\n    //\
    \ string_to_lower\n    assert(string_to_lower(\"AbC12\") == \"abc12\");\n    //\
    \ string_to_upper\n    assert(string_to_upper(\"abc12\") == \"ABC12\");\n    //\
    \ char_is_lower / upper\n    assert(char_is_lower('a') == true);\n    assert(char_is_lower('A')\
    \ == false);\n    assert(char_is_upper('Z') == true);\n    assert(char_is_upper('z')\
    \ == false);\n}\nvoid test_math_functions() {\n    // div_ceil (a/b \u3067\u5207\
    \u308A\u4E0A\u3052)\n    assert(div_ceil(10, 3) == 4);\n    assert(div_ceil(10,\
    \ 5) == 2);\n    assert(div_ceil(-10, 3) == -3); // 0\u65B9\u5411\u3067\u306F\u306A\
    \u304F\u8CA0\u306E\u7121\u9650\u5927\u65B9\u5411\u3078\u306E\u5207\u308A\u4E0A\
    \u3052\n    // div_floor (a/b \u3067\u5207\u308A\u6368\u3066)\n    assert(div_floor(10,\
    \ 3) == 3);\n    assert(div_floor(-10, 3) == -4);\n    // degree / radian\n  \
    \  assert(abs(deg_to_rad(180.0) - PI) < 1e-9);\n    assert(abs(rad_to_deg(PI /\
    \ 2.0) - 90.0) < 1e-9);\n    // arc_tan (y, x) \u306E\u9806\n    assert(abs(arc_tan(1.0,\
    \ 1.0) - (PI / 4.0)) < 1e-9);\n}\nvoid test_collection_class() {\n    vector<int>\
    \ v = {3, 1, 4, 1, 5};\n    // min / max / sum\n    assert(collection.min(v) ==\
    \ 1);\n    assert(collection.max(v) == 5);\n    assert(collection.sum(v) == 14);\n\
    \    // match\u7CFB (\u5F15\u6570: \u5024, \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    )\n    assert(collection.all_match(v, [](int x, int _) { return x > 0; }) == true);\n\
    \    assert(collection.any_match(v, [](int x, int _) { return x == 5; }) ==\n\
    \           true);\n    assert(collection.none_match(v, [](int x, int _) { return\
    \ x == 100; }) ==\n           true);\n    // sorting / distinct\n    vector<int>\
    \ v2 = {3, 1, 2, 1};\n    collection.asc(v2);\n    assert(v2 == vector<int>({1,\
    \ 1, 2, 3}));\n    collection.distinct(v2);\n    assert(v2 == vector<int>({1,\
    \ 2, 3}));\n    collection.desc(v2);\n    assert(v2 == vector<int>({3, 2, 1}));\n\
    \    collection.reverse(v2);\n    assert(v2 == vector<int>({1, 2, 3}));\n    //\
    \ sequence\n    vector<int> v3(3);\n    collection.sequence(v3, 10ll); // 10,\
    \ 11, 12\n    assert(v3[0] == 10 && v3[2] == 12);\n    // erase (set / multiset)\n\
    \    multiset<int> ms = {1, 2, 2, 3};\n    collection.erase(ms, 2ll); // 1\u3064\
    \u3060\u3051\u6D88\u3059\u306F\u305A\n    assert(ms.count(2) == 1);\n}\n/**\n\
    \ * @brief template\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n    print(\"\
    Hello World\");\n    test_conversions();\n    test_string_manipulation();\n  \
    \  test_math_functions();\n    test_collection_class();\n}\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: true
  path: tests/template.test.cpp
  requiredBy: []
  timestamp: '2026-01-12 21:09:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/template.test.cpp
layout: document
redirect_from:
- /verify/tests/template.test.cpp
- /verify/tests/template.test.cpp.html
title: "template\u306E\u30C6\u30B9\u30C8"
---
