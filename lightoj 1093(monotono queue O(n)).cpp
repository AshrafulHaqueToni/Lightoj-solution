#include<bits/stdc++.h>
using namespace std;


void solve(int ii)
{
    int n,m,re=0;
    scanf("%d%d",&n,&m);
    priority_queue<pair<int,int>>choto;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>boro;

    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        boro.push({x,i});
        choto.push({x,i});

        while(i+1-boro.top().second>m)boro.pop();
        while(i+1-choto.top().second>m)choto.pop();

        re=max(re,abs(boro.top().first-choto.top().first));
    }

    printf("Case %d: %d\n",ii,re);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);

    return 0;
}
