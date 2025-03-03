#include<bits/stdc++.h>
using namespace std;


vector<string>Sr(4,"");

int main()
{
	string temp;
	cin>>Sr[0]>>Sr[1]>>Sr[2]>>Sr[3];
	sort(Sr.begin(),Sr.end());
	string smin=Sr[0]+Sr[1]+Sr[2]+Sr[3];
	do
	{
		temp=Sr[0]+Sr[1]+Sr[2]+Sr[3];
		if(temp<smin)
		{
			smin=temp;
		}
	}
	while(next_permutation(Sr.begin(),Sr.end()));
	cout<<smin<<'\n';
	return 0;
}
