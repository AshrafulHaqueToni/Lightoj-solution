//***Bismillahir Rahmanir Rahim***//


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


int main()
{
    ash;

    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int l[101],r[101];
        Memset(l,0);
        Memset(r,0);
        int u,v,w,cnt1=0,cnt2=0,n;
        cin>>n;
        f(0,n,1)
        {
            //int u,v,w,cnt1=0,cnt2=0;
            cin>>u>>v>>w;
            if(l[u]==0&&r[v]==0)
            {
                l[u]=1;
                r[v]=1;
                cnt1+=w;
               //cout<<1<<endl;
            }
            else
            {
                l[v]=1;
                r[u]=1;
                cnt2+=w;
            }
        }
        //cout<<cnt1<<cnt2;
        cout<<"Case "<<i<<": "<<min(cnt1,cnt2)<<"\n";


    }




    return 0;
}


