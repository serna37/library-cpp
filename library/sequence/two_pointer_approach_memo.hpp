#pragma once
// 尺取り法 !!コピペ用!! 関数内をペーストして書き換えて使う
void two_pointer_approach(int N, auto test) {
    int ans = 0;
    //      左手     右手     上限
    for (int l = 0, r = 0; l < N; ++l) {
        // 伸ばせるだけ右手を伸ばす
        //               rがtest条件を満たす間伸ばす
        while (r < N and test) ++r;
        // 伸ばしきったら、区間数でansを緩和
        ans = max(ans, r - l);
    }
}
