#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<int> a(n);
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	int nmax=a[0];
	ans.push_back(a[0]);
	for(int i=1;i<n;i++)
	{
		if(a[i]>nmax)
		{
			ans.push_back(a[i]);
			nmax=a[i];
		}
	}
	int anslen=ans.size();
    cout<<anslen<<'\n';
    return 0;
}
