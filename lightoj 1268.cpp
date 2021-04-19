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

vector<int> Create_Pi_Table(const char* s)
{
	int sz=strlen(s);
	vector<int>pi(sz);
	for(int i=1;i<sz;i++)
	{
	       int j=pi[i-1];
	       while(j>0 && s[i]!=s[j])j=pi[j-1];
	       if(s[j]==s[i])j++;
	       pi[i]=j;
	}
	return pi;
}

char ch[MAX],ch1[MAX];
int ii;
 
void solve()
{
	int n;
	scanf("%d%s%s",&n,ch1,ch);
	int len=strlen(ch);
	int len1=strlen(ch1);
	vector<int>pi=Create_Pi_Table(ch);
	Matrix A(len,len),B(len,1);

	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len1;j++)
		{
			int id=i;
			while(id>0 && ch[id]!=ch1[j])id=pi[id-1];
			if(ch[id]==ch1[j])id++;
			if(id<len)A.m[i+1][id+1]++;
		}
	}

	A=Power(A,n);

	for(int i=1;i<=len;i++)B.m[i][1]=1;
	Matrix re=Multiply(A,B);

    printf("Case %d: %u\n",++ii,re.m[1][1] );

}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
