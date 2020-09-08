#include<bits/stdc++.h>
using namespace std;

#define mx 105
#define ll long long 

int par[mx];
char ch[mx];
vector<pair<int,pair<int,int>>>g;

int m,n,k,ii;

int parent(int u)
{
  return ((u==par[u])?u : (par[u]=parent(par[u])));
}


int kruskal()
{
  int re=0;
  m=g.size();
  for(int i=0;i<m;i++)
  {
    int u=g[i].second.first;
    int v=g[i].second.second;
    int w=g[i].first;
    if(parent(u)!=parent(v))
    {
      par[parent(u)]=par[parent(v)];
      //cout<<w<<endl;
      re+=w;
    }
  }
  return re;
}


void solve()
{
   scanf("%d",&n);
   while(1)
   {
     int x,y,w;
     scanf("%d%d%d",&x,&y,&w);
     if(x==0 && y==0 && w==0)break;
     g.push_back({w,{x,y}});
   }
   for(int i=0;i<=n;i++)par[i]=i;
   sort(g.begin(),g.end());
   int choto=kruskal();
  // cout<<choto<<endl;
   for(int i=0;i<=n;i++)par[i]=i;
    sort(g.rbegin(),g.rend());
    int boro=kruskal();
   // cout<<boro<<endl;
    int gc=__gcd(choto+boro,2);
    if(gc==2)printf("Case %d: %d\n",++ii,(boro+choto)/2 );
    else printf("Case %d: %d/%d\n",++ii,boro+choto,2 );
    g.clear();
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  #endif

  int t=1;
  scanf("%d",&t);
  while(t--)
  {
    solve();
  }
  return 0;
}
