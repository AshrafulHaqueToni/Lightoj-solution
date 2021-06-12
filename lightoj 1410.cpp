// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 705
#define ll long long
#define mod 1000000007
 
int ar[mx][2];
char ch[mx];
int n,m,ii,k;


 
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&ar[i][0],&ar[i][1]);
    vector<int>s;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int x=ar[i][0]-ar[j][0];
            int y=ar[i][1]-ar[j][1];
            s.push_back(x*x+y*y);
        }
    }

    sort(s.begin(),s.end());

    int re=1+distance(s.begin(),unique(s.begin(),s.end()));
   

    printf("Case %d: %d\n",++ii,re);
  
    
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
