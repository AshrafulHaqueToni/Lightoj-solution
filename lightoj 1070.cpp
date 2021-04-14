// Created by ash_98


/* Key Idea:
  (a+b)^2=a^2+b^2+2ab----(1)
  a^2+b^2=(a+b)^2-2ab

  (a+b)^3=a^3+b^3+3ab(a+b)
  a^3+b^3=(a+b)(a+b)^2-3ab(a+b)
  a^3+b^3=(a+b)((a+b)^2-3ab)
  a^3+b^3=(a+b)(a^2+b^2+2ab-3ab)  [from 1 no. equ]
  a^3+b^3=(a+b)((a^2+b^2)-ab)
  a^3+b^3=(a+b)(a^2+b^2)-(ab*(a+b)) [here a^2+b^2's  result known from previous equation]

  a^4+b^4=(a+b)(a^3+b^3)-(ab(a^2+b^2))

  So, we can say that F(n)=(a+b)*F(n-1)-(ab*F(n-2))
 */


#include<bits/stdc++.h>
using namespace std;
#define MAX 4
#define ll unsigned long long 

struct Matrix{
    int row, col;
    ll m[MAX][MAX];
    Matrix() {memset(m,0,sizeof(m));}
    void Set(int r,int c) {row = r; col = c;}
    Matrix(int r,int c) {memset(m,0,sizeof(m)); Set(r,c);}
    void normalize(){
        for(int i=1; i<=row; i++){
            for(int j=1; j<=col; j++){
                // m[i][j] %= MOD;
                // if(m[i][j] < 0) m[i][j] += MOD;
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
	 int n;
	 ll a,b;
	 scanf("%lld%lld%d",&a,&b,&n);
	 Matrix A(2,2);
	 A.m[1][1]=a;
	 A.m[1][2]=-b;
	 A.m[2][1]=1;
	 Matrix B(2,1);
	 B.m[1][1]=a;
	 B.m[2][1]=2;
	 if(n==0)
	 {
	 	printf("Case %d: 2\n",++ii );
	 }
	 else if(n==1)
	 {
	 	printf("Case %d: %lld\n",++ii,a );
	 }
	 else
	 {
	 	Matrix re=Multiply(Power(A,n-1),B);
	 	printf("Case %d: %llu\n",++ii,re.m[1][1]);
	 }


}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
