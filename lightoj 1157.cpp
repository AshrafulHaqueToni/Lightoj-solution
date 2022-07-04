// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 1005
#define ll long long
#define mod 1000007 //998244353
 
char ch[2][mx];
int n,m,ii,k;
int dp[mx][mx];
int re[mx][mx];

int add(int a,int b)
{
    a+=b;
    if(a>=mod)a-=mod;
    return a;
}
int sub(int a,int b)
{
    a-=b;
    if(a<0)a+=mod;
    return a;
}
int mul(int a,int b)
{
    ll re=a;
    re*=b;
    if(re>=mod)re%=mod;
    return re;
}
 
void solve()
{
    scanf("%s%s",ch[0],ch[1]);
    n=strlen(ch[0]);
    m=strlen(ch[1]);
    for(int i=0;i<=n;i++)re[i][0]=1;
    for(int i=0;i<=m;i++)re[0][i]=1;
  
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(ch[0][i-1]==ch[1][j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                re[i][j]=re[i-1][j-1];
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                dp[i][j]=dp[i-1][j];
                re[i][j]=re[i-1][j];
            }
            else if(dp[i-1][j]<dp[i][j-1])
            {
                dp[i][j]=dp[i][j-1];
                re[i][j]=re[i][j-1];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
                int ex=0;
                if(dp[i][j]==dp[i-1][j-1])ex=re[i-1][j-1];
                re[i][j]=sub(add(re[i][j-1],re[i-1][j]),ex);
            }
        }
    }
    printf("Case %d: %d\n",++ii,re[n][m]);
 
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
