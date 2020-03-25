#include<bits/stdc++.h>
using namespace std;

#define ll long double

void solve(int ii)
{
    ll ox,oy,ax,ay,bx,by;
    cin>>ox>>oy>>ax>>ay>>bx>>by;
    ll a=sqrt((ox-bx)*(ox-bx)+(oy-by)*(oy-by));
    ll b=sqrt((ox-ax)*(ox-ax)+(oy-ay)*(oy-ay));
    ll c=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
    ll angle_o=acos((b*b+a*a-c*c)/(2*b*a));
    cout<<"Case "<<ii<<": "<<setprecision(13)<<angle_o*a<<endl;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
