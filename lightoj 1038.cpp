#include<bits/stdc++.h>
using namespace std;

#define ll long double
#define mx 100005

ll dp[mx];
bool visit[mx];
vector<int>divi[mx];

ll func(int n)
{
    if(n==1)return 0;
    ll &re=dp[n];
    if(visit[n])return re;
    visit[n]=true;
    ll sum=0;
    ll sz=divi[n].size();
    for(auto it:divi[n])
    {
        if(it==n)break;
        sum+=(func(it)+1.0)/sz;
    }
    cout<<sum<<endl;
    re=(sum*sz+1)/(sz-1);
    //cout<<re<<endl;
    return re;
}

void solve(int ii)
{
    int n;
    scanf("%d",&n);
    printf("Case %d: %0.8LF\n",ii,func(n));
}

int main()
{
    for(int i=1;i<=100000;i++)
    {
        for(int j=i;j<=100000;j+=i)divi[j].push_back(i);
    }
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
