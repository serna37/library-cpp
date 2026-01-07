---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/polynomial/fft.hpp
    title: FFT
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u7573\u307F\u8FBC\u307F FFT"
    links: []
  bundledCode: "#line 2 \"library/polynomial/fft.hpp\"\n/**\n * @brief FFT\n */\n\
    namespace FFT {\nusing real = double;\nstruct C {\n    real x, y;\n    C() : x(0),\
    \ y(0) {};\n    C(real x, real y) : x(x), y(y) {};\n    inline C operator+(const\
    \ C &c) const {\n        return C(x + c.x, y + c.y);\n    }\n    inline C operator-(const\
    \ C &c) const {\n        return C(x - c.x, y - c.y);\n    }\n    inline C operator*(const\
    \ C &c) const {\n        return C(x * c.x - y * c.y, x * c.y + y * c.x);\n   \
    \ }\n    inline C conj() const {\n        return C(x, -y);\n    }\n};\nconst real\
    \ PI = acosl(-1);\nint base = 1;\nvector<C> rts = {{0, 0}, {1, 0}};\nvector<int>\
    \ rev = {0, 1};\nvoid ensure_base(int nbase) {\n    if (nbase <= base) return;\n\
    \    rev.resize(1 << nbase);\n    rts.resize(1 << nbase);\n    for (int i = 0;\
    \ i < (1 << nbase); i++) {\n        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) <<\
    \ (nbase - 1));\n    }\n    while (base < nbase) {\n        real angle = PI *\
    \ 2.0 / (1 << (base + 1));\n        for (int i = 1 << (base - 1); i < (1 << base);\
    \ i++) {\n            rts[i << 1] = rts[i];\n            real angle_i = angle\
    \ * (2 * i + 1 - (1 << base));\n            rts[(i << 1) + 1] = C(cos(angle_i),\
    \ sin(angle_i));\n        }\n        ++base;\n    }\n}\nvoid fft(vector<C> &a,\
    \ int n) {\n    assert((n & (n - 1)) == 0);\n    int zeros = __builtin_ctz(n);\n\
    \    ensure_base(zeros);\n    int shift = base - zeros;\n    for (int i = 0; i\
    \ < n; i++) {\n        if (i < (rev[i] >> shift)) swap(a[i], a[rev[i] >> shift]);\n\
    \    }\n    for (int k = 1; k < n; k <<= 1) {\n        for (int i = 0; i < n;\
    \ i += 2 * k) {\n            for (int j = 0; j < k; j++) {\n                C\
    \ z = a[i + j + k] * rts[j + k];\n                a[i + j + k] = a[i + j] - z;\n\
    \                a[i + j] = a[i + j] + z;\n            }\n        }\n    }\n}\n\
    } // namespace FFT\n#line 3 \"library/polynomial/convolution.hpp\"\n/**\n * @brief\
    \ \u7573\u307F\u8FBC\u307F FFT\n * \u7D50\u679C\u306Fllround\u3067\u56DB\u6368\
    \u4E94\u5165\u3057\u3066\u3044\u308B\u3001\u8AA4\u5DEE\u306A\u3057\u306F\u6570\
    \u8AD6\u5909\u63DBNTT\u304C\u5FC5\u8981\n */\ntemplate <typename R>\nvector<long\
    \ long> convolution_fft(const vector<R> &a, const vector<R> &b) {\n    using C\
    \ = FFT::C;\n    int need = (int)a.size() + (int)b.size() - 1, nbase = 1;\n  \
    \  while ((1 << nbase) < need) ++nbase;\n    FFT::ensure_base(nbase);\n    int\
    \ sz = 1 << nbase;\n    vector<C> fa(sz);\n    for (int i = 0; i < sz; i++) {\n\
    \        double x = i < (int)a.size() ? a[i] : 0;\n        double y = i < (int)b.size()\
    \ ? b[i] : 0;\n        fa[i] = C(x, y);\n    }\n    FFT::fft(fa, sz);\n    C r(0,\
    \ -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);\n    for (int i = 0; i <= (sz >> 1);\
    \ i++) {\n        int j = (sz - i) & (sz - 1);\n        C z = (fa[j] * fa[j] -\
    \ (fa[i] * fa[i]).conj()) * r;\n        fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj())\
    \ * r;\n        fa[i] = z;\n    }\n    for (int i = 0; i < (sz >> 1); i++) {\n\
    \        C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;\n        C A1 = (fa[i] - fa[i\
    \ + (sz >> 1)]) * t * FFT::rts[(sz >> 1) + i];\n        fa[i] = A0 + A1 * s;\n\
    \    }\n    FFT::fft(fa, sz >> 1);\n    vector<long long> ret(need);\n    for\
    \ (int i = 0; i < need; i++) {\n        ret[i] = llround(i & 1 ? fa[i >> 1].y\
    \ : fa[i >> 1].x);\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include \"library/polynomial/fft.hpp\"\n/**\n * @brief \u7573\
    \u307F\u8FBC\u307F FFT\n * \u7D50\u679C\u306Fllround\u3067\u56DB\u6368\u4E94\u5165\
    \u3057\u3066\u3044\u308B\u3001\u8AA4\u5DEE\u306A\u3057\u306F\u6570\u8AD6\u5909\
    \u63DBNTT\u304C\u5FC5\u8981\n */\ntemplate <typename R>\nvector<long long> convolution_fft(const\
    \ vector<R> &a, const vector<R> &b) {\n    using C = FFT::C;\n    int need = (int)a.size()\
    \ + (int)b.size() - 1, nbase = 1;\n    while ((1 << nbase) < need) ++nbase;\n\
    \    FFT::ensure_base(nbase);\n    int sz = 1 << nbase;\n    vector<C> fa(sz);\n\
    \    for (int i = 0; i < sz; i++) {\n        double x = i < (int)a.size() ? a[i]\
    \ : 0;\n        double y = i < (int)b.size() ? b[i] : 0;\n        fa[i] = C(x,\
    \ y);\n    }\n    FFT::fft(fa, sz);\n    C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5,\
    \ 0);\n    for (int i = 0; i <= (sz >> 1); i++) {\n        int j = (sz - i) &\
    \ (sz - 1);\n        C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;\n   \
    \     fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;\n        fa[i] = z;\n\
    \    }\n    for (int i = 0; i < (sz >> 1); i++) {\n        C A0 = (fa[i] + fa[i\
    \ + (sz >> 1)]) * t;\n        C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * FFT::rts[(sz\
    \ >> 1) + i];\n        fa[i] = A0 + A1 * s;\n    }\n    FFT::fft(fa, sz >> 1);\n\
    \    vector<long long> ret(need);\n    for (int i = 0; i < need; i++) {\n    \
    \    ret[i] = llround(i & 1 ? fa[i >> 1].y : fa[i >> 1].x);\n    }\n    return\
    \ ret;\n}\n"
  dependsOn:
  - library/polynomial/fft.hpp
  isVerificationFile: false
  path: library/polynomial/convolution.hpp
  requiredBy: []
  timestamp: '2026-01-07 15:59:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/polynomial/convolution.hpp
layout: document
redirect_from:
- /library/library/polynomial/convolution.hpp
- /library/library/polynomial/convolution.hpp.html
title: "\u7573\u307F\u8FBC\u307F FFT"
---
