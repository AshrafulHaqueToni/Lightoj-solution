// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 25
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx][mx];
int n,m,k,ii;
vector<pair<int,int>>v;
int dist[mx][mx][mx][mx];
int xx[]={1,1,0,0,-1,1,-1,-1};
int yy[]={-1,1,1,-1,0,0,1,-1};
int dp[(1<<15)+5][16];
int vis[(1<<15)+5][16];
int stx,sty;

int Set(int N,int pos)
{
    return N=N|(1<<pos);
}

int Reset(int N,int pos)
{
    return N=N & ~(1<<pos);
}

bool chk(int N,int pos)
{
    return (bool)(N &(1<<pos));
}

void dijkstra(int x,int y)
{
   dist[x][y][x][y]=0;
   priority_queue<pair<int,pair<int,int>>>pq;
   pq.push({0,{x,y}});
   while(!pq.empty())
   {
   	  int cost=pq.top().first;
   	  cost*=-1;
   	  int a=pq.top().second.first;
   	  int b=pq.top().second.second;
   	  pq.pop();
   	  if(dist[x][y][a][b]<cost)continue;
   	  for(int i=0;i<8;i++)
   	  {
   	  	  int temx=a+xx[i];
   	  	  int temy=b+yy[i];
   	  	  if(temx>0 && temx<=n && temy>0 && temy<=m && dist[x][y][temx][temy]>cost+1)
   	  	  {
             dist[x][y][temx][temy]=cost+1;
             pq.push({-dist[x][y][temx][temy],{temx,temy}});
   	  	  }
   	  }
   }
}

int func(int mask,int last)
{
	if(mask==(1<<k)-1)return dist[v[last].first][v[last].second][stx][sty];
	if(vis[mask][last]==ii)return dp[mask][last];
	vis[mask][last]=ii;
	int re=1e6;
	for(int i=0;i<k;i++)
	{
		if(!chk(mask,i))
		{
			int cost=0;
			if(mask==0)cost=dist[stx][sty][v[i].first][v[i].second];
			else cost=dist[v[last].first][v[last].second][v[i].first][v[i].second];
			re=min(re,cost+func(Set(mask,i),i));
		}
	}
	return dp[mask][last]=re;
}

void solve()
{
   scanf("%d%d",&n,&m);
   v.clear();
   for(int i=1;i<=n;i++)scanf("%s",ch[i]+1);
   for(int i=1;i<=n;i++)
   {
   	  for(int j=1;j<=m;j++)
   	  {
   	  	if(ch[i][j]=='g')v.push_back({i,j});
   	  	if(ch[i][j]=='x')stx=i,sty=j;
   	  }
   }
   for(int i=1;i<=n;i++)
   {
   	  for(int j=1;j<=m;j++)
   	  {
   	  	for(int l=1;l<=n;l++)
   	  	{
   	  		for(int z=1;z<=m;z++)dist[i][j][l][z]=1e6;
   	  	}
   	  }
   }



   for(int i=1;i<=n;i++)
   {
   	  for(int j=1;j<=m;j++)
   	  {
   	  	dijkstra(i,j);
   	  }
   }
   //  for(int i=1;i<=n;i++)
   // {
   // 	  for(int j=1;j<=m;j++)
   // 	  {
   // 	  	for(int l=1;l<=n;l++)
   // 	  	{
   // 	  		for(int z=1;z<=m;z++)
   // 	  		{
   // 	  			cout<<i<<" "<<j<<" "<<l<<" "<<z<<" "<<dist[i][j][l][z]<<endl;
   // 	  		}
   // 	  	}
   // 	  }
   // }
   ii++;
   k=v.size();
   if(v.size()==0)printf("Case %d: 0\n",ii );
   else  printf("Case %d: %d\n",ii,func(0,0));
    
}

int main()
{
  int t=1;
  scanf("%d",&t);
  while(t--)
  {
    solve();
  }

  return 0;
}
