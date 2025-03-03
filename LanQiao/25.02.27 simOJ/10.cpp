#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;cin>>n;
	int e[n];
	for(int i=0;i<n;i++)
	{
		cin>>e[i];
	}
	int m;cin>>m;
	int vtemp;
	queue<int> v;
	for(int i=0;i<m;i++)
	{
		cin>>vtemp;
		v.push(vtemp);
	}
	for(int i=0;i<n;i++)
	{
		while(e[i]>v.front())
		{
			v.pop();
			if(v.empty())
			{
				cout<<i<<'\n';
				return 0;
			}
		}
		v.pop();
		if(v.empty())
		{
			cout<<i+1<<'\n';
			return 0;
		}
	}
	return 0;
}
