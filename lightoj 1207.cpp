#include<bits/stdc++.h>
using namespace std;

void solve(int ii)
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int ar[n+5];
    for(int i=0;i<n;i++)scanf("%d",&ar[i]);
    sort(ar,ar+n);
    int re=0;
    for(int i=0;i<min(n,m);i++)
    {
        if(k>=ar[i])
        {
            re++;
            k-=ar[i];
        }
        else break;
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
