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
#define         mp make_pair
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

char ar[25][25];

int dis[25][25];
int r,c;
int tr[]= {-1,0,1,0};
int tc[]= {0,1,0,-1};

int bfs(int x,int y)
{
    Memset(dis,-1);
    queue<pair<int,int> >q;
    q.push({x,y});

    dis[x][y]=0;
    while(!q.empty())
    {
        int xx=q.front().first;
        int yy=q.front().second;
        q.pop();
        if(ar[xx][yy]=='h')
            return dis[xx][yy];
        for(int k=0; k<4; k++)
        {
            int xxx=xx+tr[k];
            int yyy=yy+tc[k];
            if(xxx>=0&&xxx<r&&yyy>=0&&yyy<c&&ar[xxx][yyy]!='m'&&ar[xxx][yyy]!='#'&&dis[xxx][yyy]==-1)
            {
                dis[xxx][yyy]=dis[xx][yy]+1;
                q.push({xxx,yyy});
            }
        }
    }
   /* for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }*/

}

int main()
{
    ash;
    int t,ax,ay,bx,by,cx,cy;
    cin>>t;
    for(int t1=1; t1<=t; t1++)
    {
        cin>>r>>c;
        for(int i=0;i<r;i++)
        {
            for(int j=0; j<c; j++)
            {
                cin>>ar[i][j];

                if(ar[i][j]=='a')
                {
                    ax=i,ay=j;
                }
                else if(ar[i][j]=='b')
                {
                    bx=i,by=j;
                }
                else if(ar[i][j]=='c')
                {
                    cx=i,cy=j;
                }

            }
        }
        int sum=0;
        sum=max(sum,bfs(ax,ay));//cout<<sum<<endl;

        sum=max(sum,bfs(bx,by));//cout<<sum<<endl;

        sum=max(sum,bfs(cx,cy));//cout<<cx<<cy<<endl;

        cout<<"Case "<<t1<<": "<<sum<<"\n";
    }



    return 0;
}


