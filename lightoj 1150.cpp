// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 105
#define ll long long
int n,m,ii,k;

struct BPM
{
	bool Done[mx];
    vector<pair<int,int>>g[mx];
    int Left[mx],Right[mx];
    void Done_Restore()
    {
      memset(Done,0,sizeof Done);
    }
    void addEdge(int u,int v,int w)
    {
        g[u].push_back({v,w});
    }
    void init()
    {
        for(int i=0;i<mx;i++)g[i].clear();
        memset(Done,0,sizeof Done);
        memset(Left,-1,sizeof Left);
        memset(Right,-1,sizeof Right);
    }
    bool Bipar_Matching(int u,int Limit)
    {
        for(auto it: g[u])
        {
        	int v=it.first;
        	int cost=it.second;
            if(Done[v] || cost>Limit) continue;
            Done[v] = true;
            if(Right[v]==-1 || Bipar_Matching(Right[v],Limit))
            {
                Left[u] = v;
                Right[v] = u;
                return true;
            }
        }
        return false;
    }
    bool Matching(int num,int Limit)
    {
	// Be Careful with this section. when passin num.
        memset(Left,-1,sizeof Left);
        memset(Right,-1,sizeof Right);
        int re = 0;
        for(int i = 1; i <=num; i++)
        {
            memset(Done,0,sizeof Done);
            if(!Bipar_Matching(i,Limit)) return false;
        }
        return true;
    }
 
 
};

BPM bp;


int ar[mx];
int br[mx];

map<pair<int,int>,int>mp;
char ch[26][26];
bool vis[26][26];
int xx[]={1,-1,0,0};
int yy[]={0,0,1,-1};

void dfs(int r,int c)
{
	int id=mp[{r,c}];
	memset(vis,false,sizeof(vis));
	vis[r][c]=true;
	queue<pair<int,int>>q;
	queue<int>dist;
	q.push({r,c});
	dist.push(0);
	
	while(!q.empty())
	{
		int u=q.front().first;
		int v=q.front().second;
		int cost=dist.front();
		q.pop();
		dist.pop();

		for(int l=0;l<4;l++)
		{
			int x=u+xx[l];
			int y=v+yy[l];
			if(x>=0 && x<n && y>=0 && y<n && ch[x][y]!='#' && vis[x][y]==false)
			{

                vis[x][y]=true;
                if(ch[x][y]=='G')bp.addEdge(id,mp[{x,y}],cost+1);
                q.push({x,y});
                dist.push(cost+1);
			}
		}
	}

}

 
void solve()
{
	 
	 scanf("%d",&n);

	 for(int i=0;i<n;i++)scanf("%s",ch[i]);

	 bp.init();
	 mp.clear();

	 int Human=0,Gost=0;

	 for(int i=0;i<n;i++)
	 {
	 	for(int j=0;j<n;j++)
           if(ch[i][j]=='H')mp[{i,j}]=++Human;
	 }
	 for(int i=0;i<n;i++)
	 {
	 	for(int j=0;j<n;j++)
           if(ch[i][j]=='G')mp[{i,j}]=++Gost+Human;
	 }

	 for(int i=0;i<n;i++)
	 {
	 	for(int j=0;j<n;j++)
	 	{
	 		if(ch[i][j]=='H')dfs(i,j);
	 	}
	 }

	 int be=1,en=500000;
	 int re=-1;
	 while(be<=en)
	 {
        int mid=(be+en)/2;
        if(bp.Matching(Human,mid))
        {
        	re=mid;
        	en=mid-1;
        	//cout<<re<<endl;
        }
        else be=mid+1;
	 }


	
	 printf("Case %d: ",++ii);
	 if(re==-1)printf("Vuter Dol Kupokat\n");
	 else printf("%d\n",re*2+2);

}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
