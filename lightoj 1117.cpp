#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long

int ar[20];
int m,k,ii;
ll re,n;

void func(int idx,int cnt,ll lcm)
{
    if(lcm>n)return;
    if(idx==m)
    {
        if(cnt==0)return;

        if(cnt & 1)re+=n/lcm;
        else re-=n/lcm;
        return;
    }
    func(idx+1,cnt+1,(lcm*ar[idx])/__gcd(lcm,(ll)ar[idx]));
    func(idx+1,cnt,lcm);
}

void solve()
{

    scanf("%lld%d",&n,&m);
    for(int i=0;i<m;i++)scanf("%d",&ar[i]);
    ///using bitmask
     re=0;
//    for(int i=1; i<(1<<m);i++)
//    {
//        ll lcm=1;
//        int cnt=0;
//        for(int j=0;j<m;j++)
//        {
//            if(i & (1<<j))
//            {
//                cnt++;
//                lcm=(lcm*ar[j])/__gcd(lcm,(ll)ar[j]);
//                if(lcm>n)break;
//            }
//        }
//        if(cnt&1)re+=n/lcm;
//        else re-=n/lcm;
//    }

    /// using recursive
    func(0,0,1);


    printf("Case %d: %lld\n",++ii,n-re);
}

int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t=1;
   scanf("%d",&t);
   while(t--)solve();
   return 0;
}

