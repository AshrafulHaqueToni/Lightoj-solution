// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 50005
#define ll long long
#define mod 1000000007 //998244353
 
int ar[mx];
vector<int>g[mx];
int Dist[mx];
int n,m,ii,k;
 
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=50000;i++){
        Dist[i]=mx;
        g[i].clear();
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&ar[i]);
        if(i>1){
            g[ar[i-1]].push_back(ar[i]);
            g[ar[i]].push_back(ar[i-1]);
        }
    }
    for(int i=1;i<=50000;i++)sort(g[i].begin(),g[i].end());

    queue<int>q;
    q.push(ar[n]);
    Dist[ar[n]]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:g[u]){
            if(Dist[v]>Dist[u]+1){
                Dist[v]=Dist[u]+1;
                q.push(v);
            }
        }
    }

    
    printf("Case %d:\n",++ii );

    int v=ar[1];

    //int cnt=0;

    while(v!=ar[n]){
        printf("%d ",v);
        for(int u:g[v]){
           // cout<<Dist[u]<<endl;
            if(Dist[u]+1==Dist[v]){
                v=u;
                break;
            }
        }
       // cnt++;
       // if(cnt>10)break;
    }

    printf("%d\n",v );


 
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
