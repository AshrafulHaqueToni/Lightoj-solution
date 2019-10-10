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





vector<int>v[1005];

int visit[1005];

int u,vv;

void primefactorize(int n)
{
    int div=2,add=0,ind=n;
    while(n>1)
    {
        add=0;
        while(n%div==0)
        {
            add=div;
            n/=div;

        }
        if(add)
            v[ind].pb(add);
        div++;
    }
    if(ind==add)
        v[ind].clear();
}

int bfs()
{
    Memset(visit,-1);

    queue<int>q;
    q.push(u);
    visit[u]=0;

    while(!q.empty())
    {
        int x=q.front();
        int to;
        q.pop();
        for(int i=0; i<(int)v[x].size(); i++)
        {
            to=x+v[x][i];
            if(to<=vv&&visit[to]==-1)
            {
                visit[to]=visit[x]+1;
                q.push(to);
                if(to==vv)
                    return visit[vv];

            }
        }
    }
    return visit[vv];

}/*

int bfs( ){
    int dist[1001];
    memset(dist, -1, sizeof(dist));
    dist[u] = 0;
    queue < int > q;
    q.push(u);
    int from, to;
    while( !q.empty() ){
        from = q.front();
        q.pop();
        for( int i = 0; i < (int) v[from].size(); i++ ){
            to = from + v[from][i];
            if( to <= vv && dist[to] == -1 ) {
                q.push(to);
                dist[to] = dist[from] + 1;
                if( to  == vv) return dist[vv];
            }
        }
    }
    return dist[vv];
}*/


int main()
{
    ash;
    for(int i=2; i<=1005; i++)
    {

        primefactorize(i);

    }
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {

        cin>>u>>vv;

        if(u==1)
        {
            cout<<"Case "<<i<<": "<<-1<<endl;
            continue;
        }
        if(vv<=u)
        {
            cout<<"Case "<<i<<": "<<0<<endl;
            continue;
        }
        cout<<"Case "<<i<<": "<<bfs()<<endl;


    }

    return 0;
}
