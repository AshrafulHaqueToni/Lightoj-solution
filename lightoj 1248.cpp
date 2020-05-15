#include<bits/stdc++.h>
using namespace std;

#define ll long double
#define mx 100005


void solve(int ii)
{
    int n;
    scanf("%d",&n);
    ll re=0;
    for(ll i=1;i<=n;i++)
    {
        re+=n/i;
    }
    printf("Case %d: %0.8LF\n",ii,re);
}

int main()
{

    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}

