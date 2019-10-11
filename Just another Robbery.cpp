#include<bits/stdc++.h>
using namespace std;

#define ll long long

double dp[101][101*101];
int vis[101][101*101];
int milion[101];
double probability[101];
int ii,n;
double capacity;

double func(int pos,int lav)
{
    if(lav<=0)
        return 0;

    if(pos==n)
        return (lav<=0)?0:1e6;

    if(vis[pos][lav]==ii)
        return dp[pos][lav];

    vis[pos][lav]=ii;

    return dp[pos][lav]=min(func(pos+1,lav),probability[pos]+((1-(probability[pos]))*func(pos+1,lav-milion[pos])));

}




int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1; tc<=t; tc++)
    {
        scanf("%lf%d",&capacity,&n);
        memset(vis,0,sizeof vis);
        ii=0;

        for(int i=0; i<n; i++)
            scanf("%d%lf",milion+i,probability+i);

        int lo=0,high=100*100,ans=0;

        while(lo<=high)
        {
            int mid=(lo+high)/2;

            ii++;

            if(func(0,mid)<=capacity)
            {
                ans=mid;
                lo=mid+1;
            }
            else
                high=mid-1;

           // cout<<func(0,mid)<<endl;
        }

        printf("Case %d: %d\n",tc,ans);
    }

    return 0;
}

