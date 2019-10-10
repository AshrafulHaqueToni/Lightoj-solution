#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);

    for(int ii=1;ii<=t;ii++)
    {
        int n;
        scanf("%d",&n);

        int a[n+1];

        for(int i=1;i<=n;i++)scanf("%d",a+i);

        int re=0;

        for(int i=1;i<=n;i++)
        {
            int fi=a[i];
            for(int j=i+1;j<=n;j++)
            {
                if(a[j]<a[i])break;
                fi+=a[i];
            }

            for(int j=i-1;j>=1;j--)
            {
                if(a[j]<a[i])break;
                fi+=a[i];
            }

            re=max(fi,re);
        }

        printf("Case %d: %d\n",ii,re);
    }
}
