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
   for(int i=1;i<=n;i++)scanf("%d",&ar[i]);
   int re=0;
   for(int i=1;i<=n;i++)
   {
       scanf("%d",&m);
       re^=(m-ar[i]-1);
   }
   printf("Case %d: ",++ii);
   if(re)printf("white wins\n");
   else printf("black wins\n");
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
