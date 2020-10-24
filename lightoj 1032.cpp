// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx];
int n,m,k,ii;
ll dp[32][3][3][32];
int vis[32][3][3][32];
string s;

void Convert()
{
  s="";
  while(n>0)
  {
    //cout<<(n%2)<<endl;
    if(n%2==0)s+='0';
    else s+='1';
    n/=2;
  }
  reverse(s.begin(),s.end());
  m=s.size();
  for(int i=m;i<31;i++)s='0'+s;
 // cout<<s<<endl;
}

ll func(int pos,int Small,int last,int cnt)
{
  if(pos>30)return cnt;
  if(vis[pos][Small][last][cnt]==ii)return dp[pos][Small][last][cnt];
  vis[pos][Small][last][cnt]=ii;
  ll re=0;
  int lo=0,hi=1;
  if(!Small)hi=s[pos]-'0';
  //cout<<pos<<" "<<hi<<" "<<isSmall<<" "<<last<<endl;
  for(int i=lo;i<=hi;i++)
  {
    int isSmall=Small | (i<hi);
    int isCnt=cnt+(last==i && i==1);
    re+=func(pos+1,isSmall,i,isCnt);
  }
  return dp[pos][Small][last][cnt]=re;
}


void solve()
{
   scanf("%d",&n);
   Convert();
   ii++;
   printf("Case %d: %lld\n",ii,func(0,0,0,0));
    
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
