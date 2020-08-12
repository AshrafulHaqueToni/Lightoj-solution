#include<bits/stdc++.h>
using namespace std;
 
#define mx 1000005

void IO()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
}
 
int ii,n,q;
pair<int,int>ar[mx];
set<int>s;
map<int,int>mp;
int prefix[mx];

void solve()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&ar[i].first,&ar[i].second);
        s.insert(ar[i].first);
        s.insert(ar[i].second+1);
    }
    int cnt=1;
    for(int it:s)
    {
        mp[it]=cnt;
        cnt++;
    }
    for(int i=1;i<=n;i++)
    {
        prefix[mp[ar[i].first]]++;
        prefix[mp[ar[i].second+1]]--;
    }
    for(int i=1;i<cnt;i++)prefix[i]+=prefix[i-1];
    printf("Case %d:\n",++ii );
    while(q--)
    {
        int x;
        scanf("%d",&x);
        if(x<*s.begin() || *(--s.end())<x)
        {
            printf("0\n");
        }
        else
        {
            auto it=s.lower_bound(x);
            if(*it>x)it--;
            printf("%d\n",prefix[mp[*it]] );
        }
    }
    memset(prefix,0,sizeof(prefix));
    s.clear();
    mp.clear();

}

 
int main()
{
    IO();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
    
 
    return 0;
}
