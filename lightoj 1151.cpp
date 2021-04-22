// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;

#define eps 1e-6
#define ll long double

ll A[105][105];
ll X[105];
int To[105];
 
void Gauss(int n,int m){
	 
    int r,c;
    for(r=0,c=0;r<n && c<m;c++){
        for(int i=r+1;i<n;i++) if(fabs(A[i][c])>fabs(A[r][c])) swap(A[i],A[r]);
        if(fabs(A[r][c])<eps) continue;
        ll s = A[r][c];
        for(int i=r+1;i<n;i++) if(fabs(A[i][c])>=eps){
            ll w = A[i][c];
            for(int j=c;j<=m;j++){A[i][j]-=A[r][j]/s*w; }
        }
        r++;
    }
    //Rank = r
    for(int i=r;i<n;i++) if(fabs(A[i][m])>=eps) return;  //No solution
    //Unique Solution for r variables
    for(int i=r-1;i>=0;i--){
        X[i]=A[i][m];
        for(int j=i+1;j<r;j++) {X[i]-=(A[i][j]*X[j]); }
        X[i]/=A[i][i];
        
    }
}
int ii;
 
void solve()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<=100;i++)To[i]=i;
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<101;j++)A[i][j]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;
		y--;
		To[x]=y;
	}
	A[99][99]=1;
	for(int i=0;i<99;i++)
	{
		if(To[i]==i)
		{
			int jabe=min(6,99-i);
			A[i][i]=jabe;
			for(int j=1;j<=jabe;j++)A[i][i+j]=-1;
			A[i][100]=6;
		}
		else
		{
			A[i][i]=1;
			A[i][To[i]]=-1;
		
		}
	}

	Gauss(100,100);
    printf("Case %d: %0.8LF\n",++ii,X[0] );

}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
