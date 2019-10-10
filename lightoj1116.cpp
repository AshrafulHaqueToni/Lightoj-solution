#include<bits/stdc++.h>

using namespace std;
typedef long long int toni;

int main()
{
    toni t,i,j,k,l;
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>k;
        int a=0;
        for(j=2;j<=ceil(k/2);j=j+2){
            for(l=3;l<=ceil(k/2);l=l+2){
                if(j*l==k){a=1;break;}
               //cout<<l;
            }
            if(a==1){break;}
        }
        if(a==1){printf("Case %lld: %lld %lld\n",i,j,l);}
        else{printf("Case %lld: Impossible\n",i);}
    }

}
