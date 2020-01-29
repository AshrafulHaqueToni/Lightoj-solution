#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define mx 105

int a[mx+10];
int dp[mx][mx];
int visit[mx][mx];
char ch[mx+10];
int n,ii;

int func(int i,int j)
{
    if(i>j)return 0;

    if(i==j)return a[i];

    int &re=dp[i][j];

    if(visit[i][j]==ii)return re;

    visit[i][j]==ii;

    re=INT_MIN;
    int val=0;

    for(int start=i;start<=j;start++)
    {
        val+=a[start];
        re=max(re,val-func(start+1,j));
    }
    val=0;

    for(int start=j;start>=i;start--)
    {
        val+=a[start];
        re=max(re,val-func(i,start-1));
    }

    return re;
}

void solve(int l)
{
    ii=l;
    scanf("%d",&n);

    for(int i=0;i<n;i++)scanf("%d",&a[i]);

    printf("Case %d: %d\n",ii,func(0,n-1));

   return;
}

int main()
{
    int t=1;
    scanf("%d",&t);

    for(int i=1;i<=t;i++)solve(i);

    return 0;
}

