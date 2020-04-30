#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
#define mod 1000000007
#define limi 1000000000000

vector<ll>vlucky;
int n,m;

void dfs(ll val)
{
    if(val>limi)return;
    if(val)vlucky.push_back(val);
    dfs(val*10+4);
    dfs(val*10+7);
}
void gen(ll val,int pos)
{
    if(val!=1 && val!=0)vlucky.push_back(val);
    for(int i=pos;i<n;i++)
    {
        if(val*vlucky[i]<=limi && val*vlucky[i]>0)gen(val*vlucky[i],i);
        else break;
    }
}
void solve(int ii)
{
    ll a,b;
    scanf("%lld%lld",&a,&b);
    int l=lower_bound(vlucky.begin(),vlucky.end(),a)-vlucky.begin();
    int r=upper_bound(vlucky.begin(),vlucky.end(),b)-vlucky.begin();
   // cout<<l<<" "<<r<<endl;
    printf("Case %d: %d\n",ii,r-l);
}

int main()
{
    dfs(0);
    n=vlucky.size();
    //cout<<n<<endl;
    sort(vlucky.begin(),vlucky.end());
    gen(1,0);
    sort(vlucky.begin(),vlucky.end());
    //cout<<vlucky.size()<<endl;
    vlucky.erase(unique(vlucky.begin(),vlucky.end()),vlucky.end());
   // cout<<vlucky.size()<<endl;
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}

