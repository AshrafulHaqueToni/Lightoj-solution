#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int i,a1,a2,b1,b2,c1,c2,d1,d2,r1,r2,r,t;
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>a1>>a2>>b1>>b2>>c1>>c2;
        d1=a1+c1-b1;
        d2=a2+c2-b2;
        r1=(a1*b2)+(b1*c2)+(c1*d2)+(d1*a2);
        r2=(a2*b1)+(b2*c1)+(c2*d1)+(d2*a1);
        //r=(a1*(b2-c2))-(a2*(b1-c1))+((b1*c2)-(c1*b2));
        r=abs(r1-r2);
        r=r/2;
        cout<<"Case "<<i<<": "<<d1<<" "<<d2<<" "<<r<<endl;
    }
    return 0;
}
