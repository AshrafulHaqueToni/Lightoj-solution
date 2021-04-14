// Created by ash_98

#include<bits/stdc++.h>
using namespace std;
#define MAX 55
#define ll unsigned int
#define lll long long


struct Matrix{
    int row, col;
    ll m[MAX][MAX];
    Matrix() {memset(m,0,sizeof(m));}
    void Set(int r,int c) {row = r; col = c;}
    Matrix(int r,int c) {memset(m,0,sizeof(m)); Set(r,c);}
    void normalize(){
        for(int i=1; i<=row; i++){
            for(int j=1; j<=col; j++){
               
               
            }
        }
    }
};

Matrix Multiply(Matrix A,Matrix B){
    Matrix ans(A.row,B.col);

    for(int i=1;i<=A.row;i++){
        for(int j=1;j<=B.col;j++){
            ans.m[i][j]=0;
            ll sm = 0;
            for(int k=1;k<=A.col;k++){
                sm+=(A.m[i][k]*B.m[k][j]);
               // if(sm >= MOD2) sm -= MOD2;
            }
            ans.m[i][j] = sm;
        }
    }
    return ans;
}

Matrix Power(Matrix mat,lll p){
    Matrix res(mat.row , mat.col);
    Matrix ans(mat.row , mat.col);

    int n = ans.row;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans.m[i][j]=0;
            res.m[i][j]=mat.m[i][j];
        }
        ans.m[i][i]=1;
    }

    while(p){
        if(p&1) ans=Multiply(ans,res);
        res=Multiply(res,res);
        p=p/2;
    }
    return ans;
}
int ii;
ll nCr[55][55];

void pre_cal()
{
	nCr[0][0]=1;
	for(int i=1;i<=50;i++)
	{
		nCr[i][0]=nCr[i][i]=1;
		for(int j=1;j<i;j++)nCr[i][j]=nCr[i-1][j-1]+nCr[i-1][j];
	}


}
 
void solve()
{
	 lll n;
    int k;
    scanf("%lld%d",&n,&k);
    Matrix A(k+2,k+2),B(k+2,1);
    for(int i=k+1,x=0;i>=1;i--,x++)
    {
    	for(int j=k+1,y=0;j>=i;j--,y++)
    	{
    		A.m[i][j]=nCr[x][y];
    	}
    }
    for(int i=1;i<=k+1;i++)B.m[i][1]=1;
    A.m[k+2][1]=A.m[k+2][k+2]=1;
    if(n==1)
    {
    	printf("Case %d: 1\n",++ii );
    	return;
    }
    B=Multiply(Power(A,n),B);
   // for(int i=1;i<=k+2;i++)printf("%d\n",B.m[i][1] );
    printf("Case %d: %u\n",++ii,B.m[k+2][1] );

}
 
int main()
{
	int t=1;
	pre_cal();
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
