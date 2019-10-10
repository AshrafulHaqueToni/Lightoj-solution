#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 2000010

vector<ll>v;
bool a[mx];

void sieve()
{
    for(int i=3; i*i<=mx; i++)
    {
        if(!a[i])
        {
            for(int j=i*i; j<=mx; j+=i)
            {
                a[j]=true;
            }
        }
    }

    v.push_back(2);

    for(int i=3; i<=mx; i+=2)
    {
        if(!a[i])
            v.push_back(i);
    }

    //for(auto it: v)cout<<it<<" ";
}


int main()
{
    // freopen("input.txt","r",stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(false);

    sieve();

    int t;
    //scanf("%d",&t);
    cin>>t;

    for(int ii=1; ii<=t; ii++)
    {
        ll a,b,lcm,c=1;

        //scanf("%lld%lld%lld",&a,&b,&lcm);
        cin>>a>>b>>lcm;

        //printf("Case %d: ",ii);
        //printf("Case %d: ",ii);
        cout<<"Case "<<ii<<": ";

        if(lcm%a!=0||lcm%b!=0)
        {
            //printf("impossible\n");
            //printf("impossible\n");
            cout<<"impossible\n";
            continue;
        }


        for(int i=0; v.size(); i++)
        {
            if(lcm<v[i])
                break;

            int cnt1=0,cnt2=0,cnt3=0;

            if(lcm%v[i]==0)
            {

                while(1)
                {
                    if(lcm%v[i]==0)
                    {
                        cnt3++;
                        lcm/=v[i];
                    }
                    else
                        break;

                    if(a%v[i]==0)
                    {
                        cnt1++;
                        a/=v[i];
                    }

                    if(b%v[i]==0)
                    {
                        cnt2++;
                        b/=v[i];
                    }
                }

                //cout<<a<<" "<<b<<" "<<lcm<<" "<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;


                if(max(cnt1,cnt2)<cnt3)
                {
                    for(int j=1; j<=cnt3; j++)
                        c*=v[i];
                }
            }

        }

        //printf("%lld\n",c);
        cout<<c<<endl;

    }

    return 0;
}
