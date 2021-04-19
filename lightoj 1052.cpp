// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
#define MAX 3
#define ll long long int
const ll MOD = 1e9 + 7;
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

long long fibo[50];

void func()
{
	fibo[0]=1;
	fibo[1]=1;
	for(int i=2;i<=45;i++)fibo[i]=fibo[i-1]+fibo[i-2];
	//cout<<fibo[43]<<endl;
}
int ii;

void solve()
{
	int n,x,m,y,k;
	scanf("%d%d%d%d%d",&n,&x,&m,&y,&k);
	if(n>43 || m>43)
	{
		printf("Case %d: Impossible\n",++ii );
		return;
	}
	long long a1,b1,c1,a2,b2,c2;
	a1=fibo[n-1],b1=fibo[n],c1=-x;  // f(n)=a1x+b1y --> a1x+b1y-f(n)=0
	a2=fibo[m-1],b2=fibo[m],c2=-y;  // f(m)=a2x+b2y --> a2x+b2y-f(m)=0
	long long d,dx,dy;
	d=a1*b2-a2*b1;
	dx=b1*c2-b2*c1;
	dy=a2*c1-a1*c2;
	if(d==0 || dx/d<0 || dy/d<0 || dx%d || dy%d)
	{
		printf("Case %d: Impossible\n",++ii );
		return;
	}
	Matrix A(2,2),B(2,1);
	A.m[1][1]=A.m[1][2]=A.m[2][1]=1;
	B.m[2][1]=((dx/d)+(dy/d))%MOD;
	B.m[1][1]=((dx/d)+(dy/d)+(dy/d))%MOD;
	if(k==1)
	{
		printf("Case %d: %lld\n",++ii,B.m[2][1] );

	}
	else if(k==2)
	{
		printf("Case %d: %lld\n",++ii,B.m[1][1] );
	}
	else
	{
		A=Power(A,k-2);
		Matrix re=Multiply(A,B);
		printf("Case %d: %lld\n",++ii,re.m[1][1] );
	}
}
 
int main()
{
	int t=1;
	func();
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
