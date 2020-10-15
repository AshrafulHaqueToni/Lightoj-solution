// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 1005
#define ll long long
#define mod 1000000007

int ar[mx];
int col[mx],row[mx];
char ch[mx];
int n,m,k,ii;

int getrow(int st,int per)
{
    int cnt=0;
    int re=0;
    vector<int>tem(n+2,0);
    for(int i=1;i<=n;i++)tem[i]=row[i];
    while(cnt<n)
    {
        if(tem[st]>per)
        {
            int ex=tem[st]-per;
            st++;
            if(st>n)st=1;
            tem[st]+=ex;
            re+=ex;
        }
        else if(tem[st]<per)
        {
            int ex=per-tem[st];
            st++;
            if(st>n)st=1;
            tem[st]-=ex;
            re+=ex;
        }
        else{
          st++;
          if(st>n)st=1;
        }
        cnt++;
    }

    return re;
}

int getcol(int st,int per)
{
    int cnt=0;
    int re=0;
    vector<int>tem(m+2,0);
    for(int i=1;i<=m;i++)tem[i]=col[i];
    //for(int i=1;i<=m;i++)cout<<tem[i];
    //cout<<endl;
   // cout<<st<<endl;
    while(cnt<m)
    {
        if(tem[st]>per)
        {
            int ex=tem[st]-per;
            st++;
            if(st>m)st=1;
            tem[st]+=ex;
            re+=ex;
        }
        else if(tem[st]<per)
        {
            int ex=per-tem[st];
            st++;
            if(st>m)st=1;
            tem[st]-=ex;
            re+=ex;
        }
        else{
          st++;
          if(st>m)st=1;
        }
        cnt++;
    }

   // cout<<re<<endl;

    return re;
}

void solve()
{
   scanf("%d%d",&n,&m);
   int tot=0;
   memset(col,0,sizeof(col));
   memset(row,0,sizeof(row));
   for(int i=1;i<=n;i++)
   {
       scanf(" %s",ch+1);
       for(int j=1;j<=m;j++)
       {
          if(ch[j]=='1')col[j]++,row[i]++,tot++;
       }
   }
  // for(int i=1;i<=n;i++)cout<<row[i];
  // cout<<tot<<endl;

   if(tot%n==0 && tot%m==0)
   {
      int need=0;
      int tar=1e9;
      for(int i=1;i<=n;i++)tar=min(tar,getrow(i,tot/n));
      need+=tar;
      tar=1e9;
      for(int i=1;i<=m;i++)tar=min(tar,getcol(i,tot/m));
      need+=tar;
      printf("Case %d: both %d\n",++ii,need );
   }
   else if(tot%n==0)
   {
     int need=0;
      int tar=1e9;
      for(int i=1;i<=n;i++)tar=min(tar,getrow(i,tot/n));
      need+=tar;
      printf("Case %d: row %d\n",++ii,need );
   }
   else if(tot%m==0)
   {
      int need=0;
      int tar=1e9;
      for(int i=1;i<=m;i++)tar=min(tar,getcol(i,tot/m));
      need+=tar;
      printf("Case %d: column %d\n",++ii,need );
   }
   else printf("Case %d: impossible\n",++ii );
    
}

int main()
{
  int t=1;
  scanf("%d",&t);
  while(t--)
  {
    solve();
  }

  return 0;
}
