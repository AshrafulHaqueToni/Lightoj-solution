#include<bits/stdc++.h>
#define pi 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
using namespace std;
double inRadians(double a)
{
    return(a*pi)/180;
}
int main()
{
    int t,i;
    cin>>t;
    for(i=1;i<=t;i++){
        double R,r,redian,n;
        cin>>R>>n;
        redian= inRadians(180/n);
        r=sin(redian);
        printf("Case %d: %0.9lf\n",i,((R*r)/(1+r)));
    }
    return 0;
}
