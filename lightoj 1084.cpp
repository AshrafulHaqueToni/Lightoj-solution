// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 200005
#define ll long long
#define mod 1000000007 //998244353
 
int ar[mx];
int dp[mx];
int vis[mx];
int n,m,ii,k;

int func(int i)
{
    if(i>n)return 0;
    if(vis[i]==ii)return dp[i];
    vis[i]=ii;
    int re=mx;
    int j=lower_bound(ar+i+1,ar+n+1,ar[i]+k+k)-ar;
    if(j==n+1 or ar[j]>(ar[i]+k+k))j--;
    if(j-i>=2)
    {
        re=min(re,1+func(j+1));
    }
    if(j-i>=3)
    {
        re=min(re,1+func(j));
    }
    if(j-i>=4)
    {
        re=min(re,1+func(j-1));
    }
    return dp[i]=re;


}
 
void solve()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&ar[i]);
    sort(ar+1,ar+n+1);
    ii++;
    int re=func(1);
    if(re>n)re=-1;
    printf("Case %d: %d\n",ii,re );
 
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
