#include<bits/stdc++.h>
using namespace std;
///http://lightoj.com/volume_showproblem.php?problem=1269
#define mx 2000005

int Trie[mx][2];
int End[mx];
int ar[50005];
int n,ii,st=1;


void Insert(int val)
{
    int cur=1;
    for(int i=31;i>=0;i--)
    {
        int bit=0;
        if(((1<<i) & val))bit=1;
        if(Trie[cur][bit]==0)Trie[cur][bit]=++st;
        cur=Trie[cur][bit];
    }
    End[cur]=val;
}

int query_min(int val)
{
    int cur=1;
    for(int i=31;i>=0;i--)
    {
        int bit=0;
        if(((1<<i) & val))bit=1;
        if(Trie[cur][bit])cur=Trie[cur][bit];
        else if(Trie[cur][bit^1])cur=Trie[cur][bit^1];
    }
    return End[cur]^val;
}

int query_max(int val)
{
    int cur=1;
    for(int i=31;i>=0;i--)
    {
        int bit=0;
        if(((1<<i) & val))bit=1;
        if(Trie[cur][bit^1])cur=Trie[cur][bit^1];
        else if(Trie[cur][bit])cur=Trie[cur][bit];
    }

    return End[cur]^val;
}

void solve()
{
    scanf("%d",&n);
    int suffix=0;
    memset(End,0,sizeof(End));
    memset(Trie,0,sizeof(Trie));
    int re_min=INT_MAX,re_max=0;
    Insert(0);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ar[i]);
        suffix^=ar[i];
        re_min=min(re_min,query_min(suffix));
        re_max=max(re_max,query_max(suffix));
        Insert(suffix);
    }
    printf("Case %d: %d %d\n",++ii,re_max,re_min);
    st=1;
}

int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }

    return 0;
}
