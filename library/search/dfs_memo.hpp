#pragma once
// メモ化再帰 !!コピペ用!! 関数内をペーストして書き換えて使う
void dfs_memo() {
    map<int, int> memo; // メモ
    auto dfs = [&](auto f, int n) {
        if (n <= 1) return n; // ベースケース
        if (memo.count(n)) return memo[n]; // メモにあれば採用
        return memo[n] = f(f, n - 1) + f(f, n - 2); // メモしつつ、再帰して計算
    };
    (void)dfs; // unused
    // int ans = dfs(dfs, N);
}