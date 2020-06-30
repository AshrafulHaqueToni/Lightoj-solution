#include<bits/stdc++.h>
using namespace std;

#define mx 1000005
#define ll long long

int ar[mx];
char ch[mx];


int n,m,k,ii;


void solve()
{
    ll a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    ll one=(a*b)/__gcd(a,b);
    if(c%one)
    {
        printf("Case %d: impossible\n",++ii);
        return;
    }
    ll another=1e18;
    /// lcm(one,x)=c
    /// (one*x)/__gcd(one,x)=c
    /// x=(c/one)*__gcd(one,x)
    /// x will be divisors of one times (c/one)

   // cout<<one<<endl;
    ll val=c/one;
    for(ll i=1;i*i<=one;i++)
    {
         //  cout<<i<<endl;
         if(one%i==0)
         {
             ll tem=val*i;
            ll val1=__gcd(one,tem);
            if((tem*one)/val1==c)
            {
                another=min(another,tem);
            }
             tem=one/i;
            tem*=val;
              val1=__gcd(one,tem);
            if((tem*one)/val1==c)
            {
                another=min(another,tem);
            }
         }
    }
    printf("Case %d: %lld\n",++ii,another);
}
/*
1
1000000 1000000 2000000
*/
int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t=1;
   scanf("%d",&t);
   while(t--)solve();
   return 0;
}
