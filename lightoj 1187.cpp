// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using    namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
#define mx 100005
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k;
 
void solve()
{
    scanf("%d",&n);
    ordered_set os;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ar[i]);
        os.insert(i);
    }
    for(int i=n;i>1;i--)
    {
        int val=*os.find_by_order(i-ar[i]-1);
        os.erase(os.find(val));
    }
    printf("Case %d: %d\n",++ii,*os.begin() );
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
