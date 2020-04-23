#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1005
int n,m;
int ar[mx];
char ch[mx];

int func(int tar)
{
    int need=0,sum=0;
    for(int i=0;i<n;i++)
    {
        if(sum+ar[i]>tar)
        {
            need++;
            sum=ar[i];
        }
        else sum+=ar[i];
    }

    return need+1;
}
void solve(int ii)
{
   scanf("%d%d",&n,&m);
   int lo=0,high=0;
   for(int i=0;i<n;i++)
   {
       scanf("%d",&ar[i]);
       lo=max(ar[i],lo);
       high+=ar[i];
   }
   int ans;
   while(lo<=high)
   {
       int mid=(lo+high)/2;
       if(func(mid)<=m)
       {
           ans=mid;
           high=mid-1;
       }
       else lo=mid+1;
   }
   printf("Case %d: %d\n",ii,ans);
}
int main()
{
    int t=1;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
