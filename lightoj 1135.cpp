#include<bits/stdc++.h>
using namespace std;
 
#define mx 100005
 
int lazy[4*mx];
 
struct me
{
    int c1,c2,c3;
    me()
    {
        c1=c2=c3=0;
    }
} tree[4*mx],zero;
 
me Merge(me p1,me p2)
{
    me re;
    re.c1=p1.c1+p2.c1;
    re.c2=p1.c2+p2.c2;
    re.c3=p1.c3+p2.c3;
 
    return re;
}
 
void relax(int node,int be,int en)
{
 
 
    if(lazy[node]%3==1)
    {
        int v1=tree[node].c1;
        tree[node].c1=tree[node].c3;
        tree[node].c3=tree[node].c2;
        tree[node].c2=v1;
    }
    if(lazy[node]%3==2)
    {
        int v1=tree[node].c1;
        tree[node].c1=tree[node].c2;
        tree[node].c2=tree[node].c3;
        tree[node].c3=v1;
    }
 
    if(be!=en)
    {
        lazy[2*node]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
    }
    lazy[node]=0;
 
 
}
 
 
void rangeupdate(int node,int be,int en,int i,int j)
{
    if(lazy[node])relax(node,be,en);
 
    if(i>en||j<be)
        return;
 
    //if(lazy[node])relax(node,be,en);
 
 
 
    if(i<=be&&j>=en)
    {
        lazy[node]+=1;
        relax(node,be,en);
        return;
    }
 
    int mid=(be+en)/2;
 
    rangeupdate(node*2,be,mid,i,j);
    rangeupdate(node*2+1,mid+1,en,i,j);
 
    tree[node]=Merge(tree[2*node],tree[node*2+1]);
 
 
 
}
 
void update(int node,int be,int en)
{
 
    if(be==en)
    {
        tree[node].c1=1;
        return;
    }
 
    int mid=(be+en)/2;
 
    update(node*2,be,mid);
    update(node*2+1,mid+1,en);
 
    tree[node]=Merge(tree[2*node],tree[node*2+1]);
}
 
me query(int node,int be,int en,int i,int j)
{
    if(i>en||j<be)
        return zero;///totally out
 
    if(lazy[node])
    {
        relax(node,be,en);
    }
 
    if(i<=be&&j>=en)
        return tree[node];///totally in
 
    int left=node*2;
    int right=left+1;
    int mid=(be+en)/2;
 
    me p1=query(left,be,mid,i,j);
    me p2=query(right,mid+1,en,i,j);
 
    return Merge(p1,p2);
}
 
 
int main()
{
    //freopen("3mul.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int ii=1; ii<=t; ii++)
    {
        memset(lazy,0,sizeof(lazy));
        for(int i=1;i<=mx*4;i++){
            tree[i].c1=0;
            tree[i].c2=0;
            tree[i].c3=0;
        }
        int n,q;
        scanf("%d%d",&n,&q);
 
 
        update(1,1,n);
 
        printf("Case %d:\n",ii);
        while(q--)
        {
 
            int m,i,j;
            scanf("%d",&m);
            if(m==0)
            {
                scanf("%d%d",&i,&j);
                i++,j++;
                rangeupdate(1,1,n,i,j);
            }
            else
            {
 
                scanf("%d%d",&i,&j);
                i++,j++;
 
                me fi=query(1,1,n,i,j);
 
                printf("%d\n",fi.c1);
            }
        }
    }
}
