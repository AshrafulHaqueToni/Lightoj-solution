// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 5005
#define ll long long
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

int dp[505][505];
bool vis[505][505];

int add(int a,int b)
{
    a+=b;
    if(a>=mod)a-=mod;
    return a;
}
int mul(int a,int b)
{
    ll re=(ll)a*b;
    if(re>=mod)re%=mod;
    return (int)re;
}

int func(int i,int pn)
{
    if(i==0)
    {
        if(pn==0)return 1;
        return 0;
    }
    if(pn==0)return 0;
    if(vis[i][pn])return dp[i][pn];
    vis[i][pn]=1;
    int re=0;
    ll val=1;
    for(int j=1;j<=pn;j++)
    {
        re=add(re,mul(mul(val,prime[i-1]-1),func(i-1,pn-j)));
        val=mul(val,prime[i-1]);
    }
    return dp[i][pn]=re;
}

 
void solve()
{
   scanf("%d%d",&k,&n);
   printf("Case %d: %d\n",++ii,func(n,k));
}
 
int main()
{
    int t=1;
    sieve();
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
