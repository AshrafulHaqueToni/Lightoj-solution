#include<bits/stdc++.h>
using namespace std;

#define mx 12
#define ll long long

int ar[mx];
char ch[mx][mx];
int dis[mx][mx];
int xi,yi;
pair<int,int>pos[27];
int xx[]={1,0,-1,0};
int yy[]={0,1,0,-1};
int n,m,k,ii;

bool Is_valid(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<n && ch[x][y]!='#' && (ch[x][y]=='.' || (ch[x][y]<=ch[xi][yi])))return true;
    return false;
}

void bfs(int x,int y)
{
    queue<pair<int,int>>q;
    q.push({x,y});
    dis[x][y]=0;
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int j=0;j<4;j++)
        {
            int tx=x+xx[j];
            int ty=y+yy[j];
            if(Is_valid(tx,ty))
            {
                if(dis[tx][ty]!=-1 && dis[tx][ty]<=dis[x][y]+1)continue;
                dis[tx][ty]=dis[x][y]+1;
                q.push({tx,ty});
            }
        }
    }
}

void solve()
{
   scanf("%d",&n);
   for(int i=0;i<n;i++)scanf("%s",ch[i]);
   int boro=0;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           if(ch[i][j]>='A' && ch[i][j]<='Z')
           {
               pos[ch[i][j]-'A']={i,j};
               boro=max(boro,ch[i][j]-'A');
           }
       }
   }
   int re=0;
   for(int i=0;i<boro;i++)
   {
       xi=pos[i+1].first;
       yi=pos[i+1].second;
       memset(dis,-1,sizeof(dis));
       bfs(pos[i].first,pos[i].second);
       if(dis[xi][yi]==-1)
       {
           printf("Case %d: Impossible\n",++ii);
           return;
       }
       re+=dis[xi][yi];
   }
   printf("Case %d: %d\n",++ii,re);
}

int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t=1;
   scanf("%d",&t);
   while(t--)solve();
   return 0;
}
