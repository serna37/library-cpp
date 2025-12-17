#pragma once
/**
 * @file io.hpp
 * @brief IO関連
 */
// cin >> vectorで受け取る
template <typename T> inline istream &operator>>(istream &s, vector<T> &v) {
    for (T &t : v) {
        s >> t;
    }
    return s;
}
// Yes No 出力
inline void yn(bool isok) {
    cout << (isok ? "Yes" : "No") << endl;
}
// YES NO 出力
inline void YN(bool isok) {
    cout << (isok ? "YES" : "NO") << endl;
}
// cout << vectorで出力(1次元まで)
template <typename T>
inline ostream &operator<<(ostream &s, const vector<T> &v) {
    int i = 0;
    for (auto &&e : v) {
        if (i++) s << " ";
        s << e;
    }
    s << endl;
    return s;
}
// 行列を出力
template <typename T> void coutGrid(vector<vector<T>> &G) {
    for (auto &&v : G) {
        cout << v;
    }
}
// TODO グラフのcinとか
