#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *child[4];
    int mp[4];
    node()
    {
        for(int i=0;i<4;i++)
        {
            child[i]=NULL;
                mp[i]=0;
        }
    }

}*root;

char ch[55];
vector<string>chh;
int n,re;
map<char,int>cnt;

void insert()
{
    node *curr=root;
    int len=strlen(ch);
    for(int i=0;i<len;i++)
    {
        int id=cnt[ch[i]];
        if(curr->child[id]==NULL)
        {
            curr->child[id]=new node();
            curr->mp[id]=1;
        }
        else curr->mp[id]++;

        curr=curr->child[id];
    }
}

void cntword()
{
    node *curr=root;
    int len=strlen(ch);
    for(int i=0;i<len;i++)
    {
        int id=cnt[ch[i]];
        re=max(re,curr->mp[id]*(i+1));
        curr=curr->child[id];
    }
}

void del(node* curr)
{
    for(int i=0;i<4;i++)
    {
        if(curr->child[i]!=NULL)
        {
            del(curr->child[i]);
        }
    }

    delete(curr);
}

void solve(int ii)
{
    scanf("%d",&n);
    re=0;
    root=new node();
    for(int i=0;i<n;i++)
    {
        scanf("%s",ch);
        string s(ch);
        chh.push_back(s);
        insert();
    }

    for(int i=0;i<n;i++)
    {
        strcpy(ch,chh[i].c_str());
        cntword();
    }

    printf("Case %d: %d\n",ii,re);
    del(root);
    chh.clear();
}

int main()
{
    int t;
    scanf("%d",&t);
    cnt['A']=0,cnt['C']=1,cnt['G']=2,cnt['T']=3;
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
