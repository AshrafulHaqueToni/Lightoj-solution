#include<bits/stdc++.h>
using namespace std;


void ReverseArray(int x[],int n)
{
    int i=0;
    for(int j=n-1;j>=0;i++,j--)
    {

        x[j]=x[i];

    }
}
int main()
{
    freopen("1131.txt","r",stdin);
    int t ;
    int i;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int x=n;
        int a[x];
        int j;
        for(j=0; j<n; j++)
        {
            scanf("%d",&a[j]);
        }
        getchar();
        int k;
        char s;
        int d;
        int y,z;
        for(k=1; k<=m; k++)
        {
            scanf("%c",&s);
            if (s=='S')
            {
                scanf("%d",&d);
                getchar();
                for(j=0; j<n; j++)
                {
                    a[j]=a[j]+d;
                }
            }


            else if (s=='M')
            {

                scanf("%d",&d);
                getchar();
                for(j=0; j<n; j++)
                {
                    a[j]=a[j]*d;
                }
            }

            else if (s=='D')
            {

                scanf("%d",&d);
                getchar();
                for(j=0; j<n; j++)
                {
                    a[j]=a[j]/d;
                }
            }
            else if (s=='R')
            {
                ReverseArray(a,n);
            }

            else if(s=='P')
            {
                scanf("%d %d",&y,&z);
                getchar();
                int temp;
                temp=a[y];
                a[y]=a[z];
                a[z]=temp;
            }
        }
        printf("Case %d:\n",i);
        for(j=0; j<n; j++)
        {
            if (j+1==n)
            {
                printf("%d\n",a[j]);
            }
            else
                printf("%d ",a[j]);
        }
    }
    return 0;
}
