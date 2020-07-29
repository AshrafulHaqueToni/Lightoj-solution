#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long

int ar[mx];
char ch[mx];

int n,m,k,ii;

void solve()
{
    scanf("%d%d",&n,&m);
    int val=0;
    if((n+m)%2==0)val=1;
    int re=0;
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=m;j++)
        {
            scanf("%d",&k);
            if((i+j)%2==1 && val==1) re^=k;
            if((i+j)%2==0 && val==0) re^=k;
        }
    }
    if(re)printf("Case %d: win\n",++ii);
    else printf("Case %d: lose\n",++ii);
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
