#include<bits/stdc++.h>
using namespace std;

#define ll long double

 ll x1,x2,x,yy1,y2,y,z1,z2,z;

 ll func(ll a,ll b,ll c)
 {
     return sqrt((a-x)*(a-x)+(b-y)*(b-y)+(c-z)*(c-z));
 }

void solve(int ii)
{

    cin>>x1>>yy1>>z1>>x2>>y2>>z2>>x>>y>>z;
    ll re=min(func(x1,yy1,z1),func(x2,y2,z2));
   // cout<<re<<endl;
    for(int i=1;i<=100;i++)
    {
        ll midx=(x1*2+x2)/3;
        ll midy=(yy1*2+y2)/3;
        ll midz=(z1*2+z2)/3;
         ll midxx=(x1+2*x2)/3;
        ll midyy=(yy1+2*y2)/3;
        ll midzz=(z1+2*z2)/3;

        if(func(midx,midy,midz)>func(midxx,midyy,midzz))
        {
            x1=midx;
            yy1=midy;
            z1=midz;
        }
        else
        {
            x2=midxx;
            y2=midyy;
            z2=midzz;
        }
    }
    re=min(re,func(x1,yy1,z1));
    printf("Case %d: %0.10LF\n",ii,re);
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
