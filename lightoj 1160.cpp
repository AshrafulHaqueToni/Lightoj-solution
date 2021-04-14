// Created by ash_98

#include<bits/stdc++.h>
using namespace std;
#define MAX 40
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

map<string,int>id;
map<int,string>pos;
int cnt;

void func(string s,int nichi,int one)
{
	if(nichi==7)
	{
		if(one!=4 || id.count(s))return;
		id[s]=++cnt;
		//cout<<id[s]<<endl;
		pos[cnt]=s;
		return;
	}
	func(s+"0",nichi+1,one);
	func(s+"1",nichi+1,one+1);
}

Matrix A(36,36);

void cal1(string s,string t,int i)
{
	if(i>6)
	{
		//cout<<id[s]<<" "<<t<<endl;
		if(id.count(t)){

			A.m[id[s]][id[t]]=1;
		}
		return;
	}
	if(s[i]=='0')cal1(s,t,i+1);
	else
	{
		if(i>0 && t[i-1]=='0')
		{
			t[i-1]='1';
			cal1(s,t,i+1);
			t[i-1]='0';
		}
		if(i<6 && t[i+1]=='0')
		{
			t[i+1]='1';
			cal1(s,t,i+1);
		}
	}
}

void cal()
{
	for(int i=1;i<=35;i++)
	{
		string s=pos[i];
		cal1(s,"0000000",0);
	}
}
int ii;
 
void solve()
{
	 int n;
	 scanf("%d",&n);
	 string s;
	 for(int i=1;i<=7;i++)
	 {
	 	int x;
	 	scanf("%d",&x);
	 	if(x)s+='1';
	 	else s+='0';
	 }
	 if(n==1)
	 {
	 	printf("Case %d: 1\n",++ii );
	 	return;
	 }
	 int idx=id[s];
	 Matrix B=Power(A,n-1);
	 int re=0;
	 for(int i=1;i<=35;i++)
	 {
	 	re=(re+B.m[idx][i]);
	 	if(re>=MOD)re-=MOD;
	 }
	 printf("Case %d: %d\n",++ii,re );



}
 
int main()
{
	int t=1;
	func("",0,0);
	cal();
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
