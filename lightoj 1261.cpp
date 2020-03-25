#include<bits/stdc++.h>
using namespace std;


void solve(int ii)
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    vector<string>v[n+5];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            string ch;
            cin>>ch;
            v[i].push_back(ch);
        }
    }
    vector<int>tem;
    int ti;
    scanf("%d",&ti);
    for(int i=1;i<=ti;i++)
    {
        int x;
        scanf("%d",&x);
        tem.push_back(x);
    }
    bool re=true;

    for(int i=0;i<n;i++)
    {
        bool f=false;
        for(int j=0;j<k;j++)
        {
            string ss=v[i][j],sss="";
            for(int l=1;l<ss.size();l++)
            {
                sss+=ss[l];
            }
          int val=stoi(sss);
          if(ss[0]=='+')
          {
              for(int l=0;l<ti;l++)
              {
                  if(val==tem[l])f=true;
              }
          }
          else
          {
              bool ff=true;
              for(int l=0;l<ti;l++)
              {
                  if(val==tem[l])ff=false;
              }
              if(ff)f=true;
              //cout<<val<<endl;
          }

         // cout<<f<<endl;
        }
        if(f==false)re=false;
        //cout<<re<<endl;
    }
    printf("Case %d: ",ii);
    if(re)printf("Yes\n");
    else printf("No\n");
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);

    return 0;
}
