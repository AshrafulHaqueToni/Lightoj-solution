// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 11
#define ll long long
#define mod 1000000007 //998244353
 

char ch[mx][mx];
int dist[mx][mx][mx][mx];
bool vis[mx][mx][mx];
bool take[mx][mx];
vector<pair<int,int>>edge[mx][mx][mx];

int n,m,ii,k;

int xx[]={1,1,2,2,-1,-1,-2,-2};
int yy[]={2,-2,1,-1,2,-2,1,-1};


int a,b;



void Move(int x,int y,int rem){
    if(rem<=0)return;
    if(vis[x][y][rem])return;
    vis[x][y][rem]=1;
    for(int i=0;i<8;i++){
        int nx=x+xx[i];
        int ny=y+yy[i];
        if(nx>=0 and nx<n and ny>=0 and ny<m){
            if(take[nx][ny]==0){
                edge[a][b][k].emplace_back(nx,ny);
                take[nx][ny]=1;
            }
            Move(nx,ny,rem-1); 
        }
    }

}

void dijkstra(int u,int v){
    priority_queue<pair<int,pair<int,int>>>pq;
  //  cout<<u<<" "<<v<<endl;
    pq.push({0,{u,v}});
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        auto[x,y]=it.second;
        int cost=-it.first;
      //  cout<<x<<" "<<y<<" "<<cost<<endl;
        if(dist[u][v][x][y]<cost)continue;

        for(auto[i,j]:edge[x][y][k]){
            if(dist[u][v][i][j]>cost+1){
                dist[u][v][i][j]=cost+1;
                pq.push({-cost-1,{i,j}});
            }
        }

    }
}
 
void solve()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int l=0;l<n;l++){
                for(int z=0;z<m;z++){
                    dist[i][j][l][z]=10000;
                }
            }
            for(int l=1;l<=9;l++)
            edge[i][j][l].clear();
        }
    }
    for(int i=0;i<n;i++){
        scanf("%s",ch[i]);
        for(int j=0;j<m;j++){
            for(int l=1;l<=9;l++){
                k=l;
                memset(vis,0,sizeof(vis));
                memset(take,0,sizeof(take));
                a=i;
                b=j;
                Move(i,j,k);
                /*cout<<i<<" "<<j<<endl;
                for(auto[x,y]:edge[i][j]){
                    cout<<x<<" "<<y<<endl;
                }
                cout<<endl;
*/
            }
        }
    }
    vector<pair<int,int>>rider;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ch[i][j]!='.'){
                k=ch[i][j]-'0';
                rider.emplace_back(i,j);
                dist[i][j][i][j]=0;
                dijkstra(i,j);
            }
        }
    }
    if(rider.empty()){
        printf("Case %d: 0\n",++ii);
        return;
    }
    int re=10000;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int tmp=0;
           // cout<<i<<" "<<j<<" :";
            for(auto[x,y]:rider){
                tmp+=dist[x][y][i][j];
              //  cout<<dist[i][j][x][y]<<" ";
            }
           // cout<<endl;
            re=min(re,tmp);
        }
    }
    if(re==10000)re=-1;
    printf("Case %d: %d\n",++ii,re);

 
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
