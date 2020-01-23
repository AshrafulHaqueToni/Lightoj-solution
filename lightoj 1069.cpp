#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        long long a,b;
        cin>>a>>b;
        if(a<=b){
         cout<<"Case "<<i<<": "<<19+(4*b)<<endl;
        }
        else{
             cout<<"Case "<<i<<": "<<19+(4*(a+a-b))<<endl;
        }
    }
    return 0;
}
