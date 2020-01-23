#include<bits/stdc++.h>
using namespace std;
#define ash ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
int c;

int main()
{
   // ash;

    unsigned long long a[22];
    a[0]=1;
    for(int i=1;i<=20;i++){
        a[i]=a[i-1]*i;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        ll n;
        stack<int>s;
        scanf("%lld",&n);
        int j=20;
        while(j>=0){
            if(a[j]<=n){
                n-=a[j];
                s.push(j);

            }
            j--;
        }
        if(n==0){
                printf("Case %d: ",++c);
            while(s.size()!=1){
                printf("%d!+",s.top());
                s.pop();
            }
            printf("%d!\n",s.top());
        s.pop();
        }
        else{
            printf("Case %d: impossible\n",++c);
        }
    }




    return 0;
}


