// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 10005
#define ll long long



string ch[2];
int n,m,ii,k;
vector<int>g[mx][2];
int sub[mx][2];
ll H[mx][2];
ll Base[]={1040160883,1066517951};
ll mod[]={1072857881,1000004249};


ll mul(ll a,ll b,int ty)
{
   a*=b;
   if(a>=mod[ty])a%=mod[ty];
   return a;
}
ll add(ll a,ll b,int ty)
{
   a+=b;
   if(a>=mod[ty])a-=mod[ty];
   return a;
}

pair<ll,ll> get_hash(int u,int l,int ty)
{
   sub[u][ty]=1;
   pair<ll,ll> re={0,0};
   for(int v:g[u][ty])
   {
      pair<ll,ll>tem=get_hash(v,l+1,ty);
      re.first=add(re.first,tem.first,0);
      re.second=add(re.second,tem.second,1);
      sub[u][ty]+=sub[v][ty];
   }
   re.first=add(re.first,mul(add(H[l][0],sub[u][ty],0),sub[u][ty],0),0);
   re.second=add(re.second,mul(add(H[l][1],sub[u][ty],1),sub[u][ty],1),1);
   return re;

}
 
void solve()
{
   ch[0]="";
   ch[1]="";
   getline(cin,ch[0]);
   getline(cin,ch[1]);

   n=ch[0].size();
   stack<int>st;
   st.push(1);
   int cnt=1;
   for(int i=0;i<n;i++)
   {
      if(ch[0][i]=='0')st.pop();
      else
      {
         g[st.top()][0].push_back(++cnt);
         st.push(cnt);
      }
   }
   while(!st.empty())st.pop();
   st.push(1);
   cnt=1;
   for(int i=0;i<n;i++)
   {
      if(ch[1][i]=='0')st.pop();
      else
      {
         g[st.top()][1].push_back(++cnt);
         st.push(cnt);
      }
   }
   pair<ll,ll> val1=get_hash(1,1,0);
   pair<ll,ll> val2=get_hash(1,1,1);
   //cout<<val1<<" "<<val2<<endl;
   for(int i=1;i<mx;i++)g[i][0].clear(),g[i][1].clear();
   if(val1==val2)
   {
      printf("Case %d: Same\n",++ii );
   }
   else printf("Case %d: Different\n",++ii );
}
 
int main()
{
   int t=1;
   H[0][0]=H[0][1]=1;
   for(int i=1;i<mx;i++)
      for(int j=0;j<1;j++)H[i][j]=mul(H[i-1][j],Base[j],j);
   scanf("%d",&t);
   getline(cin,ch[0]);
   while(t--)solve();
   return 0;
}
