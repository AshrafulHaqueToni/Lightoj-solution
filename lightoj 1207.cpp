#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define mx 200005

struct me
{
    int sum;
} tree[4*mx],dummy;

int lazy[4*mx];
set<int>s;


void relax(int node,int be,int en)
{
    tree[node].sum=lazy[node];

    if(be!=en)
    {
        lazy[node*2]=lazy[node];
        lazy[node*2+1]=lazy[node];
    }

    lazy[node]=0;
}

void update(int node,int be,int en,int i,int j,int val)
{
    if(lazy[node])
        relax(node,be,en);

    if(i>en||j<be)
        return;

    if(i<=be&&j>=en)
    {
        lazy[node]=val;
        relax(node,be,en);
        return;
    }

    int mid=(be+en)/2;

    update(node*2,be,mid,i,j,val);
    update(node*2+1,mid+1,en,i,j,val);

    // tree[node]=Merge(tree[node*2],tree[node*2+1]);

}

void query(int node,int be,int en)
{
    if(lazy[node])relax(node,be,en);

    if(be==en)
    {
        if(tree[node].sum)s.insert(tree[node].sum);
        return;
    }
    int mid=(be+en)/2;

    query(node*2,be,mid);
    query(node*2+1,mid+1,en);

}

int main()
{
    //freopen("1207.txt","r",stdin);
    int t;
    scanf("%d",&t);

    for(int ii=1; ii<=t; ii++)
    {
        memset(lazy,0,sizeof(lazy));

        int n;

        scanf("%d",&n);


        // for(int i=1;i<=n*4;i++)cout<<tree[i].sum<<endl;


        //printf("Case %d: ",ii);

        for(int i=1; i<=n; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);

            update(1,1,2*n,u,v,i);
        }

        query(1,1,n*2);

        printf("Case %d: %d\n",ii,s.size());

        s.clear();

        for(int i=0;i<=n*8;i++)tree[i].sum=0;

    }
    return 0;

}
