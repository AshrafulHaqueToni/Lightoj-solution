// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 205
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx],ch1[mx];
int n,m,ii,k;

int Grundy[mx];
int vis[mx];

int func(int num)
{
	if(num<=0)return 0;
	if(vis[num])return Grundy[num];
	vis[num]=1;
	bitset<105>bt;
    for(int i=1;i<=num;i++)
    {
    	bt[func(i-3)^func(num+1-i-3)]=true;
    }
    int re=0;
    while(1)
    {
    	if(bt[re]==false)break;
    	re++;
    }
    return Grundy[num]=re;

}

bool func1()
{
	for(int i=0;i<n-2;i++)
	{
		if(ch[i]=='X' && ch[i+1]==ch[i] && ch[i+2]==ch[i])return true;
	}
	for(int i=0;i<n-2;i++)
	{
		if(ch[i]=='X' && ch[i+2]=='X')return false;
	}
	for(int i=0;i<n-1;i++)
	{
		if(ch[i]==ch[i+1] && ch[i]=='X')return false;
	}
	int last=0;
	int re=0;
	for(int i=1;i<=n;i++)
	{
		if(ch[i-1]=='X')
		{
			if(last)
			{
                re^=func(i-last-5);
			}
			else
			{
				re^=func(i-last-3);
			}
			last=i;
		}
	}
	re^=func(n+1-last-3);
	if(re)return false;
	return true;
}
 
void solve()
{
	 scanf("%s",ch);
	 n=strlen(ch);
	 vector<int>v;
	 for(int i=0;i<n;i++)
	 {
	 	if(ch[i]=='.')
	 	{
	 		ch[i]='X';
	 		if(func1())v.push_back(i+1);
	 		ch[i]='.';
	 	}
	 }
	 if(v.empty())printf("Case %d: 0\n",++ii);
	 else
	 {
	 	printf("Case %d:",++ii );
	 	for(int u:v)printf(" %d",u );
	 	printf("\n");
	 }
}
 
int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
