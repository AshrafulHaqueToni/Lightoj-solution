// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 200005
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k;

struct GCD_type { ll x, y, d; };

GCD_type ex_GCD(ll a, ll b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}
 
void solve()
{
    int a,b,c,x1,x2,y1,y2;
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&x1,&x2,&y1,&y2);
    ll x=abs(x1-x2)+1;
    ll y=abs(y1-y2)+1;
    if(a==0 && b==0 && c!=0)
    {
        printf("Case %d: 0\n",++ii );
        return;
    }
    if(a==0 && b==0 && c==0)
    {
        printf("Case %d: %lld\n",++ii,x*y);
        return;
    }
    if(a==0)
    {
        if(c%b==0 && (-c/b)>=y1 && (-c/b)<=y2)
        {
            printf("Case %d: %lld\n",++ii,x );
        }
        else printf("Case %d: 0\n",++ii );
        return;
    }
    if(b==0)
    {

        if(c%a==0 && (-c/a)>=x1 && (-c/a)<=x2)
        {
            printf("Case %d: %lld\n",++ii,y );
        }
        else printf("Case %d: 0\n",++ii );
        return;
    }
    auto it=ex_GCD(a,b);
    if(c%it.d==0)
    {
        ll nx=it.x*(-c/it.d);
        ll ny=it.y*(-c/it.d);

        double sx=((x1-nx)*it.d*1.0)/b;
        double bx=((x2-nx)*it.d*1.0)/b;
        if(sx>bx)swap(sx,bx);

        sx=ceil(sx);
        bx=floor(bx);

        double sy=((ny-y1)*it.d*1.0)/a;
        double by=((ny-y2)*it.d*1.0)/a;

        if(sy>by)swap(sy,by);

        sy=ceil(sy);
        by=floor(by);

        ll re=min(by,bx)-max(sy,sx)+1;
        re=max(0LL,re);
        printf("Case %d: %lld\n",++ii,re );
    }
    else printf("Case %d: 0\n",++ii );


}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
