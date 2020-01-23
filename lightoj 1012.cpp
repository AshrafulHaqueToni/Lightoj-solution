#include<bits/stdc++.h>
 
using namespace std;
 
#define         ash ios_base::sync_with_stdio(0);
#define         pb push_back
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
char ar[21][21];
int cnt,r,c;
 
void dfs(int x,int y){
    if(x<0||x>=r||y<0||y>=c||ar[x][y]=='#')return;
    if(ar[x][y]=='@')ar[x][y]='#';
    if(ar[x][y]=='.'){
        cnt++;
        ar[x][y]='#';
    }
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);
 
}
 
int main()
{
    //ash;
    int t;
    sc(t);
    for(int i=1;i<=t;i++){
            cnt=1;
    Memset(ar,-1);
 
        sc2(c,r);
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                cin>>ar[j][k];
            }
        }
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                if(ar[j][k]=='@'){
                    dfs(j,k);
                   // pf("1");
                }
 
            }
        }
 
        pf("Case %d: %d\n",i,cnt);
 
    }
 
 
 
 
    return 0;
}
