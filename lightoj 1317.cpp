// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 200005
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k;
 
void solve()
{
    double d;
    scanf("%d%d%d%lf",&n,&m,&k,&d);
    double re=d*k*n;
    printf("Case %d: %0.6lf\n",++ii,re );

}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
