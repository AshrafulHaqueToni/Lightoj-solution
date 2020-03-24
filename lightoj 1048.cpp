#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mx 1005
 
int n,k;
int ar[mx];
 
bool possible(int val)
{
    int hate_ace=val;
    int cnt=0;
    for(int i=1;i<=n+1;i++)
    {
        if(ar[i]>val)return false;
        if(hate_ace>=ar[i])hate_ace-=ar[i];
        else
        {
            cnt++;
            hate_ace=val-ar[i];
            if(cnt>k)return false;
        }
    }
 
    return true;
}
 
 
void solve(int ii)
{
    scanf("%d%d",&n,&k);
    int lo=0,high=0;
    for(int i=1;i<=n+1;i++){
            int x;
        scanf("%d",&ar[i]);
        lo=max(lo,ar[i]);
        high+=ar[i];
 
    }
 
    while(lo<=high)
    {
         int mid=(lo+high)/2;
        if(possible(mid))
        {
            high=mid-1;
 
        }
        else lo=mid+1;
    }
 
    while(possible(high)==false)high++;
 
    printf("Case %d: %d\n",ii,high);
 
    int tem=0,cnt=0;
 
    for(int i=1;i<=n+1;i++)
    {
        if(tem+ar[i]>high)
        {
            printf("%d\n",tem);
            tem=ar[i];
            cnt++;
        }
        else if(tem+ar[i]==high)
        {
            printf("%d\n",tem+ar[i]);
            tem=0;
            cnt++;
        }
        else if(n+1-i==k-cnt)
        {
            printf("%d\n",ar[i]+tem);
            tem=0;
            cnt++;
        }
        else tem+=ar[i];
    }
 
}
 
int main()
{
    int t;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
