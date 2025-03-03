#include<bits/stdc++.h>
using namespace std;

std::vector<int> ans(1000009);
int modp=1000000007;

int main()
{
    int n;
    cin>>n;
    ans[1]=1;
    for(int i=2;i<=n;i++)
    {
        ans[i]=(ans[i-1]*i)%modp;
    }
    cout<<ans[n]<<'\n';
    return 0;
}
