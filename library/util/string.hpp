#pragma once
/**
 * @brief 文字列
 */
class String {
  public:
    // 結合
    string join(const vector<string> &v, const string &sep) {
        string res;
        for (int i = 0; i < (int)v.size(); ++i) {
            if (0 < i) res += sep;
            res += v[i];
        }
        return res;
    }
    /**
     * 文字列Tの中にあるSの一致場所を全て取得
     * マッチした頭のインデックスを返す
     */
    vector<int> finds(const string &T, const string &S) {
        vector<int> pos;
        auto p = T.find(S);
        while (p != string::npos) {
            pos.emplace_back(p);
            p = T.find(S, p + 1);
        }
        return pos;
    }
    // 区切り文字(1文字)で区切る
    vector<string> split(const string &S, const char &sep) {
        vector<string> res = {""};
        for (auto &&v : S) {
            if (v == sep) {
                res.emplace_back("");
            } else {
                res.back() += v;
            }
        }
        return res;
    }
    // 複数の区切り文字で区切る 区切り文字がない場合空文字
    vector<string> split_multi(const string &S, const string &seps) {
        vector<string> res = {""};
        for (auto &&v : S) {
            if (count(all(seps), v)) {
                res.emplace_back("");
            } else {
                res.back() += v;
            }
        }
        return res;
    }
    // 文字列の区間[A, B]を取得
    string str_range(const string &S, int A, int B) {
        if (A > B or A >= (int)S.size()) return "";
        return S.substr(A, B - A + 1);
    }
    // ランレングス圧縮 O(N)
    vector<pair<char, int>> run_length(const string &S) {
        vector<pair<char, int>> res;
        for (auto &&x : S) {
            if (res.empty() or res.back().first != x) res.emplace_back(x, 0);
            ++res.back().second;
        }
        return res;
    }
};
