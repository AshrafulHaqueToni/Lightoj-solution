// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 505
#define N 500
#define ll unsigned int
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k;
vector<pair<int,pair<int,int>>>v;
struct BIT
{
    int Tree[N+5][N+5];
    void init()
    {
    	memset(Tree,0,sizeof(Tree));
    }
    ll query(int idx,int idy)
    {
        ll re=0;
        int tem=idy;
        while(idx)
        {
        	idy=tem;
        	while(idy)
        	{
                re+=Tree[idx][idy];
                idy-=idy&-idy;
            }
            idx-=idx&-idx;
        }
        return re;
    }
    void update(int idx,int idy,ll val)
    {
    	int tem=idy;
        while(idx<=N)
        {
        	idy=tem;
        	while(idy<=N)
        	{
                Tree[idx][idy]+=val;
                idy+=idy&-idy;
            }
            idx+=idx&-idx;
        }
    }
};

BIT bit;
 
void solve()
{
	scanf("%d",&n);
	v.clear();
	bit.init();
	for(int i=1;i<=n;i++)scanf("%d",&ar[i]);
	ii++;
    ll re=0;
    for(int i=1;i<=n;i++)
    {
    	for(int j=i+1;j<=n;j++)
    	{
    		v.push_back({ar[i]+ar[j],{i,j}});
    	}
    }
    sort(v.begin(),v.end(),[](pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){
    	if(a.first==b.first)return (a.second.second-a.second.first)>(b.second.second-b.second.first);
    	return a.first<b.first;
    });
    for(auto it:v)
    {
    	//cout<<it.second.first<<" "<<it.second.second<<endl;
    	int l=it.second.first;
    	int r=it.second.second;
    	ll ace=1;
    	ace+=bit.query(r-1,r-1);
    	ace-=bit.query(r-1,l);
    	ace-=bit.query(l,r-1);
    	ace+=bit.query(l,l);
    	bit.update(it.second.first,it.second.second,ace);
    	re+=ace;
    }
	printf("Case %d: %u\n",ii,re );
}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
