// Created by ash_98

#include<bits/stdc++.h>
using namespace std;

#define mx 300005
#define ll long long
#define mod 1000000007

int ar[mx];
int n,m,ii,k;

struct Aho_Corasick
{
	 int Trie[mx][27],Suffix_Link[mx];
	 vector<int> Mark[mx];

	 int Node;

	 void Init()
	 {
	 	fill(Trie[0],Trie[0]+26,-1);
	 	Mark[0].clear();
	 	Node=0;
	 }

	 void Insert(char ch[],int idx)
	 {
	 	int len=strlen(ch);

	 	int cur=0;

	 	for(int i=0;i<len;i++)
	 	{
	 		int val=ch[i]-'a';
	 		if(Trie[cur][val]==-1)
	 			{
	 				Trie[cur][val]=++Node;
	 				fill(Trie[Node],Trie[Node]+26,-1);
	 	            Mark[Node].clear();
	 			}
	 		cur=Trie[cur][val];

	 	}

	 	Mark[cur].push_back(idx);

	 }

	 void Cal_Suffix_Link()
	 {
	 	queue<int>q;
	 	Suffix_Link[0]=0;
	 	for(int i=0;i<26;i++)
	 	{
	 		if(Trie[0][i]!=-1)
	 		{
	 			q.push(Trie[0][i]);
	 			Suffix_Link[Trie[0][i]]=0;

	 		}
	 		else Trie[0][i]=0;
	 	}

	 	while(!q.empty())
	 	{
	 		int u=q.front();
	 		q.pop();

	 		for(int v: Mark[Suffix_Link[u]])
	 		{
	 			Mark[u].push_back(v);
	 		}

	 		for(int i=0;i<26;i++)
            {
                if(Trie[u][i] != -1)
                {
                    Suffix_Link[Trie[u][i]] = Trie[Suffix_Link[u]][i];
                    q.push(Trie[u][i]);
                }
                else
                    Trie[u][i] = Trie[Suffix_Link[u]][i];
            }
	 	}
	 }

}Automata;

/// Pattern Occurence Count
int cnt[mx];

void Count_Pattern(char ch[])
{
    int cur=0;
    int len=strlen(ch);
    for(int i=0;i<len;i++)
    {
    	int val=ch[i]-'a';
    	cur= Automata.Trie[cur][val];
    	for(int id: Automata.Mark[cur])cnt[id]++;
    }
}


void solve()
{
	char ch1[1000005],ch[mx];
	scanf("%d%s",&n,ch1);
	Automata.Init();
	for(int i=0;i<n;i++)
	{
		scanf("%s",ch);
		Automata.Insert(ch,i);
	}
	Automata.Cal_Suffix_Link();
	Count_Pattern(ch1);
	printf("Case %d:\n",++ii);
	for(int i=0;i<n;i++)
	{
		printf("%d\n",cnt[i]);
		cnt[i]=0;
	}
}

int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
