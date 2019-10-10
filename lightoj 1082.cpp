#include<bits/stdc++.h>
using namespace std;

#define ma 500005

int a[ma],tree[4*ma];

int query(int node,int be,int en,int i,int j)
{
    if(i>en||j<be)
        return INT_MAX;

    if(i<=be&&j>=en)
        return tree[node];

    int left=node*2;
    int right=node*2+1;
    int mid=(be+en)/2;

    return min(query(left,be,mid,i,j),query(right,mid+1,en,i,j));
}

void inti(int node,int be,int en)
{
    if(be==en)
    {
        tree[node]=a[be];
        return;

    }
    int left=node*2;
    int right=node*2+1;
    int mid=(be+en)/2;

    inti(left,be,mid);
    inti(right,mid+1,en);

    tree[node]=min(tree[left],tree[right]);
}



int main()
{
    int t;
    scanf("%d",&t);

    for(int ii=1; ii<=t; ii++)
    {
        int n,q;
        scanf("%d%d",&n,&q);

        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);

        inti(1,1,n);

        printf("Case %d:\n",ii);

        while(q--)
        {
            int qq,qqq;
            scanf("%d%d",&qq,&qqq);

            printf("%d\n",query(1,1,n,qq,qqq));

        }

    }

    return 0;
}
