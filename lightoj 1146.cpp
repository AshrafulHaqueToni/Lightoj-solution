#include<bits/stdc++.h>
using namespace std;
 
#define eps 0.000000001
#define pi pair<double,double>
 
pi ar[4];
 
double dist(pi a,pi b)
{
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
void solve(int ii)
{
    for(int i=0;i<4;i++)scanf("%lf%lf",&ar[i].first,&ar[i].second);
 
    double ac=dist(ar[0],ar[2]);
    double bd=dist(ar[1],ar[3]);
  //  cout<<ac<<" "<<bd<<endl;
    while(abs(ac-bd)>eps)
    {
      //  cout<<ac<<" "<<bd<<endl;
        pi a,b,c,d;
        a.first=(2*ar[0].first+ar[1].first)/3.0;
        a.second=(2*ar[0].second+ar[1].second)/3.0;
        b.first=(ar[0].first+2*ar[1].first)/3.0;
        b.second=(ar[0].second+2*ar[1].second)/3.0;
 
        c.first=(2*ar[2].first+ar[3].first)/3.0;
        c.second=(2*ar[2].second+ar[3].second)/3.0;
        d.first=(ar[2].first+2*ar[3].first)/3.0;
        d.second=(ar[2].second+2*ar[3].second)/3.0;
 
        ac=dist(a,c);
        bd=dist(b,d);
 
        if(ac>bd)ar[0]=a,ar[2]=c;
        else ar[1]=b,ar[3]=d;
    }
 
    printf("Case %d: %0.8F\n",ii,(ac+bd)/2.0);
}
 
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        solve(i);
    }
    return 0;
}
