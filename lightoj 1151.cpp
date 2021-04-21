// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;

#define eps 1e-6
#define ll long double

ll a[105][105];
int To[105];
 
int Gauss(int n,int m){
    int col,i,mxr,j,row;
    for(row=col=1;row<=n&&col<=m;row++,col++){
        mxr = row;
        for(i=row+1;i<=n;i++)
            if(fabs(a[i][col])>fabs(a[mxr][col]))
                mxr = i;
        if(mxr != row) swap(a[row],a[mxr]);
        if(fabs(a[row][col]) < eps){
            row--;
            continue;
        }
        for(i=1;i<=n;i++)
            if(i!=row&&fabs(a[i][col])>eps)
                for(j=m;j>=col;j--)
                    a[i][j]-=a[row][j]/a[row][col]*a[i][col];
    }
    row--;
    for(int i = row;i>=1;i--){
        for(int j = i + 1;j <= row;j++){
			a[i][m] -= a[j][m] * a[i][j];
        }
    	a[i][m] /= a[i][i];
    }
    return row;
}
int ii;
 
void solve()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=100;i++)To[i]=i;
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=101;j++)a[i][j]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		To[x]=y;
	}
	a[100][100]=1;
	for(int i=1;i<=99;i++)
	{
		if(To[i]==i)
		{
			int jabe=min(6,100-i);
			a[i][i]=jabe;
			for(int j=1;j<=jabe;j++)a[i][i+j]=-1;
			a[i][101]=6;
		}
		else
		{
			a[i][i]=1;
			a[i][To[i]]=-1;
		
		}
	}

	Gauss(100,101);
    printf("Case %d: %0.8LF\n",++ii,a[1][101] );

}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
