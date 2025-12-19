#pragma once
/**
 * @file type.hpp
 * @brief 型 関連
 */
#define int long long
template <typename Tp> using reverse_queue = priority_queue<Tp, vector<Tp>, greater<Tp>>;
template <typename T> using vec2 = vector<vector<T>>;
// 2次元配列
template <typename T> inline vector<vector<T>> make_vec2(const int H, const int W, const T& init) {
    return vector<vector<T>>(H, vector<T>(W, init));
}
// 2次元配列
template <typename T> inline vector<vector<T>> make_vec2(const int H, const int W) {
    return vector<vector<T>>(H, vector<T>(W));
}
// int → char
inline char int_to_char(int x) {
    return (char)(x + '0');
}
// int → alph
inline char int_to_alph(int x) {
    return (char)(x + 'a');
}
// char → int
inline int char_to_int(char c) {
    return (int)(c - '0');
}
// 数字 → string
inline string toString(long long x) {
    return to_string(x);
}
// string → 数字
inline long long toInteger(string s) {
    return stoll(s);
}