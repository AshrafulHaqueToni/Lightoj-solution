#include<bits/stdc++.h>
using namespace std;

#define ll long long

int func(int val)
{
	if(val==0)return 0;
	int re=val/3;
	re*=2;
	if(val%3==2)re++;
	return re;
}

void solve(int ii)
{
	int n,m;
	scanf("%d%d",&n,&m);
	printf("Case %d: %d\n",ii,func(m)-func(n-1));
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)solve(i);
	return 0;
}
