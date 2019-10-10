#include<bits/stdc++.h>
using namespace std;
int n;

int a[201][101];
int dp[201][101];

int func(int r,int c)
{
    if(r>=0&&r<n*2-1&&c>=0&&c<n)
    {
        if(dp[r][c]!=-1)
        {
            return dp[r][c];
        }

        int re=-1e9;

        if(r<n-1)
        {
            re=max(re,func(r+1,c)+a[r][c]);
            re=max(re,func(r+1,c+1)+a[r][c]);
        }

        else
        {
            re=max(re,func(r+1,c)+a[r][c]);
            re=max(re,func(r+1,c-1)+a[r][c]);

        }


        return dp[r][c]=re;
    }
    return 0;
}


int main()
{
    int t;
    scanf("%d",&t);

    for(int ii=1; ii<=t; ii++)
    {
        memset(dp,-1,sizeof(dp));
        memset(a,0,sizeof(a));

        scanf("%d",&n);

        int i;

        for(i=0; i<n; i++)n
        {
            for(int j=0; j<=i; j++)
                scanf("%d",&a[i][j]);
        }
        int k=n-2;
        for(i=i; i<n*2-1; i++)
        {
            for(int j=0; j<=k; j++)
                scanf("%d",&a[i][j]);

            k--;
        }


//        for(int i=0;i<n*2-1;i++)
//        {
//            for(int j=0;j<n;j++)
//                cout<<a[i][j]<<" ";
//            cout<<endl;
//        }

        printf("Case %d: %d\n",ii,func(0,0));

    }

    return 0;
}
