// Created by ash_98
     
#include<bits/stdc++.h>
using namespace std;
 
#define mx 100005
#define ll long long
#define mod 1000000007
 
struct st
{
  ll x,y;
};
int n,ii;
 
st ar[mx];
 
ll TriangleArea(const st &a, const st &b, const st &c)
{
  return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
}
 
bool pointInConvexPolygon(const st &point)
{
  int be=1,en=n-1;
  while(be+1<en)
  {
    int mid=(be+en)/2;
    if(TriangleArea(ar[0],ar[mid],point)>=0)be=mid;
    else en=mid;
  }
  if(TriangleArea(ar[0],ar[be],point)<0)return false;
  if(TriangleArea(ar[be],ar[en],point)<0)return false;
  if(TriangleArea(ar[en],ar[0],point)<0)return false;
  return true;
}
 
void solve()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
      scanf("%lld%lld",&ar[i].x,&ar[i].y);
    }
    printf("Case %d:\n",++ii );
    int q;
    scanf("%d",&q);
    while(q--)
    {
      st tem;
      scanf("%lld%lld",&tem.x,&tem.y);
      if(pointInConvexPolygon(tem))printf("y\n");
      else printf("n\n");
    }
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
