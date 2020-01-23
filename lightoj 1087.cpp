#include<bits/stdc++.h>
using namespace std;
 
#define mx 150005
 
struct me
{
    int pos;
} tree[4*mx],dummy;
 
 
int a[mx];
 
 
me Merge(me p1,me p2)
{
    me re;
    re.pos = p1.pos+p2.pos;
    return re;
}
 
void built(int node,int be,int en)
{
    if(be>en)
        return;
 
    if(be==en)
    {
        tree[node].pos=1;
        return;
    }
 
    int mid=(be+en)/2;
 
    built(node*2,be,mid);
    built(node*2+1,mid+1,en);
 
    tree[node]=Merge(tree[node*2],tree[node*2+1]);
}
 
me query(int node,int be,int en,int i,int j)
{
    if(i>en||j<be)
        return dummy;
 
    if(i<=be&&j>=en)
    {
        return tree[node];
    }
 
    int mid=(be+en)/2;
 
    me p1,p2;
 
    p1=query(node*2,be,mid,i,j);
    p2=query(node*2+1,mid+1,en,i,j);
 
    return Merge(p1,p2);
 
}
 
void update(int node,int be,int en,int po,int val)
{
    if(be>po||en<po)
        return;
 
    if(be>=po&&en<=po)
    {
 
        tree[node].pos=val;
 
        return;
    }
 
    int mid=(be+en)/2;
 
    update(node*2,be,mid,po,val);
    update(node*2+1,mid+1,en,po,val);
 
    tree[node]=Merge(tree[node*2],tree[node*2+1]);
}
 
 
int main()
{
    //freopen("inputt.txt","r",stdin);
    int t;
    scanf("%d",&t);
 
    for(int ii=1; ii<=t; ii++)
    {
        int n,q;
 
        scanf("%d %d",&n,&q);
 
        for(int i=1; i<=n; i++)
            scanf("%d",a+i);
 
        int fix=2*n;
 
        built(1,1,fix);
 
        printf("Case %d:\n",ii);
 
//         for(int i=0;i<=4*n;i++)cout<<tree[i].pos<<" ";
//                cout<<endl;
 
        while(q--)
        {
            char c;
 
            int pos;
 
            scanf(" %c",&c);
 
            if(c =='c')
            {
                scanf("%d",&pos);
 
                int lo=1,hi=n;
 
 
                int ans=0;
 
                while(lo<=hi)
                {
                    int mid=(lo+hi)/2;
 
                    me fi;
 
                    fi=query(1,1,fix,1,mid);
 
                    int val=fi.pos;
 
                    if(val>=pos)
                    {
                        ans=mid;
                        hi=mid-1;
 
                    }
                    else
                        lo=mid+1;
 
                    //cout<<ans<<" ";
                }
 
//                   for(int i=0;i<=4*n;i++)cout<<tree[i].pos<<" ";
//                cout<<endl;
 
                if(ans)
                {
 
                    printf("%d\n",a[ans]);
 
                    update(1,1,fix,ans,0);
                }
                else
                    printf("none\n");
 
//                 for(int i=0;i<=4*n;i++)cout<<tree[i].pos<<" ";
//                cout<<endl;
 
            }
 
            else
            {
                int val;
                scanf("%d",&val);
 
                n++;
                a[n]=val;
 
//                 for(int i=0;i<=4*n;i++)cout<<tree[i].pos<<" ";
//                cout<<endl;
 
                update(1,1,fix,n,1);
 
//                 for(int i=0;i<=4*n;i++)cout<<tree[i].pos<<" ";
//                cout<<endl;
            }
 
        }
 
//        for(int i=0; i<=n*4; i++)
//            tree[i].pos=0;
 
    }
}
