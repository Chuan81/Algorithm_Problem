#include <bits/stdc++.h>
using namespace std;

vector<int> board; // ���ڴ洢ÿһ�лʺ����ڵ���
vector<vector<int>> solutions; // �洢���н�

// ����� (row, col) λ�÷��ûʺ��Ƿ�ȫ
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

// ���ݺ���
void backtrack(int row, int n)
{
    if (row == n)
    {
        solutions.push_back(board); // �ҵ�һ����
        return;
    }
    for (int col = 0; col < n; ++col)
    {
        if (isSafe(row, col))
        {
            board[row] = col; // ���ûʺ�
            backtrack(row + 1, n); // �ݹ鵽��һ��
            board[row] = -1; // ����
        }
    }
}

// ���ǰ������ͽ������
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

    board.resize(n, -1); // ��ʼ������
    backtrack(0, n); // ��ʼ����

    printSolutions(n); // ������

    return 0;
}