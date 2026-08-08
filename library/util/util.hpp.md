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
    path: library/number/base_convert.hpp
    title: "\u9032\u6570\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: library/number/combination.hpp
    title: "\u7D44\u307F\u5408\u308F\u305B nCk"
  - icon: ':heavy_check_mark:'
    path: library/number/div.hpp
    title: "\u5272\u308A\u7B97"
  - icon: ':heavy_check_mark:'
    path: library/number/divisors.hpp
    title: "\u7D04\u6570\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: library/number/ext_gcd.hpp
    title: "\u62E1\u5F35Euclid\u306E\u4E92\u9664\u6CD5"
  - icon: ':heavy_check_mark:'
    path: library/number/factorial.hpp
    title: "\u968E\u4E57"
  - icon: ':heavy_check_mark:'
    path: library/number/prime/prime_fact.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: library/number/prime/prime_test.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: library/sequence/collection_util.hpp
    title: "\u914D\u5217\u7CFBUtil"
  - icon: ':heavy_check_mark:'
    path: library/string/run_length.hpp
    title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E"
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
    \u8FD4\u3059\n  return isupper(c) != 0;\n}\n#line 2 \"library/string/run_length.hpp\"\
    \nvector<pair<char, int>> run_length(const string &S) {\n  vector<pair<char, int>>\
    \ res;\n  for (auto &&x : S) {\n    if (res.empty() or res.back().first != x)\
    \ res.emplace_back(x, 0);\n    ++res.back().second;\n  }\n  return res;\n}\n#line\
    \ 2 \"library/geometry/util.hpp\"\ndouble deg_to_rad(double d) { // \u5EA6\u6570\
    \u6CD5 \u2192 \u5F27\u5EA6\u6CD5\n  return d * PI / 180;\n}\ndouble rad_to_deg(double\
    \ r) { // \u5F27\u5EA6\u6CD5 \u2192 \u5EA6\u6570\u6CD5\n  return r * 180 / PI;\n\
    }\ndouble arc_tan(double x, double y) { // \u504F\u89D2\u3092\u30E9\u30B8\u30A2\
    \u30F3\u3067\u8FD4\u3059\n  return atan2(y, x);\n}\n#line 2 \"library/geometry/area_square.hpp\"\
    \ntemplate <typename T>\ndouble area_square(T x1, T y1, T x2, T y2, T x3, T y3,\
    \ T x4, T y4) {\n  return hypot(x1 - x3, y1 - y3) * hypot(x2 - x4, y2 - y4) /\
    \ 2.0;\n}\n#line 2 \"library/geometry/area_triangle.hpp\"\ntemplate <typename\
    \ T> double area_triangle(T x1, T y1, T x2, T y2, T x3, T y3) {\n  return abs((x2\
    \ - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2.0;\n}\n#line 2 \"library/number/div.hpp\"\
    \nlong long div_ceil(long long a, long long b) { // \u8CA0\u306E\u5834\u54080\u5074\
    \u3078\u4E38\u3081\u306A\u3044\n  return a / b + (((a ^ b) > 0 and a % b != 0)\
    \ ? 1 : 0);\n}\nlong long div_floor(long long a, long long b) { // \u8CA0\u306E\
    \u5834\u54080\u5074\u3078\u4E38\u3081\u306A\u3044\n  return a / b - (((a ^ b)\
    \ < 0 and a % b != 0) ? 1 : 0);\n}\n#line 2 \"library/number/divisors.hpp\"\n\
    vector<int> divisors(int N) {\n  vector<int> res;\n  for (int i = 1; i * i <=\
    \ N; ++i) {\n    if (N % i != 0) continue;\n    res.push_back(i);\n    if (N /\
    \ i != i) res.push_back(N / i);\n  }\n  return res;\n}\n#line 2 \"library/number/ext_gcd.hpp\"\
    \ntemplate <typename T> T ext_gcd(T a, T b, T &x, T &y) {\n  T d = a;\n  if (b\
    \ != 0ll) {\n    d = ext_gcd(b, a % b, y, x);\n    y -= (a / b) * x;\n  } else\
    \ {\n    x = 1ll;\n    y = 0ll;\n  }\n  return d;\n}\n#line 2 \"library/number/factorial.hpp\"\
    \nlong long factorial(int N) {\n  long long res = 1;\n  while (N > 0) res *= N--;\n\
    \  return res;\n}\n#line 2 \"library/number/combination.hpp\"\nlong long combination(int\
    \ n, int k) {\n  if (k < 0 || n < k) return 0ll;\n  long long res = 1;\n  for\
    \ (int i = 1; i <= k; ++i) {\n    res *= n--;\n    res /= i;\n  }\n  return res;\n\
    }\n#line 2 \"library/number/base_convert.hpp\"\nvector<int> base_convert(long\
    \ long x, int to) {\n  vector<int> ret;\n  long long t = 1, k = abs(to);\n  while\
    \ (x) {\n    ret.emplace_back((x * t) % k);\n    if (ret.back() < 0) ret.back()\
    \ += k;\n    x -= ret.back() * t;\n    x /= k;\n    t *= to / k;\n  }\n  if (ret.empty())\
    \ ret.emplace_back(0);\n  reverse(ret.begin(), ret.end());\n  return ret;\n}\n\
    #line 2 \"library/number/prime/prime_fact.hpp\"\nmap<int, int> prime_fact(int\
    \ N) {\n  map<int, int> P;\n  for (int i = 2; i * i <= N; ++i) {\n    while (N\
    \ % i == 0) {\n      ++P[i];\n      N /= i;\n    }\n  }\n  if (N > 1) ++P[N];\n\
    \  return P;\n}\n#line 2 \"library/number/prime/prime_test.hpp\"\nbool prime_test(int\
    \ N) {\n  if (N == 2) return true;\n  if (N == 1 or N % 2 == 0) return false;\n\
    \  for (int i = 3; i * i <= N; i += 2) {\n    if (N % i == 0) return false;\n\
    \  }\n  return true;\n}\n#line 16 \"library/util/util.hpp\"\n/** ----- end include\
    \ utility ----- */\n"
  code: '/** ----- start include utility ----- */

    #include "library/sequence/collection_util.hpp"

    #include "library/string/util.hpp"

    #include "library/string/run_length.hpp"

    #include "library/geometry/util.hpp"

    #include "library/geometry/area_square.hpp"

    #include "library/geometry/area_triangle.hpp"

    #include "library/number/div.hpp"

    #include "library/number/divisors.hpp"

    #include "library/number/ext_gcd.hpp"

    #include "library/number/factorial.hpp"

    #include "library/number/combination.hpp"

    #include "library/number/base_convert.hpp"

    #include "library/number/prime/prime_fact.hpp"

    #include "library/number/prime/prime_test.hpp"

    /** ----- end include utility ----- */'
  dependsOn:
  - library/sequence/collection_util.hpp
  - library/string/util.hpp
  - library/string/run_length.hpp
  - library/geometry/util.hpp
  - library/geometry/area_square.hpp
  - library/geometry/area_triangle.hpp
  - library/number/div.hpp
  - library/number/divisors.hpp
  - library/number/ext_gcd.hpp
  - library/number/factorial.hpp
  - library/number/combination.hpp
  - library/number/base_convert.hpp
  - library/number/prime/prime_fact.hpp
  - library/number/prime/prime_test.hpp
  isVerificationFile: false
  path: library/util/util.hpp
  requiredBy: []
  timestamp: '2026-08-08 21:18:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/util/util.hpp
layout: document
redirect_from:
- /library/library/util/util.hpp
- /library/library/util/util.hpp.html
title: library/util/util.hpp
---
