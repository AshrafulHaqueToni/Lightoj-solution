#include<bits/stdc++.h>
using namespace std;

#define mx 11
#define ll long long

int ar[mx];
char ch[mx][mx];

int n,m,k,ii;
int st1,st2,st3,en1,en2,en3;
int dis[mx][mx][mx][mx][mx][mx];
int x[]={1,0,-1,0};
int y[]={0,1,0,-1};
struct node
{
    int a1,a2,b1,b2,c1,c2;
    node(int a1,int a2,int b1,int b2,int c1,int c2)
    {
        this->a1=a1;
        this->a2=a2;
        this->b1=b1;
        this->b2=b2;
        this->c1=c1;
        this->c2=c2;
    }
};

bool Is_valid(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<n && ch[x][y]!='#')return true;
    return false;
}

void bfs()
{
    queue<node>q;
    q.push(node(st1,en1,st2,en2,st3,en3));
    dis[st1][en1][st2][en2][st3][en3]=0;
    while(!q.empty())
    {
        node tem=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int a1=tem.a1+x[i];
            int a2=tem.a2+y[i];
            int b1=tem.b1+x[i];
            int b2=tem.b2+y[i];
            int c1=tem.c1+x[i];
            int c2=tem.c2+y[i];

            if(Is_valid(a1,a2)==false)
            {
                a1=tem.a1;
                a2=tem.a2;
                if(a1==b1 && a2==b2)
                {
                    b1=tem.b1;
                    b2=tem.b2;
                    if(b1==c1 && b2==c2)
                    {
                        c1=tem.c1;
                        c2=tem.c2;
                    }
                }
                if(a1==c1 && a2==c2)
                {
                     c1=tem.c1;
                    c2=tem.c2;
                    if(b1==c1 && b2==c2)
                    {
                        b1=tem.b1;
                        b2=tem.b2;
                    }
                }

            }
            if(Is_valid(b1,b2)==false)
            {
                b1=tem.b1;
                b2=tem.b2;
                if(a1==b1 && a2==b2)
                {
                    a1=tem.a1;
                    a2=tem.a2;
                    if(a1==c1 && a2==c2)
                    {
                        c1=tem.c1;
                        c2=tem.c2;
                    }
                }
                if(b1==c1 && b2==c2)
                {
                     c1=tem.c1;
                    c2=tem.c2;
                    if(a1==c1 && a2==c2)
                    {
                        a1=tem.a1;
                        a2=tem.a2;
                    }
                }

            }
            if(Is_valid(c1,c2)==false)
            {
                c1=tem.c1;
                c2=tem.c2;
                if(a1==c1 && a2==c2)
                {
                    a1=tem.a1;
                    a2=tem.a2;
                    if(a1==b1 && a2==b2)
                    {
                        b1=tem.b1;
                        b2=tem.b2;
                    }
                }
                if(b1==c1 && b2==c2)
                {
                     b1=tem.b1;
                    b2=tem.b2;
                    if(a1==b1 && a2==b2)
                    {
                        a1=tem.a1;
                        a2=tem.a2;
                    }
                }

            }

                if(dis[a1][a2][b1][b2][c1][c2]!=-1 && dis[a1][a2][b1][b2][c1][c2]<=dis[tem.a1][tem.a2][tem.b1][tem.b2][tem.c1][tem.c2]+1)continue;
                dis[a1][a2][b1][b2][c1][c2]=dis[tem.a1][tem.a2][tem.b1][tem.b2][tem.c1][tem.c2]+1;
                q.push(node(a1,a2,b1,b2,c1,c2));

        }
    }
}

void solve()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%s",ch[i]);
    memset(dis,-1,sizeof(dis));

    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(ch[i][j]=='A')st1=i,en1=j;
            if(ch[i][j]=='B')st2=i,en2=j;
            if(ch[i][j]=='C')st3=i,en3=j;
            if(ch[i][j]=='X')v.push_back({i,j});
        }
    }
    bfs();
    int re=1000005;
    st1=v[0].first;
    en1=v[0].second;
    st2=v[1].first;
    en2=v[1].second;
    st3=v[2].first;
    en3=v[2].second;

    if(dis[st1][en1][st2][en2][st3][en3]!=-1)re=min(re,dis[st1][en1][st2][en2][st3][en3]);
    if(dis[st1][en1][st3][en3][st2][en2]!=-1)re=min(re,dis[st1][en1][st3][en3][st2][en2]);
    if(dis[st2][en2][st3][en3][st1][en1]!=-1)re=min(re,dis[st2][en2][st3][en3][st1][en1]);
    if(dis[st2][en2][st1][en1][st3][en3]!=-1)re=min(re,dis[st2][en2][st1][en1][st3][en3]);
    if(dis[st3][en3][st1][en1][st2][en2]!=-1)re=min(re,dis[st3][en3][st1][en1][st2][en2]);
    if(dis[st3][en3][st2][en2][st1][en1]!=-1)re=min(re,dis[st3][en3][st2][en2][st1][en1]);

    if(re==1000005)printf("Case %d: trapped\n",++ii);
    else printf("Case %d: %d\n",++ii,re);


}
/*
1
3
.XX
B.A
XC.
*/
int main()
{
  // freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t=1;
   scanf("%d",&t);
   while(t--)solve();
   return 0;
}
