#pragma once
/**
 * @brief モノイド作用素
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
    // 演算: 加算  更新: 最小値
    struct AddMin {
        static constexpr int op(const int &node, const int &a,
                                const int &size) {
            (void)size; // unused
            return min(node, a);
        }
    };
    // 演算: 加算  更新: 最大値
    struct AddMax {
        static constexpr int op(const int &node, const int &a,
                                const int &size) {
            (void)size; // unused
            return max(node, a);
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
    // 演算: 最小値  更新: 最小値
    struct MinMin {
        static constexpr int op(const int &node, const int &a,
                                const int &size) {
            (void)size; // unused
            return min(node, a);
        }
    };
    // 演算: 最小値  更新: 最大値
    struct MinMax {
        static constexpr int op(const int &node, const int &a,
                                const int &size) {
            (void)size; // unused
            return max(node, a);
        }
    };
    // 演算: 最大値  更新: 加算
    struct MaxAdd {
        static constexpr int op(const int &node, const int &a,
                                const int &size) {
            (void)size; // unused
            return node == Monoid::Max::e ? node : node + a;
        }
    };
    // 演算: 最大値  更新: 代入
    struct MaxSet {
        static constexpr int op(const int &node, const int &a,
                                const int &size) {
            (void)size; // unused
            return a == Monoid::Set::e ? node : a;
        }
    };
    // 演算: 最大値  更新: 最小値
    struct MaxMin {
        static constexpr int op(const int &node, const int &a,
                                const int &size) {
            (void)size; // unused
            return min(node, a);
        }
    };
    // 演算: 最大値  更新: 最大値
    struct MaxMax {
        static constexpr int op(const int &node, const int &a,
                                const int &size) {
            (void)size; // unused
            return max(node, a);
        }
    };
};
