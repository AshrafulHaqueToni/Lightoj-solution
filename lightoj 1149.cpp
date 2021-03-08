// Created by ash_98


/// BPM solution 

#include<bits/stdc++.h>
using namespace std;
#define mx 205
#define ll long long
int n,m,ii,k;
struct BPM
{
	bool Done[mx];
    vector<int>g[mx];
    int Left[mx],Right[mx];
    void Done_Restore()
    {
      memset(Done,0,sizeof Done);
    }
    void addEdge(int u,int v)
    {
        g[u].push_back(v);
    }
    void init()
    {
        for(int i=0;i<mx;i++)g[i].clear();
        memset(Done,0,sizeof Done);
        memset(Left,-1,sizeof Left);
        memset(Right,-1,sizeof Right);
    }
    bool Bipar_Matching(int u)
    {
        for(int v: g[u])
        {
            if(Done[v]) continue;
            Done[v] = true;
            if(Right[v]==-1 || Bipar_Matching(Right[v]))
            {
                Left[u] = v;
                Right[v] = u;
                return true;
            }
        }
        return false;
    }
    int Matching(int num)
    {
        memset(Left,-1,sizeof Left);
        memset(Right,-1,sizeof Right);
        int re = 0;
        for(int i = 1; i <=num; i++)
        {
            memset(Done,0,sizeof Done);
            if(Bipar_Matching(i)) 
            	{
            		re++;
            		
            	}
        }
        return re;
    }
 
 
};

BPM bp;

int ar[mx];
int br[mx];

 
void solve()
{
	 
	 scanf("%d",&n);

	 for(int i=1;i<=n;i++)scanf("%d",&ar[i]);

	 scanf("%d",&m);

	 bp.init();

	 for(int i=1;i<=m;i++)scanf("%d",&br[i]);

	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=m;j++)
	 	{
	 		if(br[j]%ar[i]==0)
 			{
 				bp.addEdge(i,j+n);
 				//cout<<i<<" "<<j<<endl;
 			}
	 	}
	 }

	
	 printf("Case %d: %d\n",++ii,bp.Matching(n) );

}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}


/// Hopcroft_Karp solution

// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 205
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
int ar[mx];
int br[mx];

 
void solve()
{
	 
	 scanf("%d",&n);

	 for(int i=1;i<=n;i++)scanf("%d",&ar[i]);

	 scanf("%d",&m);

	 hk.init(n+m+1);

	 hk.n=n;
	 hk.m=m+n;

	 for(int i=1;i<=m;i++)scanf("%d",&br[i]);

	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=m;j++)
	 	{
	 		if(br[j]%ar[i]==0)hk.addEdge(i,j+n);
	 	}
	 }

	
	 printf("Case %d: %d\n",++ii,hk.hopcroft_karp() );

}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
