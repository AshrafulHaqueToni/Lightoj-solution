#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);

    for(int ii=1;ii<=t;ii++)
    {
        string cur="http://www.lightoj.com/";

        printf("Case %d:\n",ii);
        stack<string>bac,fo,swa;

        while(1)
        {
            string s;
            cin>>s;
            if(s=="QUIT")break;

            if(s=="BACK")
            {
                if(bac.empty()){
                    printf("Ignored\n");
                    continue;
                }

                fo.push(cur);

                cur=bac.top();

                bac.pop();

                cout<<cur<<"\n";
            }

            if(s=="FORWARD")
            {
                if(fo.empty()){
                    printf("Ignored\n");
                    continue;
                }

                bac.push(cur);

                cur=fo.top();

                fo.pop();

                cout<<cur<<"\n";
            }
            if(s=="VISIT")
            {
                string t;
                cin>>t;

                bac.push(cur);
                cur=t;

                fo=swa;

                cout<<cur<<"\n";
            }

        }
    }

    return 0;
}
