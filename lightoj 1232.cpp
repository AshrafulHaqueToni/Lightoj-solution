#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 100000007
#define mx 100005

int a[mx+10];
char ch[mx+10];
int n,k;

int dp[mx];

void solve(int ii)
{
    scanf("%d%d",&n,&k);

    memset(dp,0,sizeof dp);

    for(int i=0;i<n;i++)scanf("%d",&a[i]);

    dp[0]=1;

    for(int i=0;i<n;i++)
    {
        for(int j=a[i];j<=k;j++)
        {
            dp[j]=((dp[j]%mod)+dp[j-a[i]]%mod)%mod;
        }
    }

    printf("Case %d: %d\n",ii,dp[k]);

   return;
}

int main()
{
    int t=1;

    scanf("%d",&t);

    for(int i=1;i<=t;i++)solve(i);

    return 0;
}

