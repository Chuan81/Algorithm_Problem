#include <bits/stdc++.h>
using namespace std;

int main() {
    // ���� N �� K Ϊ���ֵ
    int N = 1e5;
    long long K = 1e9;

    // ��� N �� K
    cout << N << " " << K << endl;

    // ���� A_i���� 1 �� 1e9������Ϊ 1e4
    for (int i = 1; i <= N; i++) {
        long long A_i = 1 + (i - 1) * 10000; // ����Ϊ 1e4
        if (A_i > 1e9) A_i = 1e9; // ȷ�������� 1e9
        cout << A_i << " ";
    }
    cout << endl;

    return 0;
}
