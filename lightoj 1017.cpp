#include<bits/stdc++.h>
using namespace std;

#define mx 101
#define ll long long

ll y[mx];
int dp[mx][mx];
int w,k,n;


int func(int i,int val)
{
    if(i==n || val>k)return 0;

    if(dp[i][val]!=-1)return dp[i][val];

    int re=1;
    int j;

    for(j=i+1; j<n && abs(y[i]-y[j])<=w ;j++)
    {
        re++;
    }
    re+=func(j,val+1);

    return dp[i][val]=max(re,func(i+1,val));
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(int ii=1;ii<=t;ii++)
    {
       memset(dp,-1,sizeof dp);

       scanf("%d%d%d",&n,&w,&k);

       for(int i=0;i<n;i++)
       {
           ll x;
           scanf("%lld %lld",&x,y+i);

       }

       sort(y,y+n);

       printf("Case %d: %d\n",ii,func(0,1));

    }


    return 0;
}
