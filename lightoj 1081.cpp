// Created by ash_98

#include<bits/stdc++.h>
using namespace std;

#define mx 505
#define MAX_logN 9
#define ll long long
#define mod 1000000007

int ar[mx][mx];
int n,m,ii,k;
int ST[mx][mx][MAX_logN];  

void Build_2D_Sparse()
{
	for(int l=0;(1<<l)<=n;l++)
	{
		for(int i=1;i+(1<<l)-1<=n;i++)
		{
			for(int j=1;j+(1<<l)-1<=n;j++)
			{
				if(l==0)ST[i][j][l]=ar[i][j];
				else
				{
					int pre=1<<(l-1);
					int val1=max(ST[i][j][l-1],ST[i+pre][j][l-1]);
					int val2=max(ST[i][j+pre][l-1],ST[i+pre][j+pre][l-1]);
					ST[i][j][l]=max(val1,val2);
				}
			}
		}
	}
}

int query(int i,int j,int sz)
{
	int boro_lav=log2(sz);
	int pre=1<<(boro_lav);
	int val1=max(ST[i][j][boro_lav],ST[i+sz-pre][j][boro_lav]);
	int val2=max(ST[i][j+sz-pre][boro_lav],ST[i+sz-pre][j+sz-pre][boro_lav]);
	return max(val1,val2);
}

void solve()
{
	int q;
	scanf("%d%d",&n,&q);

    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
            scanf("%d",&ar[i][j]);
    	}
    }

    Build_2D_Sparse();

    printf("Case %d:\n",++ii );

    while(q--)
    {
        int x,y,s;
        scanf("%d%d%d",&x,&y,&s);
        printf("%d\n",query(x,y,s) );
    }
}

int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
