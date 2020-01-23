#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,sum=0,a;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>a;
            if(a>0){
                sum=sum+a;
            }
        }
         cout<<"Case "<<i<<": "<<sum<<endl;
 
    }
    return 0;
}
