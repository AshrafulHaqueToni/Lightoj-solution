#include<bits/stdc++.h>
using namespace std;

#define mx 105
double dp[mx];

void solve(int ii)
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lf",&dp[i]);

    for(int i=n-1;i>=0;i--)
    {
        double sum=0.0;
        int cnt=0;

        for(int j=i+1;cnt<6 && j<n;j++)
        {
            sum+=dp[j];
            cnt++;
        }

        if(cnt)dp[i]+=sum*(1.0/cnt);
        else dp[i]+=sum;
    }
    printf("Case %d: %lf\n",ii,dp[0]);
    return;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t=1;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);

    return 0;
}
