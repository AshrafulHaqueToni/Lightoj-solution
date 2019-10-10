//***Bismillahir Rahmanir Rahim***//

//*********************************//
//******Ashraful Haque Toni********//
//********Dept. of CSE,JnU*********//
//email:ashrafulhaquetoni@gmail.com//
//*******contact:01640690531*******//
//*********************************//


#include<bits/stdc++.h>

using namespace std;

#define         ash ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define         pb push_back
#define         mp make_pair
#define         sc(n) scanf("%d",&n);
#define         scl(n) scanf("%I64d",&n);
#define         sc2(m,n) scanf("%d%d",&m,&n);
#define         sc2l(m,n) scanf("%I64d%I64d",&m,&n);
#define         pf printf
#define         Big(x,y) max(x,y);
#define         Small(x,y) min(x,y);
#define         input(array,size) for(int i=0;i<size;i++)cin>>array[i];
#define         newline pf("\n");
#define         f(s,l,in) for(ll i=s;i<l;i+=in)
#define         Max INT_MAX
#define         Min INT_MIN
#define         pi acos(-1.0)
#define         Memset(a,val) memset(a,val,sizeof(a));

const int mod =1e9+7;
const int N =5e6+5;
typedef long long ll;

int func(ll n)
{
    int cnt=0;
    for(ll k=1; k<=n; k*=2)
    {
        if(n & k)
            cnt++;
            //cout<<cnt;
    }

    return cnt;
}

int main()
{
    //ash;
    int t;
    cin>>t;

    for(int i=1; i<=t; i++)
    {

        ll n;
        cin>>n;
        ll fin;
        for(ll j=1; j<=n; j*=2)
        {
            if(n & j)
            {
                fin=n+j;
               // cout<<fin;
                break;
            }
        }

        ll cnt=func(n)-func(fin);

        for(ll j=0;j<cnt;j++)fin+=(1<<j);

        cout<<"Case "<<i<<": "<<fin<<endl;

    }
    return 0;
}
