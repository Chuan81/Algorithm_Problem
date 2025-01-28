/*
 * @lc app=leetcode.cn id=1893 lang=cpp
 *
 * [1893] 检查是否区域内所有整数都被覆盖
 */

// @lc code=start
long long check[55];
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) 
    {
      for(int i=0;i<55;i++)
      {
        check[i]=0;
      }
      int len=ranges.size();
      for(int i=0;i<len;i++)
      {
        for(int j=ranges[i][0];j<=ranges[i][1];j++)
        {
          check[j]=1;
        }
      }
      for(int i=1;i<=50;i++)
      {
        check[i]+=check[i-1];
      }
      if(check[right]-check[left-1]==(right-left+1))
      {
        return true;
      }
      else
      {
        return false;
      }
    }
};
// @lc code=end

