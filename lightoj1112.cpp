#include<bits/stdc++.h>
using namespace std;

#define mx 100005


struct me
{
    int sum;
}tree[mx*4],dummy;

int a[mx];

me Merge(me p1, me p2)
{
    me re;

    re.sum=p1.sum+p2.sum;

    return re;
}

me query(int node,int be,int en,int i,int j)
{
    if(be>j||i>en||be>en)return dummy;

    if(i<=be&&j>=en)return tree[node];

    int mid=(be+en)/2;
    me p1,p2;

    p1=query(node*2,be,mid,i,j);
    p2=query(node*2+1,mid+1,en,i,j);

    return Merge(p1,p2);
}

void update(int node,int be,int en,int pos,int val)
{
    if(pos<be||pos>en||be>en)return;

    if(be==pos&&en==pos)
    {
        tree[node].sum+=val;
        return;
    }

    int mid=(be+en)/2;

    update(node*2,be,mid,pos,val);

    update(node*2+1,mid+1,en,pos,val);

    tree[node]=Merge(tree[node*2],tree[node*2+1]);
}

void Remove(int node,int be,int en,int pos)
{
    if(pos<be||pos>en||be>en)return;

    if(be==pos&&en==pos)
    {
        printf("%d\n",tree[node].sum);

        tree[node].sum=0;
        return;
    }

    int mid=(be+en)/2;

    Remove(node*2,be,mid,pos);

    Remove(node*2+1,mid+1,en,pos);

    tree[node]=Merge(tree[node*2],tree[node*2+1]);
}


void built(int node,int be,int en)
{
    if(be==en)
    {
        tree[node].sum=a[be];

        return;
    }

    int mid=(be+en)/2;

    built(node*2,be,mid);

    built(node*2+1,mid+1,en);

    tree[node]=Merge(tree[node*2],tree[node*2+1]);
}



int main()
{
    int t;
    scanf("%d",&t);

    for(int ii=1;ii<=t;ii++)
    {
        int n,q;

        scanf("%d %d",&n,&q);

        for(int i=1;i<=n;i++)scanf("%d",a+i);

        built(1,1,n);

        printf("Case %d:\n",ii);

        while(q--)
        {
            int num,pos;

            scanf("%d %d",&num,&pos);

            pos++;

            if(num==1){
                Remove(1,1,n,pos);
            }
            if(num==2)
            {
                int val;
                scanf("%d",&val);
                update(1,1,n,pos,val);
            }
            if(num==3)
            {
                int j;
                scanf("%d",&j);

                me re;
                j++;

                re=query(1,1,n,pos,j);

                printf("%d\n",re.sum);
            }
        }
    }

    return 0;
}

