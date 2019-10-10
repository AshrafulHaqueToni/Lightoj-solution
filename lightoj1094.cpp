//***Bismillahir Rahmanir Rahim***//

//*********************************//
//******Ashraful Haque Toni********//
//********Dept. of CSE,JnU*********//
//email:ashrafulhaquetoni@gmail.com//
//*******contact:01640690531*******//
//*********************************//


#include<bits/stdc++.h>

using namespace std;

#define         ash ios_base::sync_with_stdio(0);
#define         pb push_back
#define         sc(n) scanf("%d",&n);
#define         scl(n) scanf("%I64d",&n);
#define         sc2(m,n) scanf("%d%d",&m,&n);
#define         sc2l(m,n) scanf("%I64d%I64d",&m,&n);
#define         pf printf
#define         Big(x,y) max(x,y);
#define         Small(x,y) min(x,y);
#define         input(array,size) for(int i=0;i<size;i++)cin>>array[i];
#define         newline pf("\n");
#define         f(s,l,in) for(ll i=s;i<l;i+=in)
#define         Max INT_MAX
#define         Min INT_MIN
#define         pi acos(-1.0)
#define         Memset(a,val) memset(a,val,sizeof(a));

typedef long long ll;
vector<int>v[30005];
vector<int>weight[30005];
int color[30005],dis[30005];
int value,node,edge;

void cc()
{
    for(int z=0; z<=node; z++)
        {
            v[z].clear();
            weight[z].clear();
        }

}

int bfs(int startnode)
{
    Memset(color,-1);
    Memset(dis,0);

    int maxx=0,pos;

    queue<int>q;
    q.push(startnode);
    dis[startnode]=0;
    color[startnode]=0;

    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        color[x]=0;
        //cout<<x;
        for(int i=0; i<v[x].size(); i++)
        {
            int d=v[x][i];
            if(color[d]!=0)
            {
                color[d]=0;
                dis[d]=dis[x]+weight[x][i];
                q.push(d);
                if(maxx<dis[d])
                {
                    maxx=dis[d];
                    pos=d;
                }
            }
        }
    }

    return pos;
}

int main()
{
    //ash;
    int t;
    sc(t);
    for(int i=1; i<=t; i++)
    {
        sc(node);
        cc();

        for(int j=0; j<node-1; j+=1)
        {
            int a,b,w;
            sc2(a,b);
            sc(w);
            v[a].pb(b);
            v[b].pb(a);
            weight[a].pb(w);
            weight[b].pb(w);
        }
        int zz=bfs(0);
        int fr=bfs(zz);
        pf("Case %d: %d\n",i,dis[fr]);

    }





    return 0;
}


