// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 100005
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k;
 
void solve()
{
    int q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&ar[i]);
    printf("Case %d:\n",++ii);
    for(int i=1;i<=q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x++;y++;
        if((y-x+1)>1000)printf("0\n");
        else
        {
            vector<int>cnt(1001,0),v;
            bool f=false;
            for(int j=x;j<=y;j++)cnt[ar[j]]++;
            for(int j=1;j<=1000;j++)
            {
                if(cnt[j]>1)f=true;
                if(cnt[j]==1)v.push_back(j);
            }
            if(f)
            {
                printf("0\n");
            }
            else
            {
                int sz=v.size();
                int re=1000;
                for(int j=1;j<sz;j++)re=min(re,v[j]-v[j-1]);
                printf("%d\n",re );
            }
        }
    }
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
