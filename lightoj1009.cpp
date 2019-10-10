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
vector<int>v1[20005];
int visit[20005];
int black,red,cnt;

void Mem()
{
    for(int i=0; i<20005; i++)
    {
        v1[i].clear();
    }
}

void bfs()
{
    Memset(visit,-1);
    for(int i=0; i<20005; i++)
    {
        if(v1[i].size()!=0&&visit[i]==-1)
        {
            queue<int>q;
            black=0,red=0;

            q.push(i);
            visit[i]=1;
            black++;

            while(!q.empty())
            {
                int x=q.front();
                q.pop();
                for(int j=0; j<v1[x].size(); j++)
                {
                    int d=v1[x][j];
                    if(visit[d]==-1)
                    {
                        q.push(d);
                        if(visit[x]==1)
                        {
                            visit[d]=2;
                            red++;
                        }
                        else
                        {
                            visit[d]=1;
                            black++;
                        }
                    }
                }

            }
            cnt+=max(black,red);
        }
    }
}

int main()
{
    ash;
    int t;
    cin>>t;
    for(int c=1; c<=t; c++)
    {
        Mem();
        cnt=0;
        int n;
        cin>>n;
        while(n--)
        {
            int u,v;
            cin>>u>>v;
            v1[u].pb(v);
            v1[v].pb(u);

        }
        bfs();
        cout<<"Case "<<c<<": "<<cnt<<"\n";
    }




    return 0;
}

