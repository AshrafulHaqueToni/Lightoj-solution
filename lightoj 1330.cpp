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
    int Id[mx][mx];
    vector<edge>e;
    vector<int>g[mx];
    void init() {
        e.clear();
        memset(d,0,sizeof(d));
        for(int i = 0; i < mx ; i++)g[i].clear();
        for(int i=0;i<mx;i++)
        {
        	for(int j=0;j<mx;j++)
        	{
        		Id[i][j]=0;
        	}
        }
    }
    void addEdge(int a,int b,ll cap, int x = -1, int y= -1) {
        edge e1 = { a, b, cap, 0, 1, x, y } ;
        edge e2 = { b, a, 0, 0, 0, x, y } ;
        Id[a][b]=e.size();
        g[a].push_back((int)e.size());
        e.push_back(e1);
        Id[b][a]=e.size();
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
int row[mx],col[mx];
 
void solve()
{
	 scanf("%d%d",&n,&m);
	 dc.init();
	 int rsum=0,csum=0;
	 for(int i=1;i<=n;i++)
	 {
	 	scanf("%d",&row[i]);
	 	rsum+=row[i];
	 	dc.addEdge(0,i,row[i]);

	 }

	 for(int i=1;i<=m;i++)
	 {
	 	scanf("%d",&col[i]);
	 	csum+=col[i];
	 	dc.addEdge(n+i,n+m+1,col[i]);

	 }

	 if(rsum!=csum)
	 {
	 	printf("Case %d: impossible\n",++ii );
	 	return;
	 }

	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=m;j++)
	 	{
	 		dc.addEdge(i,j+n,1);
	 	}
	 }

	 dc.s=0;
	 dc.t=n+m+1;

	 if(dc.dinic()!=(ll)rsum)
	 {
	 	printf("Case %d: impossible\n",++ii );
	 	return;
	 }

	 printf("Case %d:\n",++ii );

	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=m;j++)
	 	{
	 		int id=dc.Id[i][j+n];
	 		int idi=id^1;
	 		int ace=dc.e[id].flow;
	 		dc.e[id].cap=0;
	 		dc.e[idi].cap=0;
	 		dc.e[idi].flow=0;
	 		
	 		

	 		if(ace)
	 		{
	 			int id1=dc.Id[0][i]; // source to ith row
	 			int id2=dc.Id[j+n][n+m+1]; // jth column to sink
	 			
	 			dc.e[id1].flow=0;
	 			dc.e[id2].flow=0;
	 			dc.e[id1].cap=1;
		 		dc.e[id2].cap=1;

	 			if(dc.dinic())
	 			{
	 				ace=0;
	 			}
	 			else
	 			{
		 			dc.e[id1].cap=0;
		 			dc.e[id2].cap=0;
		 			dc.e[id1].flow=1;
	 			    dc.e[id2].flow=1;
	 			}
	 		}
	 		printf("%d",ace );
	 	}
	 	printf("\n");

	 }
}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
