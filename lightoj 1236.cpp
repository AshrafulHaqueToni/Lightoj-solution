#include<bits/stdc++.h>
using namespace std;

#define mx 10000005
#define ll long long

bitset<mx>chk;
vector<int>prime;

void seive(int n)
{
    for(int i=3;i*i<=n;i++)
    {
        if(!chk[i])
        {
            for(int j=i*i;j<=n;j+=i*2)
            {
                chk[j]=1;
            }
        }
    }
    prime.push_back(2);
    for(int i=3;i<=n;i+=2)if(!chk[i])prime.push_back(i);
}

int n,m,k,ii;

void solve()
{
    ll val;
    scanf("%lld",&val);
    ll re=1;
    int sz=prime.size();
    for(int i=0;i<sz && prime[i]*(ll)prime[i]<=val;i++)
    {
        if(val%prime[i]==0)
        {
            int cnt=0;
            while(val%prime[i]==0)
            {
                val/=prime[i];
                cnt++;
            }
            re*=(2*cnt+1);
        }
    }
    if(val>1)re*=3;
    re++;
    printf("Case %d: %lld\n",++ii,re/2);
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
