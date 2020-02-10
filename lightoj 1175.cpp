#include<bits/stdc++.h>
using namespace std;

#define mx 205
int cal[mx][mx];
int val[mx][mx];
char ch[mx][mx];
int r,c,re,st_x,st_y;
queue<pair<int,int>>q;

void bfs1(int i,int j)
{
    q.push({i,j});
    cal[i][j]=0;

    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();


        if(x+1<r && cal[x+1][y]>cal[x][y]+1 && ch[x+1][y]!='#'&& ch[x+1][y]!='F')
        {
            cal[x+1][y]=cal[x][y]+1;
            q.push({x+1,y});
        }
        if(x-1>=0 && cal[x-1][y]>cal[x][y]+1 && ch[x-1][y]!='#'&& ch[x-1][y]!='F')
        {
            cal[x-1][y]=cal[x][y]+1;
            q.push({x-1,y});
        }
        if(y+1<c && cal[x][y+1]>cal[x][y]+1 && ch[x][y+1]!='#'&& ch[x][y+1]!='F')
        {

            cal[x][y+1]=cal[x][y]+1;
            q.push({x,y+1});
        }
        if(y-1>=0 && cal[x][y-1]>cal[x][y]+1 && ch[x][y-1]!='#'&& ch[x][y-1]!='F')
        {

            cal[x][y-1]=cal[x][y]+1;
            q.push({x,y-1});
        }
    }


}

void bfs(int i,int j)
{
    q.push({i,j});
    val[i][j]=1;

    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        if(x==0 || x==r-1 || y==0 || y==c-1)
        {
            re=min(re,val[x][y]);
        }
        else
        {
            if(x+1<r && val[x+1][y]>val[x][y]+1 && cal[x+1][y]>=val[x][y]+1 && ch[x+1][y]!='#' && ch[x+1][y]!='F')
            {
                val[x+1][y]=val[x][y]+1;
                q.push({x+1,y});
            }
            if(x-1>=0 && val[x-1][y]>val[x][y]+1 && cal[x-1][y]>=val[x][y]+1&& ch[x-1][y]!='#' && ch[x-1][y]!='F')
            {
                val[x-1][y]=val[x][y]+1;
                q.push({x-1,y});
            }
            if(y+1<c && val[x][y+1]>val[x][y]+1 && cal[x][y+1]>=val[x][y]+1&& ch[x][y+1]!='#' && ch[x][y+1]!='F')
            {
                val[x][y+1]=val[x][y]+1;
                q.push({x,y+1});
            }
            if(y-1>=0 && val[x][y-1]>val[x][y]+1 && cal[x][y-1]>=val[x][y]+1&& ch[x][y-1]!='#' && ch[x][y-1]!='F')
            {
                val[x][y-1]=val[x][y]+1;
                q.push({x,y-1});
            }
        }
    }
}

void solve(int ii)
{
    for(int i=0; i<=200; i++)
        for(int j=0; j<=200; j++)
            {
                cal[i][j]=100000;
                val[i][j]=100000;
            }

    scanf("%d%d",&r,&c);
    for(int i=0; i<r; i++)
        scanf("%s",ch[i]);

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(ch[i][j]=='F')
            {
                bfs1(i,j);
            }
             if(ch[i][j]=='J')
            {

                st_x=i,st_y=j;
            }
        }
    }

//    for(int i=0;i<r;i++)
//    {
//        for(int j=0;j<c;j++)
//        {
//            printf("%d ",cal[i][j]);
//        }
//        printf("\n");
//    }

    re=INT_MAX;

    bfs(st_x,st_y);
    printf("Case %d: ",ii);

    if(re==INT_MAX)
    {
        printf("IMPOSSIBLE\n");
    }
    else
        printf("%d\n",re);

    return;
}

int main()
{
    //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);

    for(int i=1; i<=t; i++)
        solve(i);

    return 0;
}
