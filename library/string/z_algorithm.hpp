#pragma once
template <typename T = char> struct ZAlgorithm {
  private:
    vector<T> s;
    vector<int> deleted;
    vector<vector<int>> delete_hist;
    vector<int> z;
    queue<int> cur;

  public:
    ZAlgorithm() : delete_hist{{}} {}
    template <typename S> ZAlgorithm(const S &s) : ZAlgorithm() {
        for (auto &c : s) add(c);
    }
    void add(const T &c) {
        s.emplace_back(c);
        delete_hist.emplace_back();
        deleted.emplace_back(0ll);
        z.emplace_back(0ll);
        z[0ll]++;
        int len = (int)s.size();
        if (len == 1ll) return;
        if (s[0ll] == c) {
            cur.emplace(len - 1ll);
        } else {
            deleted[len - 1ll] = 1ll;
        }
        auto set = [&](int t, int len) {
            deleted[t] = 1ll;
            delete_hist[len].emplace_back(t);
            z[t] = len - t - 1ll;
        };
        while (not cur.empty()) {
            int t = cur.front();
            if (deleted[t]) {
                cur.pop();
            } else if (s[len - t - 1ll] == s.back()) {
                break;
            } else {
                set(t, len);
                cur.pop();
            }
        }
        if (not cur.empty()) {
            int t = cur.front();
            for (auto &p : delete_hist[len - t]) {
                set(p + t, len);
            }
        }
    }
    int get(int k) const { return deleted[k] ? z[k] : (int)s.size() - k; }
    int operator[](int k) const { return get(k); }
    vector<int> get() {
        vector<int> ret(s.size());
        for (int i = 0; i < (int)s.size(); i++) {
            ret[i] = get(i);
        }
        return ret;
    }
};
