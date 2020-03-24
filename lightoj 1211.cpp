#include<bits/stdc++.h>
using namespace std;

#define ll long long



void solve(int ii)
{
	int n;
	scanf("%d",&n);
	int ar[6],br[6];
	ar[0]=0,ar[1]=0,ar[2]=0,ar[3]=100005,ar[4]=100005,ar[5]=100005;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<6;j++)
		{
			
		scanf("%d",&br[j]);
		if(j>=3)ar[j]=min(ar[j],br[j]);
		else ar[j]=max(ar[j],br[j]);
		
	    }
		
	}
	printf("Case %d: %lld\n",ii,max(1LL*(ar[5]-ar[2])*(ar[4]-ar[1])*(ar[3]-ar[0]),0LL));

}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)solve(i);
	return 0;
}
