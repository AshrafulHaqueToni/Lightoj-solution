// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 105
#define ll long long
#define mod 1000000007 //998244353
 
int ar[mx][2];
int dp[mx][mx];
int vis[mx][mx];
int n,m,ii,k,tc;
int Time;

int func1(int cur,int remain)
{
	if(cur>n)
	{
		return remain==0? 0:-mx;
	}
	if(vis[cur][remain]==ii)return dp[cur][remain];
	vis[cur][remain]=ii;
	int re=-mx;
	int how=min(remain,Time/ar[cur][0]);
	for(int i=0;i<=how;i++)
	{
		int take=i*ar[cur][0];
		int extra=Time-take;
		re=max(re,(extra/ar[cur][1])+func1(cur+1,remain-i));
	}
	return dp[cur][remain]=re;
}

bool func(int T)
{
	   ii++;
	   Time=T;
       return func1(1,m)>=m;
}
 
void solve()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d%d",&ar[i][0],&ar[i][1]);
    int be=1,en=50000;
    int re=en;

    while(be<=en)
    {
    	int mid=(be+en)/2;
    	if(func(mid)){
    		re=mid;
    		en=mid-1;
    	}
    	else be=mid+1;
    }
    printf("Case %d: %d\n",++tc,re);
 
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
