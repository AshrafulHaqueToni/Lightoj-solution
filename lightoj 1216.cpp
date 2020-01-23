#include<bits/stdc++.h>
#define pie 3.141592653589793238462643383279502884197169399375105820974944592307816406286
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        double r1,r2,h,p,l,m;
        cin>>r1>>r2>>h>>p;
        if(h==p){
            l=(pie/3)*h*((r1*r1)+(r2*r2)+(r1*r2));
            printf("Case %d: %0.9lf\n",i,l);
        }
        else{
            m=(((r1-r2)/h)*p)+r2;
            l=(pie/3)*p*((m*m)+(r2*r2)+(m*r2));
             printf("Case %d: %0.9lf\n",i,l);
        }
    }
    return 0;
}
