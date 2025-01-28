/*
 * @lc app=leetcode.cn id=1413 lang=cpp
 *
 * [1413] 逐步求和得到正数的最小值
 */

// @lc code=start
int prefix[110];
class Solution {
public:
    int minStartValue(vector<int>& nums) 
    {
        for(int i=0;i<110;i++)
        {
            prefix[i]=0;
        }
        int n=nums.size();
        int minfix=0x7f7f7f7f;
        for(int i=1;i<=n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i-1];
            minfix=min(prefix[i],minfix);
        }
        minfix=max(1-minfix,1);
        return minfix;
    }
};
// @lc code=end

