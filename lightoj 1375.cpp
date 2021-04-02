#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define mx 3000005

bool is_composite[mx];
vector<int>prime;
int phi[mx],ii;
ll csum[mx];

void seive(int n)
{
    phi[1]=1;

    for(int i=2;i<=n;i++)
    {
        if(!is_composite[i])
        {
            prime.push_back(i);
            phi[i]=i-1;              ///i is prime
        }

        for(int j=0;j<prime.size() && i*prime[j]<=n;j++)
        {
            is_composite[i*prime[j]]=true;

            if(i%prime[j]==0)
            {
                phi[i*prime[j]]=phi[i]*prime[j];   ///prime[j] divides i
                break;
            }
            else
            {
                phi[i*prime[j]]=phi[i]*phi[prime[j]];  ///prime[j] do not divide i
            }
        }
    }
    for(ll i=2;i<=n;i++)
    {
    	for(int j=i;j<=n;j+=i)csum[j]+=(ll)j*phi[i]/2*i;
    }
    for(int i=1;i<=n;i++)csum[i]+=csum[i-1];
 
}

void solve()
{
   int n;
   scanf("%d",&n);
   printf("Case %d: %llu\n",++ii,csum[n]);
}

int main()
{
   int t=1;
   seive(mx-5);
   scanf("%d",&t);
   while(t--)solve();
   return 0;
}
