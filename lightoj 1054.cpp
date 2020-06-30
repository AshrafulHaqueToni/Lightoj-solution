#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx];
vector<int>prime;
bool f[mx];
int n,m,k,ii;

ll bigmod(ll e,ll x)
{
    if(!x)return 1;
    ll p=bigmod(e,x/2);
    p=(p*p)%mod;
    if(x%2)p=(p*e)%mod;
    return p;
}

void seive()
{
    for(int i=2;i<=100005;i++)
    {
        if(f[i]==false)
        {
            prime.push_back(i);
            for(ll j=1LL*i*i;j<=(ll)100005;j+=i)
            {
                f[j]=true;
            }
        }
    }
}

void solve()
{
    scanf("%d%d",&n,&m);
    if(n==mod)
    {
        printf("Case %d: 1\n",++ii);
        return;
    }
     vector<pair<int,int>>tem;
     int sz=prime.size();
    for(int i=0;i<sz && (ll)prime[i]*prime[i]<=(ll)n;i++)
    {
        if(n%prime[i]==0)
        {
            int cnt=0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                cnt++;
            }
            tem.push_back({prime[i],cnt});
        }
    }
    if(n>1)tem.push_back({n,1});
    ll re=1;
    for(auto it:tem)
    {
      //  cout<<it.first<<" "<<it.second<<endl;
        ll p=it.first;
        ll e=(ll)it.second*m+1;
       // cout<<p<<" "<<e<<endl;
        ll x=(bigmod(p,e)-1+mod)%mod;
        ll y=bigmod(p-1,mod-2);
        x=(x*y)%mod;
       // cout<<x<<endl;
        re=(re*x)%mod;
       // cout<<re<<endl;
    }
    printf("Case %d: %lld\n",++ii,re);

}
/*
1
22 4
*/

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
