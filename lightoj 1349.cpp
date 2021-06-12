// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 50005
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,q,k;
struct point
{
   int x,y,z;
};
point p[mx];
 
void solve()
{
   scanf("%d%d%d",&n,&m,&q);
   ll tot=0;
   for(int i=1;i<=q;i++)
   {
      scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
      tot+=p[i].z;
   }
   tot=(tot+1)/2;
   int x,y;
   sort(p+1,p+1+q,[&](point a,point b){
      return a.x<b.x;
   });
   ll ini=0;
   for(int i=1;i<=q;i++)
   {
      if(ini+p[i].z>=tot)
      {
         x=p[i].x;
         break;
      }
      ini+=p[i].z;
   }
    sort(p+1,p+1+q,[&](point a,point b){
      return a.y<b.y;
   });
   ini=0;
   for(int i=1;i<=q;i++)
   {
      if(ini+p[i].z>=tot)
      {
         y=p[i].y;
         break;
      }
      ini+=p[i].z;
   }


   printf("Case %d: %d %d\n",++ii,x,y );

}
 
int main()
{
   int t=1;
   scanf("%d",&t);
   while(t--)solve();
   return 0;
}
