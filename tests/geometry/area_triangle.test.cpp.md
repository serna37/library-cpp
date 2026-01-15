---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/geometry/area_triangle.hpp
    title: "\u4E09\u89D2\u5F62\u306E\u9762\u7A4D"
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
    document_title: "\u4E09\u89D2\u5F62\u306E\u9762\u7A4D\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/geometry/area_triangle.hpp\"\
    \n// \u6D6E\u52D5\u5C0F\u6570\u70B9\u306E\u6BD4\u8F03\u7528\u30D8\u30EB\u30D1\u30FC\
    \nbool is_near(double a, double b, double epsilon = 1e-9) {\n    return abs(a\
    \ - b) < epsilon;\n}\nvoid test_area_triangle() {\n    // \u30B1\u30FC\u30B91:\
    \ \u5E95\u8FBA2\u3001\u9AD8\u30551\u306E\u76F4\u89D2\u4E09\u89D2\u5F62\n    //\
    \ (0,0), (2,0), (0,1) -> \u9762\u7A4D: 2 * 1 / 2 = 1.0\n    assert(is_near(area_triangle(0,\
    \ 0, 2, 0, 0, 1), 1.0));\n    // \u30B1\u30FC\u30B92: \u5358\u4F4D\u6B63\u65B9\
    \u5F62\u306E\u534A\u5206 (45\u5EA6\u306E\u76F4\u89D2\u4E8C\u7B49\u8FBA\u4E09\u89D2\
    \u5F62)\n    // (0,0), (1,0), (0,1) -> \u9762\u7A4D: 0.5\n    assert(is_near(area_triangle(0.0,\
    \ 0.0, 1.0, 0.0, 0.0, 1.0), 0.5));\n    // \u30B1\u30FC\u30B93: \u5EA7\u6A19\u304C\
    \u8CA0\u306E\u30B1\u30FC\u30B9\n    // (-1,-1), (1,-1), (0,1) -> \u5E95\u8FBA\
    2, \u9AD8\u30552 -> \u9762\u7A4D: 2 * 2 / 2 = 2.0\n    assert(is_near(area_triangle(-1,\
    \ -1, 1, -1, 0, 1), 2.0));\n    // \u30B1\u30FC\u30B94: 3\u70B9\u304C\u4E00\u76F4\
    \u7DDA\u4E0A\u306B\u3042\u308B\u5834\u5408\uFF08\u9762\u7A4D0\uFF09\n    // (0,0),\
    \ (1,1), (2,2)\n    assert(is_near(area_triangle(0, 0, 1, 1, 2, 2), 0.0));\n \
    \   // \u30B1\u30FC\u30B95: \u5927\u304D\u306A\u5024\u306E\u8A08\u7B97\n    //\
    \ (0,0), (100,0), (0,100) -> \u9762\u7A4D: 100 * 100 / 2 = 5000.0\n    assert(is_near(area_triangle(0,\
    \ 0, 100, 0, 0, 100), 5000.0));\n}\n/**\n * @brief \u4E09\u89D2\u5F62\u306E\u9762\
    \u7A4D\u306E\u30C6\u30B9\u30C8\n */\nvoid solve() {\n    print(\"Hello World\"\
    );\n    test_area_triangle();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/geometry/area_triangle.hpp
  isVerificationFile: true
  path: tests/geometry/area_triangle.test.cpp
  requiredBy: []
  timestamp: '2026-01-15 11:46:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/geometry/area_triangle.test.cpp
layout: document
redirect_from:
- /verify/tests/geometry/area_triangle.test.cpp
- /verify/tests/geometry/area_triangle.test.cpp.html
title: "\u4E09\u89D2\u5F62\u306E\u9762\u7A4D\u306E\u30C6\u30B9\u30C8"
---
