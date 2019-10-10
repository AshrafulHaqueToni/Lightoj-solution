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


int node;
vector<int>parent(105);

void initialize()
{
    for(int i=0;i<105;i++)parent[i]=i;
}

int pp(int x)
{
    if(x!=parent[x]){
        while(1)
        {
            if(x==parent[x])break;
            x=parent[x];
        }
    }
    return x;
}

void Union(int x,int y)
{
    parent[pp(x)]=parent[pp(y)];
}



int kruskal(vector<pair<int,pair<int,int> > >v)
{
    int k=0;
    for(int i=0;i<v.size();i++)
    {
        int U=v[i].second.first;
        int V=v[i].second.second;
        int W=v[i].first;

        if(pp(U)!=pp(V)){
            k+=W;
            Union(U,V);
        }
    }
    return k;
}


int main()
{

    ash;
    int t;
    cin>>t;
    for(int ii=1;ii<=t;ii++)
    {
        cin>>node;
        vector<pair<int,pair<int,int> > >g;

        while(1)
        {
            int a1,a2,w;
            cin>>a1>>a2>>w;
            if(a1==0&&a2==0&&w==0)break;
            g.pb({w,{a1,a2}});
        }
        sort(g.begin(),g.end());
        initialize();
        int l=kruskal(g);
        reverse(g.begin(),g.end());
        initialize();
        int k=kruskal(g);

        int f=l+k;

        cout<<"Case "<<ii<<": ";

        if(f&1){
            cout<<f<<"/"<<2<<endl;
        }
        else
        cout<<f/2<<endl;;

    }





    return 0;
}


