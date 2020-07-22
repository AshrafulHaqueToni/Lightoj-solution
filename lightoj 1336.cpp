#include<bits/stdc++.h>
using namespace std;

#define mx 1000000000000
#define ll long long

vector<ll>odd;

void pre_cal()
{
    for(int i=1;i<=1000000; i+=2)
    {
       ll tem=(ll)i*i;
       for(ll j=1;j*tem<=mx;j*=2)
       {
           odd.push_back(j*tem);
       }
    }
    sort(odd.begin(),odd.end());
}

int m,k,ii;

void solve()
{
    ll n;
    scanf("%lld",&n);
    int re=lower_bound(odd.begin(),odd.end(),n)-odd.begin();
    if(odd[re]>n)re--;
    printf("Case %d: %lld\n",++ii,n-re-1);
}
/*
first 53 number of odd sum of divisors [1,1000]
1 2 4 8 9 16 18 25 32 36 49 50 64 72 81 98
100 121 128 144 162 169 196
200 225 242 256 288 289
324 338 361 392
400 441 450 484
512 529 576 578
625 648 676
722 729 784
800 841 882
900 961 968
*/

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t=1;
    pre_cal();
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
