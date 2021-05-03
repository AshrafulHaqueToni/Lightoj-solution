// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 1005
#define N  1001
#define ll long long
#define mod 1000000007
 
int ar[mx][mx];
int n,m,ii,k;

struct BIT
{
    int Tree[N+5][N+5];
    void init()
    {
    	memset(Tree,0,sizeof(Tree));
    }
    int query(int idx,int idy)
    {
        int re=0;
        int tem=idy;
        while(idx)
        {
        	idy=tem;
        	while(idy)
            {
            	re+=Tree[idx][idy];
            	idy-=idy&-idy;
            }
            idx-=idx&-idx;
        }
        return re;
    }
    void update(int idx,int idy,int val)
    {
    	int tem=idy;
        while(idx<=N)
        {
        	idy=tem;
        	while(idy<=N)
        	{
               Tree[idx][idy]+=val;
               idy+=idy&-idy;
            }
            idx+=idx&-idx;
        }
    }
};

BIT bit;

 
void solve()
{
	bit.init();
	memset(ar,0,sizeof(ar));
	int q;
	scanf("%d",&q);
	printf("Case %d:\n",++ii );
	for(int i=1;i<=q;i++)
	{
		int ti;
		scanf("%d",&ti);
		if(ti==0)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x++;
			y++;
			if(ar[x][y]==0)
			{
				ar[x][y]=1;
				bit.update(x,y,1);

			}

		}
		else
		{
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			x1++;
			y1++;
			x2++;
			y2++;
			printf("%d\n",bit.query(x2,y2)
				-bit.query(x1-1,y2)-bit.query(x2,y1-1)
				+bit.query(x1-1,y1-1));
		}
	}
}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
