---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30E2\u30CE\u30A4\u30C9\u4F5C\u7528\u7D20"
    links: []
  bundledCode: "#line 2 \"library/struct/monoid_act.hpp\"\n/**\n * @brief \u30E2\u30CE\
    \u30A4\u30C9\u4F5C\u7528\u7D20\n */\nstruct MonoidAct {\n    // \u6F14\u7B97:\
    \ \u52A0\u7B97  \u66F4\u65B0: \u52A0\u7B97\n    struct AddAdd {\n        static\
    \ constexpr int op(const int &node, const int &a,\n                          \
    \      const int &size) {\n            return node + a * size;\n        }\n  \
    \  };\n    // \u6F14\u7B97: \u52A0\u7B97  \u66F4\u65B0: \u4EE3\u5165\n    struct\
    \ AddSet {\n        static constexpr int op(const int &node, const int &a,\n \
    \                               const int &size) {\n            return a == Monoid::Set::e\
    \ ? node : a * size;\n        }\n    };\n    // \u6F14\u7B97: \u52A0\u7B97  \u66F4\
    \u65B0: \u6700\u5C0F\u5024\n    struct AddMin {\n        static constexpr int\
    \ op(const int &node, const int &a,\n                                const int\
    \ &size) {\n            (void)size; // unused\n            return min(node, a);\n\
    \        }\n    };\n    // \u6F14\u7B97: \u52A0\u7B97  \u66F4\u65B0: \u6700\u5927\
    \u5024\n    struct AddMax {\n        static constexpr int op(const int &node,\
    \ const int &a,\n                                const int &size) {\n        \
    \    (void)size; // unused\n            return max(node, a);\n        }\n    };\n\
    \    // \u6F14\u7B97: \u6700\u5C0F\u5024  \u66F4\u65B0: \u52A0\u7B97\n    struct\
    \ MinAdd {\n        static constexpr int op(const int &node, const int &a,\n \
    \                               const int &size) {\n            (void)size; //\
    \ unused\n            return node == Monoid::Min::e ? node : node + a;\n     \
    \   }\n    };\n    // \u6F14\u7B97: \u6700\u5C0F\u5024  \u66F4\u65B0: \u4EE3\u5165\
    \n    struct MinSet {\n        static constexpr int op(const int &node, const\
    \ int &a,\n                                const int &size) {\n            (void)size;\
    \ // unused\n            return a == Monoid::Set::e ? node : a;\n        }\n \
    \   };\n    // \u6F14\u7B97: \u6700\u5C0F\u5024  \u66F4\u65B0: \u6700\u5C0F\u5024\
    \n    struct MinMin {\n        static constexpr int op(const int &node, const\
    \ int &a,\n                                const int &size) {\n            (void)size;\
    \ // unused\n            return min(node, a);\n        }\n    };\n    // \u6F14\
    \u7B97: \u6700\u5C0F\u5024  \u66F4\u65B0: \u6700\u5927\u5024\n    struct MinMax\
    \ {\n        static constexpr int op(const int &node, const int &a,\n        \
    \                        const int &size) {\n            (void)size; // unused\n\
    \            return max(node, a);\n        }\n    };\n    // \u6F14\u7B97: \u6700\
    \u5927\u5024  \u66F4\u65B0: \u52A0\u7B97\n    struct MaxAdd {\n        static\
    \ constexpr int op(const int &node, const int &a,\n                          \
    \      const int &size) {\n            (void)size; // unused\n            return\
    \ node == Monoid::Max::e ? node : node + a;\n        }\n    };\n    // \u6F14\u7B97\
    : \u6700\u5927\u5024  \u66F4\u65B0: \u4EE3\u5165\n    struct MaxSet {\n      \
    \  static constexpr int op(const int &node, const int &a,\n                  \
    \              const int &size) {\n            (void)size; // unused\n       \
    \     return a == Monoid::Set::e ? node : a;\n        }\n    };\n    // \u6F14\
    \u7B97: \u6700\u5927\u5024  \u66F4\u65B0: \u6700\u5C0F\u5024\n    struct MaxMin\
    \ {\n        static constexpr int op(const int &node, const int &a,\n        \
    \                        const int &size) {\n            (void)size; // unused\n\
    \            return min(node, a);\n        }\n    };\n    // \u6F14\u7B97: \u6700\
    \u5927\u5024  \u66F4\u65B0: \u6700\u5927\u5024\n    struct MaxMax {\n        static\
    \ constexpr int op(const int &node, const int &a,\n                          \
    \      const int &size) {\n            (void)size; // unused\n            return\
    \ max(node, a);\n        }\n    };\n};\n"
  code: "#pragma once\n/**\n * @brief \u30E2\u30CE\u30A4\u30C9\u4F5C\u7528\u7D20\n\
    \ */\nstruct MonoidAct {\n    // \u6F14\u7B97: \u52A0\u7B97  \u66F4\u65B0: \u52A0\
    \u7B97\n    struct AddAdd {\n        static constexpr int op(const int &node,\
    \ const int &a,\n                                const int &size) {\n        \
    \    return node + a * size;\n        }\n    };\n    // \u6F14\u7B97: \u52A0\u7B97\
    \  \u66F4\u65B0: \u4EE3\u5165\n    struct AddSet {\n        static constexpr int\
    \ op(const int &node, const int &a,\n                                const int\
    \ &size) {\n            return a == Monoid::Set::e ? node : a * size;\n      \
    \  }\n    };\n    // \u6F14\u7B97: \u52A0\u7B97  \u66F4\u65B0: \u6700\u5C0F\u5024\
    \n    struct AddMin {\n        static constexpr int op(const int &node, const\
    \ int &a,\n                                const int &size) {\n            (void)size;\
    \ // unused\n            return min(node, a);\n        }\n    };\n    // \u6F14\
    \u7B97: \u52A0\u7B97  \u66F4\u65B0: \u6700\u5927\u5024\n    struct AddMax {\n\
    \        static constexpr int op(const int &node, const int &a,\n            \
    \                    const int &size) {\n            (void)size; // unused\n \
    \           return max(node, a);\n        }\n    };\n    // \u6F14\u7B97: \u6700\
    \u5C0F\u5024  \u66F4\u65B0: \u52A0\u7B97\n    struct MinAdd {\n        static\
    \ constexpr int op(const int &node, const int &a,\n                          \
    \      const int &size) {\n            (void)size; // unused\n            return\
    \ node == Monoid::Min::e ? node : node + a;\n        }\n    };\n    // \u6F14\u7B97\
    : \u6700\u5C0F\u5024  \u66F4\u65B0: \u4EE3\u5165\n    struct MinSet {\n      \
    \  static constexpr int op(const int &node, const int &a,\n                  \
    \              const int &size) {\n            (void)size; // unused\n       \
    \     return a == Monoid::Set::e ? node : a;\n        }\n    };\n    // \u6F14\
    \u7B97: \u6700\u5C0F\u5024  \u66F4\u65B0: \u6700\u5C0F\u5024\n    struct MinMin\
    \ {\n        static constexpr int op(const int &node, const int &a,\n        \
    \                        const int &size) {\n            (void)size; // unused\n\
    \            return min(node, a);\n        }\n    };\n    // \u6F14\u7B97: \u6700\
    \u5C0F\u5024  \u66F4\u65B0: \u6700\u5927\u5024\n    struct MinMax {\n        static\
    \ constexpr int op(const int &node, const int &a,\n                          \
    \      const int &size) {\n            (void)size; // unused\n            return\
    \ max(node, a);\n        }\n    };\n    // \u6F14\u7B97: \u6700\u5927\u5024  \u66F4\
    \u65B0: \u52A0\u7B97\n    struct MaxAdd {\n        static constexpr int op(const\
    \ int &node, const int &a,\n                                const int &size) {\n\
    \            (void)size; // unused\n            return node == Monoid::Max::e\
    \ ? node : node + a;\n        }\n    };\n    // \u6F14\u7B97: \u6700\u5927\u5024\
    \  \u66F4\u65B0: \u4EE3\u5165\n    struct MaxSet {\n        static constexpr int\
    \ op(const int &node, const int &a,\n                                const int\
    \ &size) {\n            (void)size; // unused\n            return a == Monoid::Set::e\
    \ ? node : a;\n        }\n    };\n    // \u6F14\u7B97: \u6700\u5927\u5024  \u66F4\
    \u65B0: \u6700\u5C0F\u5024\n    struct MaxMin {\n        static constexpr int\
    \ op(const int &node, const int &a,\n                                const int\
    \ &size) {\n            (void)size; // unused\n            return min(node, a);\n\
    \        }\n    };\n    // \u6F14\u7B97: \u6700\u5927\u5024  \u66F4\u65B0: \u6700\
    \u5927\u5024\n    struct MaxMax {\n        static constexpr int op(const int &node,\
    \ const int &a,\n                                const int &size) {\n        \
    \    (void)size; // unused\n            return max(node, a);\n        }\n    };\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: library/struct/monoid_act.hpp
  requiredBy: []
  timestamp: '2026-01-05 21:42:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/struct/monoid_act.hpp
layout: document
redirect_from:
- /library/library/struct/monoid_act.hpp
- /library/library/struct/monoid_act.hpp.html
title: "\u30E2\u30CE\u30A4\u30C9\u4F5C\u7528\u7D20"
---
