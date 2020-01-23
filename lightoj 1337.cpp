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
char ch[505][1005];
int r,c,cnt;
int v[505][1005];
vector<pair<int,int> >p;

void dfs(int x,int y)
{
    if(x>=0&&x<r&&y>=0&&y<c&&ch[x][y]!='#')
    {
        if(ch[x][y]=='C')cnt++;
        ch[x][y]='#';
        p.pb({x,y});
        dfs(x+1,y);
        dfs(x-1,y);
        dfs(x,y+1);
        dfs(x,y-1);
    }
    else return;
}


int main()
{
    //ash;
    int t;
    cin>>t;
    for(int t1=1;t1<=t;t1++){
            Memset(v,0);

        int q;
        cin>>r>>c>>q;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>ch[i][j];
            }
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
               p.clear();
                cnt=0;
                if(ch[i][j]=='.'||ch[i][j]=='C'){
                    dfs(i,j);

                }
                for(auto xxx: p)
                {
                    v[xxx.first][xxx.second]=cnt;
                }

            }
        }/*
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }*/
        cout<<"Case "<<t1<<":\n";
        while(q--){
            int xx,yy;
            cin>>xx>>yy;
            cout<<v[xx-1][yy-1]<<endl;
        }


    }




    return 0;
}


