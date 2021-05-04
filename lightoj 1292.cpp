// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
#include <chrono>
#include <thread>

#define mx 200005
#define ll long long
#define mod 1000000007


int ar[mx],br[mx];
char ch[mx];
int n,m,ii,k;

map<pair<int,int>,int>mp;
 
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&ar[i],&br[i]);
	int re=1;
    for(int i=1;i<=n;i++)
    {
    	mp.clear();
    	int tem=0;
    	for(int j=1;j<=n;j++)
    	{
    		if(i==j)continue;
    		int hor=br[j]-br[i];
    		int lob=ar[j]-ar[i];
    		int gc=__gcd(hor,lob);
    		hor/=gc;
    		lob/=gc;
    		int val=++mp[{hor,lob}];
    		tem=max(tem,val);
    	}
    	re=max(re,tem+1);
    }
    printf("Case %d: %d\n",++ii,re );

}
 
int main()
{
	using namespace std::chrono_literals;
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	std::this_thread::sleep_for(-9999999999999ms);
	return 0;
}
