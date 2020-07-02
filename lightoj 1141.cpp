#include<bits/stdc++.h>
using namespace std;

#define mx 1005
#define ll long long

int ar[mx];
char ch[mx];
vector<int>fact[mx];
int spf[mx],dist[mx];
int n,m,k,ii;

void seive()
{
    for(int i=2;i<=mx-5;i++)spf[i]=i;
    for(int i=2;i*i<=mx-5;i++)
    {
        if(spf[i]==i)
        {
            for(int j=i*i;j<=mx-5;j+=i)
            {
                if(spf[j]==j)spf[j]=i;
            }
        }
    }
    for(int i=2;i<=mx-5;i++)
    {
        int val=i;
        while(val>1)
        {
            int sp=spf[val];
            while(val%sp==0)val/=sp;
            if(sp!=i)fact[i].push_back(sp);
        }
    }
//    for(int i=2;i<=100;i++)
//    {
//        cout<<i<<" :";
//        for(auto it:fact[i])cout<<it<<" ";
//        cout<<endl;
//    }
}

void bfs(int st)
{
    queue<int>q;
    q.push(st);
    dist[st]=0;
    while(!q.empty())
    {
        int u=q.front();
       // cout<<u<<endl;
        q.pop();
        for(auto it:fact[u])
        {
            if(it+u>m)continue;
            int val=it+u;
            if(dist[val]!=-1 && dist[val]<=dist[u]+1)continue;
            dist[val]=dist[u]+1;
            q.push(val);
        }
    }
}

void solve()
{
    scanf("%d%d",&n,&m);
    printf("Case %d: ",++ii);
    if(n==m)
    {
        printf("0\n");
        return;
    }
    if(n==1 || n>m)
    {
        printf("-1\n");
        return;
    }
    memset(dist,-1,sizeof(dist));
    bfs(n);
    printf("%d\n",dist[m]);
}

int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t=1;
   seive();
   scanf("%d",&t);
   while(t--)solve();
   return 0;
}
