// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 1000005
#define ll long long
#define mod 1000000000
 
int ar[mx];
char ch[mx];
int n,m,ii,k;

ll bigmod(ll e,ll x)
{
    if(!x)return 1;
    ll p=bigmod(e,x/2);
    p=(p*p)%mod;
    if(x%2)p=(p*e)%mod;
    return p;
}

void solve()
{
    scanf("%d%d%d",&n,&m,&k);
    vector<pair<int,int>>v;
    int b;
    scanf("%d",&b);
    for(int i=0;i<b;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v.push_back({y,x});
    }
    ll re=1;
    sort(v.begin(),v.end());
    int x=0,y=0;
    int baki=m;
    for(auto it:v)
    {
        int xx=it.second;
        int yy=it.first;
        if(yy==y)
        {
            int gap=xx-x-1;
            if(gap>=1)
            {
                re=(re*k)%mod;
                gap--;
                if(gap)
                {
                    re=(re*bigmod((k-1),gap)%mod);
                }
            }
            x=xx;
        }
        else
        {
            if(x>0 && x!=n)
            {
               // cout<<x<<" "<<y<<endl;
                int gap=n-x;
                if(gap>=1)
                {
                    re=(re*k)%mod;
                    gap--;
                    if(gap)
                    {
                        re=(re*bigmod((k-1),gap)%mod);
                    }
                }
            }
            int gap=xx-1;
            if(gap>=1)
            {
                re=(re*k)%mod;
                gap--;
                if(gap)
                {
                    re=(re*bigmod((k-1),gap)%mod);
                }
            }
            y=yy;
            x=xx;
            baki--;
        }
    }
    if(x>0 && x!=n)
    {
        int gap=n-x;
        if(gap>=1)
        {
           // cout<<x<<" "<<y<<endl;
            re=(re*k)%mod;
            gap--;
            if(gap)
            {
                re=(re*bigmod((k-1),gap)%mod);
            }
        }
    }
   // cout<<re<<endl;
    if(baki)
    {
        ll ex=k;
        int gap=n-1;
        if(gap)
        {
            ex=(ex*bigmod((k-1),gap)%mod);
        }
      //  cout<<ex<<endl;
        re=(re*bigmod(ex,baki)%mod);
    }

    printf("Case %d: %lld\n",++ii,re );

}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
