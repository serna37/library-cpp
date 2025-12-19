#pragma once
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
template <typename T> ostream &operator<<(ostream &s, vector<T> &v) {
    int i = 0;
    for (auto &&e : v) {
        if (i++) s << " ";
        s << e;
    }
    s << endl;
    return s;
}
// 行列を出力
auto coutGrid = []<class T>(vector<vector<T>> &G) {
    for (auto &&v : G) cout << v;
};
void yn(bool o) {
    cout << (o ? "Yes" : "No") << endl;
}
void YN(bool o) {
    cout << (o ? "YES" : "NO") << endl;
}
