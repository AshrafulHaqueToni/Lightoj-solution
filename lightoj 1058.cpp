#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#define mx 100005
#define ll long long
#define mod 1000000007

int ar[mx],br[mx];
char ch[mx];

int n,m,ii;
vector<pair<int,int>>mp;
void solve()
{
    scanf("%d",&n);
    mp.clear();
    for(int j=0; j<n; j++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ar[j]=x;
        br[j]=y;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int x,y;
            x=ar[i]+ar[j];
            y=br[i]+br[j];
            mp.push_back({x,y});
        }
    }
    sort(mp.begin(),mp.end());
    ll re=0;
    int sz=mp.size();
    ll cnt=1;
    for(int i=1;i<sz;i++)
    {
        if(mp[i]==mp[i-1])cnt++;
        else re+=(cnt*(cnt-1))/2,cnt=1;
    }
    re+=(cnt*(cnt-1))/2;
    printf("Case %d: %lld\n",++ii,re);
}

int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}

