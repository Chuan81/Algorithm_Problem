/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start
int prefix[100010];
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {  
        int ans=0;
        for(int i=0;i<100010;i++)
        {
            prefix[i]=0;
        }
        int n=cardPoints.size();
        for(int i=1;i<=n;i++)
        {
            prefix[i]=prefix[i-1]+cardPoints[i-1];
        }
        for(int st=1;st-k-1<=0;st++)
        {
            ans=max(ans,(prefix[st-1]+prefix[n]-prefix[st+n-k-1]));
        }
        return ans;
        
    }
};
// @lc code=end

