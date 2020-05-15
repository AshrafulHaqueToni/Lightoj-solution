#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
#define mod 100000007

int ar[mx];
char ch[mx];

int n,m;
vector<ll>opt;
bool chk[mx];
ll fact[mx];

ll bigmod(ll e,ll x)
{
    if(!x)return 1;
    ll p=bigmod(e,x/2);
    p=(p*p)%mod;
    if(x%2)p=(p*e)%mod;
    return p;
}

void pow_cnt()
{
    for(int i=2;i<=100000;i++)
    {
        if(chk[i])continue;
        ll val=1LL*i*i;
        while(val<=10000000000)
        {
            if(val<=100000)chk[val]=true;
            opt.push_back(val);
            val*=i;
        }
    }
    opt.push_back(100000000000);
    sort(opt.begin(),opt.end());
}

void fact_cal()
{
    fact[0]=1;
    for(int i=1;i<=100000;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
}

void solve(int ii)
{
   ll a,b;
   scanf("%lld%lld",&a,&b);
   int r= upper_bound(opt.begin(),opt.end(),b)-opt.begin();
   int l=lower_bound(opt.begin(),opt.end(),a)-opt.begin();
   int diff=r-l;
   if(diff==0)
   {
       printf("Case %d: 0\n",ii);
       return;
   }
   ll ans=fact[2*diff]*bigmod((fact[diff]*fact[diff+1])%mod,mod-2);
   ans%=mod;
   printf("Case %d: %lld\n",ii,ans);
}

int main()
{
    pow_cnt();
    fact_cal();
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
