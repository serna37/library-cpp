---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/string.z_algorithm.test.cpp
    title: "Z Algorithm\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/string/z_algorithm.hpp\"\ntemplate <typename T =\
    \ char>\nstruct ZAlgorithm {\n  private:\n    vector<T> s;\n    vector<int> deleted;\n\
    \    vector<vector<int> > delete_hist;\n    vector<int> z;\n    queue<int> cur;\n\
    \n  public:\n    ZAlgorithm() : delete_hist{{}} {}\n\n    template <typename S>\n\
    \    ZAlgorithm(const S &s) : ZAlgorithm() {\n        for (auto &c : s) add(c);\n\
    \    }\n\n    void add(const T &c) {\n        s.emplace_back(c);\n        delete_hist.emplace_back();\n\
    \        deleted.emplace_back(0ll);\n        z.emplace_back(0ll);\n        z[0ll]++;\n\
    \        int len = (int)s.size();\n        if (len == 1ll) return;\n        if\
    \ (s[0ll] == c) {\n            cur.emplace(len - 1ll);\n        } else {\n   \
    \         deleted[len - 1ll] = 1ll;\n        }\n        auto set = [&](int t,\
    \ int len) {\n            deleted[t] = 1ll;\n            delete_hist[len].emplace_back(t);\n\
    \            z[t] = len - t - 1ll;\n        };\n        while (not cur.empty())\
    \ {\n            int t = cur.front();\n            if (deleted[t]) {\n       \
    \         cur.pop();\n            } else if (s[len - t - 1ll] == s.back()) {\n\
    \                break;\n            } else {\n                set(t, len);\n\
    \                cur.pop();\n            }\n        }\n        if (not cur.empty())\
    \ {\n            int t = cur.front();\n            for (auto &p : delete_hist[len\
    \ - t]) {\n                set(p + t, len);\n            }\n        }\n    }\n\
    \    int get(int k) const { return deleted[k] ? z[k] : (int)s.size() - k; }\n\
    \    int operator[](int k) const { return get(k); }\n    vector<int> get() {\n\
    \        vector<int> ret(s.size());\n        for (int i = 0; i < (int)s.size();\
    \ i++) {\n            ret[i] = get(i);\n        }\n        return ret;\n    }\n\
    };\n"
  code: "#pragma once\ntemplate <typename T = char>\nstruct ZAlgorithm {\n  private:\n\
    \    vector<T> s;\n    vector<int> deleted;\n    vector<vector<int> > delete_hist;\n\
    \    vector<int> z;\n    queue<int> cur;\n\n  public:\n    ZAlgorithm() : delete_hist{{}}\
    \ {}\n\n    template <typename S>\n    ZAlgorithm(const S &s) : ZAlgorithm() {\n\
    \        for (auto &c : s) add(c);\n    }\n\n    void add(const T &c) {\n    \
    \    s.emplace_back(c);\n        delete_hist.emplace_back();\n        deleted.emplace_back(0ll);\n\
    \        z.emplace_back(0ll);\n        z[0ll]++;\n        int len = (int)s.size();\n\
    \        if (len == 1ll) return;\n        if (s[0ll] == c) {\n            cur.emplace(len\
    \ - 1ll);\n        } else {\n            deleted[len - 1ll] = 1ll;\n        }\n\
    \        auto set = [&](int t, int len) {\n            deleted[t] = 1ll;\n   \
    \         delete_hist[len].emplace_back(t);\n            z[t] = len - t - 1ll;\n\
    \        };\n        while (not cur.empty()) {\n            int t = cur.front();\n\
    \            if (deleted[t]) {\n                cur.pop();\n            } else\
    \ if (s[len - t - 1ll] == s.back()) {\n                break;\n            } else\
    \ {\n                set(t, len);\n                cur.pop();\n            }\n\
    \        }\n        if (not cur.empty()) {\n            int t = cur.front();\n\
    \            for (auto &p : delete_hist[len - t]) {\n                set(p + t,\
    \ len);\n            }\n        }\n    }\n    int get(int k) const { return deleted[k]\
    \ ? z[k] : (int)s.size() - k; }\n    int operator[](int k) const { return get(k);\
    \ }\n    vector<int> get() {\n        vector<int> ret(s.size());\n        for\
    \ (int i = 0; i < (int)s.size(); i++) {\n            ret[i] = get(i);\n      \
    \  }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2026-01-20 04:38:29+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/string.z_algorithm.test.cpp
documentation_of: library/string/z_algorithm.hpp
layout: document
title: Z Algorithm
---

# Z Algorithm

## できること
- 文字列 $S$ が与えられたとき、それぞれの $i$ について $S$ と $S[i, \vert S \vert ]$ の最長共通接頭辞の長さを記録した配列を、線形時間で構築する
- 参考: https://heno239.hatenablog.com/entry/2020/07/07/140651
- 参考: https://ei1333.github.io/library/string/z-algorithm.hpp

```
aaabaaaab
921034210
```

## 計算量
- 空文字列で初期化 `ZAlgorithm()`: $O(1)$
- 文字列sで初期化 `ZAlgorithm(s)`: $O(N)$
- 文字列の末尾にcを追加 `add(c)`: $O(1)$
- 現在の文字列 $S$ と $S[i, \vert S \vert ]$ の最長共通接頭辞の長さを返す `get(k)`: $O(1)$
- 全ての $i$ についてgetする `get()`: $O(N)$

## 使い方
```cpp
string S = "abacaba";
ZAlgorithm za(S);

// get(k) で S[k..] と S[0..] の共通接頭辞の長さを取得
for (int i = 0; i < (int)S.size(); ++i) za.get(i);
auto all = za.get();
print(all);
```

```cpp
```

