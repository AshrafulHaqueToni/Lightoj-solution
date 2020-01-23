#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int i,k,j;
    for(i=1;i<=t;i++){
       string s,t;
    cin>>s;
    t=s;
    int l=s.size();
    for(k=0,j=l-1;k<=(l/2)-1;j--,k++){
          swap(t[k],t[j]);
       }
       if(s==t){printf("Case %d: Yes\n",i);}
       else{printf("Case %d: No\n",i);}
    }
 
}
