#include<bits/stdc++.h>
using namespace std;

#define mx 30005
#define ll long long

int ar[mx];
char ch[mx];

int n,m,k,ii,re,depth_node;

vector<pair<int,int>>g[mx];

void dfs(int u,int p,int sum)
{
    for(auto it:g[u])
    {
        if(it.first==p)continue;
        if(sum+it.second>re)
        {
            re=sum+it.second;
            depth_node=it.first;
        }
        dfs(it.first,u,sum+it.second);

    }
}

void solve()
{
   scanf("%d",&n);
   re=0;
   for(int i=1;i<n;i++)
   {
       int x,y,w;
       scanf("%d%d%d",&x,&y,&w);
       x++,y++;
       g[x].push_back({y,w});
       g[y].push_back({x,w});
   }

   dfs(1,-1,0);
   dfs(depth_node,-1,0);
   printf("Case %d: %d\n",++ii,re);
   for(int i=1;i<=n;i++)g[i].clear();
}

int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t=1;
   scanf("%d",&t);
   while(t--)solve();
   return 0;
}
