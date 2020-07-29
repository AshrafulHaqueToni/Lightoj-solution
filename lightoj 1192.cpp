#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long

int ar[mx];
char ch[mx];

int n,m,k,ii;

void solve()
{
    scanf("%d",&k);
    int re=0;
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d",&n,&m);
        re^=(m-n-1);
    }
    if(re)printf("Case %d: Alice\n",++ii);
    else printf("Case %d: Bob\n",++ii);
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
