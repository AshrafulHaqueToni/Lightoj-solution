// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 105
#define ll long long
int n,m,ii,k;
int ar[mx];
int take[mx];

struct BPM
{
    bool Done[mx];
    vector<int>g[mx];
    int macth[mx];

    void addEdge(int u,int v)
    {
        g[u].push_back(v);
    }

    void init()
    {
        for(int i=0;i<mx;i++)g[i].clear();
    }

    bool Tem_Matching(int u)
    {
        for(int i=0;i<(int)g[u].size();i++)
        {
            int v=g[u][i];
            if(Done[v] || take[v]) continue;
            Done[v] = true;
            if(macth[v]==-1 || Tem_Matching(macth[v]))
            {
                macth[v] = u;
                return true;
            }
        }
        return false;
    }
    int Max_Matching(int num)
    {
    // Be Careful with this section. when passin num.
        memset(macth,-1,sizeof(macth));
        int re = 0;
        for(int i=1;i<=num;i++)
        {
            if(take[i])continue;
            memset(Done,false,sizeof(Done));
            if(Tem_Matching(i)) re++;
            
        }
        return re;
    }
 
 
};

BPM bp;
 
void solve()
{
    scanf("%d",&n);
    bp.init();
    for(int i=1;i<=n;i++)scanf("%d",&ar[i]);
    sort(ar+1,ar+n+1);
    vector<int>val;
    for(int i=1;i<=n;i++)
    {
        if(ar[i]!=ar[i-1])val.push_back(ar[i]);
        take[i]=0;
    }
    n=val.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(val[j]%val[i]==0)bp.addEdge(i+1,j+1);
        }
    }
    int tot=n-bp.Max_Matching(n);
    vector<int>ans;
    int already_go_on_hell=0;

    for(int i=0;i<n;i++)
    {
        if(take[i+1])continue;
        int temporary_go_on_hell=0;
        for(int j=i+1;j<n;j++)
        {
            if(take[j+1])continue;
            if(val[j]%val[i]==0)
            {
                take[j+1]=1;
                temporary_go_on_hell++;
            }
        }
        int pres=n-already_go_on_hell-temporary_go_on_hell-bp.Max_Matching(n);
        int current_situation=0;
        //cout<<pres<<endl;
        if(pres==tot)
        {
            ans.push_back(val[i]);
            current_situation=2;
            already_go_on_hell+=temporary_go_on_hell;
        }
        for(int j=i+1;j<n;j++)
        {
            if(take[j+1]==1)take[j+1]=current_situation;
        }
    }
    int sz=ans.size();
    printf("Case %d: ",++ii);
    for(int i=0;i<sz-1;i++)printf("%d ",ans[i] );
    printf("%d\n",ans.back() );
    
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
