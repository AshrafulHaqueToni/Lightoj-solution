// Created by ash_98

#include<bits/stdc++.h>
using namespace std;
#define MAX 5
#define ll int
ll MOD;
int ii;
ll MOD2;


inline ll bigMod(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=(res*a)%MOD;
        a=(a*a)%MOD; b>>=1;
    }
    return res;
}

inline ll inv(ll n) {return bigMod(n,MOD-2);}
inline ll Mul(ll a,ll b) {return (a*b)%MOD;}
inline ll Div(ll a,ll b) {return Mul(a,inv(b));}

struct Matrix{
    int row, col;
    ll m[MAX][MAX];
    Matrix() {memset(m,0,sizeof(m));}
    void Set(int r,int c) {row = r; col = c;}
    Matrix(int r,int c) {memset(m,0,sizeof(m)); Set(r,c);}
    void normalize(){
        for(int i=1; i<=row; i++){
            for(int j=1; j<=col; j++){
                m[i][j] %= MOD;
                if(m[i][j] < 0) m[i][j] += MOD;
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

Matrix Power(Matrix mat,ll p){
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
 
void solve()
{
	int a,b,n,m;
	scanf("%d%d%d%d",&a,&b,&n,&m);
	if(m==1)MOD=10;
	else if(m==2)MOD=100;
	else if(m==3)MOD=1000;
	else MOD=10000;
	MOD2= MOD * MOD * 3;
	Matrix A(2,2),B(2,1);
	A.m[1][1]=A.m[1][2]=A.m[2][1]=1;
	A.m[2][2]=0;
	B.m[1][1]=b;
	B.m[2][1]=a;
	B.normalize();
	if(n==0)printf("Case %d: %d\n",++ii,a%MOD );
	else if(n==1)printf("Case %d: %d\n",++ii,b%MOD);
	else
	{
		A=Power(A,n-1);
		B=Multiply(A,B);
		printf("Case %d: %d\n",++ii,B.m[1][1]%MOD);
	}

}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
