#include<bits/stdc++.h>
using namespace std;

#define mx 1000005
#define ll long long

bitset<mx>chk;
vector<int>prime;
int mobius[mx];

void seive(int n)
{
    for(int i=3;i*i<=n;i+=2)
    {
        if(!chk[i])
        {
            for(int j=i*i;j<=n;j+=2*i)
            {
                chk[j]=true;
            }
        }
    }
    prime.push_back(2);
    for(int i=3;i<=n;i+=2)if(!chk[i])prime.push_back(i);

    for(int i=1;i<=n;i++)mobius[i]=1;
    int sz=prime.size();

    for(int i=0;i<sz && prime[i]*prime[i]<=n;i++)
    {
        int val=prime[i];
         val=val*val;
        for(int j=val;j<=n;j+=val)mobius[j]=0;

    }
    for(int i=0;i<sz;i++)
    {
        int val=prime[i];
        for(int j=val;j<=n;j+=val)mobius[j]*=-1;
    }

}

int n,m,k,ii;

void solve()
{
   scanf("%d%d",&n,&m);
   if(n>m)swap(n,m);
   ll re=0;
   for(int i=1;i<=n;i++)
   {
       re+=mobius[i]*(ll)(n/i)*(m/i);
   }
   if(n)re++;
   if(m)re++;
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
