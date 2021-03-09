// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 405
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
char ch[25][25];
map<pair<int,int>,int>mp;
int xx[]={1,-1,0,0};
int yy[]={0,0,1,-1};

bool func(int i,int j)
{
	if(i>=0 && i<n && j>=0 && j<m && ch[i][j]=='*')return true;
	return false;
}
 
void solve()
{
	 scanf("%d%d",&n,&m);
	 bp.init();
	 mp.clear();
	 for(int i=0;i<n;i++)scanf("%s",ch[i]);

	 int id=0,re=0;
	 for(int i=0;i<n;i++)
	 {
	 	for(int j=0;j<m;j++)
	 	{
	 		if(ch[i][j]=='*')
	 		{
	 			if((i+j)%2==0)
	 			{
                    bool f=false;
                    for(int l=0;l<4;l++)
                    {
                    	int x=xx[l]+i;
                    	int y=yy[l]+j;
                    	if(func(x,y))
                    	{
                    		f=true;
                    		mp[{x,y}]=(x*m)+y+1;
                    		bp.addEdge(id+1,mp[{x,y}]);
                    	}
                    }
                    if(f)id++;
                    else re++;
	 			}
	 		}
	 	}
	 }

	 for(int i=0;i<n;i++)
	 {
	 	for(int j=0;j<m;j++)
	 	{
	 		if(ch[i][j]=='*')
	 		{
	 			if((i+j)%2==1)
	 			{
                    re++;
	 			}

	 		}
	 	}
	 }

	 re=re+id-bp.Matching(id);
	 printf("Case %d: %d\n",++ii,re );
}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
