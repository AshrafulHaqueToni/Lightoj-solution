#include<bits/stdc++.h>
using namespace std;

#define ll long double

void solve(int ii)
{
    int n;
    scanf("%d",&n);
    ll same_na_hoyar_porabability=1.00;  /// same hoyar probability 0.00
    int i;
    for(i=1;same_na_hoyar_porabability>0.5;i++)
    {
        same_na_hoyar_porabability*=(1-(1.0*i/n));
       // cout<<same_na_hoyar_porabability<<endl;
      //  printf("%0.6LF\n",same_na_hoyar_porabability);
    }
    printf("Case %d: %d\n",ii,i-1);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
