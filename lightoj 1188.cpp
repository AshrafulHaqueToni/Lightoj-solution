//// Segment Tree Solution
#include<bits/stdc++.h>
using namespace std;


#define mx 100005
#define ll long long 

void IO()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  #endif
}


int re[mx],ar[mx],mark[mx];
int m,n,k,ii;
int Tree[4*mx];
vector<pair<int,int>>point[mx];

void update(int node,int be,int en,int pos,int val)
{
  if(be>pos || en<pos)return;
  if(be==en)
  {
    Tree[node]=val;
    return;
  }
  int mid=(be+en)/2;
  update(node*2,be,mid,pos,val);
  update(node*2+1,mid+1,en,pos,val);
  Tree[node]=Tree[node*2]+Tree[node*2+1];
}

int query(int node,int be,int en,int i,int j)
{
  if(be> j || i>en)return 0;
  if(i<=be && j>=en)return Tree[node];
  int mid=(be+en)/2;
  return query(node*2,be,mid,i,j)+query(node*2+1,mid+1,en,i,j);
}


void solve()
{
   
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)scanf("%d",&ar[i]),mark[ar[i]]=0,update(1,1,n,i,0),point[i].clear();
  for(int i=1;i<=m;i++)
  {
    int x,y;
    scanf("%d%d",&x,&y);
    point[y].push_back({x,i});
  }
  for(int i=1;i<=n;i++)
  {
    if(mark[ar[i]]!=0)
    {
      update(1,1,n,mark[ar[i]],0);
    }
    mark[ar[i]]=i;
    update(1,1,n,mark[ar[i]],1);
    for(auto it:point[i])
    {
       int val=query(1,1,n,it.first,i);
       re[it.second]=val;
    }
  }
  printf("Case %d:\n",++ii );
  for(int i=1;i<=m;i++)printf("%d\n",re[i]);
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

//// MO's solution

#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define block 555

struct me
{
    int lft,rht,idx;
} tree[mx];

int a[mx],cnt[mx],ans[mx],re;

bool cmp(me p1,me p2)
{
    if(p1.lft/block != p2.lft/block)
        return p1.lft/block < p2.lft/block;

    return p1.rht < p2.rht;
}


void Add(int pos)
{
    if(cnt[a[pos]])
        re--;

    cnt[a[pos]]++;

    if(cnt[a[pos]])
        re++;

}

void Remove(int pos)
{
    if(cnt[a[pos]])
        re--;

    cnt[a[pos]]--;

    if(cnt[a[pos]])
        re++;

}

int main()
{
    //freopen("1088.txt","r",stdin);
    int t;
    scanf("%d",&t);

    for(int ii=1; ii<=t; ii++)
    {
        memset(ans,0,sizeof(ans));
        memset(cnt,0,sizeof(cnt));

        int n,q;
        re=0;
        scanf("%d %d",&n,&q);

        for(int i=0; i<n; i++)
            scanf("%d",a+i);

        for(int i=0; i<q; i++)
        {
            scanf("%d %d",&tree[i].lft,&tree[i].rht);

            tree[i].lft--;
            tree[i].rht--;
            tree[i].idx=i;
        }

        sort(tree,tree+q,cmp);

//        for(int i=0;i<q;i++)
//        {
//            cout<<tree[i].lft<<" "<<tree[i].rht<<" "<<tree[i].idx<<endl;
//        }


        int cur_l=0,cur_r=0;


        for(int i=0; i<q; i++)
        {
            int l=tree[i].lft,r=tree[i].rht;

            while(cur_l<l)
                Remove(cur_l++);

            while(cur_l>l)
                Add(--cur_l);

            while(cur_r<=r)
                Add(cur_r++);

            while(cur_r>r+1)
                Remove(--cur_r);

            ans[tree[i].idx]=re;
        }

        printf("Case %d:\n",ii);

        for(int i=0; i<q; i++)
        {
            printf("%d\n",ans[i]);
        }

//        for(int i=0;i<=q;i++)
//        {
//            tree[i].idx=0;
//            tree[i].lft=0;
//            tree[i].rht=0;
//        }

    }

    return 0;
}
