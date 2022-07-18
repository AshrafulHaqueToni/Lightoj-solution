// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 405
#define ll long long
#define mod 1000000007 //998244353
 
int n,m,ii,k;
ll fact[mx],inv[mx];

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

int dp[mx][mx];
int vis[mx][mx];

int func(int cell,int col){
    if(col>cell or !cell or !col)return 0;
    if(col==1)return 1;
    if(vis[cell][col])return dp[cell][col];
    vis[cell][col]=1;
    int re=0;
    for(int i=1;i<=cell;i++){
        re=add(re,mul(nCr(cell,i),func(cell-i,col-1)));
    }
    return dp[cell][col]=re;
}
 
void solve()
{
    scanf("%d%d%d",&n,&m,&k);
    int tot=(n+1)*(m+1);
    int first_half=tot/2;
    int second_half=tot-first_half;
    if(tot==1){
        printf("Case %d: %d\n",++ii,k);
        return;
    }
    if(k==1){
        printf("Case %d: 0\n",++ii );
        return;
    }
    int re=0;
    for(int i=1;i<k;i++){

        int black=nCr(k,i);

        black=mul(black,func(first_half,i));
    
        int white=bigmod(k-i,second_half);

        re=add(re,mul(white,black));
    }
    printf("Case %d: %d\n",++ii,re);

 
}
 
int main()
{
    int t=1;
    fact_cal();
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
