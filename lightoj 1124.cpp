// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 1000005
#define ll long long
#define mod 100000007 //998244353
 
int ar[20][2];
int n,m,ii,k;
int dp[2][mx];

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

bool f;

int pre[mx];
 
void solve()
{
    scanf("%d%d",&k,&n);
    for(int i=1;i<=k;i++)scanf("%d%d",&ar[i][0],&ar[i][1]);



    for(int i=0;i<=n;i++){
        if(ar[k][0]<=i and ar[k][1]>=i)dp[1][i]=1;
        else dp[1][i]=0;
        pre[i+1]=add(pre[i],dp[1][i]);
    }

    f=1;

    for(int i=k-1;i>=1;i--){
        f^=1;
        for(int sum=0;sum<=n;sum++){
            if(sum<ar[i][0]){
                dp[f][sum]=0;
            }
            else if(sum<=ar[i][1]){
                int r=sum-ar[i][0]+1;
                dp[f][sum]=pre[r];
            }
            else{
                int r=sum-ar[i][0]+1;
                int l=sum-ar[i][1];
                dp[f][sum]=sub(pre[r],pre[l]);
            }
        }
        for(int sum=0;sum<=n;sum++)pre[sum+1]=add(pre[sum],dp[f][sum]);
        
    }
    printf("Case %d: %d\n",++ii,dp[f][n] );


 
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
