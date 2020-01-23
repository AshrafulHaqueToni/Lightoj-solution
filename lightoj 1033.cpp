#include<bits/stdc++.h>
using namespace std;
 
int dp[101][101];
int vis[101][101];
char ch[101];
int ii;
 
int func(int be,int en)
{
    if(be>=en)return 0;
 
    if(vis[be][en]==ii)return dp[be][en];
 
    vis[be][en]=ii;
 
    //printf("%d %d\n",be,en);
 
    if(ch[be]==ch[en])return dp[be][en]=func(be+1,en-1);
 
    else
    {
        int re=func(be+1,en)+1;
        int re1=func(be,en-1)+1;
 
        return dp[be][en]=min(re,re1);
    }
}
 
 
int main()
{
    int t;
    scanf("%d",&t);
 
    for(ii=1;ii<=t;ii++)
    {
        scanf("%s",ch);
 
        int n=strlen(ch);
 
       // printf("%d\n",func(0,n-1));
 
 
        printf("Case %d: %d\n",ii,func(0,n-1));
    }
 
    return 0;
 
}
