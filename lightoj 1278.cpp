/*
    Problem Tags: Number Theory
    Explanation: Let, k be the number of consecutive integers starting
                from x whose sum equals N.So we can write,
                x+(x+1)+........+(x+k-1)=N --------(1)
                or, kx+k*(k-1)/2=N
                or, 2kx+k^2-k=2N
                or, k(2x+k-1)=2N ----------(2)
                From equation (2) we can say, k is a divisor of 2N.
                Now, from (2)
                k(2x+k-1)=2N
                or, 2x+k-1=2N/k
                or, 2x+k-1=R  [Let R=2N/k]
                or, 2x=(R-k)+1 ------------(3)
                From, equation (3) we can say, (R-k) has to be odd number.
                Again, since R=2N/k and 2N is even, so R is always even and hence
                k must be odd to be (R-k) odd.
 
                From the requirement of problem, x must be positive integers,
                so from equation (3) we can write,
                R>=k
                or, 2N/k>=k
                or, 2N>=k^2
                or, k<=sqrt(2N) ------------(4)
 
                From the above explanation, we can say,
                1) k must be a divisor of 2N
                2) k must be odd
                3) k is less than or equals to the sqaure-root of 2N.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define mx 10000005

bool chk[mx+10];
char ch[mx+10];
ll n;
vector<int>prime;

void sieve()
{
    for(int i=2;i*i<=10000005;i++)
    {
        if(chk[i]==false)
        {
            for(int j=i*i;j<=10000005;j+=i)
               chk[j]=true;
        }
    }

    for(int i=3;i<=10000005;i++)if(!chk[i])prime.push_back(i);
}

void solve(int ii)
{
    scanf("%lld",&n);

    while(n%2==0)n/=2;

    ll ans=1;

    for(auto it:prime)
    {
        if(it*it>n)break;

        if(n%it==0)
        {
        int cnt=1;

        while(n%it==0)n/=it,cnt++;
        ans*=cnt;
        }
    }

    if(n>1)ans*=2;

    printf("Case %d: %lld\n",ii,ans-1);


   return;
}

int main()
{
    int t=1;
    sieve();
    scanf("%d",&t);

    for(int i=1;i<=t;i++)solve(i);

    return 0;
}
