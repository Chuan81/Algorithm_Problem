#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    for (int i = 0; i < (1 << 24); i++) { // ö������24λ��01��
        int cnt1 = 0;
        bool isValid = true;
        
        // ������������5λ���Ӵ�
        for (int j = 0; j <= 24 - 5; j++) {
            cnt1 = 0;
            // ͳ�ƴ�j��ʼ��5��λ����1�ĸ���
            for (int k = 0; k < 5; k++) {
                cnt1 += ((i >> (j + k)) & 1);
            }
            // ���1�ĸ�������3��˵������������
            if (cnt1 > 3) {
                isValid = false;
                break;
            }
        }

        // ����������������Ӽ���
        if (isValid) {
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
