#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int dp[10][2][105][105];
const ll mpos=10;
char ch[10];
int digitval,k;

void convert(int n)
{
    for(int i=0; i<mpos; i++)
    {
        ch[i]=(n%10)+'0';
        n/=10;
    }

    reverse(ch,ch+mpos);
    ch[mpos]=0;
}

int func(int pos,int smallornot,int digitvalcnt,int divid)
{
    if(pos==mpos)
    {
        if(digitvalcnt%k==0 && divid==0)
            return 1;
        else
            return 0;
    }

    if(dp[pos][smallornot][digitvalcnt][divid]!=-1)
        return dp[pos][smallornot][digitvalcnt][divid];

    int be=0;
    int en=9;

    if(!smallornot)
        en=ch[pos]-'0';

    int re=0;

    for(ll i=be; i<=en; i++)
    {
        int ismallornot= smallornot | (i<en);
        int idigitvalcnt=digitvalcnt+ i;
        re+=func(pos+1,ismallornot,idigitvalcnt,(i+divid*10)%k);
    }

    return dp[pos][smallornot][digitvalcnt][divid]=re;
}



void solve(int ii)
{

    int n,m,sum=0;
    scanf("%d%d%d",&m,&n,&k);

    if(k>90)
    {
        printf("Case %d: 0\n",ii);
        return;
    }


    memset(dp,-1,sizeof dp);

    convert(n);

    int re1=func(0,0,0,0);

    int re2=0;

    if(m>0)
    {
        convert(m-1);
        memset(dp,-1,sizeof dp);
        re2=func(0,0,0,0);
    }

    sum+=(re1-re2);

    printf("Case %d: %d\n",ii,sum);

    return;
}

int main()
{
    int t=1;
    scanf("%d",&t);

    for(int i=1; i<=t; i++)
        solve(i);

    return 0;
}
