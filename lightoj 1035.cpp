#include<bits/stdc++.h>
using namespace std;

#define mx 205
#define ll long long

int ar[mx];
char ch[mx];
int spf[mx];
int ans[mx][mx];

int n,m,k,ii;

void seive()
{
    for(int i=2;i<=100;i++)spf[i]=i;
    for(int i=2;i<=10;i++)
    {
        if(spf[i]==i)
        {
            for(int j=i*i;j<=100;j+=i)
            {
                if(spf[j]==j)spf[j]=i;

            }
        }
    }
    for(int i=2;i<=100;i++)
    {
        int val=i;
        while(val>1)
        {
            int sp=spf[val];
            int cnt=0;
            while(val%sp==0)val/=sp,cnt++;
            ans[i][sp]=cnt;
//            if(i<10)
//            {
//                cout<<i<<" "<<sp<<" "<<cnt<<endl;
//            }
        }
        for(int j=2;j<=100;j++)ans[i][j]+=ans[i-1][j];
    }
}

void solve()
{
   scanf("%d",&n);
   printf("Case %d: %d =",++ii,n);
   bool f=true;
   for(int i=1;i<=100;i++)
   {
     //  cout<<ans[n][i]<<endl;
       if(ans[n][i])
       {
           if(f)
           {
               printf(" %d (%d)",i,ans[n][i]);
               f=false;
           }
           else
           {
               printf(" * %d (%d)",i,ans[n][i]);
           }
       }
   }
   printf("\n");
}

int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t=1;
   seive();
   scanf("%d",&t);
   while(t--)solve();
   return 0;
}
