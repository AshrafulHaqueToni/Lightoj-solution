// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 200005
#define ll long long
#define mod 1000000007 //998244353

char ch[mx];
bool vis[400];
int n,m,ii,k;
map<string,int>idx;
map<int,string>name;
vector<int>g[400];
int in[400];

void solve()
{
    scanf("%d",&n);
    idx.clear();
    name.clear();
    int id=0;
    for(int i=1;i<n;i++){
        scanf("%s",ch);
        string s=ch;
        if(!idx.count(s))idx[s]=++id,name[id]=s;
        int u=idx[s];
        scanf("%s",ch);
        s=ch;
        if(!idx.count(s))idx[s]=++id,name[id]=s;
        int v=idx[s];
        g[u].push_back(v);
        in[v]++;

    }
    int root=1;
    for(int i=1;i<=id;i++){
        if(in[i]==0)root=i;
    }
    printf("Case %d:\n",++ii);
    while(!vis[root]){
        cout<<name[root]<<"\n";
        vis[root]=1;
        if(!g[root].empty())root=g[root][0];
    }
    printf("\n");
    for(int i=1;i<=id;i++){
        g[i].clear();
        vis[i]=0;
        in[i]=0;
    }

 
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
