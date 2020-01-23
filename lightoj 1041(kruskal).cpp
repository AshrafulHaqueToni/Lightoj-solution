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



vector<int>parent(55);

int Fparent(int x)
{
    return (x==parent[x])?x:(parent[x]=pp(parent[x]));
}


void Union(int x,int y)
{
    parent[Fparent(x)]=parent[Fparent(y)];
   // cout<<parent[x]<<endl;
}


int kruskal(vector<pair<int,pair<int,int> > >g,int n)
{
    int k=0;
    //cout<<g.size()<<endl;
    for(int i=0; i<g.size(); i++)
    {

        int U=g[i].second.first;
        int V=g[i].second.second;
        int W=g[i].first;

        // cout<<"("<<U<<","<<V<<","<<W<<")";
        //cout<<Fparent(U)<<Fparent(V)<<endl;
        if(Fparent(U)!=Fparent(V))
        {
            k+=W;
          //cout<<"("<<U<<","<<V<<","<<W<<")";
            Union(U,V);
        }

    }


    int l=Fparent(1);

    for(int i=2; i<=n; i++)
    {
        if(Fparent(i)!=l)
            return -1;
    }


    return k;
}

void initialize()
{
    for(int i=0; i<55; i++)
    {

        parent[i]=i;
    }
}

int main()
{
    //freopen("1041.txt","r",stdin);
    ash;
    int t;
    cin>>t;

    for(int ii=1; ii<=t; ii++)
    {
        int node,k=1;
        cin>>node;


        map<string,int>m;
        vector<pair<int,pair<int,int> > >g;


        while(node--)
        {
            string s,s1;
            int we;


            cin>>s>>s1>>we;

            if(m.find(s)==m.end())
            {
                m[s]=k++;
            }
            if(m.find(s1)==m.end())
            {
                m[s1]=k++;
            }
            g.pb({we,{m[s],m[s1]}});
            //cout<<m[s]<<m[s1]<<endl;

        }
        sort(g.begin(),g.end());

        //cout<<m.size()<<endl;

        initialize();
        int kk=kruskal(g,m.size());



        cout<<"Case "<<ii<<": ";
        if(kk==-1)
        {
            cout<<"Impossible\n";
        }
        else
        {
            cout<<kk<<endl;
        }

        //graph.clear();
    }



    return 0;
}


