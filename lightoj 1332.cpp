// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
#define MAX 39
#define ll unsigned int

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
               // if(sm >= MOD2) sm -= MOD2;
            }
            ans.m[i][j] = sm ;
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

int ii;
vector<pair<int,int>>v;
Matrix A(37,37),B(37,1);
vector<Matrix>Bit;

void pre()
{
	for(int i=0;i<10;i++)
	{
		for(int j=i+2;j<10;j++)
		{
			v.push_back({i,j});
		}
	}

	for(int i=0;i<36;i++)
	{
		B.m[i+2][1]=1;
		A.m[1][i+2]=1;
		for(int j=0;j<36;j++)
		{
			if(abs(v[i].first-v[j].first)>1 && abs(v[i].first-v[j].second)>1
				&& abs(v[i].second-v[j].first)>1 && abs(v[i].second-v[j].second)>1)
			{
				A.m[i+2][j+2]=1;
				//cout<<i<<" "<<j<<endl;
			}
		}
	}
	for(int i=0;i<30;i++)
	{
		Bit.push_back(Power(A,1<<i));
	}
}
int Set(int N,int pos)
{
    return N=N|(1<<pos);
}

int Reset(int N,int pos)
{
    return N=N & ~(1<<pos);
}

bool chk(int N,int pos)
{
    return (bool)(N &(1<<pos));
}

void solve()
{
	int n;
	scanf("%d",&n);
	Matrix re=B;
	for(int i=0;i<30;i++)
	{
		if(chk(n,i))
		{
			re=Multiply(Bit[i],re);
		}
	}

    printf("Case %d: %u\n",++ii,re.m[1][1]);
}
 
int main()
{
	int t=1;
	pre();
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
