---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://zenn.dev/sassan/articles/19db660e4da0a4
  bundledCode: "#line 2 \"template/debug.hpp\"\n#include <cxxabi.h>\n#include <iostream>\n\
    #include <map>\n#include <queue>\n#include <set>\n#include <stack>\nusing std::cerr;\n\
    using std::deque;\nusing std::map;\nusing std::multiset;\nusing std::pair;\nusing\
    \ std::priority_queue;\nusing std::queue;\nusing std::set;\nusing std::stack;\n\
    using std::string;\nusing std::tuple;\nusing std::vector;\n// =====================================\n\
    // \u533A\u5207\u308A\u6587\u5B57\u7CFB\n// =====================================\n\
    // array: \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3067\u8981\u7D20\u306B\u30A2\u30AF\
    \u30BB\u30B9\u3067\u304D\u308B\u7CFB\ninline void _print_a_start() {\n    cerr\
    \ << \"\\033[32m\"\n         << \"[\"\n         << \"\\033[m\";\n}\ninline void\
    \ _print_a_end() {\n    cerr << \"\\033[32m\"\n         << \"]\"\n         <<\
    \ \"\\033[m\";\n}\n// brucet: \u305D\u306E\u4ED6\u306E\u96C6\u5408\ninline void\
    \ _print_b_start() {\n    cerr << \"\\033[32m\"\n         << \"{\"\n         <<\
    \ \"\\033[m\";\n}\ninline void _print_b_end() {\n    cerr << \"\\033[32m\"\n \
    \        << \"}\"\n         << \"\\033[m\";\n}\n// parentheses: \u30BF\u30D7\u30EB\
    \u7CFB\ninline void _print_p_start() {\n    cerr << \"\\033[32m\"\n         <<\
    \ \"(\"\n         << \"\\033[m\";\n}\ninline void _print_p_end() {\n    cerr <<\
    \ \"\\033[32m\"\n         << \")\"\n         << \"\\033[m\";\n}\n// \u30AB\u30F3\
    \u30DE\u3001\u6539\u884C\ninline void _print_sep() {\n    cerr << \"\\033[32m\"\
    \n         << \",\"\n         << \"\\033[m\";\n}\ninline void _print_LF() {\n\
    \    cerr << \"\\n\";\n}\nconst int DEBUG_LIMIT_LOOP = 20;\n// =====================================\n\
    // \u578B\u304C\u5165\u308C\u5B50\u306B\u306A\u3063\u3066\u3044\u308B\u304B\u5224\
    \u5B9A\n// =====================================\ntemplate <typename T> bool _is_nested(const\
    \ T &v, int f = 3) {\n    // \u578B\u540D\u3092\u30C7\u30DE\u30F3\u30B0\u30EB\u3059\
    \u308B\n    int res;\n    char *r = abi::__cxa_demangle(typeid(v).name(), nullptr,\
    \ nullptr, &res);\n    if (res != 0) {\n        cerr << \"demangle error\"\n \
    \            << \"\\n\";\n        free(r);\n        return false;\n    }\n   \
    \ string tmp = r;\n    free(r);\n    // std\u3046\u3093\u305F\u3089\u3092\u6D88\
    \u3059\n    const string prefix = \"std::__1::\";\n    const int presz = prefix.size();\n\
    \    auto p = tmp.find(prefix);\n    while (p != string::npos) {\n        tmp.erase(p,\
    \ presz);\n        p = tmp.find(prefix, p + 1);\n    }\n    // string\u306Fbasic_string<char\
    \ ...\n    if (tmp == \"basic_string<\") {\n        tmp = \"string\";\n    }\n\
    \    int cnt = 0;\n    for (auto &&ch : tmp) {\n        if (ch == '<') ++cnt;\n\
    \    }\n    // \u95BE\u5024f\u306B\u3064\u3044\u3066\n    // vector<int>\u306F\
    vector<int, allocator<int>>\u306B\u306A\u308B\n    // set\u3067\u306F\u3082\u3063\
    \u3068\u591A\u3044\n    return cnt >= f;\n}\n// =====================================\n\
    // \u5BFE\u5FDC\u578B\u7528\u306Einterface\u3092\u5BA3\u8A00\u3057\u3066\u304A\
    \u304F\n// =====================================\ntemplate <typename T> void _print(const\
    \ T &v);\ntemplate <typename T> void _print(const vector<T> &v);\ntemplate <typename\
    \ T> void _print(const set<T> &v);\ntemplate <typename T> void _print(const multiset<T>\
    \ &v);\ntemplate <typename T, typename U> void _print(const map<T, U> &v);\ntemplate\
    \ <typename T, typename U> void _print(const pair<T, U> &v);\ntemplate <typename\
    \ T, typename U, typename R>\nvoid _print(const tuple<T, U, R> &v);\ntemplate\
    \ <typename T, typename U, typename R, typename S>\nvoid _print(const tuple<T,\
    \ U, R, S> &v);\ntemplate <typename T> void _print(const stack<T> &v);\ntemplate\
    \ <typename T> void _print(const queue<T> &v);\ntemplate <typename T> void _print(const\
    \ priority_queue<T> &v);\ntemplate <typename T> void _print(const deque<T> &v);\n\
    // =====================================\n// \u30D7\u30EA\u30DF\u30C6\u30A3\u30D6\
    \u578B\u7528\n// =====================================\ninline void _print(const\
    \ int &v) {\n    cerr << v;\n}\ninline void _print(const long long &v) {\n   \
    \ cerr << v;\n}\ninline void _print(const double &v) {\n    cerr << v;\n}\ninline\
    \ void _print(const char &v) {\n    cerr << \"\\033[32m'\\033[m\" << v << \"\\\
    033[32m'\\033[m\";\n}\ninline void _print(const string &v) {\n    cerr << \"\\\
    033[32m\" << '\"' << \"\\033[m\" << v << \"\\033[32m\" << '\"' << \"\\033[m\"\
    ;\n}\n// \u76F4\u63A5\u5F15\u6570\u306B\u5165\u308C\u305F\u308A\u3068\u304B\u3057\
    \u305F\u5834\u5408\ntemplate <typename T> void _print(const T &v) {\n    cerr\
    \ << v;\n}\n// =====================================\n// pair tuple3 tuple4\n\
    // =====================================\ntemplate <typename T, typename U> void\
    \ _print(const pair<T, U> &v) {\n    _print_p_start();\n    _print(v.first);\n\
    \    _print_sep();\n    _print(v.second);\n    _print_p_end();\n}\ntemplate <typename\
    \ T, typename U, typename R>\nvoid _print(const tuple<T, U, R> &v) {\n    _print_p_start();\n\
    \    _print(get<0>(v));\n    _print_sep();\n    _print(get<1>(v));\n    _print_sep();\n\
    \    _print(get<2>(v));\n    _print_p_end();\n}\ntemplate <typename T, typename\
    \ U, typename R, typename S>\nvoid _print(const tuple<T, U, R, S> &v) {\n    _print_p_start();\n\
    \    _print(get<0>(v));\n    _print_sep();\n    _print(get<1>(v));\n    _print_sep();\n\
    \    _print(get<2>(v));\n    _print_sep();\n    _print(get<3>(v));\n    _print_p_end();\n\
    }\n// =====================================\n// vector set multiset map\n// =====================================\n\
    template <typename T> void _print(const vector<T> &v) {\n    bool isnested = _is_nested(v);\n\
    \    _print_a_start();\n    if (isnested) _print_LF();\n    for (int i = 0; i\
    \ < static_cast<int>(v.size()); ++i) {\n        if (i == DEBUG_LIMIT_LOOP) {\n\
    \            cerr << \"...and more \" << v.size() - DEBUG_LIMIT_LOOP;\n      \
    \      break;\n        }\n        if (isnested) cerr << \"  \";\n        if (i)\
    \ _print_sep();\n        _print(v[i]);\n        if (isnested) _print_LF();\n \
    \   }\n    _print_a_end();\n}\ntemplate <typename T> void _print(const set<T>\
    \ &v) {\n    bool isnested = _is_nested(v, 4);\n    _print_b_start();\n    if\
    \ (isnested) _print_LF();\n    int i = 0;\n    for (auto &&x : v) {\n        if\
    \ (i == DEBUG_LIMIT_LOOP) {\n            cerr << \"...and more \" << v.size()\
    \ - DEBUG_LIMIT_LOOP;\n            break;\n        }\n        if (isnested) cerr\
    \ << \"  \";\n        if (i++) _print_sep();\n        _print(x);\n        if (isnested)\
    \ _print_LF();\n    }\n    _print_b_end();\n}\ntemplate <typename T> void _print(const\
    \ multiset<T> &v) {\n    bool isnested = _is_nested(v, 4);\n    _print_b_start();\n\
    \    if (isnested) _print_LF();\n    int i = 0;\n    for (auto &&x : v) {\n  \
    \      if (i == DEBUG_LIMIT_LOOP) {\n            cerr << \"...and more \" << v.size()\
    \ - DEBUG_LIMIT_LOOP;\n            break;\n        }\n        if (isnested) cerr\
    \ << \"  \";\n        if (i++) _print_sep();\n        _print(x);\n        if (isnested)\
    \ _print_LF();\n    }\n    _print_b_end();\n}\ntemplate <typename T, typename\
    \ U> void _print(const map<T, U> &v) {\n    _print_b_start();\n    _print_LF();\n\
    \    int i = 0;\n    for (auto &&[k, x] : v) {\n        if (i == DEBUG_LIMIT_LOOP)\
    \ {\n            cerr << \"...and more \" << v.size() - DEBUG_LIMIT_LOOP;\n  \
    \          break;\n        }\n        cerr << \"  \";\n        if (i++) _print_sep();\n\
    \        _print_p_start();\n        _print(k);\n        _print_sep();\n      \
    \  _print(x);\n        _print_p_end();\n        _print_LF();\n    }\n    _print_b_end();\n\
    }\n// =====================================\n// stack queue priority_queue deque\n\
    // =====================================\ntemplate <typename T> void _print(const\
    \ stack<T> &v) {\n    auto x = v;\n    _print_b_start();\n    int i = 0;\n   \
    \ while (!x.empty()) {\n        if (i == DEBUG_LIMIT_LOOP) {\n            cerr\
    \ << \"...and more \" << v.size() - DEBUG_LIMIT_LOOP;\n            break;\n  \
    \      }\n        if (i++) _print_sep();\n        _print(x.top());\n        x.pop();\n\
    \    }\n    _print_b_end();\n}\ntemplate <typename T> void _print(const queue<T>\
    \ &v) {\n    auto x = v;\n    _print_b_start();\n    int i = 0;\n    while (!x.empty())\
    \ {\n        if (i == DEBUG_LIMIT_LOOP) {\n            cerr << \"...and more \"\
    \ << v.size() - DEBUG_LIMIT_LOOP;\n            break;\n        }\n        if (i++)\
    \ _print_sep();\n        _print(x.front());\n        x.pop();\n    }\n    _print_b_end();\n\
    }\ntemplate <typename T> void _print(const priority_queue<T> &v) {\n    auto x\
    \ = v;\n    _print_b_start();\n    int i = 0;\n    while (!x.empty()) {\n    \
    \    if (i == DEBUG_LIMIT_LOOP) {\n            cerr << \"...and more \" << v.size()\
    \ - DEBUG_LIMIT_LOOP;\n            break;\n        }\n        if (i++) _print_sep();\n\
    \        _print(x.top());\n        x.pop();\n    }\n    _print_b_end();\n}\ntemplate\
    \ <typename T> void _print(const deque<T> &v) {\n    auto x = v;\n    _print_a_start();\n\
    \    int i = 0;\n    while (!x.empty()) {\n        if (i == DEBUG_LIMIT_LOOP)\
    \ {\n            cerr << \"...and more \" << v.size() - DEBUG_LIMIT_LOOP;\n  \
    \          break;\n        }\n        if (i++) _print_sep();\n        _print(x.front());\n\
    \        x.pop_front();\n    }\n    _print_a_end();\n}\n// =====================================\n\
    // base\n// =====================================\ntemplate <typename T> void\
    \ print_debug(const T &v, const string &name) {\n    cerr << \"\\033[90m[debug]\\\
    033[36m \" << name << \"\\033[m => \";\n    _print(v);\n    _print_LF();\n}\n\
    #define debug(...) print_debug(__VA_ARGS__, #__VA_ARGS__)\n// cpp_dump\n// https://zenn.dev/sassan/articles/19db660e4da0a4\n\
    // #include \"cpp-dump.hpp\"\n// #define debug(...) cpp_dump(__VA_ARGS__)\n"
  code: "#pragma once\n#include <cxxabi.h>\n#include <iostream>\n#include <map>\n\
    #include <queue>\n#include <set>\n#include <stack>\nusing std::cerr;\nusing std::deque;\n\
    using std::map;\nusing std::multiset;\nusing std::pair;\nusing std::priority_queue;\n\
    using std::queue;\nusing std::set;\nusing std::stack;\nusing std::string;\nusing\
    \ std::tuple;\nusing std::vector;\n// =====================================\n\
    // \u533A\u5207\u308A\u6587\u5B57\u7CFB\n// =====================================\n\
    // array: \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3067\u8981\u7D20\u306B\u30A2\u30AF\
    \u30BB\u30B9\u3067\u304D\u308B\u7CFB\ninline void _print_a_start() {\n    cerr\
    \ << \"\\033[32m\"\n         << \"[\"\n         << \"\\033[m\";\n}\ninline void\
    \ _print_a_end() {\n    cerr << \"\\033[32m\"\n         << \"]\"\n         <<\
    \ \"\\033[m\";\n}\n// brucet: \u305D\u306E\u4ED6\u306E\u96C6\u5408\ninline void\
    \ _print_b_start() {\n    cerr << \"\\033[32m\"\n         << \"{\"\n         <<\
    \ \"\\033[m\";\n}\ninline void _print_b_end() {\n    cerr << \"\\033[32m\"\n \
    \        << \"}\"\n         << \"\\033[m\";\n}\n// parentheses: \u30BF\u30D7\u30EB\
    \u7CFB\ninline void _print_p_start() {\n    cerr << \"\\033[32m\"\n         <<\
    \ \"(\"\n         << \"\\033[m\";\n}\ninline void _print_p_end() {\n    cerr <<\
    \ \"\\033[32m\"\n         << \")\"\n         << \"\\033[m\";\n}\n// \u30AB\u30F3\
    \u30DE\u3001\u6539\u884C\ninline void _print_sep() {\n    cerr << \"\\033[32m\"\
    \n         << \",\"\n         << \"\\033[m\";\n}\ninline void _print_LF() {\n\
    \    cerr << \"\\n\";\n}\nconst int DEBUG_LIMIT_LOOP = 20;\n// =====================================\n\
    // \u578B\u304C\u5165\u308C\u5B50\u306B\u306A\u3063\u3066\u3044\u308B\u304B\u5224\
    \u5B9A\n// =====================================\ntemplate <typename T> bool _is_nested(const\
    \ T &v, int f = 3) {\n    // \u578B\u540D\u3092\u30C7\u30DE\u30F3\u30B0\u30EB\u3059\
    \u308B\n    int res;\n    char *r = abi::__cxa_demangle(typeid(v).name(), nullptr,\
    \ nullptr, &res);\n    if (res != 0) {\n        cerr << \"demangle error\"\n \
    \            << \"\\n\";\n        free(r);\n        return false;\n    }\n   \
    \ string tmp = r;\n    free(r);\n    // std\u3046\u3093\u305F\u3089\u3092\u6D88\
    \u3059\n    const string prefix = \"std::__1::\";\n    const int presz = prefix.size();\n\
    \    auto p = tmp.find(prefix);\n    while (p != string::npos) {\n        tmp.erase(p,\
    \ presz);\n        p = tmp.find(prefix, p + 1);\n    }\n    // string\u306Fbasic_string<char\
    \ ...\n    if (tmp == \"basic_string<\") {\n        tmp = \"string\";\n    }\n\
    \    int cnt = 0;\n    for (auto &&ch : tmp) {\n        if (ch == '<') ++cnt;\n\
    \    }\n    // \u95BE\u5024f\u306B\u3064\u3044\u3066\n    // vector<int>\u306F\
    vector<int, allocator<int>>\u306B\u306A\u308B\n    // set\u3067\u306F\u3082\u3063\
    \u3068\u591A\u3044\n    return cnt >= f;\n}\n// =====================================\n\
    // \u5BFE\u5FDC\u578B\u7528\u306Einterface\u3092\u5BA3\u8A00\u3057\u3066\u304A\
    \u304F\n// =====================================\ntemplate <typename T> void _print(const\
    \ T &v);\ntemplate <typename T> void _print(const vector<T> &v);\ntemplate <typename\
    \ T> void _print(const set<T> &v);\ntemplate <typename T> void _print(const multiset<T>\
    \ &v);\ntemplate <typename T, typename U> void _print(const map<T, U> &v);\ntemplate\
    \ <typename T, typename U> void _print(const pair<T, U> &v);\ntemplate <typename\
    \ T, typename U, typename R>\nvoid _print(const tuple<T, U, R> &v);\ntemplate\
    \ <typename T, typename U, typename R, typename S>\nvoid _print(const tuple<T,\
    \ U, R, S> &v);\ntemplate <typename T> void _print(const stack<T> &v);\ntemplate\
    \ <typename T> void _print(const queue<T> &v);\ntemplate <typename T> void _print(const\
    \ priority_queue<T> &v);\ntemplate <typename T> void _print(const deque<T> &v);\n\
    // =====================================\n// \u30D7\u30EA\u30DF\u30C6\u30A3\u30D6\
    \u578B\u7528\n// =====================================\ninline void _print(const\
    \ int &v) {\n    cerr << v;\n}\ninline void _print(const long long &v) {\n   \
    \ cerr << v;\n}\ninline void _print(const double &v) {\n    cerr << v;\n}\ninline\
    \ void _print(const char &v) {\n    cerr << \"\\033[32m'\\033[m\" << v << \"\\\
    033[32m'\\033[m\";\n}\ninline void _print(const string &v) {\n    cerr << \"\\\
    033[32m\" << '\"' << \"\\033[m\" << v << \"\\033[32m\" << '\"' << \"\\033[m\"\
    ;\n}\n// \u76F4\u63A5\u5F15\u6570\u306B\u5165\u308C\u305F\u308A\u3068\u304B\u3057\
    \u305F\u5834\u5408\ntemplate <typename T> void _print(const T &v) {\n    cerr\
    \ << v;\n}\n// =====================================\n// pair tuple3 tuple4\n\
    // =====================================\ntemplate <typename T, typename U> void\
    \ _print(const pair<T, U> &v) {\n    _print_p_start();\n    _print(v.first);\n\
    \    _print_sep();\n    _print(v.second);\n    _print_p_end();\n}\ntemplate <typename\
    \ T, typename U, typename R>\nvoid _print(const tuple<T, U, R> &v) {\n    _print_p_start();\n\
    \    _print(get<0>(v));\n    _print_sep();\n    _print(get<1>(v));\n    _print_sep();\n\
    \    _print(get<2>(v));\n    _print_p_end();\n}\ntemplate <typename T, typename\
    \ U, typename R, typename S>\nvoid _print(const tuple<T, U, R, S> &v) {\n    _print_p_start();\n\
    \    _print(get<0>(v));\n    _print_sep();\n    _print(get<1>(v));\n    _print_sep();\n\
    \    _print(get<2>(v));\n    _print_sep();\n    _print(get<3>(v));\n    _print_p_end();\n\
    }\n// =====================================\n// vector set multiset map\n// =====================================\n\
    template <typename T> void _print(const vector<T> &v) {\n    bool isnested = _is_nested(v);\n\
    \    _print_a_start();\n    if (isnested) _print_LF();\n    for (int i = 0; i\
    \ < static_cast<int>(v.size()); ++i) {\n        if (i == DEBUG_LIMIT_LOOP) {\n\
    \            cerr << \"...and more \" << v.size() - DEBUG_LIMIT_LOOP;\n      \
    \      break;\n        }\n        if (isnested) cerr << \"  \";\n        if (i)\
    \ _print_sep();\n        _print(v[i]);\n        if (isnested) _print_LF();\n \
    \   }\n    _print_a_end();\n}\ntemplate <typename T> void _print(const set<T>\
    \ &v) {\n    bool isnested = _is_nested(v, 4);\n    _print_b_start();\n    if\
    \ (isnested) _print_LF();\n    int i = 0;\n    for (auto &&x : v) {\n        if\
    \ (i == DEBUG_LIMIT_LOOP) {\n            cerr << \"...and more \" << v.size()\
    \ - DEBUG_LIMIT_LOOP;\n            break;\n        }\n        if (isnested) cerr\
    \ << \"  \";\n        if (i++) _print_sep();\n        _print(x);\n        if (isnested)\
    \ _print_LF();\n    }\n    _print_b_end();\n}\ntemplate <typename T> void _print(const\
    \ multiset<T> &v) {\n    bool isnested = _is_nested(v, 4);\n    _print_b_start();\n\
    \    if (isnested) _print_LF();\n    int i = 0;\n    for (auto &&x : v) {\n  \
    \      if (i == DEBUG_LIMIT_LOOP) {\n            cerr << \"...and more \" << v.size()\
    \ - DEBUG_LIMIT_LOOP;\n            break;\n        }\n        if (isnested) cerr\
    \ << \"  \";\n        if (i++) _print_sep();\n        _print(x);\n        if (isnested)\
    \ _print_LF();\n    }\n    _print_b_end();\n}\ntemplate <typename T, typename\
    \ U> void _print(const map<T, U> &v) {\n    _print_b_start();\n    _print_LF();\n\
    \    int i = 0;\n    for (auto &&[k, x] : v) {\n        if (i == DEBUG_LIMIT_LOOP)\
    \ {\n            cerr << \"...and more \" << v.size() - DEBUG_LIMIT_LOOP;\n  \
    \          break;\n        }\n        cerr << \"  \";\n        if (i++) _print_sep();\n\
    \        _print_p_start();\n        _print(k);\n        _print_sep();\n      \
    \  _print(x);\n        _print_p_end();\n        _print_LF();\n    }\n    _print_b_end();\n\
    }\n// =====================================\n// stack queue priority_queue deque\n\
    // =====================================\ntemplate <typename T> void _print(const\
    \ stack<T> &v) {\n    auto x = v;\n    _print_b_start();\n    int i = 0;\n   \
    \ while (!x.empty()) {\n        if (i == DEBUG_LIMIT_LOOP) {\n            cerr\
    \ << \"...and more \" << v.size() - DEBUG_LIMIT_LOOP;\n            break;\n  \
    \      }\n        if (i++) _print_sep();\n        _print(x.top());\n        x.pop();\n\
    \    }\n    _print_b_end();\n}\ntemplate <typename T> void _print(const queue<T>\
    \ &v) {\n    auto x = v;\n    _print_b_start();\n    int i = 0;\n    while (!x.empty())\
    \ {\n        if (i == DEBUG_LIMIT_LOOP) {\n            cerr << \"...and more \"\
    \ << v.size() - DEBUG_LIMIT_LOOP;\n            break;\n        }\n        if (i++)\
    \ _print_sep();\n        _print(x.front());\n        x.pop();\n    }\n    _print_b_end();\n\
    }\ntemplate <typename T> void _print(const priority_queue<T> &v) {\n    auto x\
    \ = v;\n    _print_b_start();\n    int i = 0;\n    while (!x.empty()) {\n    \
    \    if (i == DEBUG_LIMIT_LOOP) {\n            cerr << \"...and more \" << v.size()\
    \ - DEBUG_LIMIT_LOOP;\n            break;\n        }\n        if (i++) _print_sep();\n\
    \        _print(x.top());\n        x.pop();\n    }\n    _print_b_end();\n}\ntemplate\
    \ <typename T> void _print(const deque<T> &v) {\n    auto x = v;\n    _print_a_start();\n\
    \    int i = 0;\n    while (!x.empty()) {\n        if (i == DEBUG_LIMIT_LOOP)\
    \ {\n            cerr << \"...and more \" << v.size() - DEBUG_LIMIT_LOOP;\n  \
    \          break;\n        }\n        if (i++) _print_sep();\n        _print(x.front());\n\
    \        x.pop_front();\n    }\n    _print_a_end();\n}\n// =====================================\n\
    // base\n// =====================================\ntemplate <typename T> void\
    \ print_debug(const T &v, const string &name) {\n    cerr << \"\\033[90m[debug]\\\
    033[36m \" << name << \"\\033[m => \";\n    _print(v);\n    _print_LF();\n}\n\
    #define debug(...) print_debug(__VA_ARGS__, #__VA_ARGS__)\n// cpp_dump\n// https://zenn.dev/sassan/articles/19db660e4da0a4\n\
    // #include \"cpp-dump.hpp\"\n// #define debug(...) cpp_dump(__VA_ARGS__)\n"
  dependsOn: []
  isVerificationFile: false
  path: template/debug.hpp
  requiredBy: []
  timestamp: '2026-01-08 22:50:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/debug.hpp
layout: document
title: "\u3081\u3063\u3061\u3083\u898B\u3084\u3059\u3044debug\u51FA\u529B"
---

めっちゃ見やすいdebug出力です

参考: https://zenn.dev/sassan/articles/19db660e4da0a4

