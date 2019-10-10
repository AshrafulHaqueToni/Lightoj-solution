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
#define         array_input(array,size) for(int i=0;i<size;i++)cin>>array[i];
#define         vector_input(v,size) for(int i=0;i<size;i++){lln,cin>>n,v.pb(n);}
#define         newline pf("\n");
#define         f(i,n) for(ll i=0;i<(n);i++)
#define         f1(i,n) for(ll i=1;i<=(n);i++)
#define         Max INT_MAX
#define         Min INT_MIN
#define         pi acos(-1.0)
#define         Memset(a,val) memset(a,val,sizeof(a));
#define         pa pair<int,int>
#define         paa pair<int,pair<int,int> >
#define         se second
#define         ff first


const int mod =1e9+7;
const int N =5e6+5;
typedef long long ll;

char s[11][11];
int a[11][11];
int visit[11][11],xi,yi,n,k;
int Xx[]={0,1,0,-1};
int Yy[]={1,0,-1,0};





int bfs(vector<paa>p,int curent)
{
    int x,y;
    if(curent==k)return p[0].ff;

    Memset(visit,0);

    queue<vector<paa> >q;
    q.push(p);

    while(!q.empty())
    {
        vector<paa>vv,vvv;

        vv=q.front();
        q.pop();

        f(i,4){

           x=vv[0].se.ff+Xx[i];
           y=vv[0].se.se+Yy[i];

           if(x<0||x>=n||y>=n||y<0)continue;

           if(a[x][y]==curent+1){

               int xxx=(vv[0].ff+1);
               vvv.pb({xxx,{x,y}});


                return bfs(vvv,curent+1);
           }

           if(!visit[x][y]&&(a[x][y]>=0&&a[x][y]<=curent)){

            visit[x][y]=1;


            vector<paa>ppp;
            int xxx=(vv[0].ff+1);
            ppp.pb({xxx,{x,y}});


            q.push(ppp);
           }

        }
    }

    return -1;



}



int main()
{
    freopen("1066.txt","r",stdin);

    ash;
    int t;
    cin>>t;
    f1(ii,t)
    {
        int cont;
        cin>>n;
        f(i,n)
        {
            f(j,n)
            {
                cin>>s[i][j];
                if(s[i][j]=='.')a[i][j]=0;
                else if(s[i][j]=='#')a[i][j]=-1;
                else{
                        if(s[i][j]=='A'){
                            xi=i,yi=j;
                        }
                    int m=s[i][j]-'A';
                    a[i][j]=m;
                    k=max(k,m);
                }

            }
        }


         vector<paa>p;
         p.pb({0,{xi,yi}});

         cout<<"Case "<<ii<<": ";

        cont=bfs(p,0);

        if(cont>=0)cout<<cont<<endl;
        else cout<<"Impossible"<<endl;

        Memset(a,0);
        k=0;


    }



    return 0;
}

