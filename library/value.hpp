#pragma once
/**
 * @file value.hpp
 * @brief 数や値 関連
 */
// 割り下げ（負の場合0側へ丸めない）
auto divCeil = []<class T>(T a, T b) -> T {
	return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
};
// 割り上げ（負の場合0側へ丸めない）
auto divFloor = []<class T>(T a, T b) -> T {
	return a / b - (((a ^ b) < 0 and a % b != 0) ? 1 : 0);
};
// TODO 数値系 modとか階乗、素数、約数とか
// iをjで緩和 min
template <typename T1, typename T2>
    requires totally_ordered_with<T1, T2> && assignable_from<T1&, T2>
inline bool chmin(T1& i, const T2 j) noexcept {
    if (i > j) {
        i = j;
        return true;
    }
    return false;
}
// iをjで緩和 max
template <typename T1, typename T2>
    requires totally_ordered_with<T1, T2> && assignable_from<T1&, T2>
inline bool chmax(T1& i, const T2 j) noexcept {
    if (i < j) {
        i = j;
        return true;
    }
    return false;
}