#include<bits/stdc++.h>
using namespace std;

#define mx 100005

struct me
{
    int val;

} tree[mx*4],dummy;

char ch[mx],c;

int lazy[mx*4];


void relax(int node,int be,int en)
{
    if(lazy[node]&1)
        tree[node].val=abs(tree[node].val-1);
    //cout<<node<<endl;

    if(be!=en)
    {
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
    }
    lazy[node]=0;
}

void query(int node,int be,int en,int pos)
{

    if(pos<be||pos>en||be>en)
        return ;

    if(lazy[node])
    {
        relax(node,be,en);
    }

    if(be==pos&&en==pos)
    {
        printf("%d\n",tree[node].val);
        return ;
    }

    int mid=(be+en)/2;



    query(node*2,be,mid,pos);

    query(node*2+1,mid+1,en,pos);


}


void rangeupdate(int node,int be,int en,int i,int j)
{

    if(lazy[node])
    {
        relax(node,be,en);
    }

    if(i>en||j<be)
        return;

    if(i<=be&&j>=en)
    {

        lazy[node]+=1;

        relax(node,be,en);

        return;
    }

    int mid=(be+en)/2;

    rangeupdate(node*2,be,mid,i,j);
    rangeupdate(node*2+1,mid+1,en,i,j);


    //tree[node]=Merge(tree[node*2],tree[node*2+1]);
}


void built(int node,int be,int en)
{
    //if(be>en)
    // return;

    if(be==en)
    {
        tree[node].val=ch[be-1]-48;
        //cout<<be<<" "<<node<<"\n";
        return;
    }

    int mid=(be+en)/2;

    built(node*2,be,mid);
    built(node*2+1,mid+1,en);

    //tree[node]=Merge(tree[node*2],tree[node*2+1]);
}


int main()
{
    //freopen("1080.txt","r",stdin);


    int t;

    scanf("%d",&t);

    for(int ii=1; ii<=t; ii++)
    {
        memset(lazy,0,sizeof(lazy));


        scanf(" %s",ch);

        //printf("%s",ch);


        int q;

        scanf("%d",&q);

        int n=strlen(ch);

        printf("Case %d:\n",ii);

        built(1,1,n);


        while(q--)
        {

            scanf(" %c",&c);

            if(c=='I')
            {
                int u,v;

                scanf("%d %d",&u,&v);


                rangeupdate(1,1,n,u,v);



            }

            else
            {

                int pos;

                scanf("%d",&pos);

                query(1,1,n,pos);

            }
        }
    }

    return 0;
}


