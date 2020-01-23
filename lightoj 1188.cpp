#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define block 555

struct me
{
    int lft,rht,idx;
} tree[mx];

int a[mx],cnt[mx],ans[mx],re;

bool cmp(me p1,me p2)
{
    if(p1.lft/block != p2.lft/block)
        return p1.lft/block < p2.lft/block;

    return p1.rht < p2.rht;
}


void Add(int pos)
{
    if(cnt[a[pos]])
        re--;

    cnt[a[pos]]++;

    if(cnt[a[pos]])
        re++;

}

void Remove(int pos)
{
    if(cnt[a[pos]])
        re--;

    cnt[a[pos]]--;

    if(cnt[a[pos]])
        re++;

}

int main()
{
    //freopen("1088.txt","r",stdin);
    int t;
    scanf("%d",&t);

    for(int ii=1; ii<=t; ii++)
    {
        memset(ans,0,sizeof(ans));
        memset(cnt,0,sizeof(cnt));

        int n,q;
        re=0;
        scanf("%d %d",&n,&q);

        for(int i=0; i<n; i++)
            scanf("%d",a+i);

        for(int i=0; i<q; i++)
        {
            scanf("%d %d",&tree[i].lft,&tree[i].rht);

            tree[i].lft--;
            tree[i].rht--;
            tree[i].idx=i;
        }

        sort(tree,tree+q,cmp);

//        for(int i=0;i<q;i++)
//        {
//            cout<<tree[i].lft<<" "<<tree[i].rht<<" "<<tree[i].idx<<endl;
//        }


        int cur_l=0,cur_r=0;


        for(int i=0; i<q; i++)
        {
            int l=tree[i].lft,r=tree[i].rht;

            while(cur_l<l)
                Remove(cur_l++);

            while(cur_l>l)
                Add(--cur_l);

            while(cur_r<=r)
                Add(cur_r++);

            while(cur_r>r+1)
                Remove(--cur_r);

            ans[tree[i].idx]=re;
        }

        printf("Case %d:\n",ii);

        for(int i=0; i<q; i++)
        {
            printf("%d\n",ans[i]);
        }

//        for(int i=0;i<=q;i++)
//        {
//            tree[i].idx=0;
//            tree[i].lft=0;
//            tree[i].rht=0;
//        }

    }

    return 0;
}
