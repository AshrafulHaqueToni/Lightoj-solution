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
    vector<edge>e;
    vector<int>g[mx];
    void init() {
        e.clear();
        memset(d,0,sizeof(d));
        for(int i = 0; i < mx ; i++)g[i].clear();
    }
    void addEdge(int a,int b,ll cap, int x = -1, int y= -1) {
        edge e1 = { a, b, cap, 0, 1, x, y } ;
        edge e2 = { b, a, 0, 0, 0, x, y } ;
        g[a].push_back((int)e.size());
        e.push_back(e1);
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
int Instrument[mx];
int Profit[mx];

void solve()
{
	 dc.init();
	 scanf("%d%d",&m,&n);
	 for(int i=1;i<=m;i++)scanf("%d",&Profit[i]);
	 for(int i=1;i<=n;i++)scanf("%d",&Instrument[i]);

	 ll total=0;

	 for(int i=1;i<=m;i++)
	 {
	 	dc.addEdge(0,i,Profit[i]);
	 	total+=Profit[i];
	 }

	 for(int i=1;i<=n;i++)
	 {
	 	dc.addEdge(m+i,m+n+1,Instrument[i]);
	 }

	 for(int i=1;i<=m;i++)
	 {
	 	int x;
	 	scanf("%d",&x);
	 	for(int j=1;j<=x;j++)
	 	{
	 		int y;
	 		scanf("%d",&y);
	 		dc.addEdge(i,y+m,INF);
	 	}
	 }

	 dc.s=0;
	 dc.t=n+m+1;

	 ll need=dc.dinic();

	 total=max(0LL,total-need);

	 printf("Case %d: %lld\n",++ii,total );

}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
