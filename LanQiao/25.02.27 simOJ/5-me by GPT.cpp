#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    for (int i = 0; i < (1 << 24); i++) { // 枚举所有24位的01串
        int cnt1 = 0;
        bool isValid = true;
        
        // 遍历所有连续5位的子串
        for (int j = 0; j <= 24 - 5; j++) {
            cnt1 = 0;
            // 统计从j开始的5个位置中1的个数
            for (int k = 0; k < 5; k++) {
                cnt1 += ((i >> (j + k)) & 1);
            }
            // 如果1的个数大于3，说明不满足条件
            if (cnt1 > 3) {
                isValid = false;
                break;
            }
        }

        // 如果满足条件，增加计数
        if (isValid) {
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
