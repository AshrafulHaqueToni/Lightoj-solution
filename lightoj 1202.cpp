#include<bits/stdc++.h>
using namespace std;

#define ll long long



void solve(int ii)
{
	int n,m,x,y;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	printf("Case %d: ",ii);
	if(abs(n-x)==abs(m-y))printf("1\n");
	else
	{
		if(abs(n-x)%2==abs(m-y)%2)printf("2\n");
		else printf("impossible\n");
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)solve(i);
	return 0;
}
