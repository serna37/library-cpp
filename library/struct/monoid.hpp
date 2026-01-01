
/** ======================================= */
/**              モノイド                   */
/** ======================================= */
#pragma once
template <typename U = int, typename F> struct Monoid {
    using T = U;

  private:
    T _e;
    F _op;

  public:
    Monoid(T e, F op) : _e(e), _op(op) {
    }
    T op(const T &x, const T &y) {
        return _op(x, y);
    }
    T e() {
        return _e;
    }
};
template <typename U = int> struct MonoidMin {
    using T = U;
    T op(const T &x, const T &y) {
        return min(x, y);
    }
    T e() {
        return INF;
    }
};
template <typename U = int> struct MonoidMax {
    using T = U;
    T op(const T &x, const T &y) {
        return max(x, y);
    }
    T e() {
        return -INF;
    }
};
template <typename U = int> struct MonoidAdd {
    using T = U;
    T op(const T &x, const T &y) {
        return x + y;
    }
    T e() {
        return 0ll;
    }
};
template <typename U = int> struct MonoidMul {
    using T = U;
    T op(const T &x, const T &y) {
        return x * y;
    }
    T e() {
        return 1ll;
    }
};
template <typename U = int> struct MonoidGcd {
    using T = U;
    T op(const T &x, const T &y) {
        return gcd(x, y);
    }
    T e() {
        return 0ll;
    }
};
template <typename U = int> struct MonoidLcm {
    using T = U;
    T op(const T &x, const T &y) {
        return lcm(x, y);
    }
    T e() {
        return 1ll;
    }
};
template <typename U = int> struct MonoidXor {
    using T = U;
    T op(const T &x, const T &y) {
        return x ^ y;
    }
    T e() {
        return 0ll;
    }
};
