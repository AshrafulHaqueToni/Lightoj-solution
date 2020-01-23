#include<bits/stdc++.h>
using namespace std;
 
 
int n;
 
int a[21][3];
int dp[21][3];
 
int func(int x,int y)
{
    if(x==n)return 0;
 
    if(dp[x][y]!=-1)return dp[x][y];
 
    int re=1e9;
 
    if(y==0){
        re=min(re,func(x+1,y+1)+a[x][y]);
        re=min(re,func(x+1,y+2)+a[x][y]);
    }
    else if(y==1)
    {
        re=min(re,func(x+1,y+1)+a[x][y]);
        re=min(re,func(x+1,y-1)+a[x][y]);
    }
    else
    {
        re=min(re,func(x+1,y-1)+a[x][y]);
        re=min(re,func(x+1,y-2)+a[x][y]);
    }
 
    return dp[x][y]=re;
}
 
 
int main()
{
    int t;
 
    scanf("%d",&t);
 
    for(int ii=1;ii<=t;ii++)
    {
        memset(dp,-1,sizeof(dp));
 
        scanf("%d",&n);
 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
                scanf("%d",&a[i][j]);
        }
 
        int re=1e9;
 
        re=min(func(0,0),re);
        re=min(func(0,1),re);
        re=min(func(0,2),re);
 
        printf("Case %d: %d\n",ii,re);
    }
 
    return 0;
}
 
