#include<bits/stdc++.h>
using namespace std;

#define mx 10000
#define ll long long

int cnt[mx+5];
ll ans[mx+5];
int n,m,k,ii;

void solve()
{
    memset(cnt,0,sizeof(cnt));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }

    for(int i=mx;i>=1;i--)
    {
        int tot=0;
        for(int j=i;j<=mx;j+=i)
        {
            tot+=cnt[j];
            ans[i]-=ans[j];
        }
        if(tot<4)ans[i]=0;
        else
        {
            ll val=tot*(ll)(tot-1)*(tot-2)*(tot-3);
            val/=24;
            ans[i]+=val;

        }
    }
    printf("Case %d: %lld\n",++ii,ans[1]);

}

int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t=1;
   scanf("%d",&t);
   while(t--)solve();
   return 0;
}
