#include <bits/stdc++.h>
using namespace std;
const int MAX=200010;
int vis[MAX]={0};
queue<int> q;
void bfs(int n,int k)
{
  q.push(n);
  while (!q.empty()&&vis[k]==0)
  {
    int u = q.front();
    q.pop();
    if(u+1<MAX/2&&vis[u+1]==0){q.push(u+1);vis[u+1]=vis[u]+1;}
    if(u*2<MAX&&vis[u*2]==0){q.push(2*u);vis[2*u]=vis[u]+1;}
    if(u-1>=0&&vis[u-1]==0){q.push(u-1);vis[u-1]=vis[u]+1;}
  }
}
int main()
{
  int n,k;
  cin>>n>>k;
  bfs(n,k);
  cout<<vis[k]<<endl;
  return 0;
}