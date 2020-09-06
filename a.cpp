#include<bits/stdc++.h>
using namespace std;


#define mx 100005
#define ll long long 

void IO()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  #endif
}


int ar[mx];
char ch[mx];
int m,n,k,ii;

void solve()
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++)scanf("%d",&ar[i]);
    reverse(ar+1,ar+1+n);
  for(int i=1;i<=n;i++)printf("%d ",ar[i] );
    printf("\n");
}

int main()
{
   IO();
  int t=1;
  scanf("%d",&t);
  while(t--)
  {
    solve();
  }
  return 0;
}