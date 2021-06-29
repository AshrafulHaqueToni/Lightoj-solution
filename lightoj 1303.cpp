// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 25
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k;
bitset<mx>bt[mx];
int Who[mx];


void solve()
{
    scanf("%d%d",&n,&m);
    vector<int>Queue;
    memset(Who,0,sizeof(Who));
    int tot=n*m;
    int cnt=1;
    bt[1][1]=true;
    Who[1]=1;
    int cur=1;
    for(int i=2;i<=n;i++)Queue.push_back(i);
    int re=1;
    while(cnt<tot || (int)Queue.size()<n)
    {
        cur++;
        if(cur>m)cur=1;
        int person=Who[cur];
        Who[cur]=0;
        vector<int>tem;
        bool f=false;
        for(int i:Queue)
        {
            if(f)
            {
                tem.push_back(i);
            }
            else
            {
                if(bt[i][cur]==false)
                {
                    f=true;
                    Who[cur]=i;
                    bt[i][cur]=1;
                    cnt++;
                }
                else
                {
                    tem.push_back(i);
                }
            }
        }
        if(person)tem.push_back(person);
        Queue=tem;
        re++;

    }
    printf("Case %d: %d\n",++ii,re*5 );
    for(int i=1;i<=n;i++)bt[i].reset();
    
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
