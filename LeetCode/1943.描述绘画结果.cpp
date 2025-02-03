/*
 * @lc app=leetcode.cn id=1943 lang=cpp
 *
 * [1943] 描述绘画结果
 */

// @lc code=start
int pColor[100010];
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) 
    {
        for(int i=0;i<100010;i++)
        {
            pColor[i]=0;
        }
        int n=segments.size();
        vector<bool> cChange(100010,0);
        for(int i=0;i<n;i++)
        {
            pColor[segments[i][0]]+=segments[i][2];
            pColor[segments[i][1]]-=segments[i][2];
            cChange[segments[i][0]]=cChange[segments[i][1]]=1;
        }
        vector<vector<long long>>ans;
        vector<long long>ansT(3);
        int first;
        for(int i=1;i<=100000;i++)
        {
            if(cChange[i]==1)
            {
                ansT[0]=first=i;
                break;
            }
        }
        for(int i=1;i<=100000;i++)
        {
            if(cChange[i]==1&&i!=first)
            {
                ansT[1]=i;
                ans.push_back(ansT);
                ansT[0]=i;
                ansT[2]=0;
            }
        }
        int ansl=ans.size();
        int cnt=0;
        for(int i=0;i<ansl;i++)
        {
            for(int j=0;j<ans[i][1];j++)
            {   
                ans[i][2]+=pColor[j];
            }
        }
        for(int i=0;i<ansl;i++)
        {
            if(ans[i][2]==0)
            {
                swap(ans[i],ans[ansl-1-cnt]);
                cnt++;
            }
        }
        for(int i=0;i<cnt;i++)
        {
            ans.pop_back();
        }
        return ans;
    }
};
// @lc code=end

