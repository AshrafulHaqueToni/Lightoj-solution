#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<int>prime;
bool is_composite[10000005];

void sieve(int n)
{
    for(int i=2; i*i<n; i++)
    {
        if(is_composite[i]==false)
        {
            for(int j=i*i; j<n; j+=i)
            {
                is_composite[j]=true;
            }
        }
    }

    prime.push_back(2);

    for(int i=3; i<n; i+=2)
    {
        if(is_composite[i]==false)
            prime.push_back(i);
    }
}



void solve(int ii)
{

    ll num;
    scanf("%lld",&num);
    ll ans=1;

    for(auto it:prime)
    {
        if(it*it>num)break;
        int cnt=1;
        if(num%it==0)
        {
            while(num%it==0)
            {
                num/=it;
                cnt++;
            }
        }

        ans*=(2*(cnt-1)+1);
    }

    if(num>1)ans*=3;

    printf("Case %d: %lld\n",ii,(ans+1)/2);
}

int main()
{
    sieve(10000005);
    int t;
    scanf("%d",&t);

    for(int ii=1;ii<=t;ii++)solve(ii);
}
