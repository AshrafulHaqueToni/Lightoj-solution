#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int cnt2,cnt5,n,m,p,q;
 
 
int numberofzeroinfactorial(int n,int div)
{
    int cnt=0;
 
    while(n>0)
    {
        cnt+=n/div;
        n/=div;
    }
    return cnt;
}
 
int factoraization(int n,int div)
{
    int cnt=0;
 
    while(n>0&&n%div==0)
    {
        cnt++;
        n/=div;
    }
 
    return cnt;
}
 
void cnt()
{
    int a,b,c,d,e,f;
    a=numberofzeroinfactorial(n,2);
    b=numberofzeroinfactorial(n,5);
    c=numberofzeroinfactorial(m,2);
    c+=numberofzeroinfactorial(n-m,2);
    d=numberofzeroinfactorial(m,5);
    d+=numberofzeroinfactorial(n-m,5);
 
    e=factoraization(p,2);
    f=factoraization(p,5);
 
    //printf("%d %d %d %d %d %d\n",a,b,c,d,e,f);
 
    e*=q;
    f*=q;
 
    cnt2=a-c+e;
    cnt5=b-d+f;
}
 
int main()
{
    int t;
    scanf("%d",&t);
 
    for(int ii=1;ii<=t;ii++)
    {
        cnt2=0,cnt5=0;
 
        scanf("%d%d%d%d",&n,&m,&p,&q);
 
        cnt();
 
        printf("Case %d: ",ii);
 
        if(cnt2<cnt5)
        {
            printf("%d\n",cnt2);
 
        }
        else printf("%d\n",cnt5);
 
    }
    return 9;
}
