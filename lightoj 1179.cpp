#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
 
int josepus(int n,int k)
{
    if(n==1)return 1;
 
    return ((josepus(n-1,k)+k-1)%n)+1;
}
 
int main()
{
 
    int t;
    scanf("%d",&t);
 
    for(int ii=1;ii<=t;ii++)
    {
        int n,k;
        scanf("%d%d",&n,&k);
 
        printf("Case %d: %d\n",ii,josepus(n,k));
    }
 
    return 0;
}
