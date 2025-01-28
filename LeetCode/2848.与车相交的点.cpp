/*
 * @lc app=leetcode.cn id=2848 lang=cpp
 *
 * [2848] 与车相交的点
 */

// @lc code=start
int check[110];
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) 
    {
        for(int i=0;i<110;i++)
        {
            check[i]=0;
        }
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=nums[i][0];j<=nums[i][1];j++)
            {
                check[j]=1;
            }
        }
        for(int i=1;i<=100;i++)
        {
            check[i]+=check[i-1];
        }
        return check[100];
    }
};
// @lc code=end

