// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 105
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,s,k;
double dis[mx][mx];

void solve()
{
    scanf("%d%d%d%d",&n,&m,&s,&k);
    memset(dis,0,sizeof(dis));
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x++;
        y++;
        dis[x][y]=dis[y][x]=z/100.00;
    }
    for(int l=1;l<=n;l++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=max(dis[i][j],dis[i][l]*dis[l][j]);
            }
        }
    }
    printf("Case %d %0.3lf\n",++ii,(double)s*k*2/dis[1][n]);
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
