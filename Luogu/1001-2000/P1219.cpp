#include <bits/stdc++.h>
using namespace std;

vector<int> board; // 用于存储每一行皇后所在的列
vector<vector<int>> solutions; // 存储所有解

// 检查在 (row, col) 位置放置皇后是否安全
bool isSafe(int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        if (board[i] == col || 
            board[i] - i == col - row || 
            board[i] + i == col + row)
        {
            return false;
        }
    }
    return true;
}

// 回溯函数
void backtrack(int row, int n)
{
    if (row == n)
    {
        solutions.push_back(board); // 找到一个解
        return;
    }
    for (int col = 0; col < n; ++col)
    {
        if (isSafe(row, col))
        {
            board[row] = col; // 放置皇后
            backtrack(row + 1, n); // 递归到下一行
            board[row] = -1; // 回溯
        }
    }
}

// 输出前三个解和解的总数
void printSolutions(int n)
{
    for (int i = 0; i < min(3, (int)solutions.size()); ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << solutions[i][j] + 1 << " ";
        }
        cout << endl;
    }
    cout << solutions.size() << endl;
}

int main()
{
    int n;
    cin >> n;

    board.resize(n, -1); // 初始化棋盘
    backtrack(0, n); // 开始回溯

    printSolutions(n); // 输出结果

    return 0;
}