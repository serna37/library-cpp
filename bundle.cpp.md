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
    \ LOCAL\n\n#else\n#define debug(...)\n#endif\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n/** ======================================= */\n/**      \
    \        \u5171\u901A                       */\n/** =======================================\
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
    \ */\n\nstruct IoSetup {\n    IoSetup() {\n        cin.tie(0)->sync_with_stdio(0);\n\
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
    \ greater<T>>;\ntemplate <typename T> using vec2 = vector<vector<T>>;\nvec2<int>\
    \ make_vec2(int H, int W, int init = 0) {\n    return vector<vector<int>>(H, vector<int>(W,\
    \ init));\n}\nchar int_to_char(int x) {\n    return (char)(x + '0');\n}\nchar\
    \ int_to_alph(int x) {\n    return (char)(x + 'a');\n}\nint char_to_int(char c)\
    \ {\n    return (int)(c - '0');\n}\nstring int_to_string(long long x) {\n    return\
    \ to_string(x);\n}\nlong long string_to_int(string s) {\n    return stoll(s);\n\
    }\n\n\n/** ======================================= */\n/**              \u5B9A\
    \u6570                       */\n/** ======================================= */\n\
    \nconst long long INF = 1e18;\nconst long long MAX = 2e6;\nconst long long MOD\
    \ = 998244353;\nconst long long MOD7 = 1e9 + 7;\nconst long double EPS = 1e-14;\n\
    const double PI = acos(-1);\n// \u4E0B\u53F3\u4E0A\u5DE6 DRUL\nconst vector<int>\
    \ dx = {0, 1, 0, -1};\nconst vector<int> dy = {1, 0, -1, 0};\n// 8\u65B9\u5411\
    \nconst vector<int> dx8 = {0, 1, 0, -1, 1, -1, 1, -1};\nconst vector<int> dy8\
    \ = {1, 0, -1, 0, 1, 1, -1, -1};\n\n\n/** =======================================\
    \ */\n/**           \u6570\u306E\u6027\u8CEA                      */\n/** =======================================\
    \ */\n\nclass Number {\n  private:\n    // mod\u968E\u4E57\u306E\u30E1\u30E2\u914D\
    \u5217\n    vector<long long> _mf;\n\n  public:\n    // \u5272\u308A\u4E0B\u3052\
    \uFF08\u8CA0\u306E\u5834\u54080\u5074\u3078\u4E38\u3081\u306A\u3044\uFF09\n  \
    \  template <typename T> T div_ceil(T a, T b) {\n        return a / b + (((a ^\
    \ b) > 0 and a % b != 0) ? 1 : 0);\n    }\n    // \u5272\u308A\u4E0A\u3052\uFF08\
    \u8CA0\u306E\u5834\u54080\u5074\u3078\u4E38\u3081\u306A\u3044\uFF09\n    template\
    \ <typename T> T div_floor(T a, T b) {\n        return a / b - (((a ^ b) < 0 and\
    \ a % b != 0) ? 1 : 0);\n    }\n    // \u968E\u4E57 \u30CA\u30A4\u30FC\u30D6\n\
    \    long long factorial(int N) {\n        long long res = 1;\n        while (N\
    \ > 0) res *= N--;\n        return res;\n    }\n    // nCk\n    long long combination(int\
    \ n, int k) {\n        if (k < 0 || n < k) return 0ll;\n        long long res\
    \ = 1;\n        for (int i = 1; i <= k; ++i) {\n            res *= n--;\n    \
    \        res /= i;\n        }\n        return res;\n    }\n    // \u6841\u548C\
    \n    int digit_sum(int a, int N = 10) {\n        int res = 0;\n        while\
    \ (a != 0) {\n            res += a % N;\n            a /= N;\n        }\n    \
    \    return res;\n    }\n    // \u9032\u6570\u5909\u63DB from\u3068to\u306F10\u3092\
    \u8D85\u3048\u306A\u3044\u3053\u3068\n    string base_convert(string a, int from,\
    \ int to) {\n        long long cvt = 0ll; // 10\u9032\u6570\u306B\u76F4\u3059\n\
    \        for (auto &&v : a) cvt = cvt * from + (int)(v - '0');\n        if (cvt\
    \ == 0) return \"0\";\n        string res = \"\"; // to\u9032\u6570\u306B\u76F4\
    \u3059\n        while (cvt) {    // 10\u9032\u6570\u3067\u8868\u305B\u308B\u7BC4\
    \u56F2\u306E\u6587\u5B57\u3057\u304B\u6271\u3063\u3066\u3044\u306A\u3044\n   \
    \         res = (char)(cvt % to + '0') + res;\n            cvt /= to;\n      \
    \  }\n        return res;\n    }\n    // \u7D04\u6570\u5217\u6319\n    vector<int>\
    \ divisors(int a) {\n        vector<int> res;\n        for (int i = 1; i * i <=\
    \ a; ++i) {\n            if (a % i != 0) continue;\n            res.push_back(i);\n\
    \            if (a / i != i) res.push_back(a / i);\n        }\n        return\
    \ res;\n    }\n    // \u7D20\u6570\u5224\u5B9A\n    bool prime_test(int N) {\n\
    \        if (N == 2) return true;\n        if (N == 1 or N % 2 == 0) return false;\n\
    \        for (int i = 3; i * i <= N; i += 2) {\n            if (N % i == 0) return\
    \ false;\n        }\n        return true;\n    }\n    // \u7D20\u56E0\u6570\u5206\
    \u89E3\n    map<int, int> prime_fact(int N) {\n        map<int, int> P;\n    \
    \    for (int i = 2; i * i <= N; ++i) {\n            while (N % i == 0) {\n  \
    \              ++P[i];\n                N /= i;\n            }\n        }\n  \
    \      if (N > 1) ++P[N];\n        return P;\n    }\n    // \u4E8C\u5206\u7D2F\
    \u4E57(mod)\n    long long modpow(long long a, long long n, long long m) {\n \
    \       long long res = 1ll;\n        while (n > 0) {\n            if (n & 1)\
    \ res = res * a % m;\n            a = a * a % m;\n            n >>= 1ll;\n   \
    \     }\n        return res;\n    }\n    // Fermat\u306E\u5C0F\u5B9A\u7406 \u9006\
    \u5143\u3092\u6C42\u3081\u308B\n    long long modinv(long long a, long long m)\
    \ {\n        return modpow(a, m - 2, m);\n    }\n    // mod\u968E\u4E57\n    long\
    \ long modfact(int x, long long m) {\n        if ((int)_mf.size() > x) return\
    \ _mf[x];\n        if (_mf.empty()) _mf.push_back(1);\n        for (int i = _mf.size();\
    \ i <= x; ++i) _mf.push_back(_mf.back() * i % m);\n        return _mf[x];\n  \
    \  }\n    // mod\u7D44\u307F\u5408\u308F\u305BnCk\n    long long mod_combination(int\
    \ n, int k, long long m) {\n        return modfact(n, m) * modinv(modfact(k, m),\
    \ m) % m *\n               modinv(modfact(n - k, m), m) % m;\n    }\n};\n\n\n\
    /** ======================================= */\n/**              \u6587\u5B57\u5217\
    \                     */\n/** ======================================= */\n\nclass\
    \ String {\n  public:\n    bool is_low(char c) {\n        return islower(c) !=\
    \ 0;\n    }\n    bool is_upp(char c) {\n        return isupper(c) != 0;\n    }\n\
    \    // \u5C0F\u6587\u5B57\u306B\u5909\u63DB\n    string transform_lower(string\
    \ s) {\n        std::transform(all(s), s.begin(), ::tolower);\n        return\
    \ s;\n    }\n    // \u5927\u6587\u5B57\u306B\u5909\u63DB\n    string transform_upper(string\
    \ s) {\n        std::transform(all(s), s.begin(), ::toupper);\n        return\
    \ s;\n    }\n    // \u300C0000ABCDE\u300D\u5DE6\u5074\u3092\u57CB\u3081\u305F\
    size\u6841\u306E\u6587\u5B57\n    string lpad(const string &S, int size, char\
    \ ch = '0') {\n        int N = S.size();\n        if (N >= size) return S;\n \
    \       return string(size - N, ch) + S;\n    }\n    // \u300CABCDE0000\u300D\u53F3\
    \u3092\u57CB\u3081\u305Fsize\u6841\u306E\u6587\u5B57\n    string rpad(const string\
    \ &S, int size, char ch = '0') {\n        int N = S.size();\n        if (N >=\
    \ size) return S;\n        return S + string(size - N, ch);\n    }\n    /**\n\
    \     * \u6587\u5B57\u5217T\u306E\u4E2D\u306B\u3042\u308BS\u306E\u4E00\u81F4\u5834\
    \u6240\u3092\u5168\u3066\u53D6\u5F97\n     * \u30DE\u30C3\u30C1\u3057\u305F\u982D\
    \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u8FD4\u3059\n     */\n    vector<int>\
    \ finds(const string &T, const string &S) {\n        vector<int> pos;\n      \
    \  auto p = T.find(S);\n        while (p != string::npos) {\n            pos.emplace_back(p);\n\
    \            p = T.find(S, p + 1);\n        }\n        return pos;\n    }\n  \
    \  // \u533A\u5207\u308A\u6587\u5B57(1\u6587\u5B57)\u3067\u533A\u5207\u308B\n\
    \    vector<string> split(const string &S, const char &sep) {\n        vector<string>\
    \ res = {\"\"};\n        for (auto &&v : S) {\n            if (v == sep) {\n \
    \               res.emplace_back(\"\");\n            } else {\n              \
    \  res.back() += v;\n            }\n        }\n        return res;\n    }\n  \
    \  // \u8907\u6570\u306E\u533A\u5207\u308A\u6587\u5B57\u3067\u533A\u5207\u308B\
    \ \u533A\u5207\u308A\u6587\u5B57\u304C\u306A\u3044\u5834\u5408\u7A7A\u6587\u5B57\
    \n    vector<string> split_multi(const string &S, const string &seps) {\n    \
    \    vector<string> res = {\"\"};\n        for (auto &&v : S) {\n            if\
    \ (count(all(seps), v)) {\n                res.emplace_back(\"\");\n         \
    \   } else {\n                res.back() += v;\n            }\n        }\n   \
    \     return res;\n    }\n    // \u6587\u5B57\u5217\u306E\u533A\u9593[A, B]\u3092\
    \u53D6\u5F97\n    string str_range(const string &S, int A, int B) {\n        if\
    \ (A > B or A >= (int)S.size()) return \"\";\n        return S.substr(A, B - A\
    \ + 1);\n    }\n    // \u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\n    vector<pair<char,\
    \ int>> run_length(const string &S) {\n        vector<pair<char, int>> res;\n\
    \        for (auto &&x : S) {\n            if (res.empty() or res.back().first\
    \ != x) res.emplace_back(x, 0);\n            ++res.back().second;\n        }\n\
    \        return res;\n    }\n    // Z-Algorithm: S\u3068S[i:|S|]\u306E\u6700\u5927\
    \u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\n    vector<int> z_algo(const\
    \ string &S) {\n        int n = S.size();\n        if (n == 0) return {};\n  \
    \      vector<int> z(n);\n        z[0] = n;\n        for (int i = 1, j = 0; i\
    \ < n; ++i) {\n            int &k = z[i];\n            k = (j + z[j] <= i) ? 0\
    \ : min(j + z[j] - i, z[i - j]);\n            while (i + k < n and S[k] == S[i\
    \ + k]) ++k;\n            if (j + z[j] < i + z[i]) j = i;\n        }\n       \
    \ return z;\n    }\n};\n\n\n/** ======================================= */\n/**\
    \              \u914D\u5217\u30FB\u6570\u5217                 */\n/** =======================================\
    \ */\n\nclass Sequence {\n  public:\n    template <typename T> T min(const vector<T>\
    \ &v) {\n        return *min_element(all(v));\n    }\n    template <typename T>\
    \ T max(const vector<T> &v) {\n        return *max_element(all(v));\n    }\n \
    \   template <typename T> long long sum(const vector<T> &v) {\n        return\
    \ accumulate(all(v), 0ll);\n    }\n    template <typename T, typename F> bool\
    \ all_match(const vector<T> &v, F f) {\n        return all_of(all(v), f);\n  \
    \  }\n    template <typename T, typename F> bool none_match(const vector<T> &v,\
    \ F f) {\n        return none_of(all(v), f);\n    }\n    template <typename T,\
    \ typename F> bool any_match(const vector<T> &v, F f) {\n        return any_of(all(v),\
    \ f);\n    }\n    template <typename T> void distinct(vector<T> &v) {\n      \
    \  sort(all(v));\n        v.erase(unique(all(v)), v.end());\n    }\n    template\
    \ <typename T> void sort_asc(vector<T> &v) {\n        sort(all(v));\n    }\n \
    \   template <typename T> void sort_desc(vector<T> &v) {\n        sort(rall(v));\n\
    \    }\n    template <typename T> void reverse(vector<T> &v) {\n        reverse(all(v));\n\
    \    }\n    // set\u304B\u3089\u8981\u7D20\u524A\u9664\n    template <typename\
    \ T> void erase(set<T> &st, T &v) {\n        st.erase(st.find(v));\n    }\n  \
    \  // multiset\u304B\u3089\u8981\u7D20\u524A\u9664\n    template <typename T>\
    \ void erase(multiset<T> &st, T &v) {\n        st.erase(st.find(v));\n    }\n\
    \    // \u884C\u5217\u306E\u8EE2\u7F6E\n    template <typename T>\n    vector<vector<T>>\
    \ transpose(const vector<vector<T>> &G) {\n        int H = G.size(), W = G[0].size();\n\
    \        vector<vector<T>> _G(W, vector<T>(H));\n        for (int i = 0; i < H;\
    \ ++i) {\n            for (int j = 0; j < W; ++j) {\n                _G[j][i]\
    \ = G[i][j];\n            }\n        }\n        return _G;\n    }\n    /**\n \
    \    * \u5206\u5272\u4EE3\u5165\u3067\u304D\u308B\u3088\u3046\u306B\u3059\u308B\
    \ G\u306F\u7834\u58CA\u3002\n     * auto [a,b] = unpack<2>(move(G));\n     */\n\
    \    template <int N, typename T> auto unpack(vector<T> &&G) {\n        array<T,\
    \ N> res; // vector -> array\u5909\u63DB\u3059\u308B\u3060\u3051\n        for\
    \ (int i = 0; i < N; ++i) res[i] = move(G[i]);\n        return res;\n    }\n \
    \   // \u9023\u756A\u751F\u6210\n    template <typename T> void renban(vector<T>\
    \ &v, T start = 0) {\n        iota(all(v), start);\n    }\n    // A\u3092B\u306B\
    \u30DE\u30FC\u30B8\u30C6\u30AF vector\n    template <typename T> void merge(vector<T>\
    \ &A, vector<T> &B) {\n        if (A.size() > B.size()) swap(A, B);\n        for\
    \ (auto &&v : A) B.push_back(v);\n        A.clear();\n    }\n    // A\u3092B\u306B\
    \u30DE\u30FC\u30B8\u30C6\u30AF set\n    template <typename T> void merge(set<T>\
    \ &A, set<T> &B) {\n        if (A.size() > B.size()) swap(A, B);\n        for\
    \ (auto &&v : A) B.insert(v);\n        A.clear();\n    }\n    // A\u3092B\u306B\
    \u30DE\u30FC\u30B8\u30C6\u30AF \u30DE\u30FC\u30B8\u64CD\u4F5C\u3092\u30E9\u30E0\
    \u30C0\u5316\n    template <typename T, typename F> void merge(T &A, T &B, F f)\
    \ {\n        if (A.size() > B.size()) swap(A, B);\n        for (auto &&v : A)\
    \ {\n            f(B, v);\n        }\n        A.clear();\n    }\n    // \u6570\
    \u76F4\u7DDA\u4E0A\u3067\u306E\u500B\u6570\u306B\u306A\u304A\u3059\n    vector<int>\
    \ coordinate(const vector<int> &A) {\n        vector<int> res(MAX);\n        for\
    \ (auto &&v : A) ++res[v];\n        return res;\n    }\n    // \u5EA7\u6A19\u5727\
    \u7E2E \u5727\u7E2E\u5F8C\u306E\u7A2E\u985E\u6570\u3092\u8FD4\u5374\n    template\
    \ <typename T> int zip_coordinate(vector<T> &A) {\n        vector<T> cvt = A;\n\
    \        distinct(cvt);\n        for (auto &v : A) v = lower_bound(all(cvt), v)\
    \ - cvt.begin();\n        return (int)cvt.size();\n    }\n    // \u8EE2\u5012\u6570\
    \ \u53F3\u306B\u5012\u308C\u308BA_i > A_j (i < j)\u306E\u56DE\u6570\n    template\
    \ <typename T> long long inversion_number(vector<T> &A) {\n        int sz = zip_coordinate(A);\n\
    \        vector<int> fwk(sz + 1);\n        long long inv = 0, N = A.size();\n\
    \        for (int i = 0; i < N; ++i) {\n            for (int f = sz; f; f -= f\
    \ & -f) inv += fwk[f];\n            for (int f = A[i] + 1; f; f -= f & -f) inv\
    \ -= fwk[f];\n            for (int f = A[i] + 1; f <= sz; f += f & -f) ++fwk[f];\n\
    \        }\n        return inv;\n    }\n    // \u7D2F\u7A4D\u548C S[i]=\u03A3\
    (0,i-1)  \u03A3[l,r)=S[r]-S[l]\n    template <typename T> vector<long long> zeta(vector<T>\
    \ &A) {\n        int N = A.size();\n        vector<long long> S(N + 1);\n    \
    \    for (int i = 0; i < N; ++i) S[i + 1] = S[i] + A[i];\n        return S;\n\
    \    }\n    // \u53CD\u8EE2\u7D2F\u7A4D\u548C S[i]=Ai\u304B\u3089\u53F3\u5168\u90E8\
    \  \u03A3(0,i-1)+\u03A3(i,last)=S[i]+R[i]\n    template <typename T> vector<long\
    \ long> zeta_rev(vector<T> &A) {\n        int N = A.size();\n        vector<long\
    \ long> R(N + 1);\n        for (int i = N - 1; i >= 0; --i) R[i] = R[i + 1] +\
    \ A[i];\n        return R;\n    }\n    // \u4E8C\u9805\u5DEE\u3067\u306E\u7D2F\
    \u7A4D\u548C S[i]=\u03A3(0,i-1)  \u03A3[l,r)=S[r]-S[l]\n    template <typename\
    \ T> vector<long long> zeta_diff(vector<T> &A) {\n        int N = A.size();\n\
    \        vector<long long> S(N + 1);\n        for (int i = 0; i < N; ++i) {\n\
    \            S[i + 1] = S[i];\n            if (i & 1) S[i + 1] += abs(A[i] - A[i\
    \ - 1]);\n        }\n        return S;\n    }\n    // \u4E8C\u9805\u5DEE\u3067\
    \u306E\u53CD\u8EE2\u7D2F\u7A4D\u548C S[i]=Ai\u304B\u3089\u53F3\u5168\u90E8  \u03A3\
    (0,i-1)+\u03A3(i,last)=S[i]+R[i]\n    template <typename T> vector<long long>\
    \ zeta_rev_diff(vector<T> &A) {\n        int N = A.size();\n        vector<long\
    \ long> R(N + 1);\n        for (int i = N - 1; i >= 0; --i) {\n            R[i]\
    \ = R[i + 1];\n            if (i & 1) R[i] += abs((i + 1 < N ? A[i + 1] : 0) -\
    \ A[i]);\n        }\n        return R;\n    }\n    /**\n     * 2\u6B21\u5143\u5E73\
    \u9762\u3067\u306E\u7D2F\u7A4D\u548C\n     * \u5305\u9664: (s,t)~(x,y) = S[y][x]-S[y][s]-S[t][x]+S[t][s]\n\
    \     */\n    template <typename T> vector<vector<long long>> zeta_2D(vector<T>\
    \ &G) {\n        int H = G.size(), W = G[0].size();\n        vector<vector<long\
    \ long>> S(H + 1, vector<long long>(W + 1));\n        for (int i = 0; i < H; ++i)\
    \ { // \u6A2A\u5411\u304D\n            for (int j = 0; j < W; ++j) {\n       \
    \         S[i + 1][j + 1] = S[i + 1][j] + G[i][j];\n            }\n        }\n\
    \        for (int i = 0; i < H; ++i) { // \u7E26\u5411\u304D\n            for\
    \ (int j = 0; j < W; ++j) {\n                S[i + 1][j + 1] += S[i][j + 1];\n\
    \            }\n        }\n        return S;\n    }\n    /**\n     * 3\u6B21\u5143\
    \u7D2F\u7A4D\u548C\n     * ex) Lx Ly Lz\u306F0-indexed Rx Ry Rz\u306F1-indexed\n\
    \     *   S[Rxyz] - S[Lxyz]\n     *          = S[Rx][Ry][Rz] - S[Lx][Ry][Rz] -\
    \ S[Rx][Ly][Rz] -\n     *            S[Rx][Ry][Lz] + S[Lx][Ly][Rz] + S[Lx][Ry][Lz]\
    \ +\n     *            S[Rx][Ly][Lz] - S[Lx][Ly][Lz];\n     */\n    template <typename\
    \ T>\n    vector<vector<vector<long long>>> zeta_3D(vector<vector<vector<T>>>\
    \ &A) {\n        vector<vector<vector<long long>>> S;\n        int szx = A.size(),\
    \ szy = A[0].size(), szz = A[0][0].size();\n        S.resize(szx + 1, vector<vector<long\
    \ long>>(\n                              szy + 1, vector<long long>(szz + 1, 0)));\n\
    \        for (int x = 1; x <= szx; ++x) {\n            for (int y = 1; y <= szy;\
    \ ++y) {\n                for (int z = 1; z <= szz; ++z) {\n                 \
    \   S[x][y][z] = A[x - 1][y - 1][z - 1] + S[x - 1][y][z] +\n                 \
    \                S[x][y - 1][z] + S[x][y][z - 1] -\n                         \
    \        S[x - 1][y - 1][z] - S[x - 1][y][z - 1] -\n                         \
    \        S[x][y - 1][z - 1] + S[x - 1][y - 1][z - 1];\n                }\n   \
    \         }\n        }\n        return S;\n    }\n    // \u5404\u9805\u306E\u5DEE\
    \u306E\u6570\u5217 \u30E1\u30D3\u30A6\u30B9\u5909\u63DB\n    template <typename\
    \ T> vector<long long> moebius(vector<T> &A) {\n        int N = A.size();\n  \
    \      vector<long long> D(N - 1);\n        for (int i = 0; i < N; ++i) D[i] =\
    \ A[i + 1] - A[i];\n        return D;\n    }\n};\n\n\n/** =======================================\
    \ */\n/**               \u63A2\u7D22                      */\n/** =======================================\
    \ */\n\nclass Search {\n  public:\n    /**\n     * \u9806\u5217\u5168\u63A2\u7D22\
    \ O(N!) N\u306F10\u301C12\u7A0B\u5EA6\n     * \u9806\u5217\u306E\u5168\u30D1\u30BF\
    \u30FC\u30F3\u4E2D\u3067\u3084\u308A\u305F\u3044\u95A2\u6570\u3092\u5165\u308C\
    \u308B\n     * \u4F8B) search_permu(A, [&](){cout << A;} );\n     */\n    template\
    \ <typename T, typename F> void perm(vector<T> &A, F f) {\n        sort(all(A));\n\
    \        do {\n            f();\n        } while (next_permutation(all(A)));\n\
    \    }\n    /**\n     * bit\u5168\u63A2\u7D22 O(2^N) N\u306F20\u524D\u5F8C\n \
    \    * \u96C6\u5408A\u306E\u5168\u30D1\u30BF\u30FC\u30F3\u306E\u90E8\u5206\u96C6\
    \u5408\u3092\u8FD4\u3059\n     * {1,2,3} -> { {},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}\
    \ }\n     */\n    template <typename T> vector<vector<T>> bit(vector<T> &A) {\n\
    \        int N = A.size();\n        vector<vector<T>> res;\n        for (long\
    \ long bit = 0; bit < (1ll << N); ++bit) {\n            vector<T> tmp;\n     \
    \       for (int k = 0; k < N; ++k) {\n                if (bit & (1ll << k)) {\n\
    \                    tmp.push_back(A[k]);\n                }\n            }\n\
    \            res.push_back(tmp);\n        }\n        return res;\n    }\n    /**\n\
    \     * \u6574\u6570\u4E0A\u306E\u4E8C\u5206\u63A2\u7D22\n     *     L R\n   \
    \  * x x x o o o o\n     *       \u2191\u3053\u3053\u3092\u6C42\u3081\u308B\n\
    \     * \u6761\u4EF6\uFF1A5 <= x\u306A\u3089\u3001L=4, R=5\n     */\n    template\
    \ <typename F> pair<long long, long long> bi(F f) {\n        long long L = 0,\
    \ R = 1, MID = 0;\n        while (!f(R)) R <<= 1;\n        while (abs(R - L) >\
    \ 1) {\n            MID = L + (R - L) / 2;\n            (f(MID) ? R : L) = MID;\n\
    \        }\n        return make_pair(L, R);\n    }\n    /**\n     * \u5B9F\u6570\
    \u4E0A\u306E\u4E8C\u5206\u63A2\u7D22\n     *     L R\n     * x x x o o o o\n \
    \    *       \u2191\u3053\u3053\u3092\u6C42\u3081\u308B\n     * \u6761\u4EF6\uFF1A\
    3.5 <= x\u306A\u3089\u3001L=3.5, R=3.5 (LR\u306E\u8AA4\u5DEE\u304CEPS\u5185)\n\
    \     */\n    template <typename F> pair<double, double> bi_real(F f) {\n    \
    \    double L = 0, R = 1, MID = 0;\n        while (!f(R)) R *= 2;\n        auto\
    \ ABS = [&]() { return abs(R - L) > EPS; };\n        auto REL = [&]() { return\
    \ abs(R - L) / max(R, L) > EPS; };\n        while (ABS() and REL()) {\n      \
    \      MID = L + (R - L) / 2;\n            (f(MID) ? R : L) = MID;\n        }\n\
    \        return make_pair(L, R);\n    }\n    // \u4EE5\u4E0B\u306E\u8981\u7D20\
    \u6570\n    template <typename T> int bi_le_cnt(vector<T> &v, const T &x) {\n\
    \        sort(all(v));\n        return upper_bound(all(v), x) - v.begin();\n \
    \   }\n    // \u4EE5\u4E0B\u306E\u5024 \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\
    -INF\n    template <typename T> T bi_le_val(vector<T> &v, const T &x) {\n    \
    \    sort(all(v));\n        auto it = upper_bound(all(v), x);\n        return\
    \ (it == v.begin() ? -INF : *--it);\n    }\n    // \u4EE5\u4E0B\u306E\u5024  \u5B58\
    \u5728\u3057\u306A\u3044\u5834\u5408-INF\n    template <typename T> T bi_le_val(const\
    \ set<T> &st, const T &x) {\n        auto it = st.upper_bound(x);\n        return\
    \ (it == st.begin() ? -INF : *--it);\n    }\n    // \u4EE5\u4E0A\u306E\u8981\u7D20\
    \u6570\n    template <typename T> int bi_ge_cnt(vector<T> &v, const T &x) {\n\
    \        sort(all(v));\n        return v.end() - lower_bound(all(v), x);\n   \
    \ }\n    // \u4EE5\u4E0A\u306E\u6700\u5C0F\u5024 \u5B58\u5728\u3057\u306A\u3044\
    \u5834\u5408 INF\n    template <typename T> T bi_ge_val(vector<T> &v, const T\
    \ &x) {\n        sort(all(v));\n        auto it = lower_bound(all(v), x);\n  \
    \      return (it == v.end() ? INF : *it);\n    }\n    // \u4EE5\u4E0A\u306E\u6700\
    \u5C0F\u5024 \u5B58\u5728\u3057\u306A\u3044\u5834\u5408 INF\n    template <typename\
    \ T> T bi_ge_val(const set<T> &st, const T &x) {\n        auto it = st.lower_bound(x);\n\
    \        return (it == st.end() ? INF : *it);\n    }\n    // \u672A\u6E80\u306E\
    \u8981\u7D20\u6570\n    template <typename T> int bi_lt_cnt(vector<T> &v, const\
    \ T &x) {\n        sort(all(v));\n        return lower_bound(all(v), x) - v.begin();\n\
    \    }\n    // \u672A\u6E80\u306E\u6700\u5927\u5024 \u5B58\u5728\u3057\u306A\u3044\
    \u5834\u5408 -INF\n    template <typename T> T bi_lt_val(vector<T> &v, const T\
    \ &x) {\n        sort(all(v));\n        auto it = lower_bound(all(v), x);\n  \
    \      return (it == v.begin() ? -INF : *--it);\n    }\n    // \u672A\u6E80\u306E\
    \u6700\u5927\u5024 \u5B58\u5728\u3057\u306A\u3044\u5834\u5408 -INF\n    template\
    \ <typename T> T bi_lt_val(const set<T> &st, const T &x) {\n        auto it =\
    \ st.lower_bound(x);\n        return (it == st.begin() ? -INF : *--it);\n    }\n\
    \    // \u3088\u308A\u4E0A\u306E\u8981\u7D20\u6570\n    template <typename T>\
    \ int bi_gt_cnt(vector<T> &v, const T &x) {\n        sort(all(v));\n        return\
    \ v.end() - upper_bound(all(v), x);\n    }\n    // \u3088\u308A\u4E0A\u306E\u6700\
    \u5C0F\u5024 \u5B58\u5728\u3057\u306A\u3044\u5834\u5408 INF\n    template <typename\
    \ T> T bi_gt_val(vector<T> &v, const T &x) {\n        sort(all(v));\n        auto\
    \ it = upper_bound(all(v), x);\n        return (it == v.end() ? INF : *it);\n\
    \    }\n    // \u3088\u308A\u4E0A\u306E\u6700\u5C0F\u5024 \u5B58\u5728\u3057\u306A\
    \u3044\u5834\u5408 INF\n    template <typename T> T bi_gt_val(const set<T> &st,\
    \ const T &x) {\n        auto it = st.upper_bound(x);\n        return (it == st.end()\
    \ ? INF : *it);\n    }\n    // \u30E1\u30E2\u5316\u518D\u5E30 !!\u30B3\u30D4\u30DA\
    \u7528!! \u95A2\u6570\u5185\u3092\u30DA\u30FC\u30B9\u30C8\u3057\u3066\u66F8\u304D\
    \u63DB\u3048\u3066\u4F7F\u3046\n    void dfs_memo() {\n        map<int, int> memo;\n\
    \        auto dfs = [&](auto f, int n) {\n            if (n <= 1) return n;\n\
    \            if (memo.count(n)) return memo[n];\n            return memo[n] =\
    \ f(f, n - 1) + f(f, n - 2);\n        };\n        // int ans = dfs(dfs, N);\n\
    \    }\n};\n\n\n/** ======================================= */\n/**          \
    \     \u30B0\u30EA\u30C3\u30C9                  */\n/** =======================================\
    \ */\n\nclass Grid {\n  public:\n    // \u884C\u5217\u306E\u8EE2\u7F6E\n    template\
    \ <typename T>\n    vector<vector<T>> transpose(const vector<vector<T>> &G) {\n\
    \        int H = G.size(), W = G[0].size();\n        vector<vector<T>> _G(W, vector<T>(H));\n\
    \        for (int i = 0; i < H; ++i) {\n            for (int j = 0; j < W; ++j)\
    \ {\n                _G[j][i] = G[i][j];\n            }\n        }\n        return\
    \ _G;\n    }\n    // \u30B0\u30EA\u30C3\u30C94\u65B9\u3092\u898B\u308BBFS \u5F15\
    \u6570f(y, x)\n    template <typename T, typename F> void bfs(vector<vector<T>>\
    \ &G, F f) {\n        int H = G.size(), W = G[0].size();\n        for (int i =\
    \ 0; i < H; ++i) {\n            for (int j = 0; j < W; ++j) {\n              \
    \  for (int k = 0; k < 4; ++k) {\n                    int y = i + dy[k], x = j\
    \ + dx[k];\n                    if (y < 0 or x < 0 or H <= y or W <= x) continue;\n\
    \                    f(y, x);\n                }\n            }\n        }\n \
    \   }\n    // \u30B0\u30EA\u30C3\u30C98\u65B9\u3092\u898B\u308BBFS \u5F15\u6570\
    f(y, x)\n    template <typename T, typename F> void bfs8(vector<vector<T>> &G,\
    \ F f) {\n        int H = G.size(), W = G[0].size();\n        for (int i = 0;\
    \ i < H; ++i) {\n            for (int j = 0; j < W; ++j) {\n                for\
    \ (int k = 0; k < 8; ++k) {\n                    int y = i + dy8[k], x = j + dx8[k];\n\
    \                    if (y < 0 or x < 0 or H <= y or W <= x) continue;\n     \
    \               f(y, x);\n                }\n            }\n        }\n    }\n\
    };\n\n\n/** ======================================= */\n/**               \u5E7E\
    \u4F55                      */\n/** ======================================= */\n\
    \nclass Geometry {\n  public:\n    // \u5EA6\u6570\u6CD5 \u2192 \u5F27\u5EA6\u6CD5\
    \n    double deg_to_rad(double d) {\n        return d * PI / 180;\n    }\n   \
    \ // \u5F27\u5EA6\u6CD5 \u2192 \u5EA6\u6570\u6CD5\n    double rad_to_deg(double\
    \ r) {\n        return r * 180 / PI;\n    }\n    // \u504F\u89D2\u3092\u30E9\u30B8\
    \u30A2\u30F3\u3067\u8FD4\u3059\n    double arc_tan(double x, double y) {\n   \
    \     return atan2(y, x);\n    }\n    /**\n     * \u4E09\u89D2\u5F62\u306E\u9762\
    \u7A4D\n     * double\u306F\u6841\u6570\u8868\u73FE11bit\u3092\u9664\u304D\u3001\
    52bit\u7A0B\u5EA6\u306E\u7CBE\u5EA6\n     * 18\u6841\u4F7F\u3046\u306A\u30892\u3067\
    \u5272\u3089\u305Along long\u3067\u8FD4\u3059\u3053\u3068\n     */\n    template\
    \ <typename T>\n    double area_triangle(T x1, T y1, T x2, T y2, T x3, T y3) {\n\
    \        return abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2.0;\n  \
    \  }\n    /**\n     * \u56DB\u89D2\u5F62\u306E\u9762\u7A4D\n     * double\u306F\
    \u6841\u6570\u8868\u73FE11bit\u3092\u9664\u304D\u300152bit\u7A0B\u5EA6\u306E\u7CBE\
    \u5EA6\n     * 18\u6841\u4F7F\u3046\u306A\u30892\u3067\u5272\u3089\u305Along long\u3067\
    \u8FD4\u3059\u3053\u3068\n     */\n    template <typename T>\n    double area_square(T\
    \ x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4) {\n        return hypot(x1 - x3,\
    \ y1 - y3) * hypot(x2 - x4, y2 - y4) / 2.0;\n    }\n};\n\n\n/** =======================================\
    \ */\n/**               \u30B0\u30E9\u30D5                    */\n/** =======================================\
    \ */\n\nstruct Edge {\n    int from, to;\n    long long cost;\n    Edge(int from,\
    \ int to, long long cost = 1)\n        : from(from), to(to), cost(cost) {\n  \
    \  }\n};\nstruct Graph {\n  private:\n    int N;\n    vector<vector<Edge>> G;\n\
    \n  public:\n    Graph(int N) : N(N), G(N) {\n    }\n    vector<Edge> operator[](int\
    \ v) {\n        return G[v];\n    }\n    int size() {\n        return N;\n   \
    \ }\n    // (\u6709\u5411)\u8FBA\u3092\u5F35\u308B\n    void add(int from, int\
    \ to, long long cost = 1) {\n        G[from].push_back(Edge(from, to, cost));\n\
    \    }\n    // (\u53CC\u65B9\u5411)\u8FBA\u3092\u5F35\u308B\n    void add_both(int\
    \ from, int to) {\n        G[from].push_back(Edge(from, to));\n        G[to].push_back(Edge(to,\
    \ from));\n    }\n    // \u7D4C\u8DEF\u5FA9\u5143\n    vector<int> route_restore(const\
    \ vector<int> &route, int goal) {\n        vector<int> path = {goal};\n      \
    \  while (!~route[path.back()]) path.push_back(route[path.back()]);\n        reverse(all(path));\n\
    \        return path;\n    }\n    /**\n     * BFS \u6700\u77ED\u7D4C\u8DEF \u8907\
    \u6570\u59CB\u70B9\n     * @return \u6700\u77ED\u8DDD\u96E2\u3001\u7D4C\u8DEF\n\
    \     */\n    pair<vector<int>, vector<int>> bfs(const vector<int> &starts = {0})\
    \ {\n        queue<int> q;\n        vector<int> dis(N, -1), route(N, -1);\n  \
    \      for (auto &&v : starts) q.push(v), dis[v] = 0;\n        while (!q.empty())\
    \ {\n            int v = q.front();\n            q.pop();\n            for (auto\
    \ &&[from, to, cost] : G[v]) {\n                if (~dis[to]) continue;\n    \
    \            dis[to] = dis[from] + 1;\n                q.push(to);\n         \
    \       route[to] = v;\n            }\n        }\n        return {dis, route};\n\
    \    }\n    /**\n     * Dijkstra \u6700\u5C0F\u30B3\u30B9\u30C8\u7D4C\u8DEF \u8907\
    \u6570\u59CB\u70B9\n     * @return \u6700\u5C0F\u30B3\u30B9\u30C8\u3001\u7D4C\u8DEF\
    \n     */\n    pair<vector<long long>, vector<int>> dijkstra(const vector<int>\
    \ &starts = {\n                                                      0}) {\n \
    \       reverse_queue<pair<long long, int>> q; // \u30B3\u30B9\u30C8(\u5C0F\u3055\
    \u3044\u9806), \u9802\u70B9\n        vector<long long> weight(N, INF);\n     \
    \   vector<int> route(N, -1);\n        for (auto &&v : starts) q.emplace(0, v),\
    \ weight[v] = 0;\n        while (!q.empty()) {\n            auto [w, v] = q.top();\n\
    \            q.pop();\n            if (weight[v] < w) continue;\n            for\
    \ (auto &&[from, to, cost] : G[v]) {\n                long long next_w = w + cost;\n\
    \                if (weight[to] <= next_w) continue;\n                weight[to]\
    \ = next_w;\n                q.emplace(weight[to], to);\n                route[to]\
    \ = v;\n            }\n        }\n        return {weight, route};\n    }\n   \
    \ /**\n     * DAG\u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n\
    \     */\n    vector<int> topological_sort() {\n        // TODO \u9589\u8DEF\u691C\
    \u77E5\u3057\u3066\u7A7A\u914D\u5217\u3092\u8FD4\u5374\u3068\u304B\n        vector<int>\
    \ seen(N, 0), sorted;\n        auto dfs = [&](auto &f, int v) -> void {\n    \
    \        seen[v] = 1;\n            for (auto &&[from, to, cost] : G[v]) {\n  \
    \              if (!seen[to]) f(f, to);\n            }\n            sorted.push_back(v);\n\
    \        };\n        for (int i = 0; i < N; ++i) {\n            if (!seen[i])\
    \ dfs(dfs, i);\n        }\n        reverse(all(sorted));\n        return sorted;\n\
    \    }\n    // TODO cc\n    // TODO scc\n    // TODO \u30D9\u30EB\u30DE\u30F3\u30D5\
    \u30A9\u30FC\u30C9\n    // TODO \u30B5\u30A4\u30AF\u30EB\u691C\u51FA\n    // TODO\
    \ \u30AF\u30E9\u30B9\u30AB\u30EB\n    // TODO \u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\
    \u30ED\u30A4\u30C9\n    // TODO \u30C9\u30AD\u30E5\u30E1\u30F3\u30C8\n};\n\n\n\
    /**\n * @brief UnionFind\n */\nstruct UnionFind {\n  private:\n    vector<int>\
    \ parent, size;\n\n  public:\n    UnionFind(int N) {\n        parent.assign(N,\
    \ -1);\n        size.assign(N, 1);\n    }\n    // \u81EA\u5206\u306E\u30B0\u30EB\
    \u30FC\u30D7\u306E\u30B5\u30A4\u30BA\n    int operator[](int p) {\n        return\
    \ size[find(p)];\n    }\n    // p\u306E\u89AA\u3092\u898B\u3064\u3051\u308B\n\
    \    int find(int p) {\n        return !~parent[p] ? p : (parent[p] = find(parent[p]));\n\
    \    }\n    // a\u3068b\u3092\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\u3059\u308B\
    \ \u64CD\u4F5C\u3057\u305F\u3089true\n    bool unite(int a, int b) {\n       \
    \ int x = find(a), y = find(b);\n        if (x == y) return false;\n        if\
    \ (size[x] > size[y]) swap(x, y);\n        parent[x] = y, size[y] += size[x];\n\
    \        return true;\n    }\n};\n\n\n/**\n * @brief FenwicTree 1\u70B9\u66F4\u65B0\
    \ \u533A\u9593\u53D6\u5F97 \u548C\u306E\u307F\n */\nstruct FenwickTree {\n  private:\n\
    \    int N;\n    vector<int> fwk;\n\n  public:\n    FenwickTree(int N) : N(N)\
    \ {\n        fwk.assign(N + 1, 0);\n    }\n    FenwickTree(const vector<int> &A)\
    \ : N(A.size()) {\n        fwk.assign(N + 1, 0);\n        for (int i = 1; i <=\
    \ N; ++i) {\n            fwk[i] += A[i - 1];\n            if (i + (i & -i) <=\
    \ N) fwk[i + (i & -i)] += fwk[i];\n        }\n    }\n    // \u5024\u3092\u52A0\
    \u3048\u308B\n    void add(int i, const int &x) {\n        for (++i; i <= N; i\
    \ += i & -i) fwk[i] += x;\n    }\n    // \u03A3[0, i]\n    int sum(int i) {\n\
    \        int ans = 0;\n        for (++i; i; i -= i & -i) ans += fwk[i];\n    \
    \    return ans;\n    }\n};\n\n\n/**\n * @brief SegmentTree 1\u70B9\u66F4\u65B0\
    \ \u533A\u9593\u53D6\u5F97\n */\ntemplate <class Monoid> struct SegmentTree {\n\
    \    using T = typename Monoid::T;\n\n  private:\n    Monoid M;\n    int N, size,\
    \ log = 1;\n    vector<T> node;\n    void init() {\n        while ((1 << log)\
    \ < N) ++log;\n        node.assign((size = 1 << log) << 1, M.e());\n    }\n\n\
    \  public:\n    SegmentTree(Monoid M, int N) : M(M), N(N) {\n        init();\n\
    \    }\n    SegmentTree(Monoid M, const vector<T> &A) : M(M), N(A.size()) {\n\
    \        init();\n        for (int i = 0; i < N; ++i) node[i + size] = A[i];\n\
    \        for (int i = size - 1; i >= 1; --i)\n            node[i] = M.op(node[i\
    \ << 1 | 0], node[i << 1 | 1]);\n    }\n    // \u8981\u7D20i\u306E\u5024\u3092\
    x\u306B\u3059\u308B\n    void set(int i, const T &x) {\n        node[i += size]\
    \ = x;\n        while (i >>= 1) node[i] = M.op(node[i << 1 | 0], node[i << 1 |\
    \ 1]);\n    }\n    // \u6F14\u7B97[l,r)\n    T prod(int l, int r) {\n        T\
    \ L = M.e(), R = M.e();\n        for (l += size, r += size; l < r; l >>= 1, r\
    \ >>= 1) {\n            if (l & 1) L = M.op(L, node[l++]);\n            if (r\
    \ & 1) R = M.op(node[--r], R);\n        }\n        return M.op(L, R);\n    }\n\
    };\n\n\n/** ======================================= */\n/**              \u30E2\
    \u30CE\u30A4\u30C9                   */\n/** =======================================\
    \ */\n\ntemplate <typename U, typename F> struct Monoid {\n    using T = U;\n\n\
    \  private:\n    T _e;\n    F _op;\n\n  public:\n    Monoid(T e, F op) : _e(e),\
    \ _op(op) {\n    }\n    T op(const T &x, const T &y) {\n        return _op(x,\
    \ y);\n    }\n    T e() {\n        return _e;\n    }\n};\ntemplate <typename U\
    \ = int> struct MonoidMin {\n    using T = U;\n    T op(const T &x, const T &y)\
    \ {\n        return min(x, y);\n    }\n    T e() {\n        return INF;\n    }\n\
    };\ntemplate <typename U = int> struct MonoidMax {\n    using T = U;\n    T op(const\
    \ T &x, const T &y) {\n        return max(x, y);\n    }\n    T e() {\n       \
    \ return -INF;\n    }\n};\ntemplate <typename U = int> struct MonoidAdd {\n  \
    \  using T = U;\n    T op(const T &x, const T &y) {\n        return x + y;\n \
    \   }\n    T e() {\n        return 0ll;\n    }\n};\ntemplate <typename U = int>\
    \ struct MonoidMul {\n    using T = U;\n    T op(const T &x, const T &y) {\n \
    \       return x * y;\n    }\n    T e() {\n        return 1ll;\n    }\n};\ntemplate\
    \ <typename U = int> struct MonoidGcd {\n    using T = U;\n    T op(const T &x,\
    \ const T &y) {\n        return gcd(x, y);\n    }\n    T e() {\n        return\
    \ 0ll;\n    }\n};\ntemplate <typename U = int> struct MonoidLcm {\n    using T\
    \ = U;\n    T op(const T &x, const T &y) {\n        return lcm(x, y);\n    }\n\
    \    T e() {\n        return 1ll;\n    }\n};\ntemplate <typename U = int> struct\
    \ MonoidXor {\n    using T = U;\n    T op(const T &x, const T &y) {\n        return\
    \ x ^ y;\n    }\n    T e() {\n        return 0ll;\n    }\n};\n\nnamespace lib\
    \ {\nNumber num;\nString str;\nSequence seq;\nSearch search;\nGrid grid;\nGeometry\
    \ geo;\n}; // namespace lib\nvoid solve();\nsigned main() {\n    solve();\n}\n\
    // -----------------------------------------\n// #include \"template/template.hpp\"\
    \ is done.\n// -----------------------------------------\n\n/**\n * @brief \U0001F36A\
    \U0001F9F8\U0001F43E\n */\nvoid solve() {\n}\n\n"
  code: "/**\n * @brief \u0E05^>\u03C9<^\u0E05\n * @author serna37\n * @note https://serna37.github.io/library-cpp/\n\
    \ */\n#ifdef LOCAL\n\n#else\n#define debug(...)\n#endif\n#include <bits/stdc++.h>\n\
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
    \ */\n\nstruct IoSetup {\n    IoSetup() {\n        cin.tie(0)->sync_with_stdio(0);\n\
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
    \ greater<T>>;\ntemplate <typename T> using vec2 = vector<vector<T>>;\nvec2<int>\
    \ make_vec2(int H, int W, int init = 0) {\n    return vector<vector<int>>(H, vector<int>(W,\
    \ init));\n}\nchar int_to_char(int x) {\n    return (char)(x + '0');\n}\nchar\
    \ int_to_alph(int x) {\n    return (char)(x + 'a');\n}\nint char_to_int(char c)\
    \ {\n    return (int)(c - '0');\n}\nstring int_to_string(long long x) {\n    return\
    \ to_string(x);\n}\nlong long string_to_int(string s) {\n    return stoll(s);\n\
    }\n\n\n/** ======================================= */\n/**              \u5B9A\
    \u6570                       */\n/** ======================================= */\n\
    \nconst long long INF = 1e18;\nconst long long MAX = 2e6;\nconst long long MOD\
    \ = 998244353;\nconst long long MOD7 = 1e9 + 7;\nconst long double EPS = 1e-14;\n\
    const double PI = acos(-1);\n// \u4E0B\u53F3\u4E0A\u5DE6 DRUL\nconst vector<int>\
    \ dx = {0, 1, 0, -1};\nconst vector<int> dy = {1, 0, -1, 0};\n// 8\u65B9\u5411\
    \nconst vector<int> dx8 = {0, 1, 0, -1, 1, -1, 1, -1};\nconst vector<int> dy8\
    \ = {1, 0, -1, 0, 1, 1, -1, -1};\n\n\n/** =======================================\
    \ */\n/**           \u6570\u306E\u6027\u8CEA                      */\n/** =======================================\
    \ */\n\nclass Number {\n  private:\n    // mod\u968E\u4E57\u306E\u30E1\u30E2\u914D\
    \u5217\n    vector<long long> _mf;\n\n  public:\n    // \u5272\u308A\u4E0B\u3052\
    \uFF08\u8CA0\u306E\u5834\u54080\u5074\u3078\u4E38\u3081\u306A\u3044\uFF09\n  \
    \  template <typename T> T div_ceil(T a, T b) {\n        return a / b + (((a ^\
    \ b) > 0 and a % b != 0) ? 1 : 0);\n    }\n    // \u5272\u308A\u4E0A\u3052\uFF08\
    \u8CA0\u306E\u5834\u54080\u5074\u3078\u4E38\u3081\u306A\u3044\uFF09\n    template\
    \ <typename T> T div_floor(T a, T b) {\n        return a / b - (((a ^ b) < 0 and\
    \ a % b != 0) ? 1 : 0);\n    }\n    // \u968E\u4E57 \u30CA\u30A4\u30FC\u30D6\n\
    \    long long factorial(int N) {\n        long long res = 1;\n        while (N\
    \ > 0) res *= N--;\n        return res;\n    }\n    // nCk\n    long long combination(int\
    \ n, int k) {\n        if (k < 0 || n < k) return 0ll;\n        long long res\
    \ = 1;\n        for (int i = 1; i <= k; ++i) {\n            res *= n--;\n    \
    \        res /= i;\n        }\n        return res;\n    }\n    // \u6841\u548C\
    \n    int digit_sum(int a, int N = 10) {\n        int res = 0;\n        while\
    \ (a != 0) {\n            res += a % N;\n            a /= N;\n        }\n    \
    \    return res;\n    }\n    // \u9032\u6570\u5909\u63DB from\u3068to\u306F10\u3092\
    \u8D85\u3048\u306A\u3044\u3053\u3068\n    string base_convert(string a, int from,\
    \ int to) {\n        long long cvt = 0ll; // 10\u9032\u6570\u306B\u76F4\u3059\n\
    \        for (auto &&v : a) cvt = cvt * from + (int)(v - '0');\n        if (cvt\
    \ == 0) return \"0\";\n        string res = \"\"; // to\u9032\u6570\u306B\u76F4\
    \u3059\n        while (cvt) {    // 10\u9032\u6570\u3067\u8868\u305B\u308B\u7BC4\
    \u56F2\u306E\u6587\u5B57\u3057\u304B\u6271\u3063\u3066\u3044\u306A\u3044\n   \
    \         res = (char)(cvt % to + '0') + res;\n            cvt /= to;\n      \
    \  }\n        return res;\n    }\n    // \u7D04\u6570\u5217\u6319\n    vector<int>\
    \ divisors(int a) {\n        vector<int> res;\n        for (int i = 1; i * i <=\
    \ a; ++i) {\n            if (a % i != 0) continue;\n            res.push_back(i);\n\
    \            if (a / i != i) res.push_back(a / i);\n        }\n        return\
    \ res;\n    }\n    // \u7D20\u6570\u5224\u5B9A\n    bool prime_test(int N) {\n\
    \        if (N == 2) return true;\n        if (N == 1 or N % 2 == 0) return false;\n\
    \        for (int i = 3; i * i <= N; i += 2) {\n            if (N % i == 0) return\
    \ false;\n        }\n        return true;\n    }\n    // \u7D20\u56E0\u6570\u5206\
    \u89E3\n    map<int, int> prime_fact(int N) {\n        map<int, int> P;\n    \
    \    for (int i = 2; i * i <= N; ++i) {\n            while (N % i == 0) {\n  \
    \              ++P[i];\n                N /= i;\n            }\n        }\n  \
    \      if (N > 1) ++P[N];\n        return P;\n    }\n    // \u4E8C\u5206\u7D2F\
    \u4E57(mod)\n    long long modpow(long long a, long long n, long long m) {\n \
    \       long long res = 1ll;\n        while (n > 0) {\n            if (n & 1)\
    \ res = res * a % m;\n            a = a * a % m;\n            n >>= 1ll;\n   \
    \     }\n        return res;\n    }\n    // Fermat\u306E\u5C0F\u5B9A\u7406 \u9006\
    \u5143\u3092\u6C42\u3081\u308B\n    long long modinv(long long a, long long m)\
    \ {\n        return modpow(a, m - 2, m);\n    }\n    // mod\u968E\u4E57\n    long\
    \ long modfact(int x, long long m) {\n        if ((int)_mf.size() > x) return\
    \ _mf[x];\n        if (_mf.empty()) _mf.push_back(1);\n        for (int i = _mf.size();\
    \ i <= x; ++i) _mf.push_back(_mf.back() * i % m);\n        return _mf[x];\n  \
    \  }\n    // mod\u7D44\u307F\u5408\u308F\u305BnCk\n    long long mod_combination(int\
    \ n, int k, long long m) {\n        return modfact(n, m) * modinv(modfact(k, m),\
    \ m) % m *\n               modinv(modfact(n - k, m), m) % m;\n    }\n};\n\n\n\
    /** ======================================= */\n/**              \u6587\u5B57\u5217\
    \                     */\n/** ======================================= */\n\nclass\
    \ String {\n  public:\n    bool is_low(char c) {\n        return islower(c) !=\
    \ 0;\n    }\n    bool is_upp(char c) {\n        return isupper(c) != 0;\n    }\n\
    \    // \u5C0F\u6587\u5B57\u306B\u5909\u63DB\n    string transform_lower(string\
    \ s) {\n        std::transform(all(s), s.begin(), ::tolower);\n        return\
    \ s;\n    }\n    // \u5927\u6587\u5B57\u306B\u5909\u63DB\n    string transform_upper(string\
    \ s) {\n        std::transform(all(s), s.begin(), ::toupper);\n        return\
    \ s;\n    }\n    // \u300C0000ABCDE\u300D\u5DE6\u5074\u3092\u57CB\u3081\u305F\
    size\u6841\u306E\u6587\u5B57\n    string lpad(const string &S, int size, char\
    \ ch = '0') {\n        int N = S.size();\n        if (N >= size) return S;\n \
    \       return string(size - N, ch) + S;\n    }\n    // \u300CABCDE0000\u300D\u53F3\
    \u3092\u57CB\u3081\u305Fsize\u6841\u306E\u6587\u5B57\n    string rpad(const string\
    \ &S, int size, char ch = '0') {\n        int N = S.size();\n        if (N >=\
    \ size) return S;\n        return S + string(size - N, ch);\n    }\n    /**\n\
    \     * \u6587\u5B57\u5217T\u306E\u4E2D\u306B\u3042\u308BS\u306E\u4E00\u81F4\u5834\
    \u6240\u3092\u5168\u3066\u53D6\u5F97\n     * \u30DE\u30C3\u30C1\u3057\u305F\u982D\
    \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u8FD4\u3059\n     */\n    vector<int>\
    \ finds(const string &T, const string &S) {\n        vector<int> pos;\n      \
    \  auto p = T.find(S);\n        while (p != string::npos) {\n            pos.emplace_back(p);\n\
    \            p = T.find(S, p + 1);\n        }\n        return pos;\n    }\n  \
    \  // \u533A\u5207\u308A\u6587\u5B57(1\u6587\u5B57)\u3067\u533A\u5207\u308B\n\
    \    vector<string> split(const string &S, const char &sep) {\n        vector<string>\
    \ res = {\"\"};\n        for (auto &&v : S) {\n            if (v == sep) {\n \
    \               res.emplace_back(\"\");\n            } else {\n              \
    \  res.back() += v;\n            }\n        }\n        return res;\n    }\n  \
    \  // \u8907\u6570\u306E\u533A\u5207\u308A\u6587\u5B57\u3067\u533A\u5207\u308B\
    \ \u533A\u5207\u308A\u6587\u5B57\u304C\u306A\u3044\u5834\u5408\u7A7A\u6587\u5B57\
    \n    vector<string> split_multi(const string &S, const string &seps) {\n    \
    \    vector<string> res = {\"\"};\n        for (auto &&v : S) {\n            if\
    \ (count(all(seps), v)) {\n                res.emplace_back(\"\");\n         \
    \   } else {\n                res.back() += v;\n            }\n        }\n   \
    \     return res;\n    }\n    // \u6587\u5B57\u5217\u306E\u533A\u9593[A, B]\u3092\
    \u53D6\u5F97\n    string str_range(const string &S, int A, int B) {\n        if\
    \ (A > B or A >= (int)S.size()) return \"\";\n        return S.substr(A, B - A\
    \ + 1);\n    }\n    // \u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\n    vector<pair<char,\
    \ int>> run_length(const string &S) {\n        vector<pair<char, int>> res;\n\
    \        for (auto &&x : S) {\n            if (res.empty() or res.back().first\
    \ != x) res.emplace_back(x, 0);\n            ++res.back().second;\n        }\n\
    \        return res;\n    }\n    // Z-Algorithm: S\u3068S[i:|S|]\u306E\u6700\u5927\
    \u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\n    vector<int> z_algo(const\
    \ string &S) {\n        int n = S.size();\n        if (n == 0) return {};\n  \
    \      vector<int> z(n);\n        z[0] = n;\n        for (int i = 1, j = 0; i\
    \ < n; ++i) {\n            int &k = z[i];\n            k = (j + z[j] <= i) ? 0\
    \ : min(j + z[j] - i, z[i - j]);\n            while (i + k < n and S[k] == S[i\
    \ + k]) ++k;\n            if (j + z[j] < i + z[i]) j = i;\n        }\n       \
    \ return z;\n    }\n};\n\n\n/** ======================================= */\n/**\
    \              \u914D\u5217\u30FB\u6570\u5217                 */\n/** =======================================\
    \ */\n\nclass Sequence {\n  public:\n    template <typename T> T min(const vector<T>\
    \ &v) {\n        return *min_element(all(v));\n    }\n    template <typename T>\
    \ T max(const vector<T> &v) {\n        return *max_element(all(v));\n    }\n \
    \   template <typename T> long long sum(const vector<T> &v) {\n        return\
    \ accumulate(all(v), 0ll);\n    }\n    template <typename T, typename F> bool\
    \ all_match(const vector<T> &v, F f) {\n        return all_of(all(v), f);\n  \
    \  }\n    template <typename T, typename F> bool none_match(const vector<T> &v,\
    \ F f) {\n        return none_of(all(v), f);\n    }\n    template <typename T,\
    \ typename F> bool any_match(const vector<T> &v, F f) {\n        return any_of(all(v),\
    \ f);\n    }\n    template <typename T> void distinct(vector<T> &v) {\n      \
    \  sort(all(v));\n        v.erase(unique(all(v)), v.end());\n    }\n    template\
    \ <typename T> void sort_asc(vector<T> &v) {\n        sort(all(v));\n    }\n \
    \   template <typename T> void sort_desc(vector<T> &v) {\n        sort(rall(v));\n\
    \    }\n    template <typename T> void reverse(vector<T> &v) {\n        reverse(all(v));\n\
    \    }\n    // set\u304B\u3089\u8981\u7D20\u524A\u9664\n    template <typename\
    \ T> void erase(set<T> &st, T &v) {\n        st.erase(st.find(v));\n    }\n  \
    \  // multiset\u304B\u3089\u8981\u7D20\u524A\u9664\n    template <typename T>\
    \ void erase(multiset<T> &st, T &v) {\n        st.erase(st.find(v));\n    }\n\
    \    // \u884C\u5217\u306E\u8EE2\u7F6E\n    template <typename T>\n    vector<vector<T>>\
    \ transpose(const vector<vector<T>> &G) {\n        int H = G.size(), W = G[0].size();\n\
    \        vector<vector<T>> _G(W, vector<T>(H));\n        for (int i = 0; i < H;\
    \ ++i) {\n            for (int j = 0; j < W; ++j) {\n                _G[j][i]\
    \ = G[i][j];\n            }\n        }\n        return _G;\n    }\n    /**\n \
    \    * \u5206\u5272\u4EE3\u5165\u3067\u304D\u308B\u3088\u3046\u306B\u3059\u308B\
    \ G\u306F\u7834\u58CA\u3002\n     * auto [a,b] = unpack<2>(move(G));\n     */\n\
    \    template <int N, typename T> auto unpack(vector<T> &&G) {\n        array<T,\
    \ N> res; // vector -> array\u5909\u63DB\u3059\u308B\u3060\u3051\n        for\
    \ (int i = 0; i < N; ++i) res[i] = move(G[i]);\n        return res;\n    }\n \
    \   // \u9023\u756A\u751F\u6210\n    template <typename T> void renban(vector<T>\
    \ &v, T start = 0) {\n        iota(all(v), start);\n    }\n    // A\u3092B\u306B\
    \u30DE\u30FC\u30B8\u30C6\u30AF vector\n    template <typename T> void merge(vector<T>\
    \ &A, vector<T> &B) {\n        if (A.size() > B.size()) swap(A, B);\n        for\
    \ (auto &&v : A) B.push_back(v);\n        A.clear();\n    }\n    // A\u3092B\u306B\
    \u30DE\u30FC\u30B8\u30C6\u30AF set\n    template <typename T> void merge(set<T>\
    \ &A, set<T> &B) {\n        if (A.size() > B.size()) swap(A, B);\n        for\
    \ (auto &&v : A) B.insert(v);\n        A.clear();\n    }\n    // A\u3092B\u306B\
    \u30DE\u30FC\u30B8\u30C6\u30AF \u30DE\u30FC\u30B8\u64CD\u4F5C\u3092\u30E9\u30E0\
    \u30C0\u5316\n    template <typename T, typename F> void merge(T &A, T &B, F f)\
    \ {\n        if (A.size() > B.size()) swap(A, B);\n        for (auto &&v : A)\
    \ {\n            f(B, v);\n        }\n        A.clear();\n    }\n    // \u6570\
    \u76F4\u7DDA\u4E0A\u3067\u306E\u500B\u6570\u306B\u306A\u304A\u3059\n    vector<int>\
    \ coordinate(const vector<int> &A) {\n        vector<int> res(MAX);\n        for\
    \ (auto &&v : A) ++res[v];\n        return res;\n    }\n    // \u5EA7\u6A19\u5727\
    \u7E2E \u5727\u7E2E\u5F8C\u306E\u7A2E\u985E\u6570\u3092\u8FD4\u5374\n    template\
    \ <typename T> int zip_coordinate(vector<T> &A) {\n        vector<T> cvt = A;\n\
    \        distinct(cvt);\n        for (auto &v : A) v = lower_bound(all(cvt), v)\
    \ - cvt.begin();\n        return (int)cvt.size();\n    }\n    // \u8EE2\u5012\u6570\
    \ \u53F3\u306B\u5012\u308C\u308BA_i > A_j (i < j)\u306E\u56DE\u6570\n    template\
    \ <typename T> long long inversion_number(vector<T> &A) {\n        int sz = zip_coordinate(A);\n\
    \        vector<int> fwk(sz + 1);\n        long long inv = 0, N = A.size();\n\
    \        for (int i = 0; i < N; ++i) {\n            for (int f = sz; f; f -= f\
    \ & -f) inv += fwk[f];\n            for (int f = A[i] + 1; f; f -= f & -f) inv\
    \ -= fwk[f];\n            for (int f = A[i] + 1; f <= sz; f += f & -f) ++fwk[f];\n\
    \        }\n        return inv;\n    }\n    // \u7D2F\u7A4D\u548C S[i]=\u03A3\
    (0,i-1)  \u03A3[l,r)=S[r]-S[l]\n    template <typename T> vector<long long> zeta(vector<T>\
    \ &A) {\n        int N = A.size();\n        vector<long long> S(N + 1);\n    \
    \    for (int i = 0; i < N; ++i) S[i + 1] = S[i] + A[i];\n        return S;\n\
    \    }\n    // \u53CD\u8EE2\u7D2F\u7A4D\u548C S[i]=Ai\u304B\u3089\u53F3\u5168\u90E8\
    \  \u03A3(0,i-1)+\u03A3(i,last)=S[i]+R[i]\n    template <typename T> vector<long\
    \ long> zeta_rev(vector<T> &A) {\n        int N = A.size();\n        vector<long\
    \ long> R(N + 1);\n        for (int i = N - 1; i >= 0; --i) R[i] = R[i + 1] +\
    \ A[i];\n        return R;\n    }\n    // \u4E8C\u9805\u5DEE\u3067\u306E\u7D2F\
    \u7A4D\u548C S[i]=\u03A3(0,i-1)  \u03A3[l,r)=S[r]-S[l]\n    template <typename\
    \ T> vector<long long> zeta_diff(vector<T> &A) {\n        int N = A.size();\n\
    \        vector<long long> S(N + 1);\n        for (int i = 0; i < N; ++i) {\n\
    \            S[i + 1] = S[i];\n            if (i & 1) S[i + 1] += abs(A[i] - A[i\
    \ - 1]);\n        }\n        return S;\n    }\n    // \u4E8C\u9805\u5DEE\u3067\
    \u306E\u53CD\u8EE2\u7D2F\u7A4D\u548C S[i]=Ai\u304B\u3089\u53F3\u5168\u90E8  \u03A3\
    (0,i-1)+\u03A3(i,last)=S[i]+R[i]\n    template <typename T> vector<long long>\
    \ zeta_rev_diff(vector<T> &A) {\n        int N = A.size();\n        vector<long\
    \ long> R(N + 1);\n        for (int i = N - 1; i >= 0; --i) {\n            R[i]\
    \ = R[i + 1];\n            if (i & 1) R[i] += abs((i + 1 < N ? A[i + 1] : 0) -\
    \ A[i]);\n        }\n        return R;\n    }\n    /**\n     * 2\u6B21\u5143\u5E73\
    \u9762\u3067\u306E\u7D2F\u7A4D\u548C\n     * \u5305\u9664: (s,t)~(x,y) = S[y][x]-S[y][s]-S[t][x]+S[t][s]\n\
    \     */\n    template <typename T> vector<vector<long long>> zeta_2D(vector<T>\
    \ &G) {\n        int H = G.size(), W = G[0].size();\n        vector<vector<long\
    \ long>> S(H + 1, vector<long long>(W + 1));\n        for (int i = 0; i < H; ++i)\
    \ { // \u6A2A\u5411\u304D\n            for (int j = 0; j < W; ++j) {\n       \
    \         S[i + 1][j + 1] = S[i + 1][j] + G[i][j];\n            }\n        }\n\
    \        for (int i = 0; i < H; ++i) { // \u7E26\u5411\u304D\n            for\
    \ (int j = 0; j < W; ++j) {\n                S[i + 1][j + 1] += S[i][j + 1];\n\
    \            }\n        }\n        return S;\n    }\n    /**\n     * 3\u6B21\u5143\
    \u7D2F\u7A4D\u548C\n     * ex) Lx Ly Lz\u306F0-indexed Rx Ry Rz\u306F1-indexed\n\
    \     *   S[Rxyz] - S[Lxyz]\n     *          = S[Rx][Ry][Rz] - S[Lx][Ry][Rz] -\
    \ S[Rx][Ly][Rz] -\n     *            S[Rx][Ry][Lz] + S[Lx][Ly][Rz] + S[Lx][Ry][Lz]\
    \ +\n     *            S[Rx][Ly][Lz] - S[Lx][Ly][Lz];\n     */\n    template <typename\
    \ T>\n    vector<vector<vector<long long>>> zeta_3D(vector<vector<vector<T>>>\
    \ &A) {\n        vector<vector<vector<long long>>> S;\n        int szx = A.size(),\
    \ szy = A[0].size(), szz = A[0][0].size();\n        S.resize(szx + 1, vector<vector<long\
    \ long>>(\n                              szy + 1, vector<long long>(szz + 1, 0)));\n\
    \        for (int x = 1; x <= szx; ++x) {\n            for (int y = 1; y <= szy;\
    \ ++y) {\n                for (int z = 1; z <= szz; ++z) {\n                 \
    \   S[x][y][z] = A[x - 1][y - 1][z - 1] + S[x - 1][y][z] +\n                 \
    \                S[x][y - 1][z] + S[x][y][z - 1] -\n                         \
    \        S[x - 1][y - 1][z] - S[x - 1][y][z - 1] -\n                         \
    \        S[x][y - 1][z - 1] + S[x - 1][y - 1][z - 1];\n                }\n   \
    \         }\n        }\n        return S;\n    }\n    // \u5404\u9805\u306E\u5DEE\
    \u306E\u6570\u5217 \u30E1\u30D3\u30A6\u30B9\u5909\u63DB\n    template <typename\
    \ T> vector<long long> moebius(vector<T> &A) {\n        int N = A.size();\n  \
    \      vector<long long> D(N - 1);\n        for (int i = 0; i < N; ++i) D[i] =\
    \ A[i + 1] - A[i];\n        return D;\n    }\n};\n\n\n/** =======================================\
    \ */\n/**               \u63A2\u7D22                      */\n/** =======================================\
    \ */\n\nclass Search {\n  public:\n    /**\n     * \u9806\u5217\u5168\u63A2\u7D22\
    \ O(N!) N\u306F10\u301C12\u7A0B\u5EA6\n     * \u9806\u5217\u306E\u5168\u30D1\u30BF\
    \u30FC\u30F3\u4E2D\u3067\u3084\u308A\u305F\u3044\u95A2\u6570\u3092\u5165\u308C\
    \u308B\n     * \u4F8B) search_permu(A, [&](){cout << A;} );\n     */\n    template\
    \ <typename T, typename F> void perm(vector<T> &A, F f) {\n        sort(all(A));\n\
    \        do {\n            f();\n        } while (next_permutation(all(A)));\n\
    \    }\n    /**\n     * bit\u5168\u63A2\u7D22 O(2^N) N\u306F20\u524D\u5F8C\n \
    \    * \u96C6\u5408A\u306E\u5168\u30D1\u30BF\u30FC\u30F3\u306E\u90E8\u5206\u96C6\
    \u5408\u3092\u8FD4\u3059\n     * {1,2,3} -> { {},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}\
    \ }\n     */\n    template <typename T> vector<vector<T>> bit(vector<T> &A) {\n\
    \        int N = A.size();\n        vector<vector<T>> res;\n        for (long\
    \ long bit = 0; bit < (1ll << N); ++bit) {\n            vector<T> tmp;\n     \
    \       for (int k = 0; k < N; ++k) {\n                if (bit & (1ll << k)) {\n\
    \                    tmp.push_back(A[k]);\n                }\n            }\n\
    \            res.push_back(tmp);\n        }\n        return res;\n    }\n    /**\n\
    \     * \u6574\u6570\u4E0A\u306E\u4E8C\u5206\u63A2\u7D22\n     *     L R\n   \
    \  * x x x o o o o\n     *       \u2191\u3053\u3053\u3092\u6C42\u3081\u308B\n\
    \     * \u6761\u4EF6\uFF1A5 <= x\u306A\u3089\u3001L=4, R=5\n     */\n    template\
    \ <typename F> pair<long long, long long> bi(F f) {\n        long long L = 0,\
    \ R = 1, MID = 0;\n        while (!f(R)) R <<= 1;\n        while (abs(R - L) >\
    \ 1) {\n            MID = L + (R - L) / 2;\n            (f(MID) ? R : L) = MID;\n\
    \        }\n        return make_pair(L, R);\n    }\n    /**\n     * \u5B9F\u6570\
    \u4E0A\u306E\u4E8C\u5206\u63A2\u7D22\n     *     L R\n     * x x x o o o o\n \
    \    *       \u2191\u3053\u3053\u3092\u6C42\u3081\u308B\n     * \u6761\u4EF6\uFF1A\
    3.5 <= x\u306A\u3089\u3001L=3.5, R=3.5 (LR\u306E\u8AA4\u5DEE\u304CEPS\u5185)\n\
    \     */\n    template <typename F> pair<double, double> bi_real(F f) {\n    \
    \    double L = 0, R = 1, MID = 0;\n        while (!f(R)) R *= 2;\n        auto\
    \ ABS = [&]() { return abs(R - L) > EPS; };\n        auto REL = [&]() { return\
    \ abs(R - L) / max(R, L) > EPS; };\n        while (ABS() and REL()) {\n      \
    \      MID = L + (R - L) / 2;\n            (f(MID) ? R : L) = MID;\n        }\n\
    \        return make_pair(L, R);\n    }\n    // \u4EE5\u4E0B\u306E\u8981\u7D20\
    \u6570\n    template <typename T> int bi_le_cnt(vector<T> &v, const T &x) {\n\
    \        sort(all(v));\n        return upper_bound(all(v), x) - v.begin();\n \
    \   }\n    // \u4EE5\u4E0B\u306E\u5024 \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\
    -INF\n    template <typename T> T bi_le_val(vector<T> &v, const T &x) {\n    \
    \    sort(all(v));\n        auto it = upper_bound(all(v), x);\n        return\
    \ (it == v.begin() ? -INF : *--it);\n    }\n    // \u4EE5\u4E0B\u306E\u5024  \u5B58\
    \u5728\u3057\u306A\u3044\u5834\u5408-INF\n    template <typename T> T bi_le_val(const\
    \ set<T> &st, const T &x) {\n        auto it = st.upper_bound(x);\n        return\
    \ (it == st.begin() ? -INF : *--it);\n    }\n    // \u4EE5\u4E0A\u306E\u8981\u7D20\
    \u6570\n    template <typename T> int bi_ge_cnt(vector<T> &v, const T &x) {\n\
    \        sort(all(v));\n        return v.end() - lower_bound(all(v), x);\n   \
    \ }\n    // \u4EE5\u4E0A\u306E\u6700\u5C0F\u5024 \u5B58\u5728\u3057\u306A\u3044\
    \u5834\u5408 INF\n    template <typename T> T bi_ge_val(vector<T> &v, const T\
    \ &x) {\n        sort(all(v));\n        auto it = lower_bound(all(v), x);\n  \
    \      return (it == v.end() ? INF : *it);\n    }\n    // \u4EE5\u4E0A\u306E\u6700\
    \u5C0F\u5024 \u5B58\u5728\u3057\u306A\u3044\u5834\u5408 INF\n    template <typename\
    \ T> T bi_ge_val(const set<T> &st, const T &x) {\n        auto it = st.lower_bound(x);\n\
    \        return (it == st.end() ? INF : *it);\n    }\n    // \u672A\u6E80\u306E\
    \u8981\u7D20\u6570\n    template <typename T> int bi_lt_cnt(vector<T> &v, const\
    \ T &x) {\n        sort(all(v));\n        return lower_bound(all(v), x) - v.begin();\n\
    \    }\n    // \u672A\u6E80\u306E\u6700\u5927\u5024 \u5B58\u5728\u3057\u306A\u3044\
    \u5834\u5408 -INF\n    template <typename T> T bi_lt_val(vector<T> &v, const T\
    \ &x) {\n        sort(all(v));\n        auto it = lower_bound(all(v), x);\n  \
    \      return (it == v.begin() ? -INF : *--it);\n    }\n    // \u672A\u6E80\u306E\
    \u6700\u5927\u5024 \u5B58\u5728\u3057\u306A\u3044\u5834\u5408 -INF\n    template\
    \ <typename T> T bi_lt_val(const set<T> &st, const T &x) {\n        auto it =\
    \ st.lower_bound(x);\n        return (it == st.begin() ? -INF : *--it);\n    }\n\
    \    // \u3088\u308A\u4E0A\u306E\u8981\u7D20\u6570\n    template <typename T>\
    \ int bi_gt_cnt(vector<T> &v, const T &x) {\n        sort(all(v));\n        return\
    \ v.end() - upper_bound(all(v), x);\n    }\n    // \u3088\u308A\u4E0A\u306E\u6700\
    \u5C0F\u5024 \u5B58\u5728\u3057\u306A\u3044\u5834\u5408 INF\n    template <typename\
    \ T> T bi_gt_val(vector<T> &v, const T &x) {\n        sort(all(v));\n        auto\
    \ it = upper_bound(all(v), x);\n        return (it == v.end() ? INF : *it);\n\
    \    }\n    // \u3088\u308A\u4E0A\u306E\u6700\u5C0F\u5024 \u5B58\u5728\u3057\u306A\
    \u3044\u5834\u5408 INF\n    template <typename T> T bi_gt_val(const set<T> &st,\
    \ const T &x) {\n        auto it = st.upper_bound(x);\n        return (it == st.end()\
    \ ? INF : *it);\n    }\n    // \u30E1\u30E2\u5316\u518D\u5E30 !!\u30B3\u30D4\u30DA\
    \u7528!! \u95A2\u6570\u5185\u3092\u30DA\u30FC\u30B9\u30C8\u3057\u3066\u66F8\u304D\
    \u63DB\u3048\u3066\u4F7F\u3046\n    void dfs_memo() {\n        map<int, int> memo;\n\
    \        auto dfs = [&](auto f, int n) {\n            if (n <= 1) return n;\n\
    \            if (memo.count(n)) return memo[n];\n            return memo[n] =\
    \ f(f, n - 1) + f(f, n - 2);\n        };\n        // int ans = dfs(dfs, N);\n\
    \    }\n};\n\n\n/** ======================================= */\n/**          \
    \     \u30B0\u30EA\u30C3\u30C9                  */\n/** =======================================\
    \ */\n\nclass Grid {\n  public:\n    // \u884C\u5217\u306E\u8EE2\u7F6E\n    template\
    \ <typename T>\n    vector<vector<T>> transpose(const vector<vector<T>> &G) {\n\
    \        int H = G.size(), W = G[0].size();\n        vector<vector<T>> _G(W, vector<T>(H));\n\
    \        for (int i = 0; i < H; ++i) {\n            for (int j = 0; j < W; ++j)\
    \ {\n                _G[j][i] = G[i][j];\n            }\n        }\n        return\
    \ _G;\n    }\n    // \u30B0\u30EA\u30C3\u30C94\u65B9\u3092\u898B\u308BBFS \u5F15\
    \u6570f(y, x)\n    template <typename T, typename F> void bfs(vector<vector<T>>\
    \ &G, F f) {\n        int H = G.size(), W = G[0].size();\n        for (int i =\
    \ 0; i < H; ++i) {\n            for (int j = 0; j < W; ++j) {\n              \
    \  for (int k = 0; k < 4; ++k) {\n                    int y = i + dy[k], x = j\
    \ + dx[k];\n                    if (y < 0 or x < 0 or H <= y or W <= x) continue;\n\
    \                    f(y, x);\n                }\n            }\n        }\n \
    \   }\n    // \u30B0\u30EA\u30C3\u30C98\u65B9\u3092\u898B\u308BBFS \u5F15\u6570\
    f(y, x)\n    template <typename T, typename F> void bfs8(vector<vector<T>> &G,\
    \ F f) {\n        int H = G.size(), W = G[0].size();\n        for (int i = 0;\
    \ i < H; ++i) {\n            for (int j = 0; j < W; ++j) {\n                for\
    \ (int k = 0; k < 8; ++k) {\n                    int y = i + dy8[k], x = j + dx8[k];\n\
    \                    if (y < 0 or x < 0 or H <= y or W <= x) continue;\n     \
    \               f(y, x);\n                }\n            }\n        }\n    }\n\
    };\n\n\n/** ======================================= */\n/**               \u5E7E\
    \u4F55                      */\n/** ======================================= */\n\
    \nclass Geometry {\n  public:\n    // \u5EA6\u6570\u6CD5 \u2192 \u5F27\u5EA6\u6CD5\
    \n    double deg_to_rad(double d) {\n        return d * PI / 180;\n    }\n   \
    \ // \u5F27\u5EA6\u6CD5 \u2192 \u5EA6\u6570\u6CD5\n    double rad_to_deg(double\
    \ r) {\n        return r * 180 / PI;\n    }\n    // \u504F\u89D2\u3092\u30E9\u30B8\
    \u30A2\u30F3\u3067\u8FD4\u3059\n    double arc_tan(double x, double y) {\n   \
    \     return atan2(y, x);\n    }\n    /**\n     * \u4E09\u89D2\u5F62\u306E\u9762\
    \u7A4D\n     * double\u306F\u6841\u6570\u8868\u73FE11bit\u3092\u9664\u304D\u3001\
    52bit\u7A0B\u5EA6\u306E\u7CBE\u5EA6\n     * 18\u6841\u4F7F\u3046\u306A\u30892\u3067\
    \u5272\u3089\u305Along long\u3067\u8FD4\u3059\u3053\u3068\n     */\n    template\
    \ <typename T>\n    double area_triangle(T x1, T y1, T x2, T y2, T x3, T y3) {\n\
    \        return abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2.0;\n  \
    \  }\n    /**\n     * \u56DB\u89D2\u5F62\u306E\u9762\u7A4D\n     * double\u306F\
    \u6841\u6570\u8868\u73FE11bit\u3092\u9664\u304D\u300152bit\u7A0B\u5EA6\u306E\u7CBE\
    \u5EA6\n     * 18\u6841\u4F7F\u3046\u306A\u30892\u3067\u5272\u3089\u305Along long\u3067\
    \u8FD4\u3059\u3053\u3068\n     */\n    template <typename T>\n    double area_square(T\
    \ x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4) {\n        return hypot(x1 - x3,\
    \ y1 - y3) * hypot(x2 - x4, y2 - y4) / 2.0;\n    }\n};\n\n\n/** =======================================\
    \ */\n/**               \u30B0\u30E9\u30D5                    */\n/** =======================================\
    \ */\n\nstruct Edge {\n    int from, to;\n    long long cost;\n    Edge(int from,\
    \ int to, long long cost = 1)\n        : from(from), to(to), cost(cost) {\n  \
    \  }\n};\nstruct Graph {\n  private:\n    int N;\n    vector<vector<Edge>> G;\n\
    \n  public:\n    Graph(int N) : N(N), G(N) {\n    }\n    vector<Edge> operator[](int\
    \ v) {\n        return G[v];\n    }\n    int size() {\n        return N;\n   \
    \ }\n    // (\u6709\u5411)\u8FBA\u3092\u5F35\u308B\n    void add(int from, int\
    \ to, long long cost = 1) {\n        G[from].push_back(Edge(from, to, cost));\n\
    \    }\n    // (\u53CC\u65B9\u5411)\u8FBA\u3092\u5F35\u308B\n    void add_both(int\
    \ from, int to) {\n        G[from].push_back(Edge(from, to));\n        G[to].push_back(Edge(to,\
    \ from));\n    }\n    // \u7D4C\u8DEF\u5FA9\u5143\n    vector<int> route_restore(const\
    \ vector<int> &route, int goal) {\n        vector<int> path = {goal};\n      \
    \  while (!~route[path.back()]) path.push_back(route[path.back()]);\n        reverse(all(path));\n\
    \        return path;\n    }\n    /**\n     * BFS \u6700\u77ED\u7D4C\u8DEF \u8907\
    \u6570\u59CB\u70B9\n     * @return \u6700\u77ED\u8DDD\u96E2\u3001\u7D4C\u8DEF\n\
    \     */\n    pair<vector<int>, vector<int>> bfs(const vector<int> &starts = {0})\
    \ {\n        queue<int> q;\n        vector<int> dis(N, -1), route(N, -1);\n  \
    \      for (auto &&v : starts) q.push(v), dis[v] = 0;\n        while (!q.empty())\
    \ {\n            int v = q.front();\n            q.pop();\n            for (auto\
    \ &&[from, to, cost] : G[v]) {\n                if (~dis[to]) continue;\n    \
    \            dis[to] = dis[from] + 1;\n                q.push(to);\n         \
    \       route[to] = v;\n            }\n        }\n        return {dis, route};\n\
    \    }\n    /**\n     * Dijkstra \u6700\u5C0F\u30B3\u30B9\u30C8\u7D4C\u8DEF \u8907\
    \u6570\u59CB\u70B9\n     * @return \u6700\u5C0F\u30B3\u30B9\u30C8\u3001\u7D4C\u8DEF\
    \n     */\n    pair<vector<long long>, vector<int>> dijkstra(const vector<int>\
    \ &starts = {\n                                                      0}) {\n \
    \       reverse_queue<pair<long long, int>> q; // \u30B3\u30B9\u30C8(\u5C0F\u3055\
    \u3044\u9806), \u9802\u70B9\n        vector<long long> weight(N, INF);\n     \
    \   vector<int> route(N, -1);\n        for (auto &&v : starts) q.emplace(0, v),\
    \ weight[v] = 0;\n        while (!q.empty()) {\n            auto [w, v] = q.top();\n\
    \            q.pop();\n            if (weight[v] < w) continue;\n            for\
    \ (auto &&[from, to, cost] : G[v]) {\n                long long next_w = w + cost;\n\
    \                if (weight[to] <= next_w) continue;\n                weight[to]\
    \ = next_w;\n                q.emplace(weight[to], to);\n                route[to]\
    \ = v;\n            }\n        }\n        return {weight, route};\n    }\n   \
    \ /**\n     * DAG\u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n\
    \     */\n    vector<int> topological_sort() {\n        // TODO \u9589\u8DEF\u691C\
    \u77E5\u3057\u3066\u7A7A\u914D\u5217\u3092\u8FD4\u5374\u3068\u304B\n        vector<int>\
    \ seen(N, 0), sorted;\n        auto dfs = [&](auto &f, int v) -> void {\n    \
    \        seen[v] = 1;\n            for (auto &&[from, to, cost] : G[v]) {\n  \
    \              if (!seen[to]) f(f, to);\n            }\n            sorted.push_back(v);\n\
    \        };\n        for (int i = 0; i < N; ++i) {\n            if (!seen[i])\
    \ dfs(dfs, i);\n        }\n        reverse(all(sorted));\n        return sorted;\n\
    \    }\n    // TODO cc\n    // TODO scc\n    // TODO \u30D9\u30EB\u30DE\u30F3\u30D5\
    \u30A9\u30FC\u30C9\n    // TODO \u30B5\u30A4\u30AF\u30EB\u691C\u51FA\n    // TODO\
    \ \u30AF\u30E9\u30B9\u30AB\u30EB\n    // TODO \u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\
    \u30ED\u30A4\u30C9\n    // TODO \u30C9\u30AD\u30E5\u30E1\u30F3\u30C8\n};\n\n\n\
    /**\n * @brief UnionFind\n */\nstruct UnionFind {\n  private:\n    vector<int>\
    \ parent, size;\n\n  public:\n    UnionFind(int N) {\n        parent.assign(N,\
    \ -1);\n        size.assign(N, 1);\n    }\n    // \u81EA\u5206\u306E\u30B0\u30EB\
    \u30FC\u30D7\u306E\u30B5\u30A4\u30BA\n    int operator[](int p) {\n        return\
    \ size[find(p)];\n    }\n    // p\u306E\u89AA\u3092\u898B\u3064\u3051\u308B\n\
    \    int find(int p) {\n        return !~parent[p] ? p : (parent[p] = find(parent[p]));\n\
    \    }\n    // a\u3068b\u3092\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\u3059\u308B\
    \ \u64CD\u4F5C\u3057\u305F\u3089true\n    bool unite(int a, int b) {\n       \
    \ int x = find(a), y = find(b);\n        if (x == y) return false;\n        if\
    \ (size[x] > size[y]) swap(x, y);\n        parent[x] = y, size[y] += size[x];\n\
    \        return true;\n    }\n};\n\n\n/**\n * @brief FenwicTree 1\u70B9\u66F4\u65B0\
    \ \u533A\u9593\u53D6\u5F97 \u548C\u306E\u307F\n */\nstruct FenwickTree {\n  private:\n\
    \    int N;\n    vector<int> fwk;\n\n  public:\n    FenwickTree(int N) : N(N)\
    \ {\n        fwk.assign(N + 1, 0);\n    }\n    FenwickTree(const vector<int> &A)\
    \ : N(A.size()) {\n        fwk.assign(N + 1, 0);\n        for (int i = 1; i <=\
    \ N; ++i) {\n            fwk[i] += A[i - 1];\n            if (i + (i & -i) <=\
    \ N) fwk[i + (i & -i)] += fwk[i];\n        }\n    }\n    // \u5024\u3092\u52A0\
    \u3048\u308B\n    void add(int i, const int &x) {\n        for (++i; i <= N; i\
    \ += i & -i) fwk[i] += x;\n    }\n    // \u03A3[0, i]\n    int sum(int i) {\n\
    \        int ans = 0;\n        for (++i; i; i -= i & -i) ans += fwk[i];\n    \
    \    return ans;\n    }\n};\n\n\n/**\n * @brief SegmentTree 1\u70B9\u66F4\u65B0\
    \ \u533A\u9593\u53D6\u5F97\n */\ntemplate <class Monoid> struct SegmentTree {\n\
    \    using T = typename Monoid::T;\n\n  private:\n    Monoid M;\n    int N, size,\
    \ log = 1;\n    vector<T> node;\n    void init() {\n        while ((1 << log)\
    \ < N) ++log;\n        node.assign((size = 1 << log) << 1, M.e());\n    }\n\n\
    \  public:\n    SegmentTree(Monoid M, int N) : M(M), N(N) {\n        init();\n\
    \    }\n    SegmentTree(Monoid M, const vector<T> &A) : M(M), N(A.size()) {\n\
    \        init();\n        for (int i = 0; i < N; ++i) node[i + size] = A[i];\n\
    \        for (int i = size - 1; i >= 1; --i)\n            node[i] = M.op(node[i\
    \ << 1 | 0], node[i << 1 | 1]);\n    }\n    // \u8981\u7D20i\u306E\u5024\u3092\
    x\u306B\u3059\u308B\n    void set(int i, const T &x) {\n        node[i += size]\
    \ = x;\n        while (i >>= 1) node[i] = M.op(node[i << 1 | 0], node[i << 1 |\
    \ 1]);\n    }\n    // \u6F14\u7B97[l,r)\n    T prod(int l, int r) {\n        T\
    \ L = M.e(), R = M.e();\n        for (l += size, r += size; l < r; l >>= 1, r\
    \ >>= 1) {\n            if (l & 1) L = M.op(L, node[l++]);\n            if (r\
    \ & 1) R = M.op(node[--r], R);\n        }\n        return M.op(L, R);\n    }\n\
    };\n\n\n/** ======================================= */\n/**              \u30E2\
    \u30CE\u30A4\u30C9                   */\n/** =======================================\
    \ */\n\ntemplate <typename U, typename F> struct Monoid {\n    using T = U;\n\n\
    \  private:\n    T _e;\n    F _op;\n\n  public:\n    Monoid(T e, F op) : _e(e),\
    \ _op(op) {\n    }\n    T op(const T &x, const T &y) {\n        return _op(x,\
    \ y);\n    }\n    T e() {\n        return _e;\n    }\n};\ntemplate <typename U\
    \ = int> struct MonoidMin {\n    using T = U;\n    T op(const T &x, const T &y)\
    \ {\n        return min(x, y);\n    }\n    T e() {\n        return INF;\n    }\n\
    };\ntemplate <typename U = int> struct MonoidMax {\n    using T = U;\n    T op(const\
    \ T &x, const T &y) {\n        return max(x, y);\n    }\n    T e() {\n       \
    \ return -INF;\n    }\n};\ntemplate <typename U = int> struct MonoidAdd {\n  \
    \  using T = U;\n    T op(const T &x, const T &y) {\n        return x + y;\n \
    \   }\n    T e() {\n        return 0ll;\n    }\n};\ntemplate <typename U = int>\
    \ struct MonoidMul {\n    using T = U;\n    T op(const T &x, const T &y) {\n \
    \       return x * y;\n    }\n    T e() {\n        return 1ll;\n    }\n};\ntemplate\
    \ <typename U = int> struct MonoidGcd {\n    using T = U;\n    T op(const T &x,\
    \ const T &y) {\n        return gcd(x, y);\n    }\n    T e() {\n        return\
    \ 0ll;\n    }\n};\ntemplate <typename U = int> struct MonoidLcm {\n    using T\
    \ = U;\n    T op(const T &x, const T &y) {\n        return lcm(x, y);\n    }\n\
    \    T e() {\n        return 1ll;\n    }\n};\ntemplate <typename U = int> struct\
    \ MonoidXor {\n    using T = U;\n    T op(const T &x, const T &y) {\n        return\
    \ x ^ y;\n    }\n    T e() {\n        return 0ll;\n    }\n};\n\nnamespace lib\
    \ {\nNumber num;\nString str;\nSequence seq;\nSearch search;\nGrid grid;\nGeometry\
    \ geo;\n}; // namespace lib\nvoid solve();\nsigned main() {\n    solve();\n}\n\
    // -----------------------------------------\n// #include \"template/template.hpp\"\
    \ is done.\n// -----------------------------------------\n\n/**\n * @brief \U0001F36A\
    \U0001F9F8\U0001F43E\n */\nvoid solve() {\n}\n\n"
  dependsOn:
  - bits/stdc++.h
  isVerificationFile: false
  path: bundle.cpp
  requiredBy: []
  timestamp: '2026-01-01 17:26:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bundle.cpp
layout: document
title: "\u30D0\u30F3\u30C9\u30EB\u5F8C\u306E\u30B5\u30F3\u30D7\u30EB"
---

`bundler/main.cpp`実行後に生成される`main.cpp`のサンプル。
これを提出する。

