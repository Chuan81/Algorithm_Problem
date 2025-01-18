#include <bits/stdc++.h>
using namespace std;
const int MAX=100;
int ans=0;
vector<vector<int>>mp(MAX,vector<int>(MAX,-1));
vector<vector<int>>ansl(MAX,vector<int>(MAX,-1));
void dfs(int x,int y)
{
  if(x>0)
  {
    if(y==0)
    {
      ansl[x][y]=ansl[x-1][y]+mp[x][y];
    }
    else if(y==x)
    {
      ansl[x][y]=ansl[x-1][y-1]+mp[x][y];
    }
    else
    {
      ansl[x][y]=mp[x][y]+max(ansl[x-1][y],ansl[x-1][y-1]);
    }
  }
  return;
}

int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<=i;j++)
    {
      cin>>mp[i][j];
    }
  }
  ansl[0][0]=mp[0][0];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<=i;j++)
    {
      dfs(i,j);
    }
  }
  if(n%2==1)
  {ans=ansl[n-1][n/2];}
  else{ans=max(ansl[n-1][n/2],ansl[n-1][n/2-1]);}
  cout<<ans<<endl;
  return 0;
}
