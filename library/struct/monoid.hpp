#pragma once
/**
 * @brief モノイド
 */
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
/**
 * @brief モノイド作用
 */
struct MonoidAct {
    // 演算: 加算  更新: 加算
    struct AddAdd {
        static constexpr int op(const int &node, const int &a,
                                const int &size) {
            return node + a * size;
        }
    };
    // 演算: 加算  更新: 代入
    struct AddSet {
        static constexpr int op(const int &node, const int &a,
                                const int &size) {
            return a == Monoid::Set::e ? node : a * size;
        }
    };
    // 演算: 最小値  更新: 加算
    struct MinAdd {
        static constexpr int op(const int &node, const int &a,
                                const int &size) {
            (void)size; // unused
            return node == Monoid::Min::e ? node : node + a;
        }
    };
    // 演算: 最小値  更新: 代入
    struct MinSet {
        static constexpr int op(const int &node, const int &a,
                                const int &size) {
            (void)size; // unused
            return a == Monoid::Set::e ? node : a;
        }
    };
};
