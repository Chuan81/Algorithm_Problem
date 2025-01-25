#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,temp;
  cin>>n;
  vector<int>a(n);
  vector<int>b(n);
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    a[i]=temp;
    b[i]=temp;
  }
  sort(b.begin(),b.end());
  int cnt=0;
  for(int i=0;i<n;i++)
  {
    if(a[i]==b[cnt])
    {
      cnt++;
    }
  }
  int ans = n-cnt;
  cout<<ans<<endl;
  return 0;
}
