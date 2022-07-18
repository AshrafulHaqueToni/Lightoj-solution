// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 105
#define ll long long
#define mod 1000000007 //998244353
 
int ar[mx];
vector<pair<int,int>>g[mx];
int n,m,ii,k;

pair<int,int>func(int u,int p){
    int re=0;
    int total=0;
    vector<int>candi;
    for(auto[v,w]:g[u]){
        if(v==p)continue;
        pair<int,int>a=func(v,u);
        re+=a.first;
        total+=a.second+w;
        candi.emplace_back(a.second+w);
    }
    sort(candi.begin(),candi.end());
    while(total>k){
        re++;
        total-=candi.back();
        candi.pop_back();
    }
    return {re,total};
}
 
void solve()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    printf("Case %d: %d\n",++ii,1+func(1,-1).first);
    for(int i=1;i<=n;i++)g[i].clear();
 
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
