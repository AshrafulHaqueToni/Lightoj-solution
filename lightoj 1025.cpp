#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define mx 100005
#define mod 1000000007

ll dp[65][65];
int vis[65][65];

char ch[65];
int len,ii;

ll func(int i,int j)
{
    if(i>j)return 0;

    if(i==j)return 1;

    if(vis[i][j]==ii)return dp[i][j];

    vis[i][j]=ii;

    ll re=0;

    if(ch[i]==ch[j])
    {
        re=1+func(i+1,j)+func(i,j-1);
    }
    else re=func(i+1,j)+func(i,j-1)-func(i+1,j-1);

    return dp[i][j]=re;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for(ii=1;ii<=t;ii++)
    {
        scanf("%s",ch);
        len=strlen(ch);

        //cout<<ii<<endl;

        printf("Case %d: %lld\n",ii,func(0,len-1));
    }

    return 0;
}
