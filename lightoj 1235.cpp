#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define mx 100005
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx];

int n,k;
vector<ll>sum1,sum2;

void func(ll sum,int be,int en,vector<ll>&v)
{
    if(be==en)
    {
        v.push_back(sum);
        return;
    }
    for(int i=0;i<3;i++)func(sum+ar[be]*i,be+1,en,v);
}

void solve(int ii)
{
   sum1.clear();
   sum2.clear();
   scanf("%d%d",&n,&k);
   for(int i=0;i<n;i++)scanf("%d",&ar[i]);
   func(0,0,n/2,sum1);
   func(0,n/2,n,sum2);
   sort(sum1.begin(),sum1.end());
   bool f=true;
   for(auto it:sum2)
   {
       if(k>=it)
       {
           if(*lower_bound(sum1.begin(),sum1.end(),k-it)==k-it)
           {
               f=false;
               break;
           }
       }
   }
   if(!f)
   {
       printf("Case %d: Yes\n",ii);
   }
   else printf("Case %d: No\n",ii);
}

int main()
{
    int t=1;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}

