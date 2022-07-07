// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 55
#define ll unsigned long long
#define mod 1000000007 //998244353
 
ll dp_big[mx][mx];
ll dp_small[mx][mx];
int n,m,ii,k;

void pre(){
	dp_small[1][1]=1;
	dp_big[1][1]=1;

	for(int i=2;i<=50;i++){
		for(int j=1;j<=i;j++){
			for(int l=j;l<i;l++)dp_big[i][j]+=dp_small[i-1][l];
			for(int l=1;l<j;l++)dp_small[i][j]+=dp_big[i-1][l];
		}
	}
}
 
void solve()
{
    scanf("%d%d",&n,&m);
    ll re=0;
    if(m>1)
    {
    	for(int i=1;i<m;i++)re+=dp_big[n-1][i];

    }
	else{
		re=dp_small[n-1][2];
	}
	if(n<=2)re=1;
	printf("Case %d: %llu\n",++ii,re );
 
}
 
int main()
{
    int t=1;
    pre();
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
