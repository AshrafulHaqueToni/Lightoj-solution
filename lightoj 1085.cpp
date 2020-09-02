#include<bits/stdc++.h>
using namespace std;


#define mx 100005
#define ll long long 
#define mod 1000000007

void IO()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  #endif
}



int m,n,k,ii,q;
ll Tree[mx*4];
vector<pair<int,int>>ar;

ll add(ll a,ll b)
{
  a+=b;
  if(a>=mod)a-=mod;
  return a;
}

void update(int node,int be,int en,int pos,ll val)
{
  if(pos>en || pos<be)return;
  if(be==en)
  {
    Tree[node]=val;
   // cout<<Tree[node]<<endl;
    return;
  }
  int mid=(be+en)/2;
  update(node*2,be,mid,pos,val);
  update(node*2+1,mid+1,en,pos,val);
  Tree[node]=add(Tree[node*2+1],Tree[node*2]);
}

ll query(int node,int be,int en,int i,int j)
{
  if(i>en || j<be)return 0;
  if(i<=be && j>=en)return Tree[node];
  int mid=(be+en)/2;
  return add(query(node*2,be,mid,i,j),query(node*2+1,mid+1,en,i,j));
}



void solve()
{
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
    int x;
    scanf("%d",&x);
    ar.push_back({x,i});
  } 
  sort(ar.begin(),ar.end(),[&](pair<int,int> i,pair<int,int> j)
    {
      if(i.first==j.first)return i.second>j.second;
      return (i.first<j.first);
    }
    );
  for(int i=n;i>=1;i--)
  {
        ll val=query(1,1,n,ar[i-1].second,n);
       // cout<<add(val,1)<<" "<<ar[i-1].second<<" "<<ar[i-1].first<<endl;
        update(1,1,n,ar[i-1].second,add(val,1));
  }
  printf("Case %d: %lld\n",++ii,Tree[1] );
  ar.clear();
  memset(Tree,0,sizeof(Tree));


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
