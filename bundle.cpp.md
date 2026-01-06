---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bits/stdc++.h
    title: "\u30AB\u30B9\u30BF\u30E0stdc++.h"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u0E05^>\u03C9<^\u0E05"
    links:
    - https://serna37.github.io/library-cpp/
  bundledCode: "#line 1 \"bundle.cpp\"\n/**\n * @brief \u0E05^>\u03C9<^\u0E05\n *\
    \ @author serna37\n * @note https://serna37.github.io/library-cpp/\n */\n#ifdef\
    \ LOCAL\n\n#else\n#define debug(...)\n#endif\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <complex>\n#include <chrono>\n\
    #include <deque>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <limits.h>\n#include <map>\n#include <math.h>\n#include <numeric>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <sstream>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n/** ======================================= */\n/**              \u5171\
    \u901A                       */\n/** ======================================= */\n\
    \n#define int long long\n#define all(x) begin(x), end(x)\n#define rall(x) rbegin(x),\
    \ rend(x)\n#define $(idx) (std::get<(idx)>(std::forward_as_tuple(_args...)))\n\
    // lambda($(0) + $(1))\u3068\u3067\u304D\u308B\n#define lambda(...) ([&](auto\
    \ &&..._args) { return (__VA_ARGS__); })\nauto chmin = []<class T>(T &i, const\
    \ T &j) { return i > j && (i = j, true); };\nauto chmax = []<class T>(T &i, const\
    \ T &j) { return i < j && (i = j, true); };\n// [a, b)\u3067\u4E71\u6570\u751F\
    \u6210 \u30E1\u30EB\u30BB\u30F3\u30CC\u30C4\u30A4\u30B9\u30BF\nauto random_mersenne_twister\
    \ = [](int a = 1, int b = 1e5 + 1) {\n    uniform_int_distribution<int> dist(a,\
    \ b - 1);\n    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    return dist(mt);\n};\n\n\n/** ======================================= */\n\
    /**                IO                       */\n/** =======================================\
    \ */\n\n#define endl \"\\n\"\nstruct IoSetup {\n    IoSetup() {\n        cin.tie(0)->sync_with_stdio(0);\n\
    \        cout << fixed << setprecision(20);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\ntemplate <typename T> istream &operator>>(istream &s, vector<T>\
    \ &v) {\n    for (auto &&e : v) s >> e;\n    return s;\n}\ntemplate <typename\
    \ T> ostream &operator<<(ostream &s, const vector<T> &v) {\n    int i = 0;\n \
    \   for (auto &&e : v) s << (i++ ? \" \" : \"\") << e;\n    return s;\n}\ntemplate\
    \ <typename T> void print(const vector<vector<T>> &G) {\n    for (auto &&v : G)\
    \ cout << v << endl;\n}\ntemplate <typename T, typename U> void print(const pair<T,\
    \ U> &p) {\n    cout << p.first << \" \" << p.second << endl;\n}\ntemplate <typename\
    \ T> void print(const T &v) {\n    cout << v << endl;\n}\nvoid yn(bool o) {\n\
    \    cout << (o ? \"Yes\" : \"No\") << endl;\n}\nvoid YN(bool o) {\n    cout <<\
    \ (o ? \"YES\" : \"NO\") << endl;\n}\n\n\n/** =======================================\
    \ */\n/**                 \u578B                      */\n/** =======================================\
    \ */\n\ntemplate <typename T>\nusing reverse_queue = priority_queue<T, vector<T>,\
    \ greater<T>>;\ntemplate <typename T> using vec2 = vector<vector<T>>;\ntemplate\
    \ <typename T> vec2<T> make_vec2(int H, int W, T init = 0) {\n    return vector<vector<T>>(H,\
    \ vector<T>(W, init));\n}\nchar int_to_char(int x) {\n    return (char)(x + '0');\n\
    }\nchar int_to_alph(int x) {\n    return (char)(x + 'a');\n}\nint char_to_int(char\
    \ c) {\n    return (int)(c - '0');\n}\nstring int_to_string(long long x) {\n \
    \   return to_string(x);\n}\nlong long string_to_int(string s) {\n    return stoll(s);\n\
    }\n\n\n/** ======================================= */\n/**              \u5B9A\
    \u6570                       */\n/** ======================================= */\n\
    \nconst long long INF = 1e18;\nconst long long MAX = 2e6;\nconst long long MOD\
    \ = 998244353;\nconst long long MOD7 = 1e9 + 7;\nconst long double EPS = 1e-14;\n\
    const long double PI = acos(-1);\n// \u4E0B\u53F3\u4E0A\u5DE6 DRUL\nconst vector<int>\
    \ dx = {0, 1, 0, -1};\nconst vector<int> dy = {1, 0, -1, 0};\n// 8\u65B9\u5411\
    \nconst vector<int> dx8 = {0, 1, 0, -1, 1, -1, 1, -1};\nconst vector<int> dy8\
    \ = {1, 0, -1, 0, 1, 1, -1, -1};\n\n/** =======================================\
    \ */\n/**              main                       */\n/** =======================================\
    \ */\nvoid solve();\nsigned main() {\n    solve();\n}\n// -----------------------------------------\n\
    // #include \"template/template.hpp\" is done.\n// -----------------------------------------\n\
    \n/**\n * @brief \U0001F36A\U0001F9F8\U0001F43E\n * @note https://serna37.github.io/library-cpp/\n\
    \ */\nvoid solve() {\n}\n\n"
  code: "/**\n * @brief \u0E05^>\u03C9<^\u0E05\n * @author serna37\n * @note https://serna37.github.io/library-cpp/\n\
    \ */\n#ifdef LOCAL\n\n#else\n#define debug(...)\n#endif\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <complex>\n\
    #include <chrono>\n#include <deque>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <limits.h>\n#include <map>\n#include <math.h>\n\
    #include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n#include\
    \ <sstream>\n#include <stack>\n#include <string>\n#include <tuple>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#include <vector>\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n/** ======================================= */\n/**  \
    \            \u5171\u901A                       */\n/** =======================================\
    \ */\n\n#define int long long\n#define all(x) begin(x), end(x)\n#define rall(x)\
    \ rbegin(x), rend(x)\n#define $(idx) (std::get<(idx)>(std::forward_as_tuple(_args...)))\n\
    // lambda($(0) + $(1))\u3068\u3067\u304D\u308B\n#define lambda(...) ([&](auto\
    \ &&..._args) { return (__VA_ARGS__); })\nauto chmin = []<class T>(T &i, const\
    \ T &j) { return i > j && (i = j, true); };\nauto chmax = []<class T>(T &i, const\
    \ T &j) { return i < j && (i = j, true); };\n// [a, b)\u3067\u4E71\u6570\u751F\
    \u6210 \u30E1\u30EB\u30BB\u30F3\u30CC\u30C4\u30A4\u30B9\u30BF\nauto random_mersenne_twister\
    \ = [](int a = 1, int b = 1e5 + 1) {\n    uniform_int_distribution<int> dist(a,\
    \ b - 1);\n    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    return dist(mt);\n};\n\n\n/** ======================================= */\n\
    /**                IO                       */\n/** =======================================\
    \ */\n\n#define endl \"\\n\"\nstruct IoSetup {\n    IoSetup() {\n        cin.tie(0)->sync_with_stdio(0);\n\
    \        cout << fixed << setprecision(20);\n        cerr << fixed << setprecision(10);\n\
    \    }\n} iosetup;\ntemplate <typename T> istream &operator>>(istream &s, vector<T>\
    \ &v) {\n    for (auto &&e : v) s >> e;\n    return s;\n}\ntemplate <typename\
    \ T> ostream &operator<<(ostream &s, const vector<T> &v) {\n    int i = 0;\n \
    \   for (auto &&e : v) s << (i++ ? \" \" : \"\") << e;\n    return s;\n}\ntemplate\
    \ <typename T> void print(const vector<vector<T>> &G) {\n    for (auto &&v : G)\
    \ cout << v << endl;\n}\ntemplate <typename T, typename U> void print(const pair<T,\
    \ U> &p) {\n    cout << p.first << \" \" << p.second << endl;\n}\ntemplate <typename\
    \ T> void print(const T &v) {\n    cout << v << endl;\n}\nvoid yn(bool o) {\n\
    \    cout << (o ? \"Yes\" : \"No\") << endl;\n}\nvoid YN(bool o) {\n    cout <<\
    \ (o ? \"YES\" : \"NO\") << endl;\n}\n\n\n/** =======================================\
    \ */\n/**                 \u578B                      */\n/** =======================================\
    \ */\n\ntemplate <typename T>\nusing reverse_queue = priority_queue<T, vector<T>,\
    \ greater<T>>;\ntemplate <typename T> using vec2 = vector<vector<T>>;\ntemplate\
    \ <typename T> vec2<T> make_vec2(int H, int W, T init = 0) {\n    return vector<vector<T>>(H,\
    \ vector<T>(W, init));\n}\nchar int_to_char(int x) {\n    return (char)(x + '0');\n\
    }\nchar int_to_alph(int x) {\n    return (char)(x + 'a');\n}\nint char_to_int(char\
    \ c) {\n    return (int)(c - '0');\n}\nstring int_to_string(long long x) {\n \
    \   return to_string(x);\n}\nlong long string_to_int(string s) {\n    return stoll(s);\n\
    }\n\n\n/** ======================================= */\n/**              \u5B9A\
    \u6570                       */\n/** ======================================= */\n\
    \nconst long long INF = 1e18;\nconst long long MAX = 2e6;\nconst long long MOD\
    \ = 998244353;\nconst long long MOD7 = 1e9 + 7;\nconst long double EPS = 1e-14;\n\
    const long double PI = acos(-1);\n// \u4E0B\u53F3\u4E0A\u5DE6 DRUL\nconst vector<int>\
    \ dx = {0, 1, 0, -1};\nconst vector<int> dy = {1, 0, -1, 0};\n// 8\u65B9\u5411\
    \nconst vector<int> dx8 = {0, 1, 0, -1, 1, -1, 1, -1};\nconst vector<int> dy8\
    \ = {1, 0, -1, 0, 1, 1, -1, -1};\n\n/** =======================================\
    \ */\n/**              main                       */\n/** =======================================\
    \ */\nvoid solve();\nsigned main() {\n    solve();\n}\n// -----------------------------------------\n\
    // #include \"template/template.hpp\" is done.\n// -----------------------------------------\n\
    \n/**\n * @brief \U0001F36A\U0001F9F8\U0001F43E\n * @note https://serna37.github.io/library-cpp/\n\
    \ */\nvoid solve() {\n}\n\n"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: bundle.cpp
  requiredBy: []
  timestamp: '2026-01-06 20:47:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bundle.cpp
layout: document
title: "\u30D0\u30F3\u30C9\u30EB\u5F8C\u306E\u30B5\u30F3\u30D7\u30EB"
---

`bundler/main.cpp`実行後に生成される`main.cpp`のサンプル。
これを提出する。

