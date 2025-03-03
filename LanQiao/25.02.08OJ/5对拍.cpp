#include <bits/stdc++.h>
using namespace std;

int main() {
    // 设置 N 和 K 为最大值
    int N = 1e5;
    long long K = 1e9;

    // 输出 N 和 K
    cout << N << " " << K << endl;

    // 生成 A_i，从 1 到 1e9，步长为 1e4
    for (int i = 1; i <= N; i++) {
        long long A_i = 1 + (i - 1) * 10000; // 步长为 1e4
        if (A_i > 1e9) A_i = 1e9; // 确保不超过 1e9
        cout << A_i << " ";
    }
    cout << endl;

    return 0;
}
