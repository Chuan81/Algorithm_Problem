#include<bits/stdc++.h>
using namespace std;

int nmax = pow(2,24);

int main()
{
	string s;
	int ans=0;
	bitset<24> bit();
	for(int i=0;i<nmax;i++)
	{
		bitset<24> bit(i);
		s=bit.to_string();
		int cnt1=0;
		bool isT=0;
		for(int l=0;l<24-5+1;l++)
		{
			cnt1=0;
			string s5 = s.substr(l,5);
			for(int p=0;p<5;p++)
			{
				cnt1+=s5[p];
			}
			if(cnt1>(5*'0'+3))
			{
				isT = 1;
				break;
			}
		}
		if(!isT)
		{
			ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
