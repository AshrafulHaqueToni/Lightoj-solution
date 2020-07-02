#include<bits/stdc++.h>
using namespace std;

#define mx 105
#define ll long long

int ar[mx];
char ch[mx];
vector<int>g[mx];
int st[mx],en[mx];
int n,m,k,ii;

void bfs(int p)
{
    st[p]=0;
    queue<int>q;
    q.push(p);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto it:g[u])
        {
            if(st[it]!=-1 && st[it]<=st[u]+1)continue;
            st[it]=st[u]+1;
            q.push(it);
        }
    }
}

void bfs1(int p)
{
    en[p]=0;
    queue<int>q;
    q.push(p);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto it:g[u])
        {
            if(en[it]!=-1 && en[it]<=en[u]+1)continue;
            en[it]=en[u]+1;
            q.push(it);
        }
    }
}

void solve()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x++,y++;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int x,y;
    scanf("%d%d",&x,&y);
    x++,y++;
    memset(st,-1,sizeof(st));
    memset(en,-1,sizeof(en));
    bfs(x);
    bfs1(y);
    int re=0;
    for(int i=1;i<=n;i++)re=max(re,st[i]+en[i]);
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
