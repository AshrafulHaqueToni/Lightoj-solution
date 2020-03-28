#include<bits/stdc++.h>
using namespace std;

#define ll long double

void solve(int ii)
{
    ll a,b;
    char ch;
    cin>>a>>ch>>b;
    ll r=sqrt(b*b+a*a)/2.0;
    ll deg=acos((r*r+r*r-b*b)/(2*r*r));
    ll area=r*deg;
    ll x=400.0/(2.0*area+2.0*a);
    cout<<"Case "<<ii<<": "<<setprecision(12)<<x*a<<" "<<setprecision(12)<<x*b<<endl;
}

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
