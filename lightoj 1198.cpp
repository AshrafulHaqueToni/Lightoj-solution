#include<bits/stdc++.h>
using namespace std;
 
#define  ll long long
#define mx 105
int ar[mx],br[mx];
int dp[mx][mx];
char ch[mx];
int n,m;
 
int func(int i,int j)
{
    if(i==n || j==n)return 0;
    int &re=dp[i][j];
    if(re!=-1)return re;
    re=0;
    if(ar[i]>br[j])re=2+func(i+1,j+1);
    else if(ar[i]<br[j])re=func(i+1,j);
    else {
        re=max(1+func(i+1,j+1),func(i+1,j));
    }
    return re;
}
 
void solve(int ii)
{
    scanf("%d",&n);
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)scanf("%d",&ar[i]);
    for(int i=0;i<n;i++)scanf("%d",&br[i]);
    sort(ar,ar+n);
    sort(br,br+n);
    printf("Case %d: %d\n",ii,func(0,0));
 
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
 
    return 0;
}
