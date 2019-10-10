//***Bismillahir Rahmanir Rahim***//

//*********************************//
//******Ashraful Haque Toni********//
//********Dept. of CSE,JnU*********//
//email:ashrafulhaquetoni@gmail.com//
//*******contact:01640690531*******//
//*********************************//


#include<bits/stdc++.h>

using namespace std;

#define         ash ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define         pb push_back
#define         sc scanf
#define         pf printf
#define         Max(x,y) max(x,y)?x:y;
#define         Min(x,y) min(x,y)?x:y;
#define         input(array,size) for(int i=0;i<size;i++)cin>>array[i];
#define         newline pf("\n");


typedef long long ll;


vector<int>v[1000];
int dis[1000],dis1[1000];
int node,k,kk,cnt;

void bfs(int startnode,int dis[])
{
    queue<int>q;
    vector<int>color(1000,1);
    q.push(startnode);
    dis[startnode]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        color[x]=2;
        for(int i=0; i<v[x].size(); i++)
        {
            if(color[v[x][i]]==1)
            {
                q.push(v[x][i]);
                color[v[x][i]]=2;
                    dis[v[x][i]]=dis[x]+1;
            }
        }
    }



}

int main()
{
   // ash;
    //freopen("bfs.txt","r",stdin);
    int t;
    sc("%d",&t);
    while(t--)
    {
        int edge;
        sc("%d %d",&node,&edge);
        for(int i=0; i<edge; i++)
        {
            int a1,a2;
            cin>>a1>>a2;

            v[a1].pb(a2);
            v[a2].pb(a1);
        }

        int st,en;
        cin>>st>>en;

        memset(dis,-1,sizeof(dis));
        bfs(st,dis);


        memset(dis1,-1,sizeof(dis1));
        bfs(en,dis1);


        int ma=INT_MIN;

        for(int i=0;i<node;i++)ma=max(ma,dis[i]+dis1[i]);


        pf("Case %d: %d\n",++kk,ma);


        for(int i=0; i<1000; i++)
            v[i].clear();
    }


    return 0;
}



