#include<bits/stdc++.h>
using namespace std;

vector<int>ans;

int main()
{
	int i=1;
	while(ans.size()<2024)
	{
		if(__gcd(i,2024)==1)
		{
			ans.push_back(i);
		}
		i++;
	}
	cout<<ans[2023]<<endl;
	return 0;
}
