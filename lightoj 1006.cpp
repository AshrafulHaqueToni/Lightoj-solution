#include<bits/stdc++.h>
using namespace std;
#define ash ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
typedef long long ll;
 
ll a,b,c,d,e,f;
ll ar[100005];
ll fn(ll n)
{
    if( n == 0 )
        return a;
    if( n == 1 )
        return b;
    if( n == 2 )
        return c;
    if( n == 3 )
        return d;
    if( n == 4 )
        return e;
    if( n == 5 )
        return f;
    if(ar[n]!=-1)
    {
        return ar[n];
    }
    else
    {
        ar[n]=(fn(n-1)+ fn(n-2)+ fn(n-3)+ fn(n-4) + fn(n-5) + fn(n-6))%10000007;
 
        return ar[n];
    }
}
 
int main()
{
    ash;
 
    ll ca,n;
    cin>>ca;
    ll i=0;
    while(ca--)
    {
        cin>>a>>b>>c>>d>>e>>f>>n;
        memset(ar,-1,sizeof(ar));
 
        printf("Case %lld: %lld\n",++i,fn(n)%10000007);
 
        //for(int i=0;i<=n;i++)cout<<ar[i]<<" ";
 
    }
}
