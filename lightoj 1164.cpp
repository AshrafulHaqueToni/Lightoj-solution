#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define mx 100005

struct me
{
    ll sum;
}tree[4*mx],dummy;

ll a[mx],lazy[4*mx];

me Merge(me p1,me p2)
{
    me re;
    re.sum=p1.sum+p2.sum;

    return re;
}

void relax(int node,int be,int en)
{
    tree[node].sum+=(en-be+1)*lazy[node];

    if(be!=en)
    {
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
    }

    lazy[node]=0;
}

void update(int node,int be,int en,int i,int j,int val)
{
    if(lazy[node])relax(node,be,en);

    if(i>en||j<be)return;

    if(i<=be&&j>=en)
    {
        lazy[node]+=val;
        relax(node,be,en);
        return;
    }

    int mid=(be+en)/2;

    update(node*2,be,mid,i,j,val);
    update(node*2+1,mid+1,en,i,j,val);

    tree[node]=Merge(tree[node*2],tree[node*2+1]);

}

me query(int node,int be,int en,int i,int j)
{


    if(i>en||j<be)return dummy;

     if(lazy[node])relax(node,be,en);

    if(i<=be&&j>=en)return tree[node];

    int mid=(be+en)/2;

    me p1,p2;

    p1=query(node*2,be,mid,i,j);

    p2=query(node*2+1,mid+1,en,i,j);

    return Merge(p1,p2);
}


int main()
{
    //freopen("1164.txt","r",stdin);
    int t;
    scanf("%d",&t);

    for(int ii=1;ii<=t;ii++)
    {
        memset(lazy,0,sizeof(lazy));

        int n,q;

        scanf("%d %d",&n,&q);


       // for(int i=1;i<=n*4;i++)cout<<tree[i].sum<<endl;


        printf("Case %d:\n",ii);

        while(q--)
        {
            int d,x,y;
            scanf("%d %d %d",&d,&x,&y);

            if(!d)
            {
                int val;

                scanf("%d",&val);

                x++,y++;

                update(1,1,n,x,y,val);

//                for(int i=1;i<=n*4;i++)cout<<tree[i].sum<<" ";
//                cout<<endl;
            }
            else
            {
                me fi;

                x++,y++;

                fi=query(1,1,n,x,y);

                printf("%lld\n",fi.sum);
            }
        }

        for(int i=0;i<=n*4;i++)tree[i].sum=0;
    }
}
