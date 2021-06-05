// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 60005
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k;

struct point
{
    int x,y1,y2,op;
};
 
void solve()
{
    vector<point>v;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        v.push_back({a,b,d,0});
        v.push_back({c,b,d,1});
    }
    sort(v.begin(),v.end(),[&](point a,point b){
        return a.x<b.x;
    });

    // for(auto it:v)
    // {
    //     cout<<it.x<<" "<<it.y1<<" "<<it.y2<<" "<<it.op<<endl;
    // }
    multiset<int>ms;
    ms.insert(v[0].y1);
    ms.insert(v[0].y2);
    ll x1=v[0].x;
    ll re=0;
    for(int i=1;i<(n+n);i++)
    {
        ll y1=*ms.begin();
        ll y2=*ms.rbegin();
        ll x2=v[i].x;
        //cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
        re+=(x2-x1)*(y2-y1);
        x1=x2;
        if(v[i].op==0)
        {
            ms.insert(v[i].y1);
            ms.insert(v[i].y2);
        }
        else
        {
            ms.erase(ms.find(v[i].y1));
            ms.erase(ms.find(v[i].y2));
        }
    }
    printf("Case %d: %lld\n",++ii,re );
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
