#include<bits/stdc++.h>
using namespace std;
 
#define mx 1429431

void IO()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
}
 
int ii,n,q;
int Tree[4*mx+5];

void built(int node,int be,int en)
{
    if(be==en)
    {
        Tree[node]=be%2;
        return;
    }
    int mid=(be+en)/2;
    built(node*2,be,mid);
    built(node*2+1,mid+1,en);
    Tree[node]=Tree[node*2]+Tree[node*2+1];
}

int query(int node,int be,int en,int kth)
{
    if(be==en )
    {
        return be;
    }
    int mid=(be+en)/2;
    if(kth<=Tree[node*2])return query(node*2,be,mid,kth);
    else return query(node*2+1,mid+1,en,kth-Tree[node*2]);
}

void update(int node,int be,int en,int kth)
{
    if(be==en )
    {
        Tree[node]=0;
        return;
    }
    int mid=(be+en)/2;
    if(kth<=Tree[node*2])update(node*2,be,mid,kth);
    else update(node*2+1,mid+1,en,kth-Tree[node*2]);
    Tree[node]=Tree[node*2]+Tree[node*2+1];
}

void solve()
{
   scanf("%d",&n);
   printf("Case %d: %d\n",++ii,query(1,1,mx,n) );

}

 
int main()
{
    IO();
    built(1,1,mx);
    for(int i=2;i<=100000;i++)
    {
        int pos=query(1,1,mx,i);
        int cnt=pos;
        while(pos<=mx)
        {
            update(1,1,mx,pos);
            pos+=cnt-1;
        }
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
    
 
    return 0;
}
