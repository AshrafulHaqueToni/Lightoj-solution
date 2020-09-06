#include<bits/stdc++.h>
using namespace std;

#define mx 2005
#define ll long long 

char ch[mx][mx];
int ar[mx];
int pre[mx],suf[mx];
int m,n,k,ii,dek;

int func()
{
   for(int i=1;i<=m;i++)pre[i]=0,suf[i]=0;
   stack<pair<int,int>>s;
   for(int i=1;i<=m;i++)
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
    for(int i=m;i>=1;i--)
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
    for(int i=1;i<=m;i++)
   {
   	  int val=pre[i]+suf[i]+1;
   	 // cout<<pre[i]<<" "<<suf[i]<<" "<<ar[i]<<endl;
   	  re=max(re,val*ar[i]);
   }

   // for(int i=1;i<=m;i++)printf("%d ",ar[i] );
   // printf("\n");

   return re;
}


void solve()
{
   scanf("%d%d",&n,&m);
   for(int i=0;i<n;i++)scanf("%s",ch[i]);
   for(int i=0;i<m;i++)ar[i+1]=1-(ch[0][i]-'0');
   int re=0;
   re=max(re,func());

   for(int i=1;i<n;i++)
   {
   	   for(int j=0;j<m;j++)
   	   {
   	   	  if(ch[i][j]=='0')ar[j+1]++;
   	   	  else ar[j+1]=0;
   	   }
   	   re=max(re,func());
   }
   printf("Case %d: %d\n",++ii,re );
}  

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    int t=1;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
    return 0;
}
