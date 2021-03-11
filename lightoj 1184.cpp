// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 105
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
struct BIO
{
	int h,a,d;
};
void solve()
{
	 vector<BIO>men,women;
	 scanf("%d%d",&n,&m);
	 bp.init();
	 for(int i=1;i<=n;i++)
	 {
	 	int x,y,z;
	 	scanf("%d%d%d",&x,&y,&z);
	 	men.push_back({x,y,z});
	 }
	 for(int i=1;i<=m;i++)
	 {
	 	int x,y,z;
	 	scanf("%d%d%d",&x,&y,&z);
	 	women.push_back({x,y,z});
	 }

	 for(int i=0;i<n;i++)
	 {
	 	for(int j=0;j<m;j++)
	 	{
	 		if(men[i].d==women[j].d && abs(men[i].a-women[j].a)<=5 && abs(men[i].h-women[j].h)<=12)
	 		{
                bp.addEdge(i+1,j+1+n);
	 		}
	 	}
	 }

	 printf("Case %d: %d\n",++ii,bp.Matching(n) );


}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
