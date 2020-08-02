#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long 

int prime[17];
int m,n,k,ii,dek;

bool chk(vector<int> v)
{
	
	for(int i=0;i<8;i++)
	{
		if(abs(v[i])!=i+1)return false;

	}
	
	return true;
}

void solve()
{
	vector<int>v(8),tem;
	map<vector<int>,int> mp;
	for(int i=0;i<8;i++)scanf("%d",&v[i]);
	queue<vector<int>>q;
    q.push(v);
    mp[v]=0;
    int re=1e9;
    bool f=false;
    while(!q.empty())
    {
    	dek++;
    	v=q.front();
    	q.pop();
    	if(chk(v))
    	{
    		f=true;
    		re=min(re,mp[v]);
    		break;
    	}
    	
    	for(int i=7;i>=1;i--)
    	{
            for(int j=0;j<i;j++)
            {
            	if((v[i]>0 && v[j]<0) || (v[j]>0 && v[i]<0))
            	{
            		if(prime[abs(v[i])+abs(v[j])]==1)
            		{
            			int last;
            			if(abs(v[i])<abs(v[j]))
            			{
            			tem=v;
            			 last=v[i];

            			for(int l=j;l<=i;l++)
            			{
            				int val1=tem[l];
            				tem[l]=last;
            				last=val1;

            			}
            			if(!mp.count(tem) )
            			{
            				//dek++;
            				mp[tem]=mp[v]+1;
            				q.push(tem);
            			}
            		    }
            		    if(abs(v[i])>abs(v[j]))
            			{
            			tem=v;
            			last=v[i];
            			for(int l=j+1;l<=i;l++)
            			{
            				int val1=tem[l];
            				tem[l]=last;
            				last=val1;

            			}
            			if(!mp.count(tem) )
            			{
            				//dek++;
            				mp[tem]=mp[v]+1;
            				q.push(tem);
            			}
            		}
            		    if(abs(v[i])<abs(v[j]))
            			{
            			tem=v;
            			for(int l=j;l<i;l++)
            			{
            				
            				tem[l]=tem[l+1];

            			}
            			tem[i]=v[j];
            			if(!mp.count(tem) )
            			{
            				mp[tem]=mp[v]+1;
            				q.push(tem);
            			}
            		}
            		    if(abs(v[i])>abs(v[j]))
            			{
            			tem=v;
            			for(int l=j;l<i-1;l++)
            			{
            				
            				tem[l]=tem[l+1];

            			}
            			tem[i-1]=v[j];
            			if(!mp.count(tem) )
            			{
            				mp[tem]=mp[v]+1;
            				q.push(tem);
            			}
            		}
            		}
            	}
            }
            
    	}
    }
    
    if(f)printf("Case %d: %d\n",++ii,re);
    else printf("Case %d: -1\n",++ii );


}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int t=1;
	prime[3]=1;
	prime[5]=1;
	prime[7]=1;
	prime[11]=1;
	prime[13]=1;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}
