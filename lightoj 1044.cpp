#include<bits/stdc++.h>
using namespace std;
 
int pal[1005][1005];
int dp[1005];
int vis[1005];
int vis1[1005][1005];
char ch[1005];
int ii,len;
 
bool palindrome(int be,int en)
{
    if(be>=en)return 1;
 
    if(vis1[be][en]==ii)
    {
        return pal[be][en];
    }
 
    vis1[be][en]=ii;
 
   return pal[be][en]=(bool)((ch[be]==ch[en]) && palindrome(be+1,en-1));
 
 
}
 
int func(int be)
{
    if(be==len)return 0;
 
 
    if(vis[be]==ii)return dp[be];
 
    vis[be]=ii;
 
    int re=1e9;
 
    for(int i=be;i<len;i++)
    {
        if(palindrome(be,i))
        {
            re=min(re,1+func(i+1));
        }
    }
 
    return dp[be]=re;
 
}
 
int main()
{
    int t;
    scanf("%d",&t);
 
    for(ii=1;ii<=t;ii++)
    {
        scanf("%s",ch);
        len=strlen(ch);
 
        printf("Case %d: %d\n",ii,func(0));
    }
 
 
    return 0;
}
