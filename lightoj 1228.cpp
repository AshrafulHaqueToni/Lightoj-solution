// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 13
#define ll long long
#define mod 1000000007 //998244353
 
int ar[mx];
int rival[mx][mx];
ll dp[1<<12][mx][mx];
int vis[1<<12][mx][mx];
int n,m,ii,k,tc;

ll Set(ll N,int pos)
{
    return N=N|(1LL<<pos);
}

ll Reset(ll N,int pos)
{
    return N=N & ~(1LL<<pos);
}

bool chk(ll N,int pos)
{
    return (bool)(N &(1LL<<pos));
}

ll func(int mask,int last,int hand){
    if(hand<0)return 0;
    if(mask==(1<<n)-1)return 1;
    if(vis[mask][last][hand]==ii)return dp[mask][last][hand];
    vis[mask][last][hand]=ii;
    ll re=0;
    for(int i=1;i<=n;i++){
        if(chk(mask,i-1))continue;
        re+=func(Set(mask,i-1),i,hand-rival[last][i]);
    }
    return dp[mask][last][hand]=re;
}
 
void solve()
{
    memset(rival,0,sizeof(rival));
    int q;
    scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&m);
        for(int j=1;j<=m;j++){
            int x;
            scanf("%d",&x);
            rival[x][i]=1;
        }
    }
    ii++;
    printf("Case %d:\n",++tc);
    while(q--){
        int li;
        scanf("%d",&li);
        if(k==0){
            printf("%lld\n",func(0,0,n));
        }
        else{
            printf("%lld\n",func(0,0,min(n,li/k)));
        }
    }
 
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
