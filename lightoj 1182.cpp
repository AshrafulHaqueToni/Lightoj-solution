#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i;
    cin>>t;
    for(i=1;i<=t;i++){
        long long int n;
        cin>>n;
        int sum=0;
        while(n>0){
            if(n%2==1)sum++;
            n=n/2;
        }
        if(sum%2==0){
            printf("Case %d: even\n",i);
        }
        else{
            printf("Case %d: odd\n",i);
        }
    }
    return 0;
}
