#include<bits/stdc++.h>
using namespace std;

#define mx 65540 ///2^16
#define ll long long
ll ar[mx];
ll pos,n,m,re,w;
int a[35];

void half_array_all_possible_subset(int i,ll sum)
{
    if(i==m)
    {
        ar[pos++]=sum;
        return;
    }
    half_array_all_possible_subset(i+1,sum+a[i]);
    half_array_all_possible_subset(i+1,sum);
}

void calculate_total_permutation(int i,ll sum)
{
    if(i==n)
    {
        int p=upper_bound(ar,ar+pos,sum)-ar;
        if(p>0)re+=p;
        return;
    }
    calculate_total_permutation(i+1,sum);
    calculate_total_permutation(i+1,sum-a[i]);
}
void solve(int ii)
{
    pos=0,re=0;
    scanf("%d%d",&n,&w);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    m=n/2+(n&1);
    half_array_all_possible_subset(0,0);
    sort(ar,ar+pos);
    calculate_total_permutation(m,w);
    printf("Case %d: %lld\n",ii,re);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
