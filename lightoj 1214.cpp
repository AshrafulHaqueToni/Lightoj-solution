#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    //ios_base::sync_with_stdio(false);
   // cin.tie(NULL);

    int t;
    cin>>t;

    for(int i=1; i<=t; i++)
    {
        string s;
        cin>>s;

        ll b,bb;
        cin>>b;

       // if(b<0)b*=-1;

        ll cnt=0,a=0;


        ll sz=s.size();


            for(ll j=0; j<sz; j++)
            {
                if(s[j]=='-')
                {
                    b*=-1;
                    continue;
                }
                a=10*a+(s[j]-48);
                a%=b;

                //cout<<a<<endl;

            }


        //cout<<a<<" "<<b<<endl;

        cout<<"Case "<<i<<": ";
        if(a%b)
            cout<<"not divisible\n";
                else
                    cout<<"divisible\n";


    }



    return 0;
}
