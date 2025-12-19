#pragma once
template <typename T>
using reverse_queue = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using vec2 = vector<vector<T>>;
template <typename T> vec2<T> make_vec2(int H, int W, T &init) {
    return vector<vector<T>>(H, vector<T>(W, init));
}
template <typename T> vec2<T> make_vec2(int H, int W) {
    return vector<vector<T>>(H, vector<T>(W));
}
char int_to_char(int x) {
    return (char)(x + '0');
}
char int_to_alph(int x) {
    return (char)(x + 'a');
}
int char_to_int(char c) {
    return (int)(c - '0');
}
string toString(long long x) {
    return to_string(x);
}
long long toInteger(string s) {
    return stoll(s);
}
