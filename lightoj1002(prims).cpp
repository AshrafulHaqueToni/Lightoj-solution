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

const int mod =1e9+7;
const int N =5e6+5;
typedef long long ll;

vector<pair<int,int> >v[505];
unordered_map<int,int>dis;
vector<int>color(505,0),parent(505,0);
int node,edge;

void span(int start)
{
    for(int i=0;i<node;i++)dis[i]=INT_MAX;

    dis[start]=0;

    set<pair<int,int> >s;
    s.insert({dis[start],start});

    while(!s.empty())
    {
        auto it=s.begin();
        int weight=it->first;
        int Node=it->second;

        s.erase(it);
        color[Node]=1;

        for(int i=0;i<v[Node].size();i++)
        {
            int x=v[Node][i].first;
            int cost=v[Node][i].second;

            if(dis[x]>cost && !color[x])
            {
                auto finder=s.find({dis[x],x});

                if(finder!=s.end()){
                    s.erase(finder);
                }
                dis[x]=cost;
                s.insert({dis[x],x});
                parent[x]=Node;
            }

        }
    }
}


void Road(int i,int t)
{
    if(!color[i]){
        cout<<"Impossible\n";
        return;
    }

    if(i==t){
        cout<<0<<"\n";
        return;
    }

    int r=-1,a;
    while(1){
        if(i==t)break;
        r=max(r,dis[i]);
        i=parent[i];
    }
    cout<<r<<"\n";
}


int main()
{

    //ash;

    int t;
    cin>>t;
    for(int ii=1;ii<=t;ii++)
    {
        //int node,edge;
        cin>>node>>edge;
        while(edge--)
        {
            int a1,a2,w;
            cin>>a1>>a2>>w;
            v[a1].pb({a2,w});
            v[a2].pb({a1,w});
        }
        int t;
        cin>>t;

        span(t);

        cout<<"Case "<<ii<<":\n";

        for(int i=0;i<node;i++)
        {
            Road(i,t);
        }

        for(int i=0;i<node;i++){
            v[i].clear();

        //dis.clear();
        color[i]=0;
        parent[i]=0;
        }
        dis.clear();


    }



    return 0;
}


