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
vector<int>a;
int visit[1005];
int cnt[1005];

int k,n,m,sum;

void Mem()
{
    for(int i=0; i<1005; i++)
        v[i].clear();
    a.clear();
}

void bfs()
{

    for(int i=0; i<k; i++)
    {

        queue<int>q;

        Memset(visit,0);

        q.push(a[i]);

        visit[a[i]]=1;

        cnt[a[i]]+=1;

        while(!q.empty())
        {
            int x=q.front();
            q.pop();

            int u;

            for(int l=0; l<v[x].size(); l++)
            {
                int d=v[x][l];

                if(visit[d]==0)
                {
                    visit[d]=1;


                    u=cnt[d]=cnt[d]+1;

                    q.push(d);

                }
            }

        }
    }
}


int main()
{
    ash;
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        Mem();
        sum=0;

        cin>>k>>n>>m;
        int kkk=k;
        while(kkk--)
        {
            int kk;
            cin>>kk;
            a.pb(kk);
        }
        while(m--)
        {
            int aa,bb;
            cin>>aa>>bb;
            v[aa].pb(bb);
        }
        bfs();
        for(int i=1;i<=n;i++){
            if(cnt[i]==k)sum++;
        }

        cout<<"Case "<<i<<": "<<sum<<endl;
        Memset(cnt,0);

    }




    return 0;
}
