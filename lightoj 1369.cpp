// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 200005
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k;

namespace Segment_Tree
{
    const int N=100005;
    ll Tree[N*4];
    void init(int node,int be,int en)
    {
        if(be==en)
        {
            Tree[node]=ar[be];
            return;
        }
        int mid=(be+en)/2;
        init(node*2,be,mid);
        init(node*2+1,mid+1,en);
        Tree[node]=Tree[node*2]+Tree[node*2+1];
    }

    void update(int node,int be,int en,int pos,int val)
    {
        if(be> pos || en<pos)return;
        if(be==en)
        {
            Tree[node]=val;
            return;
        }
        int mid=(be+en)/2;
        update(node*2,be,mid,pos,val);
        update(node*2+1,mid+1,en,pos,val);
        Tree[node]=(Tree[node*2]+Tree[node*2+1]);
    }

    ll query(int node,int be,int en,int i,int j)
    {
        if(be>j || en<i)return 0;
        if(be>=i && en<=j)return Tree[node];
        int mid=(be+en)/2;
        return (query(node*2,be,mid,i,j)+query(node*2+1,mid+1,en,i,j));
    }


}
using namespace Segment_Tree;
 
void solve()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&ar[i]);
    init(1,1,n);
    ll re=0;
    for(int id=1;id<=n;id++)
    {
        re+=((ll)ar[id]*(n-id))-query(1,1,n,id+1,n);
    }
    
    printf("Case %d:\n",++ii );
    for(int i=1;i<=m;i++)
    {
        int ti;
        scanf("%d",&ti);
        if(ti==0)
        {
            int id,val;
            scanf("%d%d",&id,&val);
            id++;
            re-=((ll)ar[id]*(n-id))-query(1,1,n,id+1,n);
            re-=query(1,1,n,1,id-1)-((ll)ar[id]*(id-1));
           
            ar[id]=val;
            update(1,1,n,id,val);
            re+=((ll)ar[id]*(n-id))-query(1,1,n,id+1,n);
            re+=query(1,1,n,1,id-1)-((ll)ar[id]*(id-1));

        }
        else printf("%lld\n",re );
    }
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
