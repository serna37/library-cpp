#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "template/template.hpp"
#include "library/polynomial/convolution_fft.hpp"
void run_unit_tests() {
    // ケース1: 基本的な畳み込み (1 + 2x + 3x^2) * (4 + 5x + 6x^2)
    {
        vector<int> a = {1, 2, 3};
        vector<int> b = {4, 5, 6};
        vector<long long> expected = {4, 13, 28, 27, 18};
        vector<long long> res = convolution_fft(a, b);
        assert(res.size() == expected.size());
        for (int i = 0; i < (int)res.size(); i++) {
            assert(res[i] == expected[i]);
        }
    }
    // ケース2: 長さが異なる数列の畳み込み
    {
        vector<int> a = {1, 1, 1, 1};
        vector<int> b = {1, 2};
        // (1+x+x^2+x^3)*(1+2x) = 1 + 3x + 3x^2 + 3x^3 + 2x^4
        vector<long long> expected = {1, 3, 3, 3, 2};
        vector<long long> res = convolution_fft(a, b);
        assert(res.size() == expected.size());
        for (int i = 0; i < (int)res.size(); i++) {
            assert(res[i] == expected[i]);
        }
    }
    // ケース3: 0を含むケース
    {
        vector<int> a = {0, 5, 0};
        vector<int> b = {0, 2};
        // (5x) * (2x) = 10x^2
        vector<long long> expected = {0, 0, 10, 0};
        vector<long long> res = convolution_fft(a, b);
        assert(res.size() == expected.size());
        for (int i = 0; i < (int)res.size(); i++) {
            assert(res[i] == expected[i]);
        }
    }
    // ケース4: 大きな値の精度確認 (10^6 * 10^6 = 10^12)
    {
        vector<long long> a = {1000000};
        vector<long long> b = {1000000};
        vector<long long> res = convolution_fft(a, b);
        assert(res[0] == 1000000000000LL);
    }
}
/**
 * @brief 畳み込みFFTのテスト
 */
void solve() {
    print("Hello World");
    run_unit_tests();
}
