///***Bismillahir Rahmanir Rahim***///

///*********************************///
///******Ashraful Haque Toni********///
///********Dept. of CSE,JnU*********///
///email:ashrafulhaquetoni@gmail.com///
///*******contact:01640690531*******///
///*********************************///


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
#define         d double


const int mod =1e9+7;
const int N =5e6+5;
typedef long long ll;



int main()
{

   // ash;
    //freopen("1331.txt","r",stdin);
    int t;
    cin>>t;

    for(int ii=1;ii<=t;ii++)
    {
        d r1,r2,r3;
        cin>>r1>>r2>>r3;
        d a=r1+r2,b=r2+r3,c=r3+r1;

        d s=(a+b+c)/2;

        d triarea=sqrt(s*(s-a)*(s-b)*(s-c));

        //cout<<triarea<<endl;

        d c1=acos((-b*b+c*c+a*a)/(2*a*c));//*(pi/180);
        d c2=acos((a*a-c*c+b*b)/(2*a*b));//*(pi/180);
        d c3=acos((b*b-a*a+c*c)/(2*b*c));//*(pi/180);

        //cout<<c1<<" "<<c2<<" "<<c3<<endl;

        d total=(0.5*r1*r1*c1)+(0.5*r2*r2*c2)+(0.5*r3*r3*c3);

        pf("Case %d: %0.10f\n",ii,triarea-total);
    }



    return 0;
}


