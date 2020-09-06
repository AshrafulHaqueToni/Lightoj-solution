#include<bits/stdc++.h>
using namespace std;

#define mx 1000005
#define ll long long 

void IO()
{
     #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
}

int ar[mx];
int pre[mx],suf[mx];
int m,n,k,ii,dek;

void solve()
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++)scanf("%d",&ar[i]),pre[i]=0,suf[i]=0;
   stack<pair<int,int>>s;
   for(int i=1;i<=n;i++)
   {
   	   if(s.empty())
   	   {
   	   	  s.push({ar[i],i});
   	   	  continue;
   	   }
   	   while(!s.empty() && s.top().first>=ar[i])
   	   {
   	   	  pre[i]+=pre[s.top().second]+1;
   	   	  s.pop();
   	   }
   	   s.push({ar[i],i});
       
   }
   while(!s.empty())s.pop();
    for(int i=n;i>=1;i--)
   {
   	   if(s.empty())
   	   {
   	   	  s.push({ar[i],i});
   	   	  continue;
   	   }
   	   while(!s.empty() && s.top().first>=ar[i])
   	   {
   	   	  suf[i]+=suf[s.top().second]+1;
   	   	  s.pop();
   	   }
   	   s.push({ar[i],i});
       
   }
   
   int re=0;
    for(int i=1;i<=n;i++)
   {
   	  int val=pre[i]+suf[i]+1;
   	 // cout<<pre[i]<<" "<<suf[i]<<" "<<ar[i]<<endl;
   	  re=max(re,val*ar[i]);
   }

   printf("Case %d: %d\n",++ii,re );
}

int main()
{
    IO();
    int t=1;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
    return 0;
}
