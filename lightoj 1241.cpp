#include<bits/stdc++.h>
using namespace std;

void solve(int ii)
{
    int n;
    scanf("%d",&n);
    int ar[n+5];
    for(int i=0;i<n;i++)scanf("%d",&ar[i]);

    int re=0,last=2;
    for(int i=0;i<n;i++)
    {
       int diff=ar[i]-last;
       if(diff)
       {
           int cnt=ceil((double)diff/5.0);
           if(cnt==0)re++;
           else re+=cnt;
           last=ar[i];
       }
    }
    printf("Case %d: %d\n",ii,re);
}

int  main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);

    return 0;
}
