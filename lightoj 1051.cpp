#include<bits/stdc++.h>
using namespace std;
 
char ch[55];
bool dp[55][55][55];
int vis[55][55][55];
int ii,len;
 
bool func(int pos,int vow,int con)
{
    if(vow>=3 || con>=5)return false;
    if(len==pos)return true;
 
    bool &re=dp[pos][vow][con];
 
    if(vis[pos][vow][con]==ii)return re;
 
    re=false;
 
    vis[pos][vow][con]=ii;
 
    if(ch[pos]=='?')
    {
        re|=func(pos+1,vow+1,0);
        re|=func(pos+1,0,con+1);
    }
 
     else if(ch[pos]=='A' || ch[pos]=='E' || ch[pos]=='I' || ch[pos]=='O' || ch[pos]=='U')
     {
         re|=func(pos+1,vow+1,0);
     }
 
 
    else re|=func(pos+1,0,con+1);
 
    return re;
}
 
void solve(int l)
{
    ii=l;
    scanf("%s",ch);
    bool f=false,ff=false;
    len=strlen(ch);
 
    int cnt=0;
    for(int i=0; i<strlen(ch); i++)
    {
        if(ch[i]!='A' && ch[i]!='E' && ch[i]!='I' && ch[i]!='O' && ch[i]!='U')
        {
            cnt++;
            if(cnt>=5)
            {
                f=true;
               // cout<<i<<" "<<cnt<<endl;
                break;
            }
        }
        else
            cnt=0;
    }
    cnt=0;
 
    if(!f)
    {
        for(int i=0; i<strlen(ch); i++)
        {
            if(ch[i]=='A' || ch[i]=='E' || ch[i]=='I' || ch[i]=='O' || ch[i]=='U' ||ch[i]=='?')
            {
                cnt++;
                if(cnt>=3)
                {
                    f=true;
                   // cout<<i<<" "<<cnt<<endl;
                    break;
                }
            }
            else
                cnt=0;
        }
    }
    ff=func(0,0,0);
    //cout<<ff<<endl;
 
    printf("Case %d: ",ii);
 
    if(f && ff)
    {
        printf("MIXED\n");
    }
    else if(f)
    {
        printf("BAD\n");
    }
    else if(ff)
    {
        printf("GOOD\n");
    }
 
    return;
}
int main()
{
    //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int t=1;
    scanf("%d",&t);
 
    for(int i=1; i<=t; i++)
        solve(i);
 
    return 0;
}
