#include<bits/stdc++.h>
using namespace std;

int dp[200005];
int vis[200005];
int koto_uchu,ii;

vector<int>high[200005],taka[200005];

int func(int pos)
{
    if(pos>=koto_uchu)return 0;

    if(vis[pos]==ii)return dp[pos];

    vis[pos]=ii;

    int re=0,re1=0;

    for(int i=0;i<high[pos].size();i++)
    {
        re=max(re,taka[pos][i]+func(pos+high[pos][i]));
    }

    re1=func(pos+1);

    return dp[pos]=max(re,re1);

}

int main()
{
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);

    for(ii=1;ii<=t;ii++)
    {
        int n;
        scanf("%d",&n);

        koto_uchu=0;

        for(int i=0;i<n;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);

            high[a].push_back(b);
            taka[a].push_back(c);

            koto_uchu=max(koto_uchu,a+b-1);
        }

        printf("Case %d: %d\n",ii,func(0));


        for(int i=0;i<=koto_uchu;i++)high[i].clear(),taka[i].clear();
    }


    return 0;
}
