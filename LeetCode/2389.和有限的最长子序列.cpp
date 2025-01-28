/*
 * @lc app=leetcode.cn id=2389 lang=cpp
 *
 * [2389] 和有限的最长子序列
 */

// @lc code=start
int prefix[1010];
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
      sort(nums.begin(),nums.end());
      int n=nums.size();
      int m=queries.size();
      for(int i=1;i<=n;i++)
      {
        prefix[i]=prefix[i-1]+nums[i-1];
      }
      vector<int> answer(m,n);
      for(int i=0;i<m;i++)
      {
        while(prefix[answer[i]]>queries[i])
        {
          answer[i]--;
        }
      }
    return answer; 
    }
};
// @lc code=end

