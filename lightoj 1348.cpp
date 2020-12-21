// Created by ash_98

#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx];
int n,m,ii,k;

int par[mx][25];
int depth[mx];
vector<int>g[mx];
int LOG,T;
int st[mx],sesh[mx];

void dfs(int u,int p,int lvl)
{
    par[u][0]=p;
    depth[u]=lvl;
    st[u]=++T;

    for(auto v:g[u])
    {
        if(v==p)continue;
        dfs(v,u,lvl+1);
    }

    sesh[u]=++T;
}

void build(int root)
{
    dfs(root,-1,1);

    for(int j=1;j<LOG;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(par[i][j-1]!=-1)
            {
                par[i][j]=par[par[i][j-1]][j-1];
            }
            else par[i][j]=-1;
        }
    }
}

int lca(int u,int v)
{
    if(depth[u]<depth[v])swap(u,v);
    int log=1;
    while(1)
    {
        int next=log+1;
        if(depth[u]<(1<<next))break;
        log++;
    }

    for(int i=log;i>=0;i--)
    {
        if(depth[u]-(1<<i)>=depth[v])
        {
            u=par[u][i];
        }
    }
    if(u==v)return u;

    for(int i=log;i>=0;i--)
    {
        if(par[u][i]!=-1 && par[u][i]!=par[v][i])
        {
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[v][0];
}

namespace Segment_Tree
{
	const int N=100005;
	int Tree[N*4];
	int Lazy[mx*4];
	int br[N];

	void Relax(int node,int be,int en)
	{
		if(!Lazy[node])return;

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
		//Lazy[node]=0;
        if(be==en)
        {
        	Tree[node]=br[be];
        	return;
        }
        int mid=(be+en)/2;
        init(node*2,be,mid);
        init(node*2+1,mid+1,en);
        Tree[node]=Tree[node*2]+Tree[node*2+1];
	}

	void update(int node,int be,int en,int pos,int val)
	{
		//Relax(node,be,en);
		if(be> pos || en<pos)return;
		if(be==en)
		{
			Tree[node]=val;
			return;
		}
		int mid=(be+en)/2;
		update(node*2,be,mid,pos,val);
		update(node*2+1,mid+1,en,pos,val);
		Tree[node]=Tree[node*2]+Tree[node*2+1];
	}

	void Rupdate(int node,int be,int en,int i,int j,int val)
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
		Tree[node]=max(Tree[node*2],Tree[node*2+1]);
	}

	int query(int node,int be,int en,int i,int j)
	{
		//Relax(node,be,en);
		if(be>j || en<i)return 0;
		if(be>=i && en<=j)return Tree[node];
		int mid=(be+en)/2;
		return query(node*2,be,mid,i,j)+query(node*2+1,mid+1,en,i,j);
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
	scanf("%d",&n);
	LOG=log2(n)+1;
	T=1;
	for(int i=1;i<=n;i++)scanf("%d",&ar[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x++;
		y++;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	build(1);
	for(int i=1;i<=n;i++)br[st[i]]=ar[i],br[sesh[i]]=-ar[i];
	init(1,1,2*n);
    printf("Case %d:\n",++ii);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
    	int ti,x,y;
    	scanf("%d%d%d",&ti,&x,&y);
    	if(ti)
    	{
    		x++;
    		update(1,1,2*n,st[x],y);
    		update(1,1,2*n,sesh[x],-y);
    	}
    	else
    	{
    		x++,y++;
    		if(st[x]>st[y])swap(x,y);
    		int lc=lca(x,y);
    		if(lc==x)
    		{
    			printf("%d\n",query(1,1,2*n,st[x],st[y]));
    		}
    		else
    		{
    			printf("%d\n",query(1,1,2*n,st[lc],st[x])+query(1,1,2*n,st[lc]+1,st[y]));
    		}
    	}
    }

    for(int i=1;i<=n;i++)g[i].clear();


}

int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
