// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 105
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx];
int n,m,k,ii;
vector<pair<pair<int,int>,pair<int,int>>>g;

const int inf = 1e9 ;
struct edge {
    int u, v, w;
    edge() {}
    edge(int a,int b,int c) : u(a), v(b), w(c) {}
    bool operator < (const edge& o) const {
        if (u == o.u)
            if (v == o.v)return w < o.w;
            else  return v < o.v;
        return u < o.u;
    }
};
int dmst(vector<edge> &edges, int root) { // 0 base node 0 to n-1
    int ans = 0;
    int cur_nodes = n;
    while (true) {
        vector<int> lo(cur_nodes, inf), pi(cur_nodes, inf);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i].u, v = edges[i].v, w = edges[i].w;
            if (w < lo[v] and u != v) {
                lo[v] = w;
                pi[v] = u;
            }
        }
        lo[root] = 0;
        for (int i = 0; i < lo.size(); ++i) {
            if (i == root) continue;
            if (lo[i] == inf) return -1;
        }
        int cur_id = 0;
        vector<int> id(cur_nodes, -1), mark(cur_nodes, -1);
        for (int i = 0; i < cur_nodes; ++i) {
            ans += lo[i];
            int u = i;
            while (u != root and id[u] < 0 and mark[u] != i) {
                mark[u] = i;
                u = pi[u];
            }
            if (u != root and id[u] < 0) { // Cycle
                for (int v = pi[u]; v != u; v = pi[v]) id[v] = cur_id;
                id[u] = cur_id++;
            }
        }
        if (cur_id == 0) break;
        for (int i = 0; i < cur_nodes; ++i)
            if (id[i] < 0) id[i] = cur_id++;
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i].u, v = edges[i].v, w = edges[i].w;
            edges[i].u = id[u];
            edges[i].v = id[v];
            if (id[u] != id[v]) edges[i].w -= lo[v];
        }
        cur_nodes = cur_id;
        root = id[root];
    }
    return ans;
}

bool func(int tar){
    vector<edge>tem;
    for(auto it:g){
        if(it.second.first>=tar){
            tem.push_back({it.first.first,it.first.second,it.second.second});
            //tem.push_back({it.first.second,it.first.first,it.second.second});
        }
    }
    sort(tem.begin(),tem.end());
    int re=dmst(tem,0);
    if(re!=-1 && re<=k )return true;
    return false;
}

void solve()
{
   scanf("%d%d%d",&n,&m,&k);
   g.clear();
   int bo=0;
   for(int i=1;i<=m;i++)
   {
     int x,y,b,w;
     scanf("%d%d%d%d",&x,&y,&b,&w);
     g.push_back({{x,y},{b,w}});
     bo=max(bo,b);
   }
   int be=1,en=bo;
   int re=0;
   while(be<=en){
    int mid=(be+en)/2;
    if(func(mid)){
        re=mid;
        be=mid+1;
    }
    else en=mid-1;
   }
   if(re)
   printf("Case %d: %d kbps\n",++ii,re );
   else printf("Case %d: impossible\n",++ii );
    
}

int main()
{
  int t=1;
  scanf("%d",&t);
  while(t--)
  {
    solve();
  }

  return 0;
}
