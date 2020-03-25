#include<bits/stdc++.h>
using namespace std;


void solve(int ii)
{
    int n;
    scanf("%d",&n);
    printf("Case %d:\n",ii);
    int re=0;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        if(s[0]=='d')
        {
            int x;
            scanf("%d",&x);
            re+=x;
        }
        else printf("%d\n",re);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
