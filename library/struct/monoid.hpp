
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
        return INF;
    }
};
// TODO ほかのも
