
/** ======================================= */
/**                 型                      */
/** ======================================= */
#pragma once
template <typename T>
using reverse_queue = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using vec2 = vector<vector<T>>;
vec2<int> make_vec2(int H, int W, int init = 0) {
    return vector<vector<int>>(H, vector<int>(W, init));
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
string int_to_string(long long x) {
    return to_string(x);
}
long long string_to_int(string s) {
    return stoll(s);
}
