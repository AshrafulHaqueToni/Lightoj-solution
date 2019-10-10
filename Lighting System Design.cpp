#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

int dp[1001][101];
int vis[1001][101];
int n,ii;

pair<int ,int > p[1001];

pair<int,pair<int,int> >value[1001];

int func(int pos,int minvalue)
{
    if(pos==n)
        return 0;

    if(vis[pos][minvalue]==ii)
        return dp[pos][minvalue];

    vis[pos][minvalue]=ii;

    int re1=1e9,re2=1e9,re3=1e9;

    int orginal_poss=p[pos].ss;

    int b=value[orginal_poss].ss.ss;
    int c=value[orginal_poss].ss.ff;
    int cost=value[orginal_poss].ff;

    re1=minvalue*b+func(pos+1,minvalue);


    re2=(b*c+cost)+func(pos+1,min(c,minvalue));
   // re3=(b*c+cost)+func(pos+1,min(minvalue,c));

    return dp[pos][minvalue]=min(re1,re2);

}


int main()
{
    int t;
    scanf("%d",&t);

    for(ii=1; ii<=t; ii++)
    {
        scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            p[i]= {-a,i};
            value[i]= {b,{c,d}};
        }
        sort(p,p+n);

       // for(int i=0;i<n;i++)cout<<p[i].ss<<endl;

        int orginal_poss=p[0].ss;
        int b=value[orginal_poss].ss.ss;
        int c=value[orginal_poss].ss.ff;
        int cost=value[orginal_poss].ff;
        //cout<<cost+b*c<<endl;

        printf("Case %d: %d\n",ii,(func(1,c)+b*c+cost));

    }

    return 0;
}
