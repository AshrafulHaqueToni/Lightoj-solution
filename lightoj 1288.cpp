// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll A[65][1005];
int Rank;

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
      //  ll s = modinverse(A[r][c],k);
        for(int i=r+1;i<n;i++) if(abs(A[i][c])){
          //  ll w = (s*A[i][c])%k;
            /* s bhag hobe r A[i][c] gun hobe*/
            for(int j=c;j<=m;j++){A[i][j]^=(A[r][j]); }
        }
        r++;
    }
    Rank = r;

}


int ii;

vector<int>prime;
bool chk[305];

void pre()
{
	for(int i=2;i<=300;i++)
	{
		if(chk[i]==0)
		{
			prime.push_back(i);
			for(int j=i*i;j<=300;j+=i)chk[j]=1;
		}
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



 
void solve()
{
	int n,m,k;
	scanf("%d",&m);
	n=prime.size();

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			A[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		ll x;
		scanf("%lld",&x);
		for(int j=0;j<n;j++)
		{
			int jabe=0;
			while(x%prime[j]==0)
			{
				x/=prime[j];
				jabe^=1;
			}
			A[j][i-1]=jabe;
		}
	}

	Gauss(n,m,2);
	ll re=bigmod(2,m-Rank);
	re-=1;
	if(re<0)re+=mod;
    printf("Case %d: %lld\n",++ii,re);

}
 
int main()
{
	int t=1;
	pre();
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
