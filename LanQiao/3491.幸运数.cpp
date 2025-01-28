#include<iostream>
#include<string>
using namespace std;

using ll = long long;
ll ans = 0;

bool check(string s){
    int l = s.size();
    int left=0,right=0;
    for(int i=0;i<l;i++){
        int num = s[i]-'0';
        if(i<l/2){
            left+=num;
        }
        else{
            right+=num;
        }
    }
    if(left==right)return true;
    return false;
}

int main(){
    for(int i=11;i<1e8;i++){
        string str = to_string(i);
        if(str.size()%2!=0)continue;
        if(check(str))ans++;
    }
    cout<<ans;
    //得到最终答案4430091
    return 0;
}
