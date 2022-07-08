// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 20005
#define ll long long
#define mod 100000007 //998244353
 
int dp[2][mx];
int s_pre[mx];
int n,m,ii,k;
int add(int a,int b)
{
    a+=b;
    if(a>=mod)a-=mod;
    return a;
}
int sub(int a,int b)
{
    a-=b;
    if(a<0)a+=mod;
    return a;
}
int mul(int a,int b)
{
    ll re=a;
    re*=b;
    if(re>=mod)re%=mod;
    return re;
}
void solve()
{
    int s;
    scanf("%d%d%d",&n,&k,&s);
    if(s<n or s>n*k)
    {
        printf("Case %d: 0\n",++ii);
        return;
    }
    for(int i=1;i<=s;i++){
        dp[1][i]=i<=k?i:0;
        dp[0][i]=0;
        s_pre[i]=0;
    }
    bool f=0;

    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=s;j++){
            s_pre[j]=add(s_pre[j-1],dp[f^1][j]);
        }
            
        for(int j=1;j<=s;j++)
        {
            
            int re=add(dp[f][j-1],s_pre[j-1]);
            if(j>k){
                re=sub(re,s_pre[j-k-1]);
                re=sub(re,mul(dp[f^1][j-k-1],k));
            }
            dp[f][j]=re;
            //cout<<i<<" "<<j<<" "<<re<<endl;
            
        }
        f^=1;
    }
    printf("Case %d: %d\n",++ii,dp[f^1][s]);

 
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
