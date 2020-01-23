///***Bismillahir Rahmanir Rahim***///

///*********************************///
///******Ashraful Haque Toni********///
///********Dept. of CSE,JnU*********///
///email:ashrafulhaquetoni@gmail.com///
///*******contact:01640690531*******///
///*********************************///


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


vector<int>con[10005];
vector<int>parent(10005);
vector<int>visit(10005,0);

void initialize()
{
    for(int i=1;i<=10005;i++)parent[i]=i;
}

int pp(int x)
{
    return (x==parent[x])?x:(parent[x]=pp(parent[x]));
}

void Union(int x,int y)
{
    parent[pp(x)]=parent[pp(y)];
}

int kruskal(vector<pair<int,pair<int,int> > >v)
{
    ll re=0;

    for(int i=0;i<v.size();i++)
    {
        int U=v[i].second.first;
        int V=v[i].second.second;
        int W=v[i].first;

        if(pp(U)!=pp(V)){
            re+=W;
            Union(U,V);
            con[U].pb(V);
            con[V].pb(U);
        }

    }
    return re;
}

void dfs(int start)
{
    visit[start]=1;
    for(int i=0;i<con[start].size();i++)
    {
        if(visit[con[start][i]]==0){
            dfs(con[start][i]);
        }
    }
}


int main()
{

    //ash;
    //freopen("1059.txt","r",stdin);
    int t;
    cin>>t;
    for(int ii=1;ii<=t;ii++)
    {
        int n,m,k;
        cin>>n>>m>>k;


        vector<pair<int,pair<int,int> > >grap;

        while(m--)
        {
            int a1,a2,w;
            cin>>a1>>a2>>w;
            if(w<k){
                grap.pb({w,{a1,a2}});
            }
        }
        sort(grap.begin(),grap.end());
        initialize();
        int cost=kruskal(grap);

        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(visit[i]==0){
                cnt++;
                dfs(i);
            }
            //else cout<<i<<endl;
        }
        cout<<"Case "<<ii<<": "<<(cnt*k)+cost<<" "<<cnt<<endl;

        for(int i=0;i<=10005;i++)
        {
            con[i].clear();
        visit[i]=0;
        }

    }



    return 0;
}


