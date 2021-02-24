// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 1005
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k;

int Grundy[mx][mx];
int vis[mx][mx];

int xx[]={-2,-3,-2,-1,-1,+1};
int yy[]={+1,-1,-1,-2,-3,-2};

bool valid(int i,int j)
{
	if(i<0 || j<0)return 0;
	return 1;
}

int func(int i,int j)
{
	if(vis[i][j])return Grundy[i][j];
	vis[i][j]=1;
	bitset<50>bt;
	bool f=false;

	for(int x=0;x<6;x++)
	{
		f|=valid(i+xx[x],j+yy[x]);
	}

	if(!f)
	{
		return Grundy[i][j]=0;
	}

	for(int x=0;x<6;x++)
	{
		if(valid(xx[x]+i,yy[x]+j))bt[func(i+xx[x],j+yy[x])]=true;
	}
	int re=0;
	while(1)
	{
		if(bt[re]==false)break;
		re++;
	}
	
	return Grundy[i][j]=re;
}
 
void solve()
{
	 int re=0;
	 scanf("%d",&n);
	 for(int i=1;i<=n;i++)
	 {
	 	int x,y;
	 	scanf("%d%d",&x,&y);
	 	re^=func(x,y);
	 	//cout<<Grundy[x][y]<<endl;

	 }

	 if(re)printf("Case %d: Alice\n",++ii );
	 else printf("Case %d: Bob\n",++ii );
}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
