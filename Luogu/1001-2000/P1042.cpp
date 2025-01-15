#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s[2510];
    string sum="";
    int p[2];
    p[0]=0;
    p[1]=0;
    int br=0;
    for(int i=0;i<2510;i++)
    {
        cin>>s[i];
        
        for(int j=0;j<s[i].size();j++)
        {
            if (s[i][j]=='E')
            {
                sum+=s[i].substr(0,j);
                goto a;
            }
        }
        sum+=s[i];
    }
    a:
    for(int i=0;i<=sum.size();i++)
    {
        if(sum[i]=='W')
        {
            p[0]++;
        }
        else if(sum[i]=='L')
        {
            p[1]++;
        }
        else if(sum[i]=='\0')
        {
            cout<<p[0]<<':'<<p[1]<<endl;
            break;
        }
        if((p[0]>=11&&p[0]-p[1]>=2)||(p[1]>=11&&p[1]-p[0]>=2))
        {
            cout<<p[0]<<':'<<p[1]<<endl;
            p[0]=0;
            p[1]=0;
        }
    }
    cout<<endl;
    p[0]=0;
    p[1]=0;
    for(int i=0;i<=sum.size();i++)
    {
        if(sum[i]=='W')
        {
            p[0]++;
        }
        else if(sum[i]=='L')
        {
            p[1]++;
        }
        else if(sum[i]=='\0')
        {
            cout<<p[0]<<':'<<p[1]<<endl;
            break;
        }
        if((p[0]>=21&&p[0]-p[1]>=2)||(p[1]>=21&&p[1]-p[0]>=2))
        {
            cout<<p[0]<<':'<<p[1]<<endl;
            p[0]=0;
            p[1]=0;
        }
    }

    return 0;
}

