// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 200005
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k;
 
void solve()
{
    set<int>s;
    map<int,int>cnt;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k);
        s.insert(k+1);
        cnt[k+1]++;
    }
    int re=0;
    for(int a:s)
    {
        int tot=cnt[a]/a;
        if(cnt[a]%a!=0)tot++;
        re+=tot*a;
    }
    printf("Case %d: %d\n",++ii,re );
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
