#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;

int zero(int val)
{
    int re=0;

    ll tem=5;

    while(val>=tem)
    {
        re+=val/tem;
        tem*=5;
    }

    return re;
}

int func(int be,int en)
{
    if(be>en)return -1;

    int mid=(be+en)/2;

    int cnt=zero(mid);

    if(cnt==n)
    {
        while(cnt==zero(mid))
        {
            mid--;
        }
        return ++mid;
    }
    else
    {
        if(cnt>n)return func(be,mid-1);
        else return func(mid+1,en);
    }
}

void solve(int ii)
{
   scanf("%d",&n);

   int val=func(1,1e9);

   if(val!=-1)
   {
       printf("Case %d: %d\n",ii,val);
   }
   else printf("Case %d: impossible\n",ii);
}

int main()
{
    int t=1;
    scanf("%d",&t);

    for(int ii=1;ii<=t;ii++)solve(ii);
}
