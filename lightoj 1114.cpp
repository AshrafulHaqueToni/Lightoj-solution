#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long

int ar[mx];
char ch[mx];

int n,m,k,ii;

void solve()
{
     scanf("%d",&n);
     map<string,int>mp;
     for(int i=1;i<=n;i++)
     {
         string s;
         cin>>s;
         if(s.size()>3)
         {
             sort(s.begin()+1,s.end()-1);
         }
         mp[s]++;
     }
     scanf("%d ",&m);
     printf("Case %d:\n",++ii);

     string tt;
     while(m--)
     {
         string s;
         getline(cin,s);
        // cout<<s<<endl;
         stringstream t(s);
         ll re=1;
         while((t>>tt))
         {

             if(tt.size()>3)
             {
                 sort(tt.begin()+1,tt.end()-1);

             }
            // cout<<re<<endl;
              re=re*mp[tt];
         }
         printf("%lld\n",re);
     }
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
