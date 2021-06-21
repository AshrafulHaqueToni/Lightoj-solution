// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 105
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
map<string,int>mp;
 
void solve()
{
    dc.init();
    scanf("%d%d",&n,&m);
    dc.s=0;
    dc.t=6+m+1;
    for(int i=1;i<=6;i++)dc.addEdge(0,i,n);
    for(int i=1;i<=m;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        dc.addEdge(mp[s1],i+6,1);
        dc.addEdge(mp[s2],i+6,1);
        dc.addEdge(i+6,dc.t,1);
    }
    int val=dc.dinic();
    //cout<<val<<endl;
    if(val==m)
    {
        printf("Case %d: YES\n",++ii);
    }
    else printf("Case %d: NO\n",++ii);


}
 
int main()
{
    int t=1;
    mp["L"]=1;
    mp["XL"]=2;
    mp["XXL"]=3;
    mp["M"]=4;
    mp["S"]=5;
    mp["XS"]=6;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
