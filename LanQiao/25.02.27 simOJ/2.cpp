#include<iostream>
using namespace std;

bool isSu[2025];


int main()
{
	long long cnt =0;
	isSu[0]=1;
	isSu[1]=1;
	for(int i =2;i*i<=2024;i++) 
	{
		if (!isSu[i]) 
		{
        for (int c = i * i; c <= 2024; c += i) 
		{
            isSu[c] = 1;
        	}
    	}
	}
	for(int i =2024;i>1;i--) 
	{
		if(isSu[i]==0)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}
