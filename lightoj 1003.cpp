#include<bits/stdc++.h>
using namespace std;

vector<int>g[20005];
int n,m;
int visit[20005];
int cnt;
bool f;

void dfs(int u)
{
	visit[u]=1;
	for(auto v:g[u])
	{
		if(visit[v]==1)
		{
			f=true;
			return ;
		}
		dfs(v);
	}
	visit[u]=2;
}



void solve(int ii)
{
	for(int i=0;i<=20005;i++){
	g[i].clear();
    } 
	memset(visit,0,sizeof(visit)); 
	map<string,int>mp;
	
	cnt=0;
	f=false;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		string ch,ch1;
		cin>>ch>>ch1;
		if(mp.find(ch)==mp.end())
		{
			mp[ch]=cnt;
			cnt++;
			
		}
		if(mp.find(ch1)==mp.end())
		{
			mp[ch1]=cnt;
			cnt++;
		}
		
		g[mp[ch]].push_back(mp[ch1]);
	}
	
	for(int i=0;i<cnt;i++)
	{
		if(visit[i]==0)
		dfs(i);
	}
	if(f==true)
		{
			printf("Case %d: No\n",ii);
			return;
		}
	printf("Case %d: Yes\n",ii);
}

int main()
{
	//freopen("input.txt","r",stdin);
	int t=1;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)solve(i);
	return 0;
}
