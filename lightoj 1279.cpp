// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll A[105][105];
ll X[105];
int Rank;
int NoSol;

ll gcdExtended(ll a, ll b, ll& x, ll& y){
    if(a==0) {x=0;y=1; return b;}
    ll x1,y1;
    ll gcd = gcdExtended(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return gcd;
}

ll modinverse(ll x,ll y) {ll a,b; gcdExtended(x,y,a,b); return a;}

//n equations (n rows), m variables (m+1 columns)
void Gauss(int n,int m,int k){
    int r,c;
    for(r=0,c=0;r<n && c<m;c++){
        for(int i=r+1;i<n;i++) if(abs(A[i][c])>abs(A[r][c])) swap(A[i],A[r]);
        if(!abs(A[r][c])) continue;
        ll s = modinverse(A[r][c],k);
        for(int i=r+1;i<n;i++) if(abs(A[i][c])){
            ll w = (s*A[i][c])%k;
            /* s bhag hobe r A[i][c] gun hobe*/
            for(int j=c;j<=m;j++){A[i][j]-=(A[r][j]*w)%k; A[i][j]%=k; if(A[i][j]<0) A[i][j]+=k;}
        }
        r++;
    }
    Rank = r;
    for(int i=r;i<n;i++) if(A[i][m]) return;  //No solution

    //Unique Solution for r variables
    for(int i=r-1;i>=0;i--){
        X[i]=A[i][m];
        for(int j=i+1;j<m;j++) {X[i]-=(A[i][j]*X[j])%k; X[i]%=k; if(X[i]<0) X[i]+=k;}

        ll inv=modinverse(A[i][i],k);
        X[i]=(X[i]*inv)%k; if(X[i]<0) X[i]+=k;
    }
}


ll bigmod(ll e,ll x)
{
    if(!x)return 1;
    ll p=bigmod(e,x/2);
    p=(p*p)%mod;
    if(x%2)p=(p*e)%mod;
    return p;
}

int ii;
 
void solve()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<=101;j++)
		{
			if(i==j)A[i][j]=1;
			else A[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--,y--;
		A[x][y]=k-1; //-1 mod k
		A[y][x]=k-1; //-1 mod k
	}

	Gauss(n,n,k);
	ll re=0;
	re=bigmod(k,n-Rank);
    printf("Case %d: %lld\n",++ii,re);

}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
