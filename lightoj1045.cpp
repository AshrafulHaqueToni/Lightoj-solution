#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 1000006

vector<long double>ten_base(mx);

void pre_cal()
{
    for(int i=1;i<=mx;i++)ten_base[i]=ten_base[i-1]+log(i);
}


int main()
{
     pre_cal();

     int t;

     scanf("%d",&t);

     for(int ii=1;ii<=t;ii++)
     {
         int n,b;
         scanf("%d%d",&n,&b);

         ll re= (ten_base[n]/log(b))+1;

         printf("Case %d: %lld\n",ii,re);
     }

     return 0;

}
