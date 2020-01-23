#include<bits/stdc++.h>
using namespace std;

#define ll long long

int a[201];
int n,d,m,k;
int ii;
ll dp[201][22][11];
int vis[201][22][11];

ll func(int pos,int val,int cnt)
{
    if(pos==n )
    {
        return cnt==m && val%d==0;
    }

    if(cnt==m)
    {
        return val%d==0;
    }

    if(vis[pos][val][cnt]==k)return dp[pos][val][cnt];

    vis[pos][val][cnt]=k;

    ll re=0,re1=0;

    re+=func(pos+1,(d+(val+a[pos])%d)%d,cnt+1);

    re1+=func(pos+1,(d+val%d)%d,cnt);

    return dp[pos][val][cnt]=re+re1;


}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,q;
    scanf("%d",&t);

    while(t--)
    {
        memset(vis,0,sizeof vis);

        scanf("%d%d",&n,&q);

        //if(n==0&&q==0)break;
        ii++;

        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
        }

        printf("Case %d:\n",ii);

        for(k=1;k<=q;k++)
        {
            scanf("%d%d",&d,&m);

            printf("%lld\n",func(0,0,0));

        }
    }

    return 0;

}
