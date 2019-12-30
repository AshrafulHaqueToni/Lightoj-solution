#include<bits/stdc++.h>
using namespace std;

#define ll long long

int dp[32][32];
int vis[32][32];
ll dp1[32][32][62];
int vis1[32][32][62];
char ch1[32],ch2[32];

int n1,n2,tot,ii;

int lcs(int i,int j)
{
    if(i>=n1 || j>=n2)return 0;

    int &val=dp[i][j];

    if(vis[i][j]==ii)return val;

    vis[i][j]=ii;
    val=0;

    if(ch1[i]==ch2[j])
    {
        val=1+lcs(i+1,j+1);
    }
    else
    {
        val=max(lcs(i+1,j),lcs(i,j+1));
    }

    return val;
}

ll func(int i,int j,int l)
{
    if(i>=n1)
    {
        l+=n2-j;
        return (l==tot);
    }
    if(j>=n2)
    {
        l+=n1-i;
        return (l==tot);
    }

    ll &val=dp1[i][j][l];

    if(vis1[i][j][l]==ii)return val;

    vis1[i][j][l]=ii;

    val=0;

    if(ch1[i]==ch2[j])
    {
        val=func(i+1,j+1,l+1);
    }
    else
    {
        val+=func(i+1,j,l+1);
        val+=func(i,j+1,l+1);
    }

    return val;
}

int main()
{
    int t;
    scanf("%d",&t);

    for(ii=1;ii<=t;ii++)
    {
        scanf("%s%s",ch1,ch2);
        n1=strlen(ch1);
        n2=strlen(ch2);
        tot=n1+n2-lcs(0,0);

        printf("Case %d: %d %lld\n",ii,tot,func(0,0,0));

    }



    return 0;
}
