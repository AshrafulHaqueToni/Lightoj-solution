#include<bits/stdc++.h>
using namespace std;

#define mx 1000005
#define ll long long

int ar[mx];
char ch[mx];
vector<int>prime;
bool vis[mx];

void seive(int n)
{
    for(int i=3;i*i<=n;i++)
    {
        if(!vis[i])
        {
            for(int j=i*i;j<=n;j+=i+i)
            {
                vis[j]=true;
            }
        }
    }
    prime.push_back(2);
    for(int i=3;i<=n;i+=2)if(!vis[i])prime.push_back(i);
}

int m,k,ii;

void solve()
{
    ll n;
    scanf("%lld",&n);
    ll re=1;
    int sz=prime.size();

    for(int i=0;i<sz && prime[i]*(ll)prime[i]<=n;i++)
    {
  
        if(n%prime[i]==0)
        {
            int cnt=1;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                cnt++;
            }
        
            re*=cnt;
        }
    }
    if(n>1)re*=2;
    printf("Case %d: %lld\n",++ii,re-1);

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
