#include<bits/stdc++.h>
using namespace std;

#define mx 105
#define ll long long

int ar[mx];
char ch[mx];

int n,m,k,ii;

vector<int>g[mx];
int niye[mx],na_niye[mx];

void solve()
{
     scanf("%d%d",&n,&m);
     for(int i=1;i<=m;i++)
     {
         int u,v;
         scanf("%d%d",&u,&v);
         g[u].push_back(v);
         g[v].push_back(u);
     }
     memset(niye,0,sizeof(niye));
     memset(na_niye,0,sizeof(na_niye));
     int re=0;
     queue<int>q;
     q.push(1);
     while(!q.empty())
     {
         int x=q.front();
         q.pop();
         for(auto it:g[x])
         {
             if(na_niye[it]==0 && (x==1 || niye[x]==1))
             {
                 na_niye[it]=1;
                 q.push(it);
             }
             if(niye[it]==0 && na_niye[x]==1)
             {
                 niye[it]=1;
                // cout<<x<<" "<<it<<endl;
                 re++;
                 q.push(it);
             }
         }
     }
     printf("Case %d: %d\n",++ii,re);
     for(int i=1;i<=n;i++)g[i].clear();
}

int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t=1;
   scanf("%d",&t);
   while(t--)solve();
   return 0;
}
