// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 200005
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k;

ll func(int val,int div)
{
    ll re=0;
    int pres=div;
    while(val>=pres)
    {
        re+=val/pres;
        pres*=div;
    }
    return re;
}
ll fact(int val,int p)
{
    ll re=0;
    while(val%p==0)
    {
        val/=p;
        re++;
    }
    return re;
}
 
void solve()
{
    int r,p,q;
    scanf("%d%d%d%d",&n,&r,&p,&q);
    ll two=func(n,2)-func(r,2)-func(n-r,2)+fact(p,2)*q;
    ll five=func(n,5)-func(r,5)-func(n-r,5)+fact(p,5)*q;
    printf("Case %d: %lld\n",++ii,max(0LL,min(two,five)) );
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
