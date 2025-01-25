#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
  cin>>n;
  vector<int>x(n);
  for(int i=0;i<n;i++)
  {
    cin>>x[i];
  }
  sort(x.begin(),x.end());
  int minx = x[0];
  int maxx = x[n-1];
  int ans = (maxx+minx)/2;
  cout<<ans<<endl;
  return 0;
}
