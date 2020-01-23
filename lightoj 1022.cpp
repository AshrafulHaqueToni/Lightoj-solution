#include<bits/stdc++.h>
#define pi 2*acos(0.0)
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        double r;
        cin>>r;
       printf("Case %d: %0.2lf\n",i,(4*r*r)-(pi*r*r));
    }
    return 0;
}
