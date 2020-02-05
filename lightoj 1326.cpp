/// at first follow this tutorial for understand https://shahidul-brur.blogspot.com/2017/04/tutorial-lightoj-1326-uva-12034-solution.html
#include<bits/stdc++.h>
using namespace std;

#define mod 10056
#define mx 1005

int dp[1005];
int nCr[1005][1005];

void calculate_nCr()
{
    nCr[1][1]=1;
    nCr[1][0]=1;

    for(int i=2;i<mx;i++)
    {
        nCr[i][i]=1;
        nCr[i][0]=1;

        for(int j=1;j<i;j++)
            nCr[i][j]=(nCr[i-1][j-1]+nCr[i-1][j])%mod;
    }
}

int Pre_cal(int n)
{
    int &val=dp[n];

    if(val!=-1)return val;

    val=0;

    for(int i=1;i<=n;i++)
    {
        val=(val+(nCr[n][i]*Pre_cal(n-i))%mod+mod)%mod;
    }

    return val;
}

void solve(int ii)
{
    int n;
    scanf("%d",&n);
    printf("Case %d: %d\n",ii,dp[n]);
    return;
}

int main()
{
    int t=1;
    scanf("%d",&t);

    calculate_nCr();
    memset(dp,-1,sizeof dp);
    dp[1]=1;
    dp[0]=1;
    Pre_cal(mx-1);

    for(int i=1;i<=t;i++)solve(i);

    return 0;
}
