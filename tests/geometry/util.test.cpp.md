---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/geometry/util.hpp
    title: "\u5E7E\u4F55Util"
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
    document_title: "\u5E7E\u4F55Util\u306E\u30C6\u30B9\u30C8"
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
    \n#include \"template/template.hpp\"\n#include \"library/geometry/util.hpp\"\n\
    void test_util() {\n    // degree / radian\n    assert(abs(deg_to_rad(180.0) -\
    \ PI) < 1e-9);\n    assert(abs(rad_to_deg(PI / 2.0) - 90.0) < 1e-9);\n    // arc_tan\
    \ (y, x) \u306E\u9806\n    assert(abs(arc_tan(1.0, 1.0) - (PI / 4.0)) < 1e-9);\n\
    }\n/**\n * @brief \u5E7E\u4F55Util\u306E\u30C6\u30B9\u30C8\n */\nvoid solve()\
    \ {\n    print(\"Hello World\");\n    test_util();\n}\n"
  dependsOn:
  - template/template.hpp
  - library/geometry/util.hpp
  isVerificationFile: true
  path: tests/geometry/util.test.cpp
  requiredBy: []
  timestamp: '2026-01-15 11:46:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/geometry/util.test.cpp
layout: document
redirect_from:
- /verify/tests/geometry/util.test.cpp
- /verify/tests/geometry/util.test.cpp.html
title: "\u5E7E\u4F55Util\u306E\u30C6\u30B9\u30C8"
---
