// Created by ash_98

#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define mod 100000007

int ar[55],br[55];
char ch[mx];
int dp[55][1005];
int n,m,ii,k;

int add(int a,int b)
{
	a+=b;
	if(a>=mod)a-=mod;
	return a;
}

void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&ar[i]);
	for(int i=1;i<=n;i++)scanf("%d",&br[i]);

    dp[n+1][0]=1;
    for(int i=1;i<=m;i++)dp[n+1][i]=0;

    for(int i=n;i>=1;i--)
    {
         for(int j=0;j<=m;j++)
         {
         	dp[i][j]=0;
         	for(int l=0;l<=br[i];l++)
         	{
         		if(l*ar[i]>j)break;
         		dp[i][j]=add(dp[i][j],dp[i+1][j-l*ar[i]]);
         	}
         }
        
    }
    
    printf("Case %d: %d\n",++ii, dp[1][m]);

}

int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
