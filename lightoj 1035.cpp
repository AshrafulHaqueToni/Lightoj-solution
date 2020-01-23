//***Bismillahir Rahmanir Rahim***///
///*********************************///
///******Ashraful Haque Toni********///
///********Dept. of CSE,JnU*********///
///email:ashrafulhaquetoni@gmail.com///
///*******contact:01640690531*******///
///*********************************///
 
#include<bits/stdc++.h>
 
using namespace std;
 
#define         ash               ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define         pb                push_back
#define         mp                make_pair
#define         I1(n)             cin>>n
#define         I2(m,n)           cin>>m>>n;
#define         sc(n)             scanf("%d",&n);
#define         scl(n)            scanf("%I64d",&n);
#define         sc2(m,n)          scanf("%d%d",&m,&n);
#define         sc2l(m,n)         scanf("%I64d%I64d",&m,&n);
#define         pf                printf
#define         f(i,n)            for(ll i=0;i<(n);i++)
#define         f1(i,n)           for(ll i=1;i<=(n);i++)
#define         ar_input(a,n)     f(i,n)cin>>a[i];
#define         ve_input(v,n)     f(i,n){ll m;cin>>m,v.pb(m);}
#define         Max               INT_MAX
#define         Min               INT_MIN
#define         pi                acos(-1.0)
#define         Mem(a,val)        memset(a,val,sizeof(a));
#define         asort(a,n)        sort(a,a+n)
#define         vsort(v)          sort(v.begin(),v.end())
#define         fr(i,s,e)         for(ll i=s;i<=e;i++)
#define         ff                first
#define         ss                second
#define         vec               vector<ll>
#define         pai               pair<ll,ll>
#define         Map               map<ll,ll>
#define         mod               1000000007
#define         ll                long long
 
                         ///template function///
 
/// ll GCD(ll a,ll b){if(a<0) a*=-1;if(b<0) b*=-1;if(a<b)swap(a,b);if(b==1) return 1;if(!b) return a;if(!(a%b)) return b;else return GCD(b,a%b);}
/// ll LCM(ll a,ll b){ll x=GCD(a,b);return (a/x)*b;}
/// ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n+mod)%mod;if(p%2)return (bigmod(n,p-1)*n+mod)%mod;else{ll x=bigmod(n,p/2);return (x*x+mod)%mod;}}
/// ll modinverse(ll n){return bigmod(n,mod-2)%mod;}
/// vec de;void devisors(ll n){ll i;for(i=1;i<=sqrt(n);i++){if(!(n%i) && i!=sqrt(n)){de.pb(i);de.pb(n%i);}}if((i-1)*(i-1)==n) de.pb(i-1);vsort(v);}
 
///*********************************************start***********************************************///
 
 
int con[102];
vector<pai>v[102];
set<ll>s;
 
 void fac_count(int n)
 {
     int mm=n;
 
     if(n%2==0)
     {
         while(n%2==0)
         {n/=2;
 
         con[2]++;
         }
         s.insert(2);
     }
     for(int i=3;i<=n;i+=2)
     {
         if(n%i==0)
         {
             while(n%i==0){
                n/=i;
                //cout<<i<<endl;
             con[i]++;
             }
             s.insert(i);
         }
         //cout<<i<<endl;
     }
 
     if(n>1){s.insert(n);con[n]++;}
 
     for(auto it : s)
     {
        // cout<<it<<endl;
         v[mm].pb({it,con[it]});
     }
     //cout<<mm<<endl;
 }
 
 
int main()
{
  ash;
  fr(i,2,101)fac_count(i);
 
  int t;
  //cout<<1<<endl;
  I1(t);
 
  f1(i,t)
  {
      int n;
      I1(n);
      cout<<"Case "<<i<<": "<<n<<" = ";
      int len=v[n].size()-1;
 
      f(j,v[n].size())
      {
          if(j==len)cout<<v[n][j].ff<<" ("<<v[n][j].ss<<")"<<endl;
          else{
            cout<<v[n][j].ff<<" ("<<v[n][j].ss<<")"<<" * ";
          }
      }
  }
 
 
  return 0;
}
