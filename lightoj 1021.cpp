#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define mx 100005

ll dp[1<<16][21];
int visit[1<<16][21];
char ch[100];
int n,ii,base,d;

unordered_map<char,int>m;

bool chk(int mask,int i)
{
    return (bool)(mask & (1<<i));
}

int Set(int mask,int i)
{
    return mask=mask|(1<<i);
}

ll func(int mask,int hateacekoto)
{
    if(mask==(1<<n)-1)return hateacekoto==0;

    ll &re=dp[mask][hateacekoto];

    if(visit[mask][hateacekoto]==ii)return re;

    visit[mask][hateacekoto]=ii;

    re=0;

    for(int i=0;i<n;i++)
    {
        if(!chk(mask,i))
        {
            re+=func(Set(mask,i),(hateacekoto*base+m[ch[i]])%d);
        }
    }

    return re;

}

void solve(int l)
{
    ii=l;
    scanf("%d%d",&base,&d);

    scanf("%s",ch);

    n=strlen(ch);

    printf("Case %d: %lld\n",ii,func(0,0));

   return;
}
void pre_cal()
{
    for(int i=0;i<10;i++)m[i+'0']=i;
    m['A']=10,m['B']=11,m['C']=12,m['D']=13;
    m['E']=14,m['F']=15;
}

int main()
{
    int t=1;
    scanf("%d",&t);
    pre_cal();
    for(int i=1;i<=t;i++)solve(i);

    return 0;
}

