// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 200005
#define ll long long
#define mod 1000
 
int ar[mx];
char ch[mx];
int n,m,ii,k;


ll bigmod(ll e,ll x)
{
    if(!x)return 1;
    ll p=bigmod(e,x/2);
    p=(p*p)%mod;
    if(x%2)p=(p*e)%mod;
    return p;
}

void solve()
{
    scanf("%d%d",&n,&k);
    double val=(double)k*log10(n);
    val=val-(ll)val;
    val=pow(10,val);
    ll re=val*100;
    printf("Case %d: %3lld ",++ii,re );
    ll re1=bigmod(n,k);
    if(re1<10)printf("00%lld\n",re1 );
    else if(re1<100)printf("0%lld\n",re1 );
    else printf("%lld\n",re1 );

}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
