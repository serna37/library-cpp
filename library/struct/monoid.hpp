
/** ======================================= */
/**              モノイド                   */
/** ======================================= */
#pragma once
template <typename U, typename F> struct Monoid {
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
template <typename U> struct MonoidMin {
    using T = U;
    T op(const T &x, const T &y) {
        return min(x, y);
    }
    T e() {
        return 2147483647;
    }
};
template <typename U> struct MonoidMax {
    using T = U;
    T op(const T &x, const T &y) {
        return max(x, y);
    }
    T e() {
        return -2147483647;
    }
};
template <typename U> struct MonoidAdd {
    using T = U;
    T op(const T &x, const T &y) {
        return x + y;
    }
    T e() {
        return 0ll;
    }
};
template <typename U> struct MonoidMul {
    using T = U;
    T op(const T &x, const T &y) {
        return x * y;
    }
    T e() {
        return 1ll;
    }
};
template <typename U> struct MonoidGcd {
    using T = U;
    T op(const T &x, const T &y) {
        return gcd(x, y);
    }
    T e() {
        return 0ll;
    }
};
template <typename U> struct MonoidLcm {
    using T = U;
    T op(const T &x, const T &y) {
        return lcm(x, y);
    }
    T e() {
        return 1ll;
    }
};
template <typename U> struct MonoidXor {
    using T = U;
    T op(const T &x, const T &y) {
        return x ^ y;
    }
    T e() {
        return 0ll;
    }
};
