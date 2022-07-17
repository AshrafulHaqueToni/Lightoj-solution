// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 1005
#define ll long long
int n,m,ii,k;
vector<int>g[mx];
pair<int,int>dp[mx][2];
int vis[mx][2];

pair<int,int>func(int u,int p,int take){
    if(vis[u][take]==ii)return dp[u][take];
    vis[u][take]=ii;
    pair<int,int>re={take,0};
    for(int v:g[u]){
        if(v==p)continue;
        pair<int,int>a=func(v,u,1);
        if(take)a.second--;
        if(take)a=min(a,func(v,u,0));
        re.first+=a.first;
        re.second+=a.second;

    }
    return dp[u][take]=re;
}

void solve()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x++;
        y++;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ii++;
    pair<int,int>re={0,0};
    for(int i=1;i<=n;i++){
        if(vis[i][0]==ii or vis[i][1]==ii)continue;
        pair<int,int>a=min(func(i,0,0),func(i,0,1));
        re.first+=a.first;
        re.second+=a.second;
    }
    printf("Case %d: %d %d %d\n",ii,re.first,-re.second,m+re.second);
    for(int i=1;i<=n;i++)g[i].clear();
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
