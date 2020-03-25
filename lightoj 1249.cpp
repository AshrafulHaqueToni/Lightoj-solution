#include<bits/stdc++.h>
using namespace std;

void solve(int ii)
{
    int n;
    scanf("%d",&n);
    pair<int,string>p[n+5];
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        p[i]={x*y*z,s};
    }
    sort(p+1,p+n+1);
    if(p[1].first!=p[n].first)
    {
        cout<<"Case "<<ii<<": "<<p[n].second<<" took chocolate from "<<p[1].second<<endl;
        //cout<<p[1].second<<" "<<p[n].second<<endl;
    }
    else cout<<"Case "<<ii<<": no thief"<<endl;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);

    return 0;
}
