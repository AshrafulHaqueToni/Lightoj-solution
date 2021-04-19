// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
#define MAX 35
#define ll int
const ll MOD = 10;
const ll MOD2 = MOD * MOD * 3;
/* 1 base row columun index */
struct Matrix{
    int row, col;
    ll m[MAX][MAX];
    Matrix() {memset(m,0,sizeof(m));}
    void Set(int r,int c) {row = r; col = c;}
    Matrix(int r,int c) {memset(m,0,sizeof(m)); Set(r,c);}
    void normalize(){
        for(int i=1; i<=row; i++){
            for(int j=1; j<=col; j++){
                m[i][j]=1;
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
                if(sm >= MOD2) sm -= MOD2;
            }
            ans.m[i][j] = sm % MOD;
        }
    }
    return ans;
}

Matrix Power(Matrix mat,int p){
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

Matrix func(Matrix A,int k,Matrix I)
{
	if(k==0)return I;
	if(k==1)return A;
	Matrix re=func(A,k/2,I);
	Matrix tem=Multiply(re,Power(A,k/2));
	for(int i=1;i<=A.row;i++)
	{
		for(int j=1;j<=A.col;j++)
		{
			re.m[i][j]=(re.m[i][j]+tem.m[i][j])%MOD;
		}
	}
	if(k&1)
	{
		tem=Power(A,k);
		for(int i=1;i<=A.row;i++)
		{
			for(int j=1;j<=A.col;j++)
			{
				re.m[i][j]=(re.m[i][j]+tem.m[i][j])%MOD;
			}
		}

	}
	return re;
}

int ii;

void solve()
{
	int n,k;
	scanf("%d%d",&n,&k);
	Matrix A(n,n);
	Matrix I(n,n);
	I.normalize();
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)scanf("%d",&A.m[i][j]);
	}
    A=func(A,k,I);
    printf("Case %d:\n",++ii );
    for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)printf("%d",A.m[i][j]);
		printf("\n");
	}

}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
