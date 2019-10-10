#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define inf 2000000000

int ar[mx];
int lis[mx];
int tem[mx];
int n,len,q;

void LIS()
{
    tem[1]=ar[n];
    lis[n]=1;
    len=1;

    //for(int i=1;i<=n;i++)tem[i]=inf;

    for(int i=n-1; i>=1; i--)
    {
        int lo=1,high=len+1;

        while(lo<high)
        {
            int mid=(lo+high)/2;

            if(tem[mid]>ar[i])
                lo=mid+1;
            else
                high=mid;
        }

        lis[i]=high;
        tem[high]=ar[i];

        if(high==len+1)
            len++;
    }
}


int main()
{
    int t;
    scanf("%d",&t);

    for(int ii=1; ii<=t; ii++)
    {
        //len=1;
        scanf("%d%d",&n,&q);

        for(int i=1; i<=n; i++)
        {
            scanf("%d",ar+i);
        }

        //reverse(ar,ar+n);

        LIS();
        //reverse(lis,lis+n);
        //reverse(ar,ar+n);
        // cout<<len<<endl;

//        for(int i=1;i<=n;i++)
//            cout<<lis[i]<<" ";

        // lis[n-1]=1;

        printf("Case %d:\n",ii);

        while(q--)
        {
            int val;
            scanf("%d",&val);

            if(val>len)
            {
                printf("Impossible\n");
                continue;
            }

            int re=-inf;

            for(int i=1; i<=n&&val>0; i++)
            {
                if(lis[i]>=val && re<ar[i])
                {
                    printf("%d",ar[i]);
                    val--;
                    if(val>0)
                        printf(" ");
                    //else break;
                    re=ar[i];
                }
            }
            printf("\n");
        }

    }

    return 0;
}
