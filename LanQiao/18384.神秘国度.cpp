#include <bits/stdc++.h>
using namespace std;

long long s;          // 目标路程
long long min_days = LLONG_MAX;  // 初始化最小天数为最大值
bool found = false;       // 是否找到解

void dfs(long long speed, long long distance, long long days)
{
  // 如果当前总路程超过 S，直接返回
  if (distance > s)
  {
    return;
  }
  // 如果当前天数已经大于最小天数，直接返回
  if (days >= min_days)
  {
    return;
  }
  // 如果达到目标值 S，更新最小天数
  if (distance == s)
  {
    if (days >= 2)
    {
      found = true;
      min_days = min(min_days, days);
    }
    return;
  }
  // 遍历可能的倍数（2 到 9）
  for (long long i = 2; i <= 9; i++)
  {
    long long new_speed = speed * i;
    long long new_distance = distance + new_speed;
    // 如果新总路程超过 S，跳过
    if (new_distance > s)
    {
      continue;
    }
    dfs(new_speed, new_distance, days + 1);
  }
}

int main()
{
  cin >> s;  // 输入目标值 S
  // 从 S/3 到 1 的范围内尝试不同的起始值
  for (long long a = s / 3; a >= 1; a--)
  {
    if (!found)
    {
      dfs(a, a, 1);
    }
    else
    {
      break;  // 如果已经找到解，提前退出
    }
  }
  // 如果没有找到解，输出 -1
  if (!found)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << min_days << endl;  // 输出最小天数
  }
  return 0;
}