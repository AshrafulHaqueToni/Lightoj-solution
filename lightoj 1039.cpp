#include<bits/stdc++.h>
using namespace std;
 
struct me
{
    int x;
    int y;
    int z;
 
    me(){};
    me(int x,int y,int z){this->x=x,this->y=y,this->z=z;}
};
 
int ans[26][26][26];
int visit[26][26][26];
 
int x[6]={0,0,1,0,0,-1};
int y[6]={0,1,0,0,-1,0};
int z[6]={1,0,0,-1,0,0};
char start[4],End[4];
char a1[26],b1[26],c1[26];
bool f;
 
void bfs()
{
    queue<me>q;
    me tem;
 
    q.push(me(start[0]-'a',start[1]-'a',start[2]-'a'));
    ans[start[0]-'a'][start[1]-'a'][start[2]-'a']=0;
    visit[start[0]-'a'][start[1]-'a'][start[2]-'a']=1;
 
    while(!q.empty())
    {
        tem=q.front();
        q.pop();
 
        if(tem.x==End[0]-'a' && tem.y==End[1]-'a' && tem.z==End[2]-'a')
        {
            f=false;
            break;
        }
 
        for(int i=0;i<6;i++)
        {
            int a=(tem.x+x[i]+26)%26;
            int b=(tem.y+y[i]+26)%26;
            int c=(tem.z+z[i]+26)%26;
 
 
            if(visit[a][b][c]==0)
            {
               // cout<<a<<" "<<b<<" "<<c<<endl;
                visit[a][b][c]=1;
                ans[a][b][c]=ans[tem.x][tem.y][tem.z]+1;
                q.push(me(a,b,c));
            }
        }
    }
    if(!f)
    {
        printf("%d\n",ans[tem.x][tem.y][tem.z]);
    }
    else printf("-1\n");
 
    return;
}
 
void solve(int ii)
{
    memset(visit,0,sizeof visit);
    f=true;
    scanf("%s%s",start,End);
 
    int n;
    scanf("%d",&n);
 
    for(int i=1;i<=n;i++)
    {
        scanf("%s%s%s",a1,b1,c1);
 
        for(int j=0;j<strlen(a1);j++)
        {
            for(int k=0;k<strlen(b1);k++)
            {
                for(int l=0;l<strlen(c1);l++)
                {
                    visit[a1[j]-'a'][b1[k]-'a'][c1[l]-'a']=-1;
                }
            }
        }
    }
    printf("Case %d: ",ii);
 
    if(visit[start[0]-'a'][start[1]-'a'][start[2]-'a']==-1)
    {
        printf("-1\n");
        return;
    }
    bfs();
    return;
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
 
    for(int i=1;i<=t;i++)solve(i);
 
    return 0;
}
