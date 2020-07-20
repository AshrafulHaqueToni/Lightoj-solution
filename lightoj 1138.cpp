#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long

int ar[mx];
char ch[mx];

int n,m,k,ii;

int cnt(int val)
{
    int tem=0;
    int sp=val;
    while(sp>=2)
    {
        tem+=sp/2;
        sp/=2;
    }
    int re=tem;
    tem=0;
    sp=val;
    while(sp>=5)
    {
        tem+=sp/5;
        sp/=5;
    }
    return min(re,tem);
}

void solve()
{
     scanf("%d",&n);
     int be=5,en=1e9;
     int re=-1;
     while(be<=en)
     {
         int mid=(be+en)/2;
         int val=cnt(mid);
       //  cout<<val<<" "<<mid<<endl;
         if(val==n)
         {
             re=mid;
             en=mid-1;
         }
         else
         {
             if(val>n)en=mid-1;
             else be=mid+1;
         }
     }
     printf("Case %d: ",++ii);
     if(re==-1)printf("impossible\n");
     else printf("%d\n",re);
}

int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t=1;
   scanf("%d",&t);
   while(t--)solve();
   return 0;
}
