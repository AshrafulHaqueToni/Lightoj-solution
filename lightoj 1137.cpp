// Created by ash_98
 ///http://shoshikkha.com/archives/4816     
#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long double
#define mod 1000000007

int ar[mx];
char ch[mx];
int n,m,k,ii;
ll l,deg,so,exl;

bool func(ll b)
{
  // L'=S=((c*c)/2b+b/2)*(2sin^-1(c/((c*c)/2b+b/2)));
   ll c=l/2.0;
   ll r=(c*c)/(2*b)+(b/2);
   ll s=r*(2*asin(c/r));
   return exl<=s;

}

void solve()
{
   
   cin>>l>>deg>>so;
   exl=(1+deg*so)*l;
   ll be=0,en=exl;
   int magic=100;
   while(magic--)
   {
      ll mid=(be+en)/2;
      if(func(mid))
      {
        en=mid;
      }
      else be=mid;

   }
   printf("Case %d: %0.12LF\n",++ii,be );
    
}

int main()
{
  int t=1;
  scanf("%d",&t);
  while(t--)
  {
    solve();
  }

  return 0;
}
