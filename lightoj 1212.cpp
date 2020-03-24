#include<bits/stdc++.h>
using namespace std;

int n,m;

void solve(int ii)
{
	scanf("%d%d",&n,&m);
	printf("Case %d:\n",ii);
	deque<int>q;
	while(m--)
	{
		string ch;
		cin>>ch;
		
		if(ch=="pushLeft"||ch=="pushRight")
		{
			int x;
			scanf("%d",&x);
			if(q.size()==n)
			{
				printf("The queue is full\n");
			}
			else if(ch=="pushLeft")
			{
				q.push_front(x);
				printf("Pushed in left: %d\n",x);
			}
			else 
			{
			    q.push_back(x);
			    printf("Pushed in right: %d\n",x);
		    } 
		}
		else
		{
			if(q.size()==0)printf("The queue is empty\n");
			else if(ch=="popRight")
			{
				printf("Popped from right: %d\n",q.back());
				q.pop_back();
			}
			else
			{
				printf("Popped from left: %d\n",q.front());
				q.pop_front();
			}
		}
	}
}

int main()
{
	int t=1;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)solve(i);
	
	return 0;
}
