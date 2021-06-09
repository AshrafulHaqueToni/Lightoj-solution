// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 200005
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k;
double l,w;

double func(double x)
{
    return (x*(l-2*x)*(w-2*x));
}
 
void solve()
{
    
    scanf("%lf%lf",&l,&w);
    double be=0,en=min(l,w)/2;
    int magic=200;
    while(magic--)
    {
        double mid1=(be+be+en)/3.00;
        double mid2=(be+en+en)/3.00;
        if(func(mid1)>=func(mid2))
        {
            en=mid2;
        }
        else be=mid1;
    }
    printf("Case %d: %0.6lf\n",++ii,func(be) );
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
