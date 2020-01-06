#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define mx 100005

int a[mx+10];
char ch[mx+10];
int n;

void solve(int ii)
{
    scanf("%d",&n);

    int sum=0,cnt=0;

    for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum+=abs(a[i]);
    if(a[i]<0)cnt++;
    }

    printf("Case %d: ",ii);

    if(cnt==n)
    {
        printf("inf\n");
        return;
    }

    int gc=__gcd(sum,n-cnt);

    printf("%d/%d\n",sum/gc,(n-cnt)/gc);

   return;
}

int main()
{
    int t=1;
    scanf("%d",&t);

    for(int i=1;i<=t;i++)solve(i);

    return 0;
}

