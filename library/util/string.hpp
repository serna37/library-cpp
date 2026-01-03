#pragma once
/**
 * @brief 文字列
 */
class String {
  public:
    bool is_low(char c) {
        return islower(c) != 0;
    }
    bool is_upp(char c) {
        return isupper(c) != 0;
    }
    // 小文字に変換
    string transform_lower(string s) {
        std::transform(all(s), s.begin(), ::tolower);
        return s;
    }
    // 大文字に変換
    string transform_upper(string s) {
        std::transform(all(s), s.begin(), ::toupper);
        return s;
    }
    // 「0000ABCDE」左側を埋めたsize桁の文字
    string lpad(const string &S, int size, char ch = '0') {
        int N = S.size();
        if (N >= size) return S;
        return string(size - N, ch) + S;
    }
    // 「ABCDE0000」右を埋めたsize桁の文字
    string rpad(const string &S, int size, char ch = '0') {
        int N = S.size();
        if (N >= size) return S;
        return S + string(size - N, ch);
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
    // ランレングス圧縮
    vector<pair<char, int>> run_length(const string &S) {
        vector<pair<char, int>> res;
        for (auto &&x : S) {
            if (res.empty() or res.back().first != x) res.emplace_back(x, 0);
            ++res.back().second;
        }
        return res;
    }
    // Z-Algorithm: SとS[i:|S|]の最大共通接頭辞の長さ
    vector<int> z_algo(const string &S) {
        int n = S.size();
        if (n == 0) return {};
        vector<int> z(n);
        z[0] = n;
        for (int i = 1, j = 0; i < n; ++i) {
            int &k = z[i];
            k = (j + z[j] <= i) ? 0 : min(j + z[j] - i, z[i - j]);
            while (i + k < n and S[k] == S[i + k]) ++k;
            if (j + z[j] < i + z[i]) j = i;
        }
        return z;
    }
};
