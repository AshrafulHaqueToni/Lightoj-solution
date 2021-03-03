// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 205
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k;
vector<pair<int,int>>point;

#define INF 1e12

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

bool func(int tar)
{
	dc.init();
	int sz=point.size();
	for(int i=0;i<sz;i++)
	{
		if(point[i].second)dc.addEdge(i,i+sz,2);
		else dc.addEdge(i,i+sz,1);

        for(int j=i+1;j<sz;j++)
        {
        	if((point[j].first-point[i].first)>tar)continue;
        	if(point[i].second)dc.addEdge(i+sz,j,2);
        	else dc.addEdge(i+sz,j,1);
        }
	}
	dc.s=0;
	dc.t=sz-1+sz;
	//cout<<tar<<" "<<dc.dinic()<<endl;
	if(dc.dinic()>1)return true;
	return false;
}


void solve()
{
	 scanf("%d%d",&n,&k);
	 point.clear();
	 point.push_back({0,1});
	 point.push_back({k,1});
	 for(int i=1;i<=n;i++)
	 {
	 	char c1,c2;
	 	scanf(" %c%c",&c1,&c2);
	 	int x;
	 	scanf("%d",&x);
	 	if(c1=='B')point.push_back({x,1});
	 	else point.push_back({x,0});
	 }

	 sort(point.begin(),point.end());

	 int be=1,en=k;
	 int re=en;
	 while(be<=en)
	 {
	 	int mid=(be+en)/2;
	 	if(func(mid))
	 	{
	 		re=mid;
	 		en=mid-1;
	 	}
	 	else be=mid+1;
	 }

	 printf("Case %d: %d\n",++ii,re);

}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
