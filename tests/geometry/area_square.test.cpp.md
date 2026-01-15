---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/geometry/area_square.hpp
    title: "\u56DB\u89D2\u5F62\u306E\u9762\u7A4D"
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
    document_title: "\u56DB\u89D2\u5F62\u306E\u9762\u7A4D\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/geometry/area_square.hpp\"\
    \n// \u6D6E\u52D5\u5C0F\u6570\u70B9\u306E\u6BD4\u8F03\u7528\u30D8\u30EB\u30D1\u30FC\
    \nbool is_near(double a, double b, double epsilon = 1e-9) {\n    return abs(a\
    \ - b) < epsilon;\n}\nvoid test_area_square() {\n    // \u30B1\u30FC\u30B91: \u5358\
    \u4F4D\u6B63\u65B9\u5F62 (0,1), (1,1), (1,0), (0,0)\n    // \u5BFE\u89D2\u7DDA\
    1: (0,1) to (1,0) -> \u9577\u3055 \u221A2\n    // \u5BFE\u89D2\u7DDA2: (1,1) to\
    \ (0,0) -> \u9577\u3055 \u221A2\n    // \u9762\u7A4D: (\u221A2 * \u221A2) / 2\
    \ = 1.0\n    assert(is_near(area_square(0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0),\
    \ 1.0));\n    // \u30B1\u30FC\u30B92: \u3072\u3057\u5F62 (0,2), (1,0), (0,-2),\
    \ (-1,0)\n    // \u5BFE\u89D2\u7DDA1: (0,2) to (0,-2) -> \u9577\u3055 4\n    //\
    \ \u5BFE\u89D2\u7DDA2: (1,0) to (-1,0) -> \u9577\u3055 2\n    // \u9762\u7A4D\
    : (4 * 2) / 2 = 4.0\n    assert(is_near(area_square(0, 2, 1, 0, 0, -2, -1, 0),\
    \ 4.0));\n    // \u30B1\u30FC\u30B93: 1\u8FBA\u304C3\u306E\u6B63\u65B9\u5F62 (\u56DE\
    \u8EE2\u306A\u3057)\n    // (0,3), (3,3), (3,0), (0,0)\n    // \u9762\u7A4D: 3\
    \ * 3 = 9.0\n    assert(is_near(area_square(0, 3, 3, 3, 3, 0, 0, 0), 9.0));\n\
    \    // \u30B1\u30FC\u30B94: \u9762\u7A4D0 (\u5168\u3066\u306E\u70B9\u304C\u539F\
    \u70B9)\n    assert(is_near(area_square(0, 0, 0, 0, 0, 0, 0, 0), 0.0));\n}\n/**\n\
    \ * @brief \u56DB\u89D2\u5F62\u306E\u9762\u7A4D\u306E\u30C6\u30B9\u30C8\n */\n\
    void solve() {\n    print(\"Hello World\");\n    test_area_square();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/geometry/area_square.hpp
  isVerificationFile: true
  path: tests/geometry/area_square.test.cpp
  requiredBy: []
  timestamp: '2026-01-15 11:05:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/geometry/area_square.test.cpp
layout: document
redirect_from:
- /verify/tests/geometry/area_square.test.cpp
- /verify/tests/geometry/area_square.test.cpp.html
title: "\u56DB\u89D2\u5F62\u306E\u9762\u7A4D\u306E\u30C6\u30B9\u30C8"
---
