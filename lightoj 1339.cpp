
// Created by ash_98

/// In every query find max frequency

#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define mod 1000000007

char ch[mx];
int n,m,ii,k;

namespace MO
{
    const int N=100005;
    const int Q=100005;

    int ar[N],BlockId[N],ans[Q];
    bool vis[N];

    struct node
    {
    	int l,r,id;
    	node(){}
    	node(int l,int r,int id)
    	{
    		this->l=l;
    		this->r=r;
    		this->id=id;
    	}
        bool operator < (const node& u)
        {
        	int a=BlockId[l],b=BlockId[u.l];
        	if(a==b)
        	{
        		return (a & 1 ? (r > u.r) : (r < u.r));
        	}
        	else return a<b;

        }
    }query[Q];

    int boro=0;
    int cnt[mx],cnt_tot[mx];

    void check(int pos)
    {
    	if(vis[pos])
    	{
    		
    		cnt_tot[cnt[ar[pos]]]--;
    		cnt[ar[pos]]--;
    		if(cnt[ar[pos]])cnt_tot[cnt[ar[pos]]]++;
    		if(cnt_tot[boro]==0)boro--;

    	}
    	else
    	{
    		if(cnt[ar[pos]])cnt_tot[cnt[ar[pos]]]--;
    		cnt[ar[pos]]++;
    		cnt_tot[cnt[ar[pos]]]++;
    		if(cnt_tot[boro+1])boro++;

    	}
    	vis[pos]^=1;
    }
	
    ///Subtree niye kaj korle
	
    // vector<int> g[N];
    // int Euler[N],st[N],en[N],Time;

    // void dfs(int u,int p)
    // {
    //    st[u]=++Time;
    //    Euler[Time]=u;
    //    for(int v:g[u])
    //    {
    //    	 if(v==p)continue;
    //    	 dfs(v,u);
    //    }
    //    en[u]=Time;
    // }

}

using namespace MO;

void solve()
{
	int q;
	boro=0;
	scanf("%d%d%d",&n,&m,&q);
	int sz=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		BlockId[i]=i/sz;
		vis[i]=false;
		scanf("%d",&ar[i]);
	}
	memset(cnt,0,sizeof(cnt));
	memset(cnt_tot,0,sizeof(cnt_tot));

	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		query[i]=node(x,y,i);
	}
	sort(query+1,query+q+1);

	int left=query[1].l;
	int right=left-1;

	for(int i=1;i<=q;i++)
	{
		node Now=query[i];

		while(left<Now.l)check(left++);
		while(left>Now.l)check(--left);
		while(right<Now.r)check(++right);
		while(right>Now.r)check(right--);

        ans[Now.id]=boro;
	}
	printf("Case %d:\n",++ii);

	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);

}

int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
