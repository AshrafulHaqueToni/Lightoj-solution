#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
ll dp[15][2][15][2];
const ll mpos=11;
char ch[40];
 
void convert(ll n)
{
    for(ll i=0; i<mpos; i++)
    {
        ch[i]=(n%10)+'0';
        n/=10;
    }
 
    reverse(ch,ch+mpos);
    ch[mpos]=0;
}
 
ll func(ll pos,ll smallornot,ll zerocnt,ll startornot)
{
    if(pos==mpos)
        return zerocnt;
 
    if(dp[pos][smallornot][zerocnt][startornot]!=-1)
        return dp[pos][smallornot][zerocnt][startornot];
 
    ll be=0;
    ll en=9;
 
    if(!smallornot)
        en=ch[pos]-'0';
 
    ll re=0;
 
    for(ll i=be; i<=en; i++)
    {
        ll ismallornot= smallornot | (i<en);
        ll izerocnt=zerocnt+((i==0) && startornot);
        ll istartornot= startornot | (i!=0);
 
        re+=func(pos+1,ismallornot,izerocnt,istartornot);
    }
 
    return dp[pos][smallornot][zerocnt][startornot]=re;
}
 
 
 
int main()
{
    int t;
    scanf("%d",&t);
    for(int ii=1; ii<=t; ii++)
    {
 
        ll n,m;
        scanf("%lld%lld",&m,&n);
 
        memset(dp,-1,sizeof dp);
 
        convert(n);
        // printf("%s\n",ch);
        ll re1=func(0,0,0,0)+1;
 
        ll re2=0;
 
        //printf("%s\n",ch);
 
        if(m>0)
        {
            convert(m-1);
            // printf("%s\n",ch);
            memset(dp,-1,sizeof dp);
            re2=func(0,0,0,0)+1;
        }
 
        //cout<<re1<<" "<<re2<<endl;
 
        printf("Case %d: %lld\n",ii,re1-re2);
    }
 
    return 0;
}
