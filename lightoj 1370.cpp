#include<bits/stdc++.h>
using namespace std;

#define mx 1000005
#define ll long long

int phi[mx];
int cnt[mx],re[mx],z;

void seive(int n)
{
    for(int i=0; i<=n; i++) phi[i]=i;
    phi[2]=1;
    for(int i=4;i<=n;i+=2)phi[i]>>=1;
    for(int i=3; i<=n; i+=2) {
        if(phi[i]==i) {
            phi[i]--;
            for(int j=2*i; j<=n; j+=i)
                phi[j]-=(phi[j]/i);
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(cnt[phi[i]]==0)cnt[phi[i]]=i;
    }
    int val=n;
    for(int i=n;i>=1;i--)
    {
        if(cnt[i]!=0)val=min(val,cnt[i]);
        re[i]=val;
    }

}


int n,m,k,ii;

void solve()
{
   scanf("%d",&n);
   ll ans=0;
   for(int i=1;i<=n;i++)
   {
       int x;
       scanf("%d",&x);
       ans+=re[x];
   }
   printf("Case %d: %lld Xukha\n",++ii,ans);
}

int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t=1;
   seive(mx-2);
   scanf("%d",&t);
   while(t--)solve();
   return 0;
}
