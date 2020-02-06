#include<bits/stdc++.h>
using namespace std;
 
#define mx 100005
 
 
struct me
{
    int Min,Max;
 
}tree[4*mx],dummy;
 
int a[mx];
 
 
me Merge(me p1,me p2)
{
    me re;
 
    re.Min=min(p1.Min,p2.Min);
    re.Max=max(p1.Max,p2.Max);
 
    return re;
}
 
void built(int node,int be,int en)
{
    //cout<<node<<" ";
    if(be>en)return;
 
    if(be==en)
    {
        tree[node].Min=a[be];
        tree[node].Max=a[be];
 
        return ;
    }
 
    int mid=(be+en)/2;
 
    built(node*2,be,mid);
    built(node*2+1,mid+1,en);
 
 
    tree[node]=Merge(tree[node*2],tree[node*2+1]);
}
 
int Maxfind(int node,int be,int en,int i,int j)
{
    if(i>en||j<be)return 0;
 
    if(i<=be&&j>=en)
    {
        return tree[node].Max;
    }
 
    int p1,p2;
 
    int mid=(be+en)/2;
 
    p1=Maxfind(node*2,be,mid,i,j);
    p2=Maxfind(node*2+1,mid+1,en,i,j);
 
    return max(p1,p2);
}
 
int Minfind(int node,int be,int en,int i,int j)
{
    if(i>en||j<be)return (int)1e9;
 
    if(i<=be&&j>=en)
    {
        return tree[node].Min;
    }
 
   int p1,p2;
 
    int mid=(be+en)/2;
 
    p1=Minfind(node*2,be,mid,i,j);
    p2=Minfind(node*2+1,mid+1,en,i,j);
 
    return min(p1,p2);
}
 
int main()
{
    int t;
    scanf("%d",&t);
 
    for(int ii=1;ii<=t;ii++)
    {
        int n,time;
        scanf("%d %d",&n,&time);
 
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
        }
 
        built(1,1,n);
 
        int fi=0;
 
        for(int i=1;i<=n;i++)
        {
            if(i+time-1>n)break;
 
            int re;
           
            re=Maxfind(1,1,n,i,i+time-1);
 
            int re1;
 
            re1=Minfind(1,1,n,i,i+time-1);
 
            fi=max(fi,re-re1);
 
        }
 
        printf("Case %d: %d\n",ii,fi);
 
        for(int i=0;i<=4*n;i++)tree[i].Min=0,tree[i].Max=0;
 
    }
    return 0;
}
