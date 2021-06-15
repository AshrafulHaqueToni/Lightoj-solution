// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
int n,m,ii,k;
#define mx 80005
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

int lp[500005];
vector<int>prime;

void sieve()
{
    for(int i=2;i<500003;i++)
    {
        if(lp[i]==0)
        {
            prime.push_back(i);
            lp[i]=i;
        }
        for(int j=0;j<prime.size()&&prime[j]<=lp[i]&&i*prime[j]<500003;j++)
            lp[i*prime[j]]=prime[j];
    }
}

int ar[mx];
int cnt[500005];
 
void solve()
{
   memset(cnt,0,sizeof(cnt));
   scanf("%d",&n);
   hk.init(n*2);
   hk.n=n;
   int boro=0;
   for(int i=1;i<=n;i++)scanf("%d",&ar[i]),cnt[ar[i]]=i;
   int sz=prime.size();
   sort(ar,ar+1+n);
   boro=ar[n];
   for(int i=1;i<=n;i++)
   {
      int p=ar[i];
      int id=0;
      while(id<sz && prime[id]*p<=boro)
      {
        int val=p*prime[id];
        if(cnt[val])
        {

            hk.addEdge(cnt[p],cnt[val]+n);
            hk.addEdge(cnt[val],cnt[p]+n);
        }
        id++;
      }
   } 

   int val=hk.hopcroft_karp();
   int re=((2*n)-val)/2;
   printf("Case %d: %d\n",++ii,re );


}
 
int main()
{
   int t=1;
   scanf("%d",&t);
   sieve();
   while(t--)solve();
   return 0;
}
