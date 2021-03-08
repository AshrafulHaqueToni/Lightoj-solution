// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 40005
#define INF (1<<28)

struct Hopcroft_Karp
{
	vector< int > g[mx];
	int n, m, Matching[mx], Distance[mx];
	// n: number of nodes on left side, nodes are numbered 1 to n
	// m: number of nodes on right side, nodes are numbered n+1 to n+m
	// G = 0[0] ∪ G1[G[1---n]] ∪ G2[G[n+1---n+m]]

	void init(int num)
	{
        for(int i=0;i<=num;i++)Matching[i]=0,Distance[i]=0,g[i].clear();
	}
    
    void addEdge(int u,int v)
    {
    	g[u].push_back(v);
    }

	bool bfs() {
	    int i, u, v, len;
	    queue< int > q;
	    for(i=1; i<=n; i++) {
	        if(Matching[i]==0) {
	            Distance[i] = 0;
	            q.push(i);
	        }
	        else Distance[i] = INF;
	    }
	    Distance[0] = INF;
	    while(!q.empty()) {
	        u = q.front(); q.pop();
	        if(u!=0) {	           
	            for(int v:g[u]) {
	             	    if(Distance[Matching[v]]==INF) {
	                    Distance[Matching[v]] = Distance[u] + 1;
	                    q.push(Matching[v]);
	                }
	            }
	        }
	    }
	    return (Distance[0]!=INF);
	}

	bool dfs(int u) {
	    int i, v, len;
	    if(u!=0) {
	        for(int v:g[u]) {
	            if(Distance[Matching[v]]==Distance[u]+1) {
	                if(dfs(Matching[v])) {
	                    Matching[v] = u;
	                    Matching[u] = v;
	                    return true;
	                }
	            }
	        }
	        Distance[u] = INF;
	        return false;
	    }
	    return true;
	}

	int hopcroft_karp() {
	    int Matchinging = 0, i;
	    while(bfs())
	        for(i=1; i<=n; i++)
	            if(Matching[i]==0 && dfs(i))
	                Matchinging++;
	    return Matchinging;
	}
};

Hopcroft_Karp hk;

int n,m,k,ii;

int xx[]={-1,-1,-2,-2,1,1,2,2};
int yy[]={2,-2,1,-1,-2,2,-1,1};

bool vis[205][205];
int ID[205][205];

bool chk(int x,int y)
{
	if(x<1 || y<1 || x>n || y>m || vis[x][y]==true)return false;
	return true;
}
 
void solve()
{
	 
	 scanf("%d%d%d",&n,&m,&k);
	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=m;j++)vis[i][j]=false,ID[i][j]=0;
	 }
	 int id=1;

	 for(int i=1;i<=k;i++)
	 {
	 	int x,y;
	 	scanf("%d%d",&x,&y);
	 	vis[x][y]=true;
	 }

	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=m;j++)
	 	{
	 		if((i+j)%2==0 && vis[i][j]==0)ID[i][j]=id++;
	 	}
	 }

	 hk.n=id-1;

	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=m;j++)
	 	{
	 		if((i+j)%2==1 && vis[i][j]==0)ID[i][j]=id++;
	 	}
	 }

	 hk.m=id-1;


	 hk.init(id);

	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=m;j++)
	 	{
	 		if((i+j)%2==0 && vis[i][j]==false)
	 		{
                for(int l=0;l<8;l++)
                {
                	int u=i+xx[l];
                	int v=j+yy[l];
                	if(chk(u,v))
                	{
                		hk.addEdge(ID[i][j],ID[u][v]);
                	}
                }
	 		}
	 	}
	 }
	 
	 int re=n*m-hk.hopcroft_karp()-k;
	 printf("Case %d: %d\n",++ii,re );

}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
