#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 20

ll ar[mx],br[mx];
int n,m,ii;

struct GCD_type { ll x, y, d; };

GCD_type ex_GCD(ll a, ll b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}

ll normalize(ll val,ll mod)
{
    val%=mod;
    if(val<0)val+=mod;
    return val;
}

void solve()
{
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
      scanf("%lld%lld",&ar[i],&br[i]);
  }
  ll ans=br[1];
  ll lcm=ar[1];
  bool f=true;
  for(int i=2;i<=n;i++)
  {
      auto pom=ex_GCD(lcm,ar[i]);
      ll x1=pom.x;
      ll d=pom.d;
      if((br[i]-ans)%d!=0)
      {
          f=false;
          break;
      }
      ans=ans+x1*(br[i]-ans)/d%(ar[i]/d)*lcm;
      ans=normalize(ans,lcm*ar[i]/d);
      lcm=(lcm*ar[i])/__gcd(lcm,ar[i]);
  }

  printf("Case %d: ",++ii);
  if(f)printf("%lld\n",ans);
  else printf("Impossible\n");

}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}

