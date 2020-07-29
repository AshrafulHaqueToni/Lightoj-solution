#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long

int ar[mx];
char ch[mx];

int n,m,k,ii;

void solve()
{
    scanf("%d",&n);
    int re=0;
    int one=0;
    for(int i=1;i<=n;i++)
    {

        scanf("%d",&k);
        re^=k;
        if(k==1)one++;
    }
    if(one==n)
    {
        if(n&1)re=0;
        else re=1;
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
