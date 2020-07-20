#include<bits/stdc++.h>
using namespace std;

#define mx 100000005
#define ll unsigned  int
#define N 5761455

bitset<mx>is_composite;
int prime[N+5];
ll csum[N+5];

void seive(int n)
{

    for(int i=3; i*i<=n; i+=2)
    {
        if(!is_composite[i])
        {

            for(int j=i*i; j<=n; j+=2*i)
            {
                is_composite[j]=true;


            }
        }
    }
    prime[0]=2;
    int cnt=1;
    for(int i=3; i<=n; i+=2)if(is_composite[i]==false)prime[cnt++]=i;
    csum[0]=1;
    for(int i=0; i<N; i++)csum[i+1]=csum[i]*prime[i];
}

int n,m,k,ii;

void solve()
{
    scanf("%d",&n);
    ll re;
    int be=1,en=N;
    while(be<=en)
    {
        int mid=(be+en)/2;
        if(prime[mid-1]<=n)
        {
            re=csum[mid];
            be=mid+1;
        }
        else en=mid-1;
    }
    for(int i=0; prime[i]*prime[i]<=n; i++)
    {
        int tem=n/prime[i];
        while(tem>=prime[i])
        {
            tem/=prime[i];
            re*=prime[i];
        }
    }
    printf("Case %d: ",++ii);
    cout<<re<<endl;

}

int main()
{
    // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t=1;
    seive(mx-5);
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
