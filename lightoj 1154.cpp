// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 205
#define ll long long
#define INF 1000005

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

int ar[mx],br[mx];
int n,m,ii,k;

struct point
{
     int x,y;
     int num,capa;
};

struct Temedge
{
     int x,y;
     ll w;
};
 
void solve()
{
     long double Li;
     scanf("%d%LF",&n,&Li);
     Li*=Li;
     
     vector<point>v;
     ll tot=0;
     for(int i=1;i<=n;i++)
     {
          int x,y,num,capa;
          scanf("%d%d%d%d",&x,&y,&num,&capa);
          v.push_back({x,y,num,capa});
          tot+=num;
          ar[i-1]=num;
          br[i-1]=capa;

     }


     vector<Temedge>tem;

     for(int i=1;i<n;i++)
     {
          for(int j=i+1;j<=n;j++)
          {
               long double xx=abs(v[i-1].x-v[j-1].x);
               long double yy=abs(v[i-1].y-v[j-1].y);
               long double need=(xx*xx)+(yy*yy);
               if(need<=Li)
               {
                   tem.push_back({i+n,j,INF});
                   tem.push_back({j+n,i,INF});
               }
          }
     }

     vector<int>re;


     for(int i=0;i<n;i++)
     {
         dc.init();
         for(Temedge a:tem)dc.addEdge(a.x,a.y,a.w);
         for(int j=0;j<n;j++)
         {
           dc.addEdge(0,j+1,ar[j]);
           dc.addEdge(j+1,j+1+n,br[j]);
         }
         dc.s=0;
         dc.t=i+1;
       //  cout<<dc.dinic()<<" "<<tot-ar[i]<<endl;
         if(dc.dinic()==tot)
         {
            re.push_back(i);
           // cout<<"aci\n";
         }
     }
     

     printf("Case %d:",++ii);
     if(re.empty())printf(" -1\n");
     else
     {
          for(int a:re)printf(" %d",a );
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
