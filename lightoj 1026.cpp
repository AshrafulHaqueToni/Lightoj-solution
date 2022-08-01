// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;

#define mx 10005
#define ll long long


vector<int>g[mx];
vector<pair<int,int>>Bridge;
int n,m,k,ii;
int st[mx],low[mx];
int Time=1;

void dfs(int u,int p)
{
    st[u]=low[u]=Time++;
    int child=0;
    for(auto it:g[u])
    {
        if(it==p)continue;
        if(st[it]==0)
        {
            dfs(it,u);
            if(st[u]<low[it])Bridge.push_back({min(u,it),max(u,it)});
            low[u]=min(low[u],low[it]);
        }
        else low[u]=min(low[u],st[it]);

    }
}


 
void solve()
{
    Time=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d",&x);
        x++;
        char c;
        scanf(" %c%d %c",&c,&k,&c);
        for(int j=1;j<=k;j++){
            scanf("%d",&y);
            y++;
            g[x].push_back(y);
          //  cout<<x<<" "<<y<<endl;
        }
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)if(st[i]==0)dfs(i,-1);
    printf("Case %d:\n",++ii);
    printf("%d critical links\n",(int)Bridge.size());
    sort(Bridge.begin(),Bridge.end());
    for(auto[u,v]:Bridge)printf("%d - %d\n",u-1,v-1);
    
    Bridge.clear();
    for(int i=1;i<=n;i++){
        g[i].clear();
        st[i]=0;
        low[i]=0;
    }

}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
