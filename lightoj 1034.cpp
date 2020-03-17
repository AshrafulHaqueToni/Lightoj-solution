#include<bits/stdc++.h>
using namespace std;

vector<int>g[10005];
int n,m;
bool visit[10005];
stack<int>st;

void dfs(int u)
{
	visit[u]=true;
	for(auto v:g[u])
	{
		if(visit[v]==true)continue;
		dfs(v);
	}
	st.push(u);
}

void dfs1(int u)
{
	visit[u]=true;
	for(auto v:g[u])
	{
		if(visit[v]==true)continue;
		dfs1(v);
	}
}

void solve(int ii)
{
	memset(visit,false,sizeof(visit));
	for(int i=1;i<=n;i++)g[i].clear();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
	}
	
	for(int i=1;i<=n;i++)
	{
		if(visit[i])continue;
		dfs(i);   ///for topological sort
	}
	
	memset(visit,false,sizeof(visit));
	
	
	int re=0;
	while(!st.empty())
	{
		int u=st.top();
		st.pop();
		if(visit[u]==true)continue;
		dfs1(u);
		re++;
	}
	printf("Case %d: %d\n",ii,re);
}

int main()
{
//	freopen("input.txt","r",stdin);
	int t=1;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)solve(i);
	return 0;
}
