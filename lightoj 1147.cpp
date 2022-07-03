// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 200005
#define ll long long
#define mod 1000000007 //998244353
 
int ar[mx];
ll dp[mx];
int n,m,ii,k;
 
void solve()
{
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    int tot=0;
    for(int i=1;i<=n;i++)scanf("%d",&ar[i]),tot+=ar[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=tot;j>=0;j--)
        {
            if(dp[j])dp[j+ar[i]]|=(dp[j]<<1);
        }
    }
    int val1=0,val2=tot;
    ll mask=1LL<<(n/2);
    for(int i=1;i<=tot;i++)
    {
        if((dp[i]&mask))
        {
            int a=min(i,tot-i);
            int b=max(i,tot-i);
            if(b-a<val2-val1)val1=a,val2=b;
        }
    }
    printf("Case %d: %d %d\n",++ii,val1,val2 );

 
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
