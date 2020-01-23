#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i;
    cin>>t;
    for(i=1;i<=t;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int max,min;
        if(a>=b&&a>=c){max=a*a,min=((b*b)+(c*c));}
        else if(b>=a&&b>=c){max=b*b,min=((a*a)+(c*c));}
        else{max=c*c,min=((a*a)+(b*b));}
        if(max==min){printf("Case %d: yes\n",i);}
        else{printf("Case %d: no\n",i);}
    }
}
