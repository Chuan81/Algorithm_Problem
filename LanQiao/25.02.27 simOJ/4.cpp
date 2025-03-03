#include<bits/stdc++.h>
using namespace std;

map<string,int>mp;

int main()
{
	string S = "ANQNANBNQNANQNQNBNINQNQNANQNINANQNANBNQNANQNQNBNBNQNQNANQNINANQNANBNQNANQNQNBNINQNQNANQNINBNQNANBNQN";
	int len=S.size();
	int ans=0;
	string anss="";
	for(int subl=1;subl<=10;subl++)
	{
		for(int start=0;start<len-subl+1;start++)
		{
			string A = S.substr(start,subl);
			mp[A]++;
		}
	}
	for (auto &pr : mp)
    {
    	pr.second=pr.first.size()*pr.second;
	}
	for (auto &pr : mp)
    {
    	if(pr.second>ans)
    	{
    		ans=pr.second;
    		anss=pr.first;
		}
	}
	cout<<anss<<'\n';
	return 0;
}
