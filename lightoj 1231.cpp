#include<bits/stdc++.h>
using namespace std;

#define mod 100000007

int dp[51][1005],coin[51],b[51],n;

int dpcall(int i,int val)
{

    if(i>=n)
    {
        if(val==0)return 1;
        return 0;
    }

    if(dp[i][val]!=-1)return dp[i][val];

    dp[i][val]=0;

    for(int j=0; j<=b[i] && val-coin[i]*j>=0 ;j++)
    {
        dp[i][val]+=dpcall(i+1,val-coin[i]*j)%mod;
    }

    return dp[i][val]%mod;
}

int main()
{
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for(int ii=1;ii<=t;ii++)
    {
        memset(dp,-1,sizeof(dp));
        int k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)scanf("%d",coin+i);
        for(int i=0;i<n;i++)scanf("%d",b+i);

        printf("Case %d: %d\n",ii,dpcall(0,k));

    }
}
