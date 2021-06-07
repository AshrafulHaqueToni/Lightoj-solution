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
    int a,b;
    scanf("%d%d",&a,&b);
    if(a&1)
    {
        printf("Case %d: 0\n",++ii );
    }
    else
    {
        printf("Case %d: %0.6lf\n",++ii,1.00/(a+1) );
    }
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
