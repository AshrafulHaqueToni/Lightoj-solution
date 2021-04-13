// Created by ash_98

#include<bits/stdc++.h>
using namespace std;
#define MAX 7
#define ll long long int
ll MOD,MOD2;

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
	int a1,a2,b1,b2,c1,c2;
	int f0,f1,f2,g1,g2,g0;

	scanf("%d%d%d",&a1,&b1,&c1);
	scanf("%d%d%d",&a2,&b2,&c2);
	scanf("%d%d%d",&f0,&f1,&f2);
	scanf("%d%d%d",&g0,&g1,&g2);
	scanf("%lld",&MOD);
	MOD2 = MOD * MOD * 3;
	
	Matrix A(6,6),B(6,1);
	A.m[1][1]=a1,A.m[1][2]=b1,A.m[1][6]=c1,A.m[5][4]=1;
	A.m[2][1]=A.m[3][2]=A.m[6][5]=1;
	A.m[4][3]=c2,A.m[4][4]=a2,A.m[4][5]=b2;
	B.m[4][1]=g2;
	B.m[5][1]=g1;
	B.m[6][1]=g0;
	B.m[1][1]=f2;
	B.m[2][1]=f1;
	B.m[3][1]=f0;
	
	int q;
	scanf("%d",&q);
	printf("Case %d:\n",++ii );
	for(int i=1;i<=q;i++)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
		{
			printf("%lld %lld\n",f0%MOD,g0%MOD );
		}
		else if(n==1)
		{
			printf("%lld %lld\n",f1%MOD,g1%MOD );
		}
		else if(n==2)
		{
			printf("%lld %lld\n",f2%MOD,g2%MOD );
		}
		else
		{
			Matrix re(6,1);
			re=Multiply(Power(A,n-2),B);
			printf("%lld %lld\n",re.m[1][1],re.m[4][1] );
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
