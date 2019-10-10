#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 100005

struct me
{
    ll val;
}tree[4*mx];

int lazy[mx*4];

void relax(int node,int be,int en)
{
    tree[node].val=lazy[node]*(en-be+1);

    if(be!=en)
    {
       lazy[node*2]=lazy[node];
       lazy[node*2+1]=lazy[node];
    }
    lazy[node]=-1;
}

ll query(int node,int be,int en,int i,int j)
{

    if(i>en||j<be)return 0ll;

    if(lazy[node]!=-1)
    {
        relax(node,be,en);
    }


    if(i<=be&&j>=en){
        return tree[node].val;
    }

    int mid=(be+en)/2;

    ll p1=query(node*2,be,mid,i,j);
    ll p2=query(node*2+1,mid+1,en,i,j);

    return p1+p2;
}

void update(int node,int be,int en,int i,int j,int val)
{
    if(lazy[node]!=-1)
    {
        relax(node,be,en);
    }

    if(i>en||j<be)return;

    if(i<=be&&j>=en){
        lazy[node]=val;
        relax(node,be,en);

        return;
    }

    int mid=(be+en)/2;
    update(node*2,be,mid,i,j,val);
    update(node*2+1,mid+1,en,i,j,val);

    tree[node].val=tree[node*2].val+tree[node*2+1].val;

}

int main()
{
    //freopen("input.txt","r",stdin);

    int t;
    scanf("%d",&t);

    for(int ii=1;ii<=t;ii++)
    {
       int n,q;

       scanf("%d%d",&n,&q);

       for(int i=0;i<=n*4;i++)lazy[i]=-1;

       printf("Case %d:\n",ii);

       while(q--)
       {
           int type,x,y;

           scanf("%d%d%d",&type,&x,&y);
           x++,y++;

           if(type==1)
           {
               int val;

               scanf("%d",&val);

               update(1,1,n,x,y,val);
           }

           else{

              ll re=query(1,1,n,x,y);

              ll num=y-x+1;

              ll gcd=__gcd(re,num);

             // for(int i=1;i<n*4;i++)cout<<tree[i].val<<" ";
             // cout<<endl<<re<<endl;

              if(re%num==0){

                printf("%lld\n",re/num);

              }
              else{

                printf("%lld/%lld\n",re/gcd,num/gcd);

              }
           }
       }

       for(int i=1;i<=n*4;i++)tree[i].val=0;

    }
    return 0;
}
