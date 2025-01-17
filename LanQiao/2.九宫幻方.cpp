#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mp(3, vector<int>(3));  // 存储当前网格
vector<bool> vis(10);  // 标记数字是否已被使用
vector<vector<int>> ans(3, vector<int>(3));  // 存储最终的解
int isFind = 0;  // 记录找到的解的数量

// 检查当前网格是否满足魔方阵的条件
bool isSafe() {
    int sum = mp[0][0] + mp[0][1] + mp[0][2];  // 计算第一行的和
    // 检查每一行、每一列和两条对角线的和是否相等
    if (mp[1][0] + mp[1][1] + mp[1][2] != sum ||
        mp[2][0] + mp[2][1] + mp[2][2] != sum ||
        mp[0][0] + mp[1][0] + mp[2][0] != sum ||
        mp[0][1] + mp[1][1] + mp[2][1] != sum ||
        mp[0][2] + mp[1][2] + mp[2][2] != sum ||
        mp[0][0] + mp[1][1] + mp[2][2] != sum ||
        mp[0][2] + mp[1][1] + mp[2][0] != sum) {
        return false;
    }
    return true;
}

// 深度优先搜索函数
void dfs(int step) {
    if (step > 8) {  // 如果所有单元格都已填充
        if (isSafe()) {  // 检查是否满足魔方阵条件
            isFind++;
            if (isFind == 1) {
                ans = mp;  // 存储第一个解
            } else if (isFind > 1) {
                cout << "Too Many" << endl;  // 如果找到多个解，输出提示并终止
                exit(0);
            }
        }
        return;
    }

    int row = step / 3;
    int col = step % 3;

    // 如果当前单元格是中心且未填充，强制填充5
    if (row == 1 && col == 1 && mp[row][col] == 0) {
        mp[row][col] = 5;
        vis[5] = true;
        dfs(step + 1);
        vis[5] = false;
        mp[row][col] = 0;
        return;
    }

    if (mp[row][col] > 0) {  // 如果当前单元格已填充，跳过
        dfs(step + 1);
        return;
    }

    for (int i = 1; i <= 9; i++) {  // 尝试填充1到9的数字
        if (vis[i]) continue;  // 如果数字已被使用，跳过
        mp[row][col] = i;
        vis[i] = true;
        dfs(step + 1);  // 递归填充下一个单元格
        vis[i] = false;  // 回溯
        mp[row][col] = 0;  // 回溯
    }
}

int main() {
    // 输入初始网格
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mp[i][j];
            if (mp[i][j] > 0) {
                vis[mp[i][j]] = true;  // 标记已使用的数字
            }
        }
    }

    dfs(0);  // 从第一个单元格开始DFS

    // 输出找到的解
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}