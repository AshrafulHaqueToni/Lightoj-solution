#include<bits/stdc++.h>
using namespace std;

#define ll long double

void solve(int ii)
{
    ll a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;

    ll t1=a/d;
    ll t2=b/e;
    cout<<"Case "<<ii<<": ";
    cout<<setprecision(10)<<((a*t1+0.5*(-d)*t1*t1)+(b*t2+0.5*(-e)*t2*t2))<<" ";
    cout<<setprecision(10)<<max(t1,t2)*c<<endl;

}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
