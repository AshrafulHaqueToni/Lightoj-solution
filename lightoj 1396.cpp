// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define mod 1000000007

int ar[mx],ans[mx];
char ch[mx];
int n,m,k,ii;

void solve()
{
   scanf("%s",ch);
   n=strlen(ch);
   bool f=true;
   for(int i=0;i<n;i++)
    {
      ar[i]=ch[i]-'0';
      if(ar[i]!=9)f=false;
    }
   printf("Case %d: ",++ii );
   if(n==1)
   {
      if(ar[0]<9)
      printf("%d\n",ar[0]+1);
      else printf("11\n");
      return;
   }
   if(f)
   {
      printf("1");
      for(int i=1;i<n;i++)printf("0");
      printf("1\n");
      return;
   }
   int mid=(n-1)/2;
   f=true;
   int idx;
   //cout<<n<<" "<<mid<<endl;
   for(int i=mid;i>=0;i--)
   {
      // cout<<ar[i]<<" "<<ar[n-i-1]<<endl;
       if(ar[i]!=ar[n-i-1])
       {
          if(ar[i]>ar[n-i-1])
          {
          f=false;
          idx=i;
          }
          break;
       }
   }

   if(!f)
   {
       for(int i=mid;i>=0;i--)
       {
          ans[i]=ans[n-i-1]=ar[i];
       }
   }
   else
   {
      for(int i=mid;i>=0;i--)
      {
        if(ar[i]!=9)
        {
          idx=i;
          ar[i]++;
          break;
        }
      }

     // cout<<n-idx-1<<endl;

      for(int i=idx;i>=0;i--)ans[i]=ar[i],ans[n-i-1]=ar[i];
      for(int i=mid;i>idx;i--)ans[i]=0,ans[n-i-1]=0;
   }

   for(int i=0;i<n;i++)printf("%d",ans[i]);
    printf("\n");
   

    
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
