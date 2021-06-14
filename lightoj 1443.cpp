// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 70005
#define int long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k;

int lp[mx];
vector<int>prime;

void sieve()
{
    for(int i=2;i<mx-3;i++)
    {
        if(lp[i]==0)
        {
            prime.push_back(i);
            lp[i]=i;
        }
        for(int j=0;j<prime.size()&&prime[j]<=lp[i]&&i*prime[j]<mx-3;j++)
            lp[i*prime[j]]=prime[j];
    }
}

 
void solve()
{
    scanf("%lld",&n);
    int sz=prime.size();
    vector<pair<int,int>>factor;
    for(int i=0;i<sz&& prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i])continue;
        int cnt=0;
        while(n%prime[i]==0)
        {
            cnt++;
            n/=prime[i];
        }
        factor.push_back({prime[i],cnt});
    }
    if(n>1)factor.push_back({n,1});
    sort(factor.begin(),factor.end());
    vector<int>ans;
    ans.push_back(1);
    for(auto it:factor)
    {
        int val=it.first;
        int koto=it.second;
        int initial=1;
        vector<int>tem;
        int ansz=ans.size();
        for(int i=0;i<=koto;i++)
        {
            if(i&1)
            {
                for(int j=ansz-1;j>=0;j--)tem.push_back(ans[j]*initial);
            }
            else for(int j=0;j<ansz;j++)tem.push_back(ans[j]*initial);
            initial*=val;
        }
        ans=tem;
    }
    printf("Case %lld:\n",++ii );
    int ansz=ans.size();
    for(int i=0;i<ansz-1;i++)printf("%lld ",ans[i]);
    printf("%lld\n",ans[ansz-1] );
}
 
signed main()
{
    int t=1;
    sieve();
    scanf("%lld",&t);
    while(t--)solve();
    return 0;
}
