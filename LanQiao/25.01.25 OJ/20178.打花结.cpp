#include <iostream>
using namespace std;
int n,x;
int l,w,sizep;
string s="";
void dfs(int sz,int x)
{
  if(sz>x)
  {
    if(sz%2==1)
    {
      s="No";
      return;
    }
    sz/=2;
    dfs(sz,x);
  }
  else if(sz==x)
  {
    s="Yes";
  }
  else
  {
    s="No";
  }
  return;
}

int main()
{
  cin>>n>>x;
  for(int i=0;i<n;i++)
  {
    cin>>l>>w;
    sizep=l*w;
    dfs(sizep,x);
    cout<<s<<endl;
  }
  return 0;
}
