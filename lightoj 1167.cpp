// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 205
#define ll long long
#define INF 1e12
int n,m,ii,k;

const ll eps = 0;

struct edge {
    int a, b;
    ll cap,flow;
    int yo, x, y;
};

struct Dinic {
    int s,t,d[mx], ptr[mx] ;
    //int Id[mx][mx];
    vector<edge>e;
    vector<int>g[mx];
    void init() {
        e.clear();
        memset(d,0,sizeof(d));
        for(int i = 0; i < mx ; i++)g[i].clear();
        // for(int i=0;i<mx;i++)
        // {
        //  for(int j=0;j<mx;j++)
        //  {
        //      Id[i][j]=0;
        //  }
        // }
    }
    void addEdge(int a,int b,ll cap, int x = -1, int y= -1) {
        edge e1 = { a, b, cap, 0, 1, x, y } ;
        edge e2 = { b, a, 0, 0, 0, x, y } ;
      //  Id[a][b]=e.size();
        g[a].push_back((int)e.size());
        e.push_back(e1);
      //  Id[b][a]=e.size();
        g[b].push_back((int)e.size());
        e.push_back(e2);
    }
    bool bfs() {
        queue < int > Q ;
        Q.push(s);
        memset(d,-1,sizeof(d));
        d[s]=0 ;
        while (!Q.empty()) {
            int u=Q.front() ;
            Q.pop() ;
            for(int i=0; i<g[u].size(); i++) {
                int id=g[u][i];
                int v=e[id].b;
              //  printf("%d %d %0.3lf %0.3lf\n",u,v,e[id].cap,e[id].flow);
                if(d[v]==-1&&e[id].flow<e[id].cap) {
                    Q.push(v) ;
                    d[v]=d[u]+1 ;
                }
            }
        }
        return d[t]!=-1 ;
    }
    ll dfs(int u,ll flow) {
        if (flow<=eps)  return 0 ;
        if ( u==t )  return flow ;
        for(int& i = ptr[u] ; i<g[u].size(); i++) {
            int id = g[u][i];
            int v =  e[id].b ;
            if ( d[v] != d[u]+1 )  continue ;
            ll pushed = dfs (v,min (flow,e[id].cap-e[id].flow)) ;
            //cout << "pushed " << pushed << endl;
            if (pushed>eps) {
                e [id].flow+=pushed ;
                e [id^1].flow-=pushed ;
                return pushed ;
            }
        }
        return 0 ;
    }
    ll dinic() {
        ll flow = 0 ;
        while(true) {
            if(!bfs())  break ;
            memset(ptr, 0, sizeof(ptr)) ;
            while (true){
                ll pushed = dfs(s,INF );
                if(pushed<=eps)break;
                flow += pushed ;
            }
        }
        return flow ;
    }
};

Dinic dc;
vector<pair<pair<int,int>,int>>edge;
int on_going[mx];

int func(int tar)
{
    dc.init();
    dc.s=0;
    dc.t=n+1;
    on_going[0]=0;
    on_going[n+1]=n+1;
    for(int i=1;i<=n;i++)
    {
        on_going[i]=i+n+1;
        dc.addEdge(i,on_going[i],1);
    }
    for(auto it:edge)
    {
        if(it.second<=tar)dc.addEdge(on_going[it.first.first],it.first.second,1);

    }

    return dc.dinic();

}

 
void solve()
{
    scanf("%d%d",&n,&m);
    edge.clear();
    for(int i=1;i<=m;i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        if(x>y)swap(x,y);
        edge.push_back({{x,y},w});
    }
    scanf("%d",&k);
    int be=1,en=100000;
    int re=-1;
    while(be<=en)
    {
        int mid=(be+en)/2;
        if(func(mid)>=k)
        {
            re=mid;
            en=mid-1;
        }
        else be=mid+1;
    }
    printf("Case %d: ",++ii);
    if(re==-1)printf("no solution\n");
    else printf("%d\n",re );


}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
