#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define mod 10000019
bool is_composite[mx];
vector<int>prime;



void seive(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!is_composite[i])
        {
            prime.push_back(i);
        }

        for(int j=0;j<prime.size() && i*prime[j]<=n;j++)
        {
            is_composite[i*prime[j]]=true;

            if(i%prime[j]==0)
            {

                break;
            }

        }
    }
}

ll bigmod(ll e,ll x)
{
    if(!x)return 1;
    ll p=bigmod(e,x/2);
    p=(p*p)%mod;
    if(x%2)p=(p*e)%mod;
    return p;
}

int n,m,k,ii;

void solve()
{
    int t;
    scanf("%d%d",&n,&t);
    ll re=1;
    bool f=true;
    int sz=prime.size();
    for(int i=0;i<sz && prime[i]<=n;i++)
    {
        int val=n;
        int cnt=0;
        while(val>1)
        {
            cnt+=val/prime[i];
            val/=prime[i];
        }
        cnt/=t;
        if(cnt)f=false;
        re=(re*bigmod(prime[i],cnt))%mod;
    }
    if(f)re=-1;
    printf("Case %d: %lld\n",++ii,re);


}

int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t=1;
   seive(mx-5);
   scanf("%d",&t);
   while(t--)solve();
   return 0;
}
