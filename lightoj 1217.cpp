#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 1005

int dp[mx][3];
int visit[mx][3];
int a[mx];
int ii,n;

int func(int pos,bool f)
{
    if(pos>=n)return 0;

    int &re=dp[pos][f];

    if(visit[pos][f]==ii)return re;

    visit[pos][f]=ii;

    re=0;

    if(f && pos==n-1)return 0;

    re=max(a[pos]+func(pos+2,(pos==0)?1:f),func(pos+1,f));

    return re;

}

void solve(int l)
{
    ii=l;

    scanf("%d",&n);

    for(int i=0;i<n;i++)scanf("%d",&a[i]);

    printf("Case %d: %d\n",ii,func(0,0));

    return;

}

int main()
{
    int t=1;
    scanf("%d",&t);

    for(int i=1;i<=t;i++)solve(i);

    return 0;
}
