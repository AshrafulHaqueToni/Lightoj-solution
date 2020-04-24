#include<bits/stdc++.h>
using namespace std;
#define mx 2005
int ar[mx];

void solve(int ii)
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&ar[i]);
    sort(ar,ar+n);
    int re=0;
    for(int i=n-1;i>=1;i--)
    {
       int l=0,r=i-1;
       while(l<r)
       {
           if(ar[l]+ar[r]>ar[i])
           {
               re+=r-l;
               r--;
           }
           else l++;
       }
    }
    printf("Case %d: %d\n",ii,re);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
