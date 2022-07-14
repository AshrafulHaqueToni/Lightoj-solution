// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 1000005
#define ll long long
#define mod 1000000007 //998244353
 

int n,m,ii,k;
ll bigmod(ll e,ll x)
{
    if(!x)
    {
        if(e)return 1;
        return 0;
    }
    ll p=bigmod(e,x/2);
    p=(p*p)%mod;
    if(x%2)p=(p*e)%mod;
    return p;
}
ll fact[mx],inv[mx];

void fact_cal()
{
    fact[0]=1;
    inv[0]=1;
    for(int i=1;i<=mx-3;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
    inv[mx-3]=bigmod(fact[mx-3],mod-2);
    for(int i=mx-4;i>=1;i--)inv[i]=(inv[i+1]*(i+1))%mod;
}

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

int nCr(int nn,int r)
{
    if(nn<r)return 0;
    return mul(fact[nn],mul(inv[nn-r],inv[r]));
}
void solve()
{
    scanf("%d",&n);
    int re=1;
    int sum=0;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        sum+=x;
        re=mul(re,nCr(sum-1,x-1));
    }
    printf("Case %d: %d\n",++ii,re );
 
}
 
int main()
{
    int t=1;
    fact_cal();
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
