---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/geometry/area_square.hpp
    title: "\u56DB\u89D2\u5F62\u306E\u9762\u7A4D"
  - icon: ':heavy_check_mark:'
    path: library/geometry/area_triangle.hpp
    title: "\u4E09\u89D2\u5F62\u306E\u9762\u7A4D"
  - icon: ':heavy_check_mark:'
    path: library/geometry/util.hpp
    title: "\u5E7E\u4F55Util"
  - icon: ':heavy_check_mark:'
    path: library/sequence/collection_util.hpp
    title: "\u914D\u5217\u7CFBUtil"
  - icon: ':heavy_check_mark:'
    path: library/string/util.hpp
    title: "\u6587\u5B57\u5217Util"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/util/util.hpp\"\n/** ----- start include utility\
    \ ----- */\n#line 2 \"library/sequence/collection_util.hpp\"\nclass CollectionUtil\
    \ {\npublic:\n  template <typename T> T min(const vector<T> &v) {\n    return\
    \ *min_element(v.begin(), v.end());\n  }\n  template <typename T> T max(const\
    \ vector<T> &v) {\n    return *max_element(v.begin(), v.end());\n  }\n  template\
    \ <typename T> long long sum(const vector<T> &v) {\n    return accumulate(v.begin(),\
    \ v.end(), 0ll);\n  }\n  template <typename T, typename F> bool all_match(const\
    \ vector<T> &v, F f) {\n    bool b = true;\n    for (int i = 0; i < (int)v.size();\
    \ ++i) b &= f(v[i], i);\n    return b;\n  }\n  template <typename T, typename\
    \ F> bool none_match(const vector<T> &v, F f) {\n    return !any_match(v, f);\n\
    \  }\n  template <typename T, typename F> bool any_match(const vector<T> &v, F\
    \ f) {\n    bool b = false;\n    for (int i = 0; i < (int)v.size(); ++i) b |=\
    \ f(v[i], i);\n    return b;\n  }\n  template <typename T> void distinct(vector<T>\
    \ &v) {\n    sort(v.begin(), v.end());\n    v.erase(unique(v.begin(), v.end()),\
    \ v.end());\n  }\n  template <typename T> void asc(vector<T> &v) { sort(v.begin(),\
    \ v.end()); }\n  template <typename T> void desc(vector<T> &v) { sort(v.rbegin(),\
    \ v.rend()); }\n  template <typename T> void reverse(vector<T> &v) { std::reverse(v.begin(),\
    \ v.end()); }\n  template <typename T> void sequence(vector<T> &v, T start = 0)\
    \ {\n    iota(v.begin(), v.end(), start);\n  }\n  template <typename T> void erase(set<T>\
    \ &st, const T &v) {\n    st.erase(st.find(v));\n  }\n  template <typename T>\
    \ void erase(multiset<T> &st, const T &v) {\n    st.erase(st.find(v));\n  }\n\
    } collection;\n#line 2 \"library/string/util.hpp\"\nstring string_to_lower(string\
    \ s) {\n  std::transform(s.begin(), s.end(), s.begin(), ::tolower);\n  return\
    \ s;\n}\nstring string_to_upper(string s) {\n  std::transform(s.begin(), s.end(),\
    \ s.begin(), ::toupper);\n  return s;\n}\nbool char_is_lower(char c) { // bool\u3067\
    \u8FD4\u3059\n  return islower(c) != 0;\n}\nbool char_is_upper(char c) { // bool\u3067\
    \u8FD4\u3059\n  return isupper(c) != 0;\n}\n#line 2 \"library/geometry/util.hpp\"\
    \ndouble deg_to_rad(double d) { // \u5EA6\u6570\u6CD5 \u2192 \u5F27\u5EA6\u6CD5\
    \n  return d * PI / 180;\n}\ndouble rad_to_deg(double r) { // \u5F27\u5EA6\u6CD5\
    \ \u2192 \u5EA6\u6570\u6CD5\n  return r * 180 / PI;\n}\ndouble arc_tan(double\
    \ x, double y) { // \u504F\u89D2\u3092\u30E9\u30B8\u30A2\u30F3\u3067\u8FD4\u3059\
    \n  return atan2(y, x);\n}\n#line 2 \"library/geometry/area_square.hpp\"\ntemplate\
    \ <typename T>\ndouble area_square(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T\
    \ y4) {\n  return hypot(x1 - x3, y1 - y3) * hypot(x2 - x4, y2 - y4) / 2.0;\n}\n\
    #line 2 \"library/geometry/area_triangle.hpp\"\ntemplate <typename T> double area_triangle(T\
    \ x1, T y1, T x2, T y2, T x3, T y3) {\n  return abs((x2 - x1) * (y3 - y1) - (x3\
    \ - x1) * (y2 - y1)) / 2.0;\n}\n#line 7 \"library/util/util.hpp\"\n/** ----- end\
    \ include utility ----- */\n"
  code: '/** ----- start include utility ----- */

    #include "library/sequence/collection_util.hpp"

    #include "library/string/util.hpp"

    #include "library/geometry/util.hpp"

    #include "library/geometry/area_square.hpp"

    #include "library/geometry/area_triangle.hpp"

    /** ----- end include utility ----- */'
  dependsOn:
  - library/sequence/collection_util.hpp
  - library/string/util.hpp
  - library/geometry/util.hpp
  - library/geometry/area_square.hpp
  - library/geometry/area_triangle.hpp
  isVerificationFile: false
  path: library/util/util.hpp
  requiredBy: []
  timestamp: '2026-08-08 21:09:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/util/util.hpp
layout: document
redirect_from:
- /library/library/util/util.hpp
- /library/library/util/util.hpp.html
title: library/util/util.hpp
---
