// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 1005
#define ll long long
#define mod 1000000007 //998244353
 
int ar[mx][2];
int dp[30][mx];
int vis[30][mx];
int take[mx];
int ans[30];

int n,m,ii,k;

int nxt[30];

int func(int cur,int how)
{
    if(cur>n)return 0;
    if(how<=0)return 0;

    if(vis[cur][how]==ii)return dp[cur][how];
    vis[cur][how]=ii;

    int re=0;
    int need=take[cur]*5;

    if(need<=how)re=max(re,func(cur+1,how-need));

   // nxt[cur]=0;

    int have=ar[cur][0];
    int dec=ar[cur][1];

    int tot=0;
    int available=how;

    for(int i=1;i<=how/5;i++)
    {
        tot+=have;
        available-=5;

        int val=tot;
        if(need<=available)val+=func(cur+1,available-need);
       // if(val>=re)nxt[cur]=i;
        re=max(re,val);
        have=max(0,have-dec);
    }
    return dp[cur][how]=re;
}
 
void solve()
{
    scanf("%d%d",&n,&m);
    m*=60;

    for(int i=1;i<=n;i++)scanf("%d",&ar[i][0]),ans[i]=0;
    for(int i=1;i<=n;i++)scanf("%d",&ar[i][1]);

    for(int i=1;i<n;i++)scanf("%d",&take[i]);
    take[n]=0;
   // cout<<n<<endl;

    ii++;

    int re=func(1,m);

    int id=1;
    int cur=re;
    //cout<<n<<endl;
    //for(int i=1;i<=n;i++)cout<<nxt[i]<<" ";
  // cout<<endl;
    while(m>0 and id<=n)
    {
        int got=0;
        int need=take[id]*5;
        int tmp=func(id+1,m-need);

        int have=ar[id][0];
        int dec=ar[id][1];

        int tot=0;
        int available=m;

        for(int i=1;i<=m/5;i++)
        {
            tot+=have;
            available-=5;

            int val=tot;
            if(need<=available)val+=func(id+1,available-need);
           
            if(tmp<=val)
            {
                tmp=val;
                got=i;
            }
            have=max(0,have-dec);
        }
        m-=got*5;
        m-=need;
        ans[id]=got*5;
        id++;
    }
   // cout<<n<<endl;
    printf("Case %d:\n",ii );
    //cout<<n<<endl;
    printf("%d",ans[1]);
    for(int i=2;i<=n;i++)printf(", %d",ans[i]);
    printf("\n");
    printf("Number of fish expected: %d\n",re);

 
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
