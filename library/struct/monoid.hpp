
/** ======================================= */
/**              モノイド                   */
/** ======================================= */
#pragma once
struct Monoid {
    // 最小値
    struct Min {
        static constexpr int e = INT_MAX;
        static int op(int x, int y) {
            return min(x, y);
        }
    };
    // 最大値
    struct Max {
        static constexpr int e = -INT_MAX;
        static int op(int x, int y) {
            return max(x, y);
        }
    };
    // 加算
    struct Add {
        static constexpr int e = 0;
        static int op(int x, int y) {
            return x + y;
        }
    };
    // 乗算
    struct Mul {
        static constexpr int e = 1;
        static int op(int x, int y) {
            return x * y;
        }
    };
    // 代入
    struct Set {
        static constexpr int e = INT_MAX;
        static int op(int x, int y) {
            return y == INT_MAX ? x : y;
        }
    };
    // 最大公約数
    struct Gcd {
        static constexpr int e = 0;
        static int op(int x, int y) {
            return gcd(x, y);
        }
    };
    // 最小公倍数
    struct Lcm {
        static constexpr int e = 1;
        static int op(int x, int y) {
            return lcm(x, y);
        }
    };
    // 排他的論理和
    struct Xor {
        static constexpr int e = 0;
        static int op(int x, int y) {
            return x ^ y;
        }
    };
};
