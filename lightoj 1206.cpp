// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 1005
#define ll long long
int n,m,ii,k;
struct BPM
{
	bool Done[mx];
    vector<int>g[mx];
    int Left[mx],Right[mx];
    void Done_Restore()
    {
      memset(Done,0,sizeof Done);
    }
    void addEdge(int u,int v)
    {
        g[u].push_back(v);
    }
    void init()
    {
        for(int i=0;i<mx;i++)g[i].clear();
        memset(Done,0,sizeof Done);
        memset(Left,-1,sizeof Left);
        memset(Right,-1,sizeof Right);
    }
    bool Bipar_Matching(int u)
    {
        for(int &v: g[u])
        {
            if(Done[v]) continue;
            Done[v] = true;
            if(Right[v]==-1 || Bipar_Matching(Right[v]))
            {
                Left[u] = v;
                Right[v] = u;
                return true;
            }
        }
        return false;
    }
    int Matching(int num)
    {
	// Be Careful with this section. when passin num.
        memset(Left,-1,sizeof Left);
        memset(Right,-1,sizeof Right);
        int re = 0;
        for(int i = 1; i <=num; i++)
        {
            memset(Done,0,sizeof Done);
            if(Bipar_Matching(i)) re++;
        }
        return re;
    }
 
 
};

BPM bp;
struct info
{
	int Ti,xi,yi,xf,yf;
};
char ch[mx];
void solve()
{
	 vector<info>v;
	 scanf("%d",&n);
	 bp.init();
	 for(int i=1;i<=n;i++)
	 {
	 	int xi,xf,yi,yf;
	 	scanf("%s%d%d%d%d",ch,&xi,&yi,&xf,&yf);
	 	int limit=((ch[0]-'0')*10+(ch[1]-'0'))*60+((ch[3]-'0')*10)+(ch[4]-'0');
	 	v.push_back({limit,xi,yi,xf,yf});

	 }

	 for(int i=0;i<n-1;i++)
	 {
	 	for(int j=i+1;j<n;j++)
	 	{
	 		int need=v[i].Ti+abs(v[i].xi-v[i].xf)+abs(v[i].yi-v[i].yf)+abs(v[i].xf-v[j].xi)+abs(v[i].yf-v[j].yi);
	 		if(need<v[j].Ti)bp.addEdge(i+1,j+n+1);

	 	}
	 }
	 

	 printf("Case %d: %d\n",++ii,n-bp.Matching(n) );


}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
