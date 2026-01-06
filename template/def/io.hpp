
/** ======================================= */
/**                IO                       */
/** ======================================= */
#pragma once
#define endl "\n"
struct IoSetup {
    IoSetup() {
        cin.tie(0)->sync_with_stdio(0);
        cout << fixed << setprecision(20);
        cerr << fixed << setprecision(10);
    }
} iosetup;
template <typename T> istream &operator>>(istream &s, vector<T> &v) {
    for (auto &&e : v) s >> e;
    return s;
}
template <typename T> ostream &operator<<(ostream &s, const vector<T> &v) {
    int i = 0;
    for (auto &&e : v) s << (i++ ? " " : "") << e;
    return s;
}
template <typename T> void print(const vector<vector<T>> &G) {
    for (auto &&v : G) cout << v << endl;
}
template <typename T, typename U> void print(const pair<T, U> &p) {
    cout << p.first << " " << p.second << endl;
}
template <typename T> void print(const T &v) {
    cout << v << endl;
}
void yn(bool o) {
    cout << (o ? "Yes" : "No") << endl;
}
void YN(bool o) {
    cout << (o ? "YES" : "NO") << endl;
}
