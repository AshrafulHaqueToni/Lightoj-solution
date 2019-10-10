#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define inf 2000000000

int n;
int ar[mx];
int lis[mx];
int lds[mx];
int tem[mx];


void LIS()
{
    tem[0]=-inf;

    for(int i=1;i<=n;i++)tem[i]=inf;

    int len=0;

    for(int i=0;i<n;i++)
    {
        int lo=0,high=len;

        while(lo<=high)
        {
            int mid=(lo+high)/2;

            if(tem[mid]<ar[i])lo=mid+1;
            else high=mid-1;
        }

        tem[lo]=ar[i];
        lis[i]=lo;

        if(lo>len)len++;
    }
}

void LDS()
{
    tem[0]=-inf;

    for(int i=1;i<=n;i++)tem[i]=inf;

    int len=0;

    for(int i=0;i<n;i++)
    {
        int lo=0,high=len;

        while(lo<=high)
        {
            int mid=(lo+high)/2;

            if(tem[mid]<ar[i])lo=mid+1;
            else high=mid-1;
        }

        tem[lo]=ar[i];
        lds[i]=lo;

        if(lo>len)len++;
    }
}


int main()
{
    int t;
    scanf("%d",&t);

    for(int ii=1;ii<=t;ii++)
    {
        scanf("%d",&n);

        for(int i=0;i<n;i++)scanf("%d",ar+i);

        LIS();
        reverse(ar,ar+n);
        LDS();

        int re=0;

        reverse(lds,lds+n);

        for(int i=0;i<n;i++){
           re=max(re,(2*min(lis[i],lds[i]))-1);
           //cout<<lis[i]<<" "<<lds[i]<<endl;
        }

        printf("Case %d: %d\n",ii,re);
    }

    return 0;
}
