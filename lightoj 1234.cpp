#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define gama 0.57721566490
double ar[1000005],ans;
int n;
 
void precal()
{
    for(int i=1;i<=1000000;i++)
    {
        ar[i]+=ar[i-1]+(1.0/(double)i);
    }
}
 
void solve(int ii)
{
    scanf("%d",&n);
 
    if(n<=1000000)
    {
        ans=ar[n];
    }
    else
    {
        ans=log(n+0.5)+gama;
    }
 
    printf("Case %d: %.9lf\n",ii,ans);
}
 
int main()
{
    int t=1;
    precal();
 
    scanf("%d",&t);
 
    for(int ii=1; ii<=t; ii++)
        solve(ii);
 
    return 0;
}
