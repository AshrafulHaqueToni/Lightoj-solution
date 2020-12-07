// Created by ash_98

#include<bits/stdc++.h>
using namespace std;

#define mx 200005
#define ll long long
#define mod 1000000007

int ar[mx][2];
int last[mx];
ll dp[mx];
int piche[mx];
char ch[mx];
int n,m,ii,k;

namespace Segment_Tree
{
	const int N=200005;
	ll Tree[N*4];
	ll Lazy[mx*4];

	void Relax(int node,int be,int en)
	{
		//if(!Lazy[node])return;

		Tree[node]+=Lazy[node];
		if(be!=en)
		{
			Lazy[node*2]+=Lazy[node];
			Lazy[node*2+1]+=Lazy[node];
		}
		Lazy[node]=0;
	}

	void init(int node,int be,int en)
	{
		Lazy[node]=0;
        if(be==en)
        {
        	Tree[node]=0;
        	return;
        }
        int mid=(be+en)/2;
        init(node*2,be,mid);
        init(node*2+1,mid+1,en);
        Tree[node]=min(Tree[node*2],Tree[node*2+1]);
	}

	void update(int node,int be,int en,int pos,ll val)
	{
		Relax(node,be,en);
		if(be> pos || en<pos)return;
		if(be==en)
		{
			Tree[node]=val;
			return;
		}
		int mid=(be+en)/2;
		update(node*2,be,mid,pos,val);
		update(node*2+1,mid+1,en,pos,val);
		Tree[node]=min(Tree[node*2],Tree[node*2+1]);
	}

	void Rupdate(int node,int be,int en,int i,int j,ll val)
	{
		Relax(node,be,en);
		if(be>j || en<i)return ;
		if(be>=i && en<=j)
		{
			Lazy[node]+=val;
			Relax(node,be,en);
			return;
		}
		int mid=(be+en)/2;
		Rupdate(node*2,be,mid,i,j,val);
		Rupdate(node*2+1,mid+1,en,i,j,val);
		Tree[node]=min(Tree[node*2],Tree[node*2+1]);
	}

	ll query(int node,int be,int en,int i,int j)
	{
		Relax(node,be,en);
		if(be>j || en<i)return 1e15;
		if(be>=i && en<=j)return Tree[node];
		int mid=(be+en)/2;
		return min(query(node*2,be,mid,i,j),query(node*2+1,mid+1,en,i,j));
	}

	void dbg_test(int node,int be,int en)
	{
		if(be==en)return;
		int mid=(be+en)/2;
		dbg_test(node*2,be,mid);
		dbg_test(node*2+1,mid+1,en);
	}
}

using namespace Segment_Tree;

void solve()
{
	memset(last,0,sizeof(last));
	scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&ar[i][0],&ar[i][1]);
    int prv=1;
    for(int i=1;i<=n;i++)
    {
    	prv=max(prv,last[ar[i][0]]+1);
    	piche[i]=prv;
    	last[ar[i][0]]=i;
    }

    init(1,1,n);

    stack<int>st;
    ar[0][1]=1e9;
    st.push(0);

    for(int i=1;i<=n;i++)
    {
       while(ar[st.top()][1]<ar[i][1])
       {
       	  int y=st.top();
       	  st.pop();
       	  int x=st.top()+1;
       	  Rupdate(1,1,n,x,y,-ar[y][1]);
       }

       Rupdate(1,1,n,st.top()+1,i,ar[i][1]);

       dp[i]=query(1,1,n,piche[i],i);

       update(1,1,n,i+1,dp[i]);

       st.push(i);
    }

    printf("Case %d: %lld\n",++ii,dp[n]);


}

int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
