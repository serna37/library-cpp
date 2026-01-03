---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: bundle.cpp
    title: "\u30D0\u30F3\u30C9\u30EB\u5F8C\u306E\u30B5\u30F3\u30D7\u30EB"
  - icon: ':warning:'
    path: main.cpp
    title: "main\u30D5\u30A1\u30A4\u30EB"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u0E05^>\u03C9<^\u0E05"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/struct.dual_segment_tree.test.cpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/struct.fenwick_tree.test.cpp
    title: "Fenwick Tree\u306E\u30C6\u30B9\u30C8:RSQ"
  - icon: ':heavy_check_mark:'
    path: tests/struct.lazy_segment_tree.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ RUQ"
  - icon: ':heavy_check_mark:'
    path: tests/struct.segment_tree.test.cpp
    title: "\u30BB\u30B0\u6728\u306E\u30C6\u30B9\u30C8:RMQ"
  - icon: ':heavy_check_mark:'
    path: tests/struct.union_find.test.cpp
    title: "Union Find\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: tests/template.test.cpp
    title: "library/util/xxx.hpp\u306E\u30E6\u30CB\u30C3\u30C8\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30AB\u30B9\u30BF\u30E0stdc++.h"
    links:
    - http://www.gnu.org/licenses/>.
  bundledCode: "#line 1 \"bits/stdc++.h\"\n// C++ includes used for precompiling -*-\
    \ C++ -*-\n// Copyright (C) 2003-2023 Free Software Foundation, Inc.\n//\n// This\
    \ file is part of the GNU ISO C++ Library.  This library is free\n// software;\
    \ you can redistribute it and/or modify it under the\n// terms of the GNU General\
    \ Public License as published by the\n// Free Software Foundation; either version\
    \ 3, or (at your option)\n// any later version.\n// This library is distributed\
    \ in the hope that it will be useful,\n// but WITHOUT ANY WARRANTY; without even\
    \ the implied warranty of\n// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\
    \  See the\n// GNU General Public License for more details.\n// Under Section\
    \ 7 of GPL version 3, you are granted additional\n// permissions described in\
    \ the GCC Runtime Library Exception, version\n// 3.1, as published by the Free\
    \ Software Foundation.\n// You should have received a copy of the GNU General\
    \ Public License and\n// a copy of the GCC Runtime Library Exception along with\
    \ this program;\n// see the files COPYING3 and COPYING.RUNTIME respectively. \
    \ If not, see\n// <http://www.gnu.org/licenses/>.\n/** @file stdc++.h\n *  This\
    \ is an implementation file for a precompiled header.\n */\n/**\n * @brief \u30AB\
    \u30B9\u30BF\u30E0stdc++.h\n */\n#include <algorithm>\n#include <bitset>\n#include\
    \ <complex>\n#include <deque>\n#include <iomanip>\n#include <iostream>\n#include\
    \ <limits.h>\n#include <map>\n#include <math.h>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <sstream>\n#include <stack>\n#include <string>\n\
    #include <tuple>\n#include <unordered_map>\n#include <unordered_set>\n#include\
    \ <utility>\n#include <vector>\n#include <array>\n#include <cassert>\n#include\
    \ <random>\n#include <chrono>\n\n"
  code: "// C++ includes used for precompiling -*- C++ -*-\n// Copyright (C) 2003-2023\
    \ Free Software Foundation, Inc.\n//\n// This file is part of the GNU ISO C++\
    \ Library.  This library is free\n// software; you can redistribute it and/or\
    \ modify it under the\n// terms of the GNU General Public License as published\
    \ by the\n// Free Software Foundation; either version 3, or (at your option)\n\
    // any later version.\n// This library is distributed in the hope that it will\
    \ be useful,\n// but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
    // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n// GNU General\
    \ Public License for more details.\n// Under Section 7 of GPL version 3, you are\
    \ granted additional\n// permissions described in the GCC Runtime Library Exception,\
    \ version\n// 3.1, as published by the Free Software Foundation.\n// You should\
    \ have received a copy of the GNU General Public License and\n// a copy of the\
    \ GCC Runtime Library Exception along with this program;\n// see the files COPYING3\
    \ and COPYING.RUNTIME respectively.  If not, see\n// <http://www.gnu.org/licenses/>.\n\
    /** @file stdc++.h\n *  This is an implementation file for a precompiled header.\n\
    \ */\n/**\n * @brief \u30AB\u30B9\u30BF\u30E0stdc++.h\n */\n#include <algorithm>\n\
    #include <bitset>\n#include <complex>\n#include <deque>\n#include <iomanip>\n\
    #include <iostream>\n#include <limits.h>\n#include <map>\n#include <math.h>\n\
    #include <numeric>\n#include <queue>\n#include <set>\n#include <sstream>\n#include\
    \ <stack>\n#include <string>\n#include <tuple>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#include <utility>\n#include <vector>\n#include <array>\n#include\
    \ <cassert>\n#include <random>\n#include <chrono>\n\n"
  dependsOn: []
  isVerificationFile: false
  path: bits/stdc++.h
  requiredBy:
  - template/template.hpp
  - main.cpp
  - bundle.cpp
  timestamp: '2026-01-03 22:01:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/struct.lazy_segment_tree.test.cpp
  - tests/struct.fenwick_tree.test.cpp
  - tests/template.test.cpp
  - tests/struct.dual_segment_tree.test.cpp
  - tests/struct.segment_tree.test.cpp
  - tests/struct.union_find.test.cpp
documentation_of: bits/stdc++.h
layout: document
redirect_from:
- /library/bits/stdc++.h
- /library/bits/stdc++.h.html
title: "\u30AB\u30B9\u30BF\u30E0stdc++.h"
---
