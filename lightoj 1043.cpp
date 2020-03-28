#include<bits/stdc++.h>
using namespace std;

#define ll long double

ll ab,bc,ca,area_of_triangle_abc,rat;

ll chk(ll ad)
{
    ll ae=(ca*(ad/ab)); /// ab/ad=ac/ae;
    ll de=(bc*(ad/ab)); ///ad/ab=de/bc;
    ll s=(ae+de+ad)/2.0;
    ll area_of_triangle_ade=sqrt(s*(s-ae)*(s-de)*(s-ad));
    ll area_of_trapiziam_bced=area_of_triangle_abc-area_of_triangle_ade;
    return area_of_triangle_ade/area_of_trapiziam_bced;
}

void solve(int ii)
{
    cin>>ab>>ca>>bc>>rat;
    ll lo=0,high=ab;
    ll s=(ab+ca+bc)/2.0;
    area_of_triangle_abc=sqrt(s*(s-ab)*(s-ca)*(s-bc));
    for(int i=1;i<=100;i++)///100 times iteration.
    {
        ll mid=(lo+high)/2;
        if(chk(mid)<=rat)
        {
            lo=mid;
        }
        else high=mid;
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
