#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,a,b=0;
        cin>>n;
        if(n>10){
            a=10;
            b=n-a;
        }
        else{
            a=n;
        }
        cout<<a<<" "<<b<<endl;
    }
return 0;
}
