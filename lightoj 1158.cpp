#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int dp[1<<10][1005];
int vis[1<<10][1005];
int ii,len,d;
int fac[10],digit[10],cnt[10];
char ch[10];
 
 
bool chk(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
 
int Set(int N,int pos)
{
    return N=N|(1<<pos);
}
 
 
void pre_cal()
{
    fac[0]=1;
 
    for(int i=1;i<=9;i++)fac[i]=fac[i-1]*i;
}
 
 
int func(int mask, int hate_ace_koto)
{
    if(mask==(1<<len)-1)
        return hate_ace_koto==0;
 
    if(vis[mask][hate_ace_koto]==ii)return dp[mask][hate_ace_koto];
 
    vis[mask][hate_ace_koto]=ii;
 
    int re=0;
    //cout<<hate_ace_koto<<endl;
 
    for(int i=0;i<len;i++)
    {
        if(!chk(mask,i))
        {
            re+=func(Set(mask,i),(hate_ace_koto*10+digit[i])%d);
        }
    }
 
    return dp[mask][hate_ace_koto]=re;
}
 
 
int main()
{
    pre_cal();
 
    int t;
    scanf("%d",&t);
 
    for(ii=1;ii<=t;ii++)
    {
        memset(cnt,0,sizeof cnt);
 
        scanf("%s%d",ch,&d);
 
        len=strlen(ch);
 
        for(int i=0;i<len;i++)
        {
            digit[i]=(int)(ch[i]-'0');
            cnt[digit[i]]++;
           // cout<<digit[i];
        }
 
        int re=func(0,0);
 
        for(int i=0;i<10;i++)
        {
            re/=fac[cnt[i]];
        }
 
        //cout<<endl<<re<<endl;
        printf("Case %d: %d\n",ii,re);
       //printf("%d\n",re);
    }
 
    return 0;
}
