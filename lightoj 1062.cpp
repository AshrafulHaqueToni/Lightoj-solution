#include<bits/stdc++.h>
using namespace std;

#define ll long double

ll x,y,c;

ll func(ll w)
{
    ll h1=sqrt(x*x-w*w);
    ll h2=sqrt(y*y-w*w);

    //cout<<(h1*h2)/(h1+h2)<<endl;

    return (h1*h2)/(h1+h2);
}

void solve(int ii)
{
    cin>>x>>y>>c;
    ll lo=0,high=min(x,y);
    for(int i=1;i<=100;i++)
    {
        ll mid=(lo+high)/2.0;
        if(func(mid)<=c)
        {
            high=mid;
        }
        else lo=mid;
        //cout<<lo<<" "<<high<<endl;
    }
    cout<<"Case "<<ii<<": "<<setprecision(12)<<lo<<endl;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
