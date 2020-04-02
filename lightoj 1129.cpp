#include<bits/stdc++.h>
using namespace std;

struct node
{
    bool endmark;
    node *next[11];
    node()
    {
        endmark=false;
        for(int i=0; i<10; i++)
        {
            next[i]=NULL;
        }
    }
}*root;

int n,q;

void insert(char ch[],int len)
{
    node* curr=root;
    for(int i=0; i<len; i++)
    {
        int id=ch[i]-'0';
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
    }
    curr->endmark=true;
}

bool search(char ch[],int len)
{
    node* curr=root;
    for(int i=0; i<len; i++)
    {
        int id=ch[i]-'0';
        if(curr->next[id]==NULL)
            return false;
        curr=curr->next[id];
    }
    return curr->endmark;
}

bool prefix_search(char* ch,int len)
{
    node* curr=root;
    for(int i=0; i<len; i++)
    {
        int id=ch[i]-'0';
        if(curr->next[id]==NULL)
            return false;
        curr=curr->next[id];
    }
    return true;
}

bool is_Empty(node* curr)
{
    for(int i=0; i<10; i++)
    {
        if(curr->next[i])
            return false;
    }
    return true;
}

node* remove(node* curr,char ch[],int dep=0)
{
    if(curr==NULL)
        return NULL;
    if(dep==strlen(ch))
    {
        if(curr->endmark)
            curr->endmark=false;
        if(is_Empty(curr))
        {
            delete(curr);
            curr=NULL;
        }
        return curr;
    }
    int id=ch[dep]-'0';

    curr->next[id]=remove(curr->next[id],ch,dep+1);

    if(is_Empty(curr) && curr->endmark==false)
    {
        delete(curr);
        curr=NULL;
    }
    return curr;
}

void del(node* curr)
{
    for(int i=0; i<10; i++)
        if(curr->next[i])
            del(curr->next[i]);
    delete(curr);
}

int main()
{

    int t;
    scanf("%d",&t);
    for(int ii=1; ii<=t; ii++)
    {
        root=new node();
        scanf("%d",&n);
        //vector<char[20]>v;
        char ch[n+5][20];
        for(int i=1; i<=n; i++)
        {
            scanf("%s",ch[i]);
            insert(ch[i],strlen(ch[i]));
        }
        bool f=false;
        for(int i=1; i<=n; i++)
        {
            remove(root,ch[i]);
            f|=prefix_search(ch[i],strlen(ch[i]));
            //cout<<ff<<endl;
            insert(ch[i],strlen(ch[i]));
        }
        printf("Case %d: ",ii);
        if(!f)
            printf("YES\n");
        else
            printf("NO\n");
        del(root);///distroy the trie
    }
}
