///***Bismillahir Rahmanir Rahim***///
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
#define         I3(m,n,o)         cin>>m>>n>>o;
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
#define         PC(i)             cout<<"Case "<<i<<": ";


                               ///template function///

///ll GCD(ll a,ll b){if(a<0) a*=-1;if(b<0) b*=-1;if(a<b)swap(a,b);if(b==1) return 1;if(!b) return a;if(!(a%b)) return b;else return GCD(b,a%b);}
///ll LCM(ll a,ll b){ll x=GCD(a,b);return (a/x)*b;}
///ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n+mod)%mod;if(p%2)return (bigmod(n,p-1)*n+mod)%mod;else{ll x=bigmod(n,p/2);return (x*x+mod)%mod;}}
///ll modinverse(ll n){return bigmod(n,mod-2)%mod;}
///ll num_coprime(ll n){ll ans=n;for(ll i=2;i*i<=n; i++){if(n%i==0){while(n%i==0)n/=i;ans-=ans/i;}}if(n>1)ans-=ans/n;return ans;}
set<ll>s;void divisors(ll n){f1(i,sqrt(n))if(n%i==0){s.insert(i);s.insert(n/i);}}


///*********************************************start***********************************************///

set<ll>ss;





int main()
{
    freopen("1014.txt","r",stdin);

    //ash;
    ll t;
    I1(t);
    f1(i,t)
    {
        s.clear();
        ss.clear();
        ll p,m;
        I2(p,m);

        PC(i);
        if(p==0&&m==0){cout<<1<<endl;continue;}

        divisors(p-m);
        //vec v;
        if(p-m<=m){cout<<"impossible"<<endl;continue;}

        else{

            for(auto it:s)
            {
                //cout<<it<<endl;
                if(it>m)ss.insert(it);
            }
        }
        //vsort(ss);

        auto it1=ss.end();
        it1--;

       for(auto it: ss)
       {
           if(it==*it1)cout<<it;
           else cout<<it<<" ";
       }
       cout<<endl;


        //s.clear();
        //ss.clear();

    }




    return 0;
}

///**********************************************end*************************************************///
