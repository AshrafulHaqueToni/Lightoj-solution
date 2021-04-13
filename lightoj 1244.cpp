// Created by ash_98

#include<bits/stdc++.h>
using namespace std;
#define MAX 5
#define ll long long int
const ll MOD = 1e4 + 7;
const ll MOD2 = MOD * MOD * 3;

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
int ii;
 
void solve()
{
	Matrix A(4,4);
	Matrix B(4,1);
	A.m[1][1]=A.m[1][2]=A.m[1][3]=A.m[1][4]=1;
	A.m[2][1]=A.m[3][2]=A.m[3][4]=A.m[4][3]=A.m[4][2]=1;
	B.m[1][1]=2;
	B.m[2][1]=1;
	B.m[3][1]=1;
	B.m[4][1]=1;
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int x;
		scanf("%d",&x);
		if(x==1)
		{
			printf("Case %d: 1\n",i);
		}
		else if(x==2)
		{
			printf("Case %d: 2\n",i );
		}
		else
		{
			Matrix re(4,1);
			re=Multiply(Power(A,x-2),B);
			printf("Case %d: %lld\n",i,re.m[1][1] );
		}
	}

}
 
int main()
{
	int t=1;
	//scanf("%d",&t);
	while(t--)solve();
	return 0;
}
