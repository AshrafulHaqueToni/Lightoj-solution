#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int a,b,c,d,n,m,o;
        cout<<"Case "<<i<<":"<<endl;
 
        cin>>a>>b>>c>>d>>n;
 
        for(int j=0;j<n;j++){
            cin>>m>>o;
            if((m>=a&&m<=c)&&(o>=b&&o<=d)){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}
