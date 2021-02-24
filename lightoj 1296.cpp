// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 200005
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k;



int func(int id)
{
	if(id==1)return 0;

	if(id&1)return func(id/2);

	else return id/2;


}
 
void solve()
{
	 scanf("%d",&n);
	 int re=0;
	 for(int i=1;i<=n;i++)
	 {
	 	int x;
	 	scanf("%d",&x);
	 	re^=func(x);
	 }

	 if(re)printf("Case %d: Alice\n",++ii );
	 else printf("Case %d: Bob\n",++ii );
}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
